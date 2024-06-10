#version 300 es
precision mediump float;


//STRUCT
//**********************************************************************************************************************
#if (DLIGHTS)
struct DLight {
    //bool directional;
    //vec3 position;
    vec3 color;
};
#fi
#if (PLIGHTS)
struct PLight {
    //bool directional;
    vec3 position;
    vec3 color;
    float distance;
    //float decay;

    float constant;
    float linear;
    float quadratic;
};
#fi
#if (SLIGHTS)
struct SLight {
    //bool directional;
    vec3 position;
    vec3 color;
    float distance;
    //float decay;
    float cutoff;
    float outerCutoff;
    vec3 direction;

    float constant;
    float linear;
    float quadratic;
};
#fi

struct Material {
    vec3 emissive;
    vec3 diffuse;
    #if (TEXTURE)
        #for I_TEX in 0 to NUM_TEX
            sampler2D texture##I_TEX;
        #end
    #fi
    #if (CUBETEXTURES)
        #for I_TEX in 0 to NUM_CUBETEXTURES
            samplerCube cubeTexture##I_TEX;
        #end
    #fi
};


//UIO
//**********************************************************************************************************************
uniform Material material;
#if (TRANSPARENT)
uniform float alpha;
#else
float alpha = 1.0;
#fi


#if (DLIGHTS)
uniform DLight dLights[##NUM_DLIGHTS];
#fi
#if (PLIGHTS)
uniform PLight pLights[##NUM_PLIGHTS];
#fi
#if (SLIGHTS)
uniform SLight sLights[##NUM_SLIGHTS];
#fi
uniform vec3 ambient;

#if (PLIGHTS || SLIGHTS)
in vec3 fragVPos;
#fi


#if (COLORS)
    in vec4 fragVColor;
#fi

#if (TEXTURE)
    in vec2 fragUV;
#fi

out vec4 color;

#if (CLIPPING_PLANES)
    struct ClippingPlane {
        vec3 normal;
        float constant;
    };

    uniform ClippingPlane clippingPlanes[##NUM_CLIPPING_PLANES];

    in vec3 vViewPosition;
#fi

#if (CUBETEXTURES)
    uniform vec3 cameraPosition;
    //uniform samplerCube skybox_tex;
    uniform mat4 VMat;
    in vec3 fragVPos_worldspace;
    in vec3 fragVNorm_worldspace;
#fi


//FUNCTIONS
//**********************************************************************************************************************
#if (PLIGHTS || SLIGHTS)
float calcAttenuation(float constant, float linear, float quadratic, float distance) {
    //float attenuation = 1.0f / (1.0f + 0.01f * distance + 0.0001f * (distance * distance));
    //float attenuation = light.decay / (light.decay + 0.01f * distance + 0.0001f * (distance * distance));
    
    return 1.0 / (constant + linear * distance + quadratic * (distance * distance));
}
#fi

#if (PLIGHTS)
    // Calculates the point light color contribution
    vec3 calcPointLight(PLight light) {

        float distance = length(light.position - fragVPos);
        if(light.distance > 0.0 && distance > light.distance) return vec3(0.0, 0.0, 0.0);

        // Attenuation
        float attenuation = calcAttenuation(light.constant, light.linear, light.quadratic, distance);

        // Combine results
        vec3 diffuse = light.color * material.diffuse * attenuation;

        return diffuse;
    }
#fi

#if (SLIGHTS)
    // Calculates the point light color contribution
    vec3 calcSpotLight(SLight light) {
        
        float distance = length(light.position - fragVPos);
        if(light.distance > 0.0 && distance > light.distance) return vec3(0.0, 0.0, 0.0);


        // spot
        vec3 lightDir = normalize(light.position - fragVPos);
        
        float theta = dot(lightDir, normalize(-light.direction));
        float epsilon = light.cutoff - light.outerCutoff;
        float intensity = clamp((theta - light.outerCutoff) / epsilon, 0.0, 1.0);
        //if(theta <= light.cutoff) return vec3(0.0, 0.0, 0.0);
        if(theta <= light.outerCutoff) return vec3(0.0, 0.0, 0.0);


        // Attenuation
        float attenuation = calcAttenuation(light.constant, light.linear, light.quadratic, distance);

        // Combine results
        vec3 diffuse = light.color * material.diffuse * attenuation;

        return diffuse * intensity;
    }
#fi


//MAIN
//**********************************************************************************************************************
void main() {
    #if (CLIPPING_PLANES)
        bool clipped = true;
        for(int i = 0; i < ##NUM_CLIPPING_PLANES; i++){
                clipped = ( dot( vViewPosition, clippingPlanes[i].normal ) > clippingPlanes[i].constant ) && clipped;
        }
        if ( clipped ) discard;
    #fi


    #if (CIRCLES)
        vec2 cxy = 2.0 * gl_PointCoord - 1.0;
        float pct = dot(cxy, cxy);
        if (pct > 1.0) {
            discard; //performance trap
            //color = vec4(1.0, 1.0, 1.0, 0.0);
        }
    #fi


    // Calculate combined light contribution
    vec3 combined = ambient + material.emissive;

    #if (DLIGHTS)
        #for lightIdx in 0 to NUM_DLIGHTS
            combined += dLights[##lightIdx].color * material.diffuse;
        #end
    #fi
    #if (PLIGHTS)
        #for lightIdx in 0 to NUM_PLIGHTS
            combined += calcPointLight(pLights[##lightIdx]);
        #end
    #fi
    #if (SLIGHTS)
        #for lightIdx in 0 to NUM_SLIGHTS
            combined += calcSpotLight(sLights[##lightIdx]);
        #end
    #fi

    color = vec4(combined, alpha);


    #if (COLORS)
        color += fragVColor;
    #fi


    #if (TEXTURE)
        // Apply all of the textures
        #for I_TEX in 0 to NUM_TEX
            color *= texture(material.texture##I_TEX, fragUV);
        #end
    #fi

    #if (CUBETEXTURES)
        vec3 I = normalize(fragVPos_worldspace - cameraPosition);
        vec3 R = reflect(I, normalize(fragVNorm_worldspace));

        // float ratio = 1.00 / 1.52;
        // vec3 I = normalize(fragVPos_worldspace - cameraPosition);
        // vec3 R = refract(I, normalize(fragVNorm_worldspace), ratio);

        // Apply all of the textures
        #for I_TEX in 0 to NUM_CUBETEXTURES
            color *= texture(material.cubeTexture##I_TEX, R);
        #end
    #fi
}

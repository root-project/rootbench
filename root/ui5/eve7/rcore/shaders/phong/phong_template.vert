#version 300 es
precision mediump float;


//STRUCT
//**********************************************************************************************************************
#if (DLIGHTS)
struct DLight {
    //bool directional;
    vec3 position;
    vec3 direction;
    vec3 color;

    mat4 VPMat;
    sampler2D shadowmap;
    bool castShadows;
    bool hardShadows;
    float minBias;
    float maxBias;
};
#fi
#if (PLIGHTS)
struct PLight {
    //bool directional;
    vec3 position;
    vec3 position_worldspace;
    vec3 color;
    float distance;
    //float decay;

    mat4 VPMat;
    samplerCube shadowmap;
    bool castShadows;
    bool hardShadows;
    float minBias;
    float maxBias;
    float shadowFar;

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
    // float decay;
    float cutoff;
    float outerCutoff;
    vec3 direction;

    mat4 VPMat;
    sampler2D shadowmap;
    bool castShadows;
    bool hardShadows;
    float minBias;
    float maxBias;

    float constant;
    float linear;
    float quadratic;
};
#fi


//UIO
//**********************************************************************************************************************
#if (DLIGHTS)
uniform DLight dLights[##NUM_DLIGHTS];
#fi
#if (PLIGHTS)
uniform PLight pLights[##NUM_PLIGHTS];
#fi
#if (SLIGHTS)
uniform SLight sLights[##NUM_SLIGHTS];
#fi


#if (INSTANCED)
//uniform mat4 VMat;
uniform mat4 MVMat;
#fi
#if (!INSTANCED)
uniform mat4 MVMat; // Model View Matrix
#fi
uniform mat4 PMat;  // Projection Matrix
uniform mat3 NMat;  // Normal Matrix

#if (INSTANCED)
in mat4 MMat;
#fi
in vec3 VPos;       // Vertex position
#if (!NORMAL_MAP && !NORMAL_FLAT)
in vec3 VNorm;      // Vertex normal
#fi

#if (TEXTURE || DIFFUSE_MAP || SPECULAR_MAP || NORMAL_MAP)
    in vec2 uv;          // Texture coordinate
#fi

#if (COLORS)
    in vec4 VColor;
    out vec4 fragVColor;
#fi

// Output transformed vertex position, normal and texture coordinate
out vec3 fragVPos;
#if (!NORMAL_MAP && !NORMAL_FLAT)
out vec3 fragVNorm;
#fi
#if (TEXTURE || DIFFUSE_MAP || SPECULAR_MAP || NORMAL_MAP)
out vec2 fragUV;
#fi

#if (POINTS)
    uniform float pointSize;
#fi

#if (CLIPPING_PLANES)
    out vec3 vViewPosition;
#fi

out vec3 fragVPos_worldspace;
#if (CUBETEXTURES)
    //uniform mat3 NMat;  // Normal Matrix
    //uniform mat4 u_MMat;
    //in vec3 VNorm;
    //out vec3 fragVPos_worldspace;
    out vec3 fragVNorm_worldspace;
#fi


uniform mat4 u_MMat;
#if (DLIGHTS)
out vec4 fragVPos_dlightspace[##NUM_DLIGHTS];
#fi
#if (PLIGHTS)
out vec4 fragVPos_plightspace[##NUM_PLIGHTS];
#fi
#if (SLIGHTS)
out vec4 fragVPos_slightspace[##NUM_SLIGHTS];
#fi


#if (NORMAL_MAP)
in vec3 a_Tangent;
in vec3 a_Bitangent;

out vec3 v_position_tangentspace;
//out vec3 v_viewPosition_tangentspace; // = vec3(0.0, 0.0, 0.0)
//out vec3 v_lightPosition_tangentspace; //array per light type


#if (DLIGHTS)
//out vec3 v_dLightPosition_tangentspace[##NUM_DLIGHTS];
out vec3 v_dLightDirection_tangentspace[##NUM_DLIGHTS];
#fi
#if (PLIGHTS)
out vec3 v_pLightPosition_tangentspace[##NUM_PLIGHTS];
#fi
#if (SLIGHTS)
out vec3 v_sLightPosition_tangentspace[##NUM_SLIGHTS];
out vec3 v_sLightDirection_tangentspace[##NUM_SLIGHTS];
#fi
#fi


//MAIN
//**********************************************************************************************************************
void main() {
    // Model view position
    //vec4 VPos4 = MVMat * vec4(VPos, 1.0); //original (non-instanced)
    #if (!INSTANCED)
    vec4 VPos4 = MVMat * vec4(VPos, 1.0);

        #if (DLIGHTS)
            #for lightIdx in 0 to NUM_DLIGHTS
                fragVPos_dlightspace[##lightIdx] = dLights[##lightIdx].VPMat * u_MMat * vec4(VPos, 1.0);
            #end
        #fi
        #if (PLIGHTS)
            #for lightIdx in 0 to NUM_PLIGHTS
                fragVPos_plightspace[##lightIdx] = pLights[##lightIdx].VPMat * u_MMat * vec4(VPos, 1.0);
            #end
        #fi
        #if (SLIGHTS)
            #for lightIdx in 0 to NUM_SLIGHTS
                fragVPos_slightspace[##lightIdx] = sLights[##lightIdx].VPMat * u_MMat * vec4(VPos, 1.0);
            #end
        #fi
    #fi
    #if (INSTANCED)
    //vec4 VPos4 = VMat * MMat * vec4(VPos, 1.0);
    vec4 VPos4 = MVMat * MMat * vec4(VPos, 1.0);

        #if (DLIGHTS)
            #for lightIdx in 0 to NUM_DLIGHTS
                    fragVPos_dlightspace[##lightIdx] = dLights[##lightIdx].VPMat * u_MMat * MMat * vec4(VPos, 1.0);
            #end
        #fi
        #if (PLIGHTS)
            #for lightIdx in 0 to NUM_PLIGHTS
                    fragVPos_plightspace[##lightIdx] = pLights[##lightIdx].VPMat * u_MMat * MMat * vec4(VPos, 1.0);
            #end
        #fi
        #if (SLIGHTS)
            #for lightIdx in 0 to NUM_SLIGHTS
                    fragVPos_slightspace[##lightIdx] = sLights[##lightIdx].VPMat * u_MMat * MMat * vec4(VPos, 1.0);
            #end
        #fi
    #fi


    #if (NORMAL_MAP)
    vec3 T = normalize(vec3(MVMat * vec4(a_Tangent, 0.0)));
    vec3 B = normalize(vec3(MVMat * vec4(a_Bitangent, 0.0)));
    vec3 N = normalize(vec3(MVMat * vec4(VNorm, 0.0)));
    mat3 TBN = mat3(T, B, N);
    TBN = transpose(TBN); //inverse

    #if (DLIGHTS)
        #for lightIdx in 0 to NUM_DLIGHTS
            //v_dLightPosition_tangentspace[##lightIdx] = TBN * dLights[##lightIdx].position; //viewspace to tangentspace
            v_dLightDirection_tangentspace[##lightIdx] = TBN * dLights[##lightIdx].direction;
        #end
    #fi
    #if (PLIGHTS)
        #for lightIdx in 0 to NUM_PLIGHTS
            v_pLightPosition_tangentspace[##lightIdx] = TBN * pLights[##lightIdx].position;
        #end
    #fi
    #if (SLIGHTS)
        #for lightIdx in 0 to NUM_SLIGHTS
            v_sLightPosition_tangentspace[##lightIdx] = TBN * sLights[##lightIdx].position;
            v_sLightDirection_tangentspace[##lightIdx] = TBN * sLights[##lightIdx].direction;
        #end
    #fi

    v_position_tangentspace = TBN * VPos4.xyz;
    #fi


    // Projected position
    gl_Position = PMat * VPos4;
    fragVPos = vec3(VPos4) / VPos4.w;

    #if (!NORMAL_MAP && !NORMAL_FLAT)
        // Transform normal
        //fragVNorm = vec3(NMat * VNorm);
        #if (!INSTANCED)
        fragVNorm = vec3(NMat * VNorm);
        #fi
        #if (INSTANCED)
        fragVNorm = vec3(NMat * mat3(MMat) * VNorm);
        #fi
    #fi

    #if (TEXTURE || DIFFUSE_MAP || SPECULAR_MAP || NORMAL_MAP)
        // Pass-through texture coordinate
        fragUV = uv;
    #fi

    #if (COLORS)
        // Pass vertex color to fragment shader
        fragVColor = VColor;
    #fi

    #if (POINTS)
        gl_PointSize = pointSize / length(VPos4.xyz);
        if(gl_PointSize < 1.0) gl_PointSize = 1.0;
    #fi

    #if (CLIPPING_PLANES)
        vViewPosition = -VPos4.xyz;
    #fi

    fragVPos_worldspace = vec3(u_MMat * vec4(VPos, 1.0));
    #if (CUBETEXTURES)
        //fragVPos_worldspace = vec3(u_MMat * vec4(VPos, 1.0));
        fragVNorm_worldspace = mat3(transpose(inverse(u_MMat))) * VNorm;
    #fi
}

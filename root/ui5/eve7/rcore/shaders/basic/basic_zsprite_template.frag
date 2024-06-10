#version 300 es
precision mediump float;

//DEF
//**********************************************************************************************************************

#define SPRITE_SPACE_WORLD 0.0
#define SPRITE_SPACE_SCREEN 1.0

struct Material {
    vec3 emissive;
    // vec3 diffuse;
    #if (INSTANCED)
        sampler2D instanceData0;
    #fi
    #if (TEXTURE)
        #for I_TEX in 0 to NUM_TEX
            sampler2D texture##I_TEX;
        #end
    #fi
};


//UIO
//**********************************************************************************************************************

uniform Material material;
uniform vec3 ambient;

#if (TRANSPARENT)
    uniform float alpha;
#else
    float alpha = 1.0;
#fi

#if (COLORS)
    in vec4 fragVColor;
#fi

#if (TEXTURE)
    in vec2 fragUV;
#fi

#if (PICK_MODE_RGB)
    uniform vec3 u_RGB_ID;
    layout(location = 0) out vec4 objectID;
#else if (PICK_MODE_UINT)
    uniform uint u_UINT_ID;
    #if (INSTANCED)
        uniform bool u_PickInstance;
        flat in uint InstanceID;
    #fi
    layout(location = 0) out uint objectID;
#else if (OUTLINE)
    // in vec3 v_position_viewspace;
    in vec3 v_normal_viewspace;
    in vec3 v_ViewDirection_viewspace;

    layout (location = 0) out vec4 vn_viewspace;
    layout (location = 1) out vec4 vd_viewspace;
    #if (DEPTH)
        layout (location = 2) out vec4 de_viewspace; // could be float
    #fi
#else
    out vec4 outColor;
#fi

#if (CLIPPING_PLANES)
    struct ClippingPlane {
        vec3 normal;
        float constant;
    };

    uniform ClippingPlane clippingPlanes[##NUM_CLIPPING_PLANES];

    in vec3 vViewPosition;
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

    vec4 color = vec4(ambient + material.emissive, alpha);

    #if (COLORS)
        color += fragVColor;
    #fi

    #if (TEXTURE)
        #for I_TEX in 0 to NUM_TEX
            color *= texture(material.texture##I_TEX, fragUV);
        #end
        #if (TRANSPARENT)
            if (color.w <= 0.00392) discard;
        #fi
    #fi

    // Special handling for outline to provide better edge detection,
    // especially with overlapping outlined objects.
    #if (OUTLINE)
        if (color.w > 0.50) {
            vn_viewspace = vec4(v_normal_viewspace, 0.0);
            vd_viewspace = vec4(v_ViewDirection_viewspace, 0.0);
            #if (DEPTH)
                de_viewspace = vec4(gl_FragCoord.z, 0.0, 0.0, 1.0);
            #fi
        } else {
            discard;
        }
    #else
        #if (PICK_MODE_RGB)
            objectID = vec4(u_RGB_ID, 1.0);
        #else if (PICK_MODE_UINT)
            #if (INSTANCED)
                if (u_PickInstance) {
                    objectID = InstanceID; // 0 is a valid result
                } else {
                    objectID = u_UINT_ID;
                }
            #else
                objectID = u_UINT_ID;
            #fi
        #else
            outColor = color;
        #fi
    #fi
}

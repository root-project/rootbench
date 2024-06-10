#version 300 es
precision mediump float;


//DEF
//**********************************************************************************************************************
#define SPRITE_SPACE_WORLD 0.0
#define SPRITE_SPACE_SCREEN 1.0

#if (INSTANCED)
struct Material {
    vec3 emissive;
    // vec3 diffuse;
    sampler2D instanceData0;
    // The following could (should, really) be an int attribute with divisor 1
    // #if (OUTLINE)
    //    isampler2D instance_indices;
    // #fi
    #if (TEXTURE)
        #for I_TEX in 0 to NUM_TEX
            sampler2D texture##I_TEX;
        #end
    #fi
};
#fi

//UIO
//**********************************************************************************************************************
uniform mat4 MVMat; // Model View Matrix
uniform mat4 PMat;  // Projection Matrix
uniform vec2 viewport;
uniform float SpriteMode;
uniform vec2 SpriteSize;

in vec3 VPos;       // Vertex position

#if (COLORS)
    in vec4 VColor;
    out vec4 fragVColor;
#fi

#if (TEXTURE)
    in vec2 uv;
    out vec2 fragUV;
#fi

#if (CLIPPING_PLANES)
    out vec3 vViewPosition;
#fi

#if (INSTANCED)
    uniform Material material;
    #if (PICK_MODE_UINT)
        flat out uint InstanceID;
    #fi
    #if (OUTLINE)
        uniform bool u_OutlineGivenInstances;
        in  int  a_OutlineInstances;
    #fi
#fi

#if (OUTLINE)
    out vec3 v_normal_viewspace;
    out vec3 v_ViewDirection_viewspace;
#fi

//MAIN
//**********************************************************************************************************************
void main() {
    // Position of the origin in viewspace.
    vec4 VPos_viewspace;

    #if (INSTANCED)
        int iID = gl_InstanceID;
        #if (OUTLINE)
            if (u_OutlineGivenInstances)
                iID = a_OutlineInstances;
        #fi
        int   tsx = textureSize(material.instanceData0, 0).x;
        ivec2 tc  = ivec2(iID % tsx, iID / tsx);
        vec4  pos = texelFetch(material.instanceData0, tc, 0);
        // see also texelFetchOffset about how to get neigboring texels

        VPos_viewspace = MVMat * vec4(pos.xyz, 1.0);
    #else
        VPos_viewspace = MVMat * vec4(0.0, 0.0, 0.0, 1.0);
    #fi


    if(SpriteMode == SPRITE_SPACE_WORLD)
    {
        // Assume vertices in x,y plane, z = 0; close to (0, 0) as SpriteSize
        // will scale them (for centered sprite there should be a quad with x, y = +-0.5).
        gl_Position = PMat * (VPos_viewspace + vec4(VPos, 1.0)*vec4(SpriteSize.xy, 0.0, 0.0));
    }
    else if(SpriteMode == SPRITE_SPACE_SCREEN)
    {
        vec4 VPos_clipspace = PMat * VPos_viewspace;
        gl_Position = VPos_clipspace + vec4(VPos.xy * 2.0 * SpriteSize.xy / viewport * VPos_clipspace.w, 0.0, 0.0);
    }

    #if (COLORS)
        // Pass vertex color to fragment shader
        fragVColor = VColor;
    #fi

    #if (TEXTURE)
        // Pass uv coordinate to fragment shader
        fragUV = uv;
    #fi

    #if (CLIPPING_PLANES)
        vViewPosition = -VPos_viewspace.xyz;
    #fi

    #if (OUTLINE)
        v_normal_viewspace = vec3(0.0, 0.0, -1.0);

        float dToCam = length(VPos_viewspace.xyz);
        v_ViewDirection_viewspace = -VPos_viewspace.xyz / dToCam;
    #fi

    #if (INSTANCED && PICK_MODE_UINT)
        InstanceID = uint(iID);
    #fi
 }

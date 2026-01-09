#version 300 es
precision mediump float;


//UIO
//**********************************************************************************************************************
#if (INSTANCED)
//uniform mat4 VMat;
uniform mat4 MVMat;
#fi
#if (!INSTANCED)
uniform mat4 MVMat; // Model View Matrix
#fi
uniform mat4 PMat;  // Projection Matrix

#if (INSTANCED)
in mat4 MMat;
#fi
in vec3 VPos;       // Vertex position
#if (OUTLINE)
    in vec3 VNorm;      // Vertex normal
    //uniform mat3 NMat;  // Normal Matrix
    //uniform vec3 cameraPosition;
    uniform float offset;
#fi

#if (COLORS)
    in vec4 VColor;
    out vec4 fragVColor;
#fi

#if (TEXTURE)
    in vec2 uv;
    out vec2 fragUV;
#fi

#if (PLIGHTS || SLIGHTS)
    out vec3 fragVPos;
#fi

#if (POINTS)
    uniform float pointSize;
#fi

#if (CLIPPING_PLANES)
    out vec3 vViewPosition;
#fi

#if (CUBETEXTURES)
    //uniform mat3 NMat;  // Normal Matrix
    uniform mat4 MMat;
    in vec3 VNorm;
    out vec3 fragVPos_worldspace;
    out vec3 fragVNorm_worldspace;
#fi


//MAIN
//**********************************************************************************************************************
void main() {
    // Model view position
    #if (!OUTLINE)
        #if (!INSTANCED)
        vec4 VPos4 = MVMat * vec4(VPos, 1.0);
        #fi
        #if (INSTANCED)
        //vec4 VPos4 = VMat * MMat * vec4(VPos, 1.0);
        vec4 VPos4 = MVMat * MMat * vec4(VPos, 1.0);
        #fi
    #fi
    #if (OUTLINE)
        #if (!INSTANCED)
        vec4 VPos4 = MVMat * vec4(VPos + VNorm * offset, 1.0);
        #fi
        #if (INSTANCED)
        //vec4 VPos4 = VMat * MMat * vec4(VPos + VNorm * offset, 1.0);
        vec4 VPos4 = MVMat * MMat * vec4(VPos + VNorm * offset, 1.0);
        #fi
    #fi

    // Projected position
    gl_Position = PMat * VPos4;

    #if (PLIGHTS || SLIGHTS)
        // Pass vertex position to fragment shader
        fragVPos = vec3(VPos4) / VPos4.w;
    #fi

    #if (COLORS)
        // Pass vertex color to fragment shader
        fragVColor = VColor;
    #fi

    #if (TEXTURE)
        // Pass uv coordinate to fragment shader
        fragUV = uv;
    #fi

    #if (POINTS)
        #if (POINTS_SCALE)
            gl_PointSize = pointSize / length(VPos4.xyz);
        #else
            gl_PointSize = pointSize;
        #fi
        if(gl_PointSize < 1.0) gl_PointSize = 1.0;
    #fi

    #if (CLIPPING_PLANES)
        vViewPosition = -VPos4.xyz;
    #fi

    #if (CUBETEXTURES)
        fragVPos_worldspace = vec3(MMat * vec4(VPos, 1.0));
        fragVNorm_worldspace = mat3(transpose(inverse(MMat))) * VNorm;
    #fi
 }
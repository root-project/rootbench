#version 300 es
precision mediump float;


//UIO
//**********************************************************************************************************************//
uniform mat4 MVMat; // Model View Matrix
uniform mat4 PMat;  // Projection Matrix
uniform mat3 NMat;  // Normal Matrix

// uniform vec3 cameraPosition;
#if (POINTS)
uniform float pointSize;
#fi

#if (INSTANCED)
in mat4 MMat;
#fi
in vec3 VPos;       // Vertex position
#if (!NORMAL_FLAT)
in vec3 VNorm;      // Vertex normal
#fi

#if (NORMAL_FLAT)
out vec3 v_position_viewspace;
#else if (!NORMAL_FLAT)
out vec3 v_normal_viewspace;
#fi
out vec3 v_ViewDirection_viewspace;

#if (CLIPPING_PLANES)
out vec3 v_ViewPosition;
#fi


//MAIN
//**********************************************************************************************************************//
void main() {
    // View position and normal
    #if (INSTANCED)
        vec4 VPos4 = MVMat * MMat * vec4(VPos, 1.0);
        #if (!NORMAL_FLAT)
        v_normal_viewspace = normalize(NMat * mat3(MMat) * VNorm);
        #fi
    #else
        vec4 VPos4 = MVMat * vec4(VPos, 1.0);
        #if (!NORMAL_FLAT)
        v_normal_viewspace = normalize(NMat * VNorm);
        #fi
    #fi

    // Position
    #if (NORMAL_FLAT)
    v_position_viewspace = VPos4.xyz;
    #fi

    // View direction
    v_ViewDirection_viewspace = normalize(-VPos4.xyz);

    #if (POINTS)
        gl_PointSize = pointSize / length(VPos4.xyz);
        if(gl_PointSize < 1.0) gl_PointSize = 1.0;
    #fi

    #if (CLIPPING_PLANES)
        v_ViewPosition = -VPos4.xyz;
    #fi

    // Projected position
    gl_Position = PMat * VPos4;
 }

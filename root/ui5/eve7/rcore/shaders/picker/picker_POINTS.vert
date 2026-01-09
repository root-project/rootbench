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
uniform float pointSize;

#if (INSTANCED)
in mat4 MMat;
#fi
in vec3 VPos;       // Vertex position


//MAIN
//**********************************************************************************************************************
void main() {
    // MVP position
    //gl_Position = PMat * MVMat * vec4(VPos, 1.0);


    // Model view position
    //vec4 VPos4 = MVMat * vec4(VPos, 1.0); //original (non-instanced)
    #if (!INSTANCED)
    vec4 VPos4 = MVMat * vec4(VPos, 1.0);
    #fi
    #if (INSTANCED)
    //vec4 VPos4 = VMat * MMat * vec4(VPos, 1.0);
    vec4 VPos4 = MVMat * MMat * vec4(VPos, 1.0);
    #fi

    // Projected position
    gl_Position = PMat * VPos4;


    #if (POINTS_SCALE)
        gl_PointSize = pointSize / length(VPos4.xyz);
    #else
        gl_PointSize = pointSize;
    #fi
    if(gl_PointSize < 1.0) gl_PointSize = 1.0;
}
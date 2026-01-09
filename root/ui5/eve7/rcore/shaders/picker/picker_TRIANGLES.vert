#version 300 es
precision mediump float;

//UIO
//**********************************************************************************************************************
uniform mat4 MVMat; // Model View Matrix
uniform mat4 PMat;  // Projection Matrix

#if (INSTANCED)
in mat4 MMat;
#fi

in vec3 VPos;       // Vertex position

#if (PICK_MODE_UINT)
flat out uint InstanceID;
#fi

//MAIN
//**********************************************************************************************************************
void main() {
    // MVP position
    //gl_Position = PMat * MVMat * vec4(VPos, 1.0); //original (non-instanced)
    #if (!INSTANCED)
    gl_Position = PMat * MVMat * vec4(VPos, 1.0);
    #fi
    #if (INSTANCED)
    //gl_Position = PMat * VMat * MMat * vec4(VPos, 1.0);
    gl_Position = PMat * MVMat * MMat * vec4(VPos, 1.0);
    #fi

    #if (PICK_MODE_UINT)
        #if (INSTACED)
            InstanceID = uint(gl_InstanceID);
        #else
            InstanceID = uint(gl_VertexID);
        #fi
    #fi
}
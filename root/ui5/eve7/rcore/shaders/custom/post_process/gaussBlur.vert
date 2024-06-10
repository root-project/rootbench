#version 300 es
precision mediump float;


//UIO
//**********************************************************************************************************************//
in vec3 VPos; // Vertex position

#if (TEXTURE)
    in vec2 uv;  // Texture coordinate
#fi

// Output quad texture coordinates
out vec2 fragUV;


//MAIN
//**********************************************************************************************************************//
void main() {
    gl_Position = vec4(VPos, 1.0);


    #if (TEXTURE)
        // Pass-through texture coordinate
        fragUV = uv;
    #fi
}

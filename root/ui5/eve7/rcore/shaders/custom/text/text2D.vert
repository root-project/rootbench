#version 300 es
precision mediump float;


//DEF
//**********************************************************************************************************************
#define TEXT2D_SPACE_WORLD 0.0
#define TEXT2D_SPACE_SCREEN 1.0


//UIO
//**********************************************************************************************************************
uniform mat4 MVPMat;
uniform float aspect;
uniform vec2 viewport;
//uniform float fontSize;
uniform float MODE;
//uniform vec2 offset;

in vec2 VPos; // Vertex position (screenspace)
#if (TEXTURE)
in vec2 uv;  // Texture coordinate
#fi
//in vec2 positionIdentifier;
//in vec2 centerOffset;
in vec2 deltaOffset;

// Output quad texture coordinates
out vec2 fragUV;


void main() {
    if(MODE == TEXT2D_SPACE_SCREEN){
        //vec2 viewportHalfSize = vec2(1280, 720) * 0.5;
        vec2 viewportHalfSize = viewport * 0.5;

        //map [0, x][0, y] to [-1, 1][-1, 1]
        vec2 VPos_clipspace = (VPos - viewportHalfSize) / viewportHalfSize;

        // Vertex position in clip space
        gl_Position = vec4(VPos_clipspace, 0.0, 1.0);
    }else if (MODE == TEXT2D_SPACE_WORLD){
        //vec2 deltaOffset_screenspace = positionIdentifier * fontSize/2.0 + centerOffset * fontSize + offset;
        vec2 deltaOffset_screenspace = deltaOffset;
        vec3 deltaOffset_NDC = vec3(deltaOffset_screenspace / viewport, 0.0);

        vec4 VPos_clipspace = MVPMat * vec4(VPos, 0.0, 1.0);
        vec3 VPos_NDC = VPos_clipspace.xyz / VPos_clipspace.w;
        //vec2 VPos_screenspace = VPos_NDC.xy * viewport;
        vec3 deltaVPos_NDC = VPos_NDC + deltaOffset_NDC;


        gl_Position = vec4(deltaVPos_NDC * VPos_clipspace.w, VPos_clipspace.w);
    }


    #if (TEXTURE)
    // Pass-through texture coordinate
    fragUV = uv;
    #fi
}

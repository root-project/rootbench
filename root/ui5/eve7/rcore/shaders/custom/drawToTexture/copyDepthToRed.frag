#version 300 es
precision highp float;
precision highp sampler2D;

struct Material {
    #if (TEXTURE)
        sampler2D texture0;
    #fi
};

uniform Material material;

#if (TEXTURE)
    in vec2 fragUV;
#fi

out float color;


void main() {
    #if (TEXTURE)
        // TEST, write known numbers into result
        // color.r = 0.5370;
        // color.r = fragUV.x;

        color = texture(material.texture0, fragUV).r;
    #fi
}

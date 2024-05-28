#version 300 es
precision highp float;

struct Material {
    #if (TEXTURE)
        sampler2D texture0;
    #fi
};

uniform Material material;

#if (TEXTURE)
    in vec2 fragUV;
#fi

out vec4 color;


void main() {
    #if (TEXTURE)
        color = texture(material.texture0, fragUV).rgba;
    #fi
}
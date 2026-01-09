#version 300 es
precision mediump float;


#if (TEXTURE)
struct Material {
    vec3 diffuse;
    sampler2D texture0; //FONT TEXTURE
};
#fi


#if (TEXTURE)
uniform Material material;
#fi

#if (TEXTURE)
in vec2 fragUV;
#fi

out vec4 color;


void main() {
	#if (TEXTURE)
    vec4 texel = texture(material.texture0, fragUV);
    color = vec4(texel.rgb * material.diffuse, texel.a);
	#fi
}

#version 300 es
precision mediump float;


//UIO
//**********************************************************************************************************************//
struct Material {
    #if (TEXTURE)
        sampler2D texture0;
    #fi
};


uniform Material material;
uniform bool horizontal;
uniform float power;

#if (TEXTURE)
    in vec2 fragUV;
#fi

out vec4 color;


//MAIN
//**********************************************************************************************************************//
void main() {
	#if (TEXTURE)
		//bool horizontal = true;

		//float weight[5] = float[] (0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);
		float[5] weight = float[] (0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);
		//float[8] weight = float[] (0.383, 0.300, 0.242, 0.200, 0.061, 0.030, 0.006, 0.001); //custom "gauss"
		//float[8] weight = float[] (0.19950135, 0.17605932, 0.12100368, 0.0647686, 0.02699957, 0.00876548, 0.00221626, 0.00043641);


		vec2 tex_offset = 1.0 / vec2(textureSize(material.texture0, 0)); // gets size of single texel
		vec4 result = texture(material.texture0, fragUV).rgba * weight[0]*power; // current fragment's contribution


		if(horizontal) {
			for(int i = 1; i < weight.length(); i++) {
			    result += texture(material.texture0, fragUV + vec2(tex_offset.x * float(i), 0.0)).rgba * weight[i]*power;
			    result += texture(material.texture0, fragUV - vec2(tex_offset.x * float(i), 0.0)).rgba * weight[i]*power;
			}
		}else {
			for(int i = 1; i < weight.length(); i++) {
			    result += texture(material.texture0, fragUV + vec2(0.0, tex_offset.y * float(i))).rgba * weight[i]*power;
			    result += texture(material.texture0, fragUV - vec2(0.0, tex_offset.y * float(i))).rgba * weight[i]*power;
			}
		}


		//color = vec4(result, 1.0);
		color = result;
		//color = vec4(result.rgb, min(result.a, 1.0)); //separability issues
	#fi
}

#version 300 es
precision mediump float;


//UIO
//**********************************************************************************************************************//
struct Material {
    #if (TEXTURE)
        sampler2D texture0;
        sampler2D texture1;
    #fi
};

uniform Material material;

#if (TEXTURE)
    in vec2 fragUV;
#fi

out vec4 color;


//MAIN
//**********************************************************************************************************************//
void main() {
    #if (TEXTURE)
        vec4 SRC = texture(material.texture0, fragUV).rgba;
        vec4 DST = texture(material.texture1, fragUV).rgba;

        vec3 srcRGB = SRC.rgb;
        vec3 dstRGB = DST.rgb;

        float srcA = SRC.a;
        float dstA = DST.a;


        // // Enable Blending
        // this._gl.enable(this._gl.BLEND);

        // // Set up blending equation and params
        // this._gl.blendEquation(this._gl.FUNC_ADD);
        
        // // blending function
        // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        // // added separate blending function
        // this._gl.blendFuncSeparate(this._gl.SRC_ALPHA, this._gl.ONE_MINUS_SRC_ALPHA, this._gl.ONE, this._gl.ONE_MINUS_SRC_ALPHA);
    
        // * Orgb = srgb * Srgb + drgb * Drgb
        // * Oa = sa * Sa + da * Da

        // // glBlendFunc(GL_ONE, GL_ONE); 
        // color = SRC*(1.0) + DST*(1.0);

        // // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        // color = SRC*(srcA) + DST*(1.0 - srcA);
        // //if(srcA > 1.0) color = vec4(0.5, 0.0, 0.0, 1.0);


        #if (SRC_A_ONE)
            #define SRC_A (1.0)
        #else if (SRC_A_SRC_ALPHA)
            #define SRC_A (srcA)
        #else if (SRC_A_ONE_MINUS_SRC_ALPHA)
            #define SRC_A (1.0 - srcA)
        #else
            //#define SRC_A (srcA)
            #define SRC_A (min(srcA, 1.0))
        #fi

        #if (DST_A_ONE)
            #define DST_A (1.0)
        #else if (DST_A_SRC_ALPHA)
            #define DST_A (srcA)
        #else if (DST_A_ONE_MINUS_SRC_ALPHA)
            #define DST_A (1.0 - srcA)
        #else
            //#define DST_A (1.0 - srcA)
            #define DST_A (1.0 - min(srcA, 1.0))
        #fi


        color = SRC*SRC_A + DST*DST_A;
    #fi
}
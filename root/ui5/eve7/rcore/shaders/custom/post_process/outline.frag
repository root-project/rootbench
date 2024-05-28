#version 300 es
precision highp float;


struct Material {
    #if (TEXTURE)
        sampler2D texture0; //MODIFIABLE, VOLATILE! (DEPTH TEXTURE)
        sampler2D texture1; //MODIFIABLE, VOLATILE! (NORMAL TEXTURE)
        sampler2D texture2; //MODIFIABLE, VOLATILE! (VIEWDIR TEXTURE)
    #fi
};


uniform float scale;
uniform vec4 edgeColor;
uniform float _DepthThreshold;
uniform float _NormalThreshold;
uniform float _DepthNormalThreshold;
uniform float _DepthNormalThresholdScale;
uniform Material material;

#if (TEXTURE)
    in vec2 fragUV;
#fi

out vec4 color;


float sempleDepth(){
    return 0.0;
}
void main() {
	#if (TEXTURE)

        // float2 inParam   = float2(1/width, 1/height);
        //float4 thisSample   = tex2D(sample, coord);
        //float4 rightSample  = tex2D(sample, coord + float2(inParam.x, 0));
        //float4 upSample     = tex2D(sample, coord - float2(0, inParam.y));
        //float _DepthThreshold = 6.0; //6.0
        //float _NormalThreshold = 0.4; //0.4
        //float _DepthNormalThreshold = 0.5; //0.5
        //float _DepthNormalThresholdScale = 7.0; //7.0
        //vec4 _EdgeColor = vec4(1.0, 1.0, 1.0, 1.0); //vec4(1.0, 1.0, 1.0, 1.0)


        float halfScaleFloor = floor(scale * 0.5);
        float halfScaleCeil = ceil(scale * 0.5);

        ivec2 textureSize = textureSize(material.texture0, 0);
        float texelSizeX = 1.0 / float(textureSize.x);
        float texelSizeY = 1.0 / float(textureSize.y);

        vec2 topLeftUV = fragUV + vec2(-texelSizeX * halfScaleFloor, texelSizeY * halfScaleCeil);
        vec2 topRightUV = fragUV + vec2(texelSizeX, texelSizeY) * halfScaleCeil;  
        vec2 bottomLeftUV = fragUV - vec2(texelSizeX, texelSizeY) * halfScaleFloor;
        vec2 bottomRightUV = fragUV + vec2(texelSizeX * halfScaleCeil, -texelSizeY * halfScaleFloor);


        // Sample depth
        float depthTL = texture(material.texture0, topLeftUV).r;
        float depthTR = texture(material.texture0, topRightUV).r;
        float depthBL = texture(material.texture0, bottomLeftUV).r; //"central" sample
        float depthBR = texture(material.texture0, bottomRightUV).r;

        // Sample normals
        // vec3 normalTL = texture(material.texture1, topLeftUV).rgb * 2.0 - 1.0;
        // vec3 normalTR = texture(material.texture1, topRightUV).rgb * 2.0 - 1.0;
        // vec3 normalBL = texture(material.texture1, bottomLeftUV).rgb * 2.0 - 1.0; //"central" sample
        // vec3 normalBR = texture(material.texture1, bottomRightUV).rgb * 2.0 - 1.0;
        vec3 normalTL = texture(material.texture1, topLeftUV).rgb;
        vec3 normalTR = texture(material.texture1, topRightUV).rgb;
        vec3 normalBL = texture(material.texture1, bottomLeftUV).rgb; //"central" sample
        vec3 normalBR = texture(material.texture1, bottomRightUV).rgb;


        // Depth difference
        float depthDiffTLBR = depthTL - depthBR;
        float depthDiffTRBL = depthTR - depthBL;			
        float edgeDepth = sqrt(pow(depthDiffTLBR, 2.0) + pow(depthDiffTRBL, 2.0)) * 100.0;

        // Enhancement VIEWDIR
        vec3 fragNormal = normalBL;
        //vec3 viewDir = texture(material.texture2, bottomLeftUV).rgb  * 2.0 - 1.0;
        //float NdotV = 1.0 - dot(fragNormal, -viewDir);
        vec3 viewDir = texture(material.texture2, bottomLeftUV).rgb;
        float NdotV = 1.0 - dot(fragNormal, viewDir);
        float normalThreshold01 = clamp((NdotV - _DepthNormalThreshold) / (1.0 - _DepthNormalThreshold), 0.0, 1.0);
        float normalThreshold = normalThreshold01 * _DepthNormalThresholdScale + 1.0; 


        // Depth Threshold
        //float depthThreshold = _DepthThreshold * (1.0 - depthBL); //(1.0 - depthBL) instead of depthBL - depth close is dark [0 - 1]
        float depthThreshold = _DepthThreshold * (1.0 - depthBL) * normalThreshold;
        edgeDepth = edgeDepth > depthThreshold ? 1.0 : 0.0;



        // Normal difference			
        vec3 normalDiffTLBR = normalTL - normalBR;
        vec3 normalDiffTRBL = normalTR - normalBL;
        float edgeNormal = sqrt(dot(normalDiffTLBR, normalDiffTLBR) + dot(normalDiffTRBL, normalDiffTRBL));
        edgeNormal = edgeNormal > _NormalThreshold ? 1.0 : 0.0;


        // Edge decision
        float edge = max(edgeDepth, edgeNormal); //edge is either 0 or 1

        #if (DISCARD_NON_EDGE)
            if (edge == 0.0)
                discard;
        #fi

        // Edge color
        vec4 edgeColor = vec4(edgeColor.rgb, edgeColor.a * edge);


        // Output
		//color = vec4(vec3(edge), 1.0);
        //color = vec4(texture(material.texture0, fragUV).rrr, 1.0); //DEPTH
        //color = vec4(texture(material.texture1, fragUV).rgb, 1.0); //NORMAL
        //color = vec4(texture(material.texture2, fragUV).rgb,  1.0); //VIEWDIR
        //color = vec4(vec3(texture(material.texture2, fragUV).rg, 0.0),  1.0); //VIEWDIR (ignore blue)
        //color = vec4(texture(material.texture3, fragUV).rgb,  1.0); //ORIGINAL

        //blend to output      
        /*if(edge == 1.0){
            color = edgeColor;
        }else{
            color = texture(material.texture3, fragUV).rgba;
        }*/
        //color = edgeColor * edge + texture(material.texture3, fragUV).rgba * (1.0 - edge);
                
        //edge is either 0 or 1 (alpha is either 0 or edgeColor.a), mask to output
        color = edgeColor;
	#fi
}
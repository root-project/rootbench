#version 300 es
precision mediump float;


//UIO
//**********************************************************************************************************************//
#if (NORMAL_FLAT)
in vec3 v_position_viewspace;
#else if (!NORMAL_FLAT)
in vec3 v_normal_viewspace;
#fi
in vec3 v_ViewDirection_viewspace;

layout (location = 0) out vec4 vn_viewspace;
layout (location = 1) out vec4 vd_viewspace;
#if (DEPTH)
    layout (location = 2) out vec4 de_viewspace; // could be float
#fi

#if (CLIPPING_PLANES)
    struct ClippingPlane {
        vec3 normal;
        float constant;
    };

    uniform ClippingPlane clippingPlanes[##NUM_CLIPPING_PLANES];

    in vec3 v_ViewPosition;
#fi


//MAIN
//**********************************************************************************************************************//
void main() {

    #if (CLIPPING_PLANES)
        bool clipped = true;
        for(int i = 0; i < ##NUM_CLIPPING_PLANES; i++){
                clipped = ( dot( v_ViewPosition, clippingPlanes[i].normal ) > clippingPlanes[i].constant ) && clipped;
        }
        if ( clipped ) discard;
    #fi


    #if (CIRCLES)
        vec2 cxy = 2.0 * gl_PointCoord - 1.0;
        float pct = dot(cxy, cxy);
        if (pct > 1.0) {
            discard; //performance trap
            //color = vec4(1.0, 1.0, 1.0, 0.0);
        }
    #fi

    //******************************************************************************************************************//

    #if (NORMAL_FLAT)
        vec3 fdx = dFdx(v_position_viewspace);
        vec3 fdy = dFdy(v_position_viewspace);
        vec3 v_normal_viewspace = normalize(cross(fdx, fdy));
    #fi

    if(gl_FrontFacing) {
        vn_viewspace = vec4(v_normal_viewspace, 0.0);
    }else{
        vn_viewspace = vec4(-v_normal_viewspace, 0.0);
    }
    vd_viewspace = vec4(v_ViewDirection_viewspace, 0.0);

    #if (DEPTH)
        de_viewspace = vec4(gl_FragCoord.z, 0.0, 0.0, 1.0);
    #fi
}

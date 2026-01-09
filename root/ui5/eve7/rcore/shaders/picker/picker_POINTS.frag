#version 300 es
precision mediump float;


//UIO
//**********************************************************************************************************************
#if(PICK_MODE_RGB)
uniform vec3 u_RGB_ID;
#fi
#if(PICK_MODE_UINT)
uniform uint u_UINT_ID;
#fi

#if(PICK_MODE_RGB)
layout(location = 0) out vec4 objectID;
#fi
#if(PICK_MODE_UINT)
layout(location = 0) out uint objectID;
#fi


//MAIN
//**********************************************************************************************************************
void main() {
    #if (CIRCLES)
        vec2 cxy = 2.0 * gl_PointCoord - 1.0;
        float pct = dot(cxy, cxy);
        if (pct > 1.0) {
            discard; //performance trap
            //color = vec4(1.0, 1.0, 1.0, 0.0);
        }
    #fi


    #if(PICK_MODE_RGB)
    objectID = vec4(u_RGB_ID, 1.0);
    #fi
    #if(PICK_MODE_UINT)
    objectID = u_UINT_ID;
    #fi
}
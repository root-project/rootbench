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
uniform bool u_PickInstance;
flat in uint InstanceID;
#fi


//MAIN
//**********************************************************************************************************************
void main() {
    #if(PICK_MODE_RGB)
    objectID = vec4(u_RGB_ID, 1.0);
    #fi
    #if(PICK_MODE_UINT)
    if (u_PickInstance)
        objectID = InstanceID;
    else
        objectID = u_UINT_ID;
    #fi
}
#version 300 es
precision mediump float;


//STRUCT
//**********************************************************************************************************************


//UIO
//**********************************************************************************************************************
#if (PICK_MODE_UINT)
    uniform uint u_UINT_ID;
    layout(location = 0) out uint objectID;
#else
    in vec3 v_position_viewspace;
    vec3 v_normal_viewspace = vec3(0.0, 0.0, 1.0);
    in vec3 v_ViewDirection_viewspace;

    layout (location = 0) out vec4 vn_viewspace;
    layout (location = 1) out vec4 vd_viewspace;
#fi

//FUNCTIONS
//**********************************************************************************************************************
// float linearizeDepth_1(float depth){
//     return (-depth - u_Near) / (u_Far - u_Near); //linearizaiton [0-1]
// }
// float linearizeDepth_2(float depth) {
//     float z_NDC = depth * 2.0 - 1.0; // back to NDC 

//     return (2.0 * u_Near * u_Far) / (u_Far + u_Near - z_NDC * (u_Far - u_Near));	
// }


//MAIN
//**********************************************************************************************************************
void main() {
#if (PICK_MODE_UINT)
    objectID = u_UINT_ID;
#else
    vn_viewspace = vec4(v_normal_viewspace, 1.0);
    vd_viewspace = vec4(v_ViewDirection_viewspace, 1.0);
#fi
}
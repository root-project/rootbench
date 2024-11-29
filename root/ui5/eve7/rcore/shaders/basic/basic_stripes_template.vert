#version 300 es
precision mediump float;


//DEF
//**********************************************************************************************************************//
#define STRIPE_SPACE_WORLD 0.0
#define STRIPE_SPACE_SCREEN 1.0

#define STRIPE_JOIN_DEFAULT 0.0
#define STRIPE_JOIN_MITER 1.0
#define STRIPE_JOIN_BEVEL 2.0
#define STRIPE_JOIN_ROUND 3.0


//UIO
//**********************************************************************************************************************//
uniform mat4 MMat;
uniform mat4 MVMat; // Model View Matrix
uniform mat4 PMat;  // Projection Matrix
uniform mat4 MVPMat;
uniform float aspect;
uniform vec2 viewport;
uniform vec3 cameraPosition; // World space // Camera position
uniform float halfLineWidth;
uniform float MODE;
//uniform float JOIN_MODE;

in vec3 VPos;       // Vertex position
in vec3 prevVertex;
in vec3 nextVertex;
in vec2 deltaOffset;

#if (COLORS)
in vec4 VColor;
out vec4 fragVColor;
#fi

#if (TEXTURE)
in vec2 uv;
out vec2 fragUV;
#fi

#if (PLIGHTS)
out vec3 fragVPos;
#fi
out vec3 VCOL;

#if (POINTS)
uniform float pointSize;
#fi

#if (CLIPPING_PLANES)
out vec3 vViewPosition;
#fi


//MAIN
//**********************************************************************************************************************//
void main() {
    if(MODE == STRIPE_SPACE_WORLD){
        //VIEWSPACE DEFAULT


        //position
        vec4 curr_viewspace = MVMat * vec4(VPos, 1.0);
        vec4 prev_viewspace = MVMat * vec4(prevVertex, 1.0);
        vec4 next_viewspace = MVMat * vec4(nextVertex, 1.0);


        //tangent
        /*vec4 AB_tangent_viewspace;
        if(deltaOffset.x == -1.0){
            AB_tangent_viewspace = next_viewspace - curr_viewspace;
        }else if(deltaOffset.x == +1.0){
            AB_tangent_viewspace = curr_viewspace - prev_viewspace;
        }*/
        vec4 AB_tangent_viewspace = next_viewspace - prev_viewspace;


        //normal
        vec4 CamB_viewspace = curr_viewspace;
        vec3 normal_viewspace = normalize(cross(AB_tangent_viewspace.xyz, CamB_viewspace.xyz));


        //delta
        vec3 directionToMove_viewpsace = normal_viewspace * deltaOffset.y;
        float distanceToMove_viewspace = halfLineWidth;

        vec4 delta_viewspace = vec4(directionToMove_viewpsace * distanceToMove_viewspace, 0.0);
        vec4 deltaVPos_viewspace = curr_viewspace + delta_viewspace;

        
        gl_Position = PMat * deltaVPos_viewspace;
    }else if (MODE == STRIPE_SPACE_SCREEN){
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        /*//SCREENSPACE DEFAULT
        //(lerp clipspace pos if different sign, screenspace tangent, screenspace normal)


        //position
        vec4 curr_clipspace = MVPMat * vec4(VPos, 1.0);
        vec4 prev_clipspace = MVPMat * vec4(prevVertex, 1.0);
        vec4 next_clipspace = MVPMat * vec4(nextVertex, 1.0);

        // if(deltaOffset.x == -1.0)
        // {
        //     if(next_clipspace.z < 0.0 && curr_clipspace.z > 0.0)
        //     {
        //         // float distancez = -next_clipspace.z + curr_clipspace.z;
        //         // next_clipspace = mix(next_clipspace, curr_clipspace, -next_clipspace.z/distancez);

        //         next_clipspace.xyzw = mix(next_clipspace.xyzw, curr_clipspace.xyzw, clamp(next_clipspace.z/(next_clipspace.z - curr_clipspace.z), 0.0, 1.0));
        //         //next_clipspace.w = 1.0;
        //     }
        //     else if (next_clipspace.z > 0.0 && curr_clipspace.z < 0.0)
        //     {
        //         curr_clipspace.xyzw = mix(curr_clipspace.xyzw, next_clipspace.xyzw, clamp(curr_clipspace.z/(curr_clipspace.z - next_clipspace.z), 0.0, 1.0));
        //         //curr_clipspace.w = 1.0;
        //         //prev_clipspace.xyzw = curr_clipspace;
        //     }
        // }
        // else if(deltaOffset.x == +1.0)
        // {
        //     if(curr_clipspace.z < 0.0 && prev_clipspace.z > 0.0)
        //     {
        //         curr_clipspace.xyzw = mix(curr_clipspace.xyzw, prev_clipspace.xyzw, clamp(curr_clipspace.z/(curr_clipspace.z - prev_clipspace.z), 0.0, 1.0));
        //         //curr_clipspace.w = 1.0;
        //         //next_clipspace.xyzw = curr_clipspace;
        //     }
        //     else if (curr_clipspace.z > 0.0 && prev_clipspace.z < 0.0)
        //     {
        //         prev_clipspace.xyzw = mix(prev_clipspace.xyzw, curr_clipspace.xyzw, clamp(prev_clipspace.z/(prev_clipspace.z - curr_clipspace.z), 0.0, 1.0));
        //         //prev_clipspace.w = 1.0;
        //     }
        // }

        // if(deltaOffset.x == -1.0)
        // {
        //     if(sign(next_clipspace.z) != sign(curr_clipspace.z)){
        //         curr_clipspace = mix(curr_clipspace, next_clipspace, clamp(curr_clipspace.z/(curr_clipspace.z - next_clipspace.z)*sign(next_clipspace.z), 0.0, 1.0));
        //         next_clipspace = mix(next_clipspace, curr_clipspace, clamp(next_clipspace.z/(next_clipspace.z - curr_clipspace.z)*sign(curr_clipspace.z), 0.0, 1.0));
        //     }
        // }
        // else if(deltaOffset.x == +1.0)
        // {
        //     if(sign(curr_clipspace.z) != sign(prev_clipspace.z))
        //     {
        //         curr_clipspace = mix(curr_clipspace, prev_clipspace, clamp(curr_clipspace.z/(curr_clipspace.z - prev_clipspace.z)*sign(prev_clipspace.z), 0.0, 1.0));
        //         prev_clipspace = mix(prev_clipspace, curr_clipspace, clamp(prev_clipspace.z/(prev_clipspace.z - curr_clipspace.z)*sign(curr_clipspace.z), 0.0, 1.0));
        //     }
        // }

        if(sign(prev_clipspace.z) != sign(next_clipspace.z)){ // w_clipspace = -z_viewspace
            prev_clipspace = mix(prev_clipspace, next_clipspace, clamp(prev_clipspace.z/(prev_clipspace.z - next_clipspace.z)*sign(prev_clipspace.z), 0.0, 1.0));
            next_clipspace = mix(next_clipspace, prev_clipspace, clamp(next_clipspace.z/(next_clipspace.z - prev_clipspace.z)*sign(next_clipspace.z), 0.0, 1.0));
        }

        if (deltaOffset.x == -1.0){
            curr_clipspace = prev_clipspace;
        }else{
            curr_clipspace = next_clipspace;
        }

        vec3 curr_NDC = curr_clipspace.xyz / curr_clipspace.w;
        vec3 prev_NDC = prev_clipspace.xyz / prev_clipspace.w;
        vec3 next_NDC = next_clipspace.xyz / next_clipspace.w;

        vec2 curr_screenspace = curr_NDC.xy * viewport;
        vec2 prev_screenspace = prev_NDC.xy * viewport;
        vec2 next_screenspace = next_NDC.xy * viewport;


        //tangent
        // vec2 AB_tangent_screenspace;
        // if(deltaOffset.x == -1.0){
        //     AB_tangent_screenspace = next_screenspace - curr_screenspace;
        // }else if(deltaOffset.x == +1.0){
        //     AB_tangent_screenspace = curr_screenspace - prev_screenspace;
        // }
        vec2 AB_tangent_screenspace = next_screenspace - prev_screenspace;


        //normal
        vec2 AB_normal_screenspace = normalize(vec2(-AB_tangent_screenspace.y, AB_tangent_screenspace.x));
        

        //delta
        vec2 directionToMove_screenspace = AB_normal_screenspace * deltaOffset.y;
        float distanceToMove_screenspace = halfLineWidth;

        vec2 delta_screenspace = directionToMove_screenspace * distanceToMove_screenspace;
        vec3 delta_NDC = vec3(delta_screenspace / viewport, 0.0);
        vec3 deltaVPos_NDC = curr_NDC + delta_NDC;


        gl_Position = vec4(deltaVPos_NDC * curr_clipspace.w, curr_clipspace.w); //END
        //gl_Position = vec4(deltaVPos_NDC, 1.0); //END*/
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        //SCREENSPACE DEFAULT
        //(viewspace tnagent, viewspace normal)


        //positon
        vec4 curr_viewspace = MVMat * vec4(VPos, 1.0);
        vec4 prev_viewspace = MVMat * vec4(prevVertex, 1.0);
        vec4 next_viewspace = MVMat * vec4(nextVertex, 1.0);

        //messes up color interpolation!!!
        if(sign(prev_viewspace.z) != sign(next_viewspace.z)){ // w_clipspace = -z_viewspace
            prev_viewspace = mix(prev_viewspace, next_viewspace, clamp(prev_viewspace.z/(prev_viewspace.z - next_viewspace.z)*sign(prev_viewspace.z), 0.0, 1.0));
            next_viewspace = mix(next_viewspace, prev_viewspace, clamp(next_viewspace.z/(next_viewspace.z - prev_viewspace.z)*sign(next_viewspace.z), 0.0, 1.0));
        }

                
        if (deltaOffset.x == -1.0){
            curr_viewspace = prev_viewspace;
        }else{
            curr_viewspace = next_viewspace;
        }


        vec4 curr_clipspace = PMat * curr_viewspace;
        vec4 prev_clipspace = PMat * prev_viewspace;
        vec4 next_clipspace = PMat * next_viewspace;

        vec3 curr_NDC = curr_clipspace.xyz / curr_clipspace.w;
        vec3 prev_NDC = prev_clipspace.xyz / prev_clipspace.w;
        vec3 next_NDC = next_clipspace.xyz / next_clipspace.w;

        vec2 curr_screenspace = curr_NDC.xy * viewport;
        vec2 prev_screenspace = prev_NDC.xy * viewport;
        vec2 next_screenspace = next_NDC.xy * viewport;



        //tangent
        vec4 AB_tangent_viewspace = next_viewspace - prev_viewspace;


        //normal
        vec4 CamB_viewspace = curr_viewspace;
        vec3 normal_viewspace = normalize(cross(AB_tangent_viewspace.xyz, CamB_viewspace.xyz));


        //delta
        vec3 directionToMove_viewpsace = normal_viewspace * deltaOffset.y;
        vec4 directionToMove_clipspace = PMat * vec4(directionToMove_viewpsace, 0.0);
        vec2 directionToMove_screenspace = normalize(directionToMove_clipspace.xy);
        float distanceToMove_screenspace = halfLineWidth;



        vec2 delta_screenspace = directionToMove_screenspace * distanceToMove_screenspace;
        vec3 delta_NDC = vec3(delta_screenspace / viewport, 0.0);
        vec3 deltaVPos_NDC = curr_NDC + delta_NDC;


        gl_Position = vec4(deltaVPos_NDC * curr_clipspace.w, curr_clipspace.w); //END
        //gl_Position = vec4(deltaVPos_NDC, 1.0); //END
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        // //SCREENSPACE DEFAULT
        // //(viewspace tnagent, viewspace normal)


        // //position
        // vec4 curr_clipspace = MVPMat * vec4(VPos, 1.0);
        // vec4 prev_clipspace = MVPMat * vec4(prevVertex, 1.0);
        // vec4 next_clipspace = MVPMat * vec4(nextVertex, 1.0);

        // vec3 curr_NDC = curr_clipspace.xyz / curr_clipspace.w;
        // vec3 prev_NDC = prev_clipspace.xyz / prev_clipspace.w;
        // vec3 next_NDC = next_clipspace.xyz / next_clipspace.w;

        // vec2 curr_screenspace = curr_NDC.xy * viewport;
        // vec2 prev_screenspace = prev_NDC.xy * viewport;
        // vec2 next_screenspace = next_NDC.xy * viewport;


        // //tangent
        // vec2 AB_tangent_screenspace = next_screenspace - prev_screenspace;
        // if(sign(prev_clipspace.z) != sign(next_clipspace.z)) AB_tangent_screenspace *= -1.0;


        // //normal
        // vec2 AB_normal_screenspace = normalize(vec2(-AB_tangent_screenspace.y, AB_tangent_screenspace.x));
        

        // //delta
        // vec2 directionToMove_screenspace = AB_normal_screenspace * deltaOffset.y;
        // float distanceToMove_screenspace = halfLineWidth;

        // vec2 delta_screenspace = directionToMove_screenspace * distanceToMove_screenspace;
        // vec3 delta_NDC = vec3(delta_screenspace / viewport, 0.0);
        // vec3 deltaVPos_NDC = curr_NDC + delta_NDC;


        // gl_Position = vec4(deltaVPos_NDC * curr_clipspace.w, curr_clipspace.w); //END

        // //lerp dolzino linije, clipping poskrbi za rezanje!!! 
        // // if(sign(prev_viewspace.z) != sign(next_viewspace.z)){ // w_clipspace = -z_viewspace
        // //     prev_viewspace = mix(prev_viewspace, next_viewspace, clamp(prev_viewspace.z/(prev_viewspace.z - next_viewspace.z)*sign(prev_viewspace.z), 0.0, 1.0));
        // //     next_viewspace = mix(next_viewspace, prev_viewspace, clamp(next_viewspace.z/(next_viewspace.z - prev_viewspace.z)*sign(next_viewspace.z), 0.0, 1.0));
        // // }
    }



    // //SCREENSPACE DEFAULT
    // vec4 currentProjected = MVP * vec4(VPos, 1.0);
    // vec4 prevProjected = MVP * vec4(prevVertex, 1.0);
    // vec4 nextProjected = MVP * vec4(nextVertex, 1.0);

    // vec2 currentNDC = currentProjected.xy / currentProjected.w; //z coordinate is "lost" on projection
    // vec2 prevNDC = prevProjected.xy / prevProjected.w;
    // vec2 nextNDC = nextProjected.xy / nextProjected.w;

    // currentNDC.x = currentNDC.x * aspect;
    // prevNDC.x = prevNDC.x * aspect;
    // nextNDC.x = nextNDC.x * aspect;


    // vec2 AB;
    // if(deltaOffset.x == -1.0){
    //     AB = nextNDC - currentNDC;
    // }else if(deltaOffset.x == +1.0){
    //     AB = currentNDC - prevNDC;
    // }
    // // if(VPos == prevVertex){ //start vertex
    // //     AB = nextNDC - currentNDC;
    // // }else if(VPos == nextVertex){ //end vertex
    // //     AB = currentNDC - prevNDC;
    // // }else{ //middle
    // //     //direction = nextNDC - prevNDC;
    // //     AB = normalize(currentNDC - prevNDC) + normalize(nextNDC - currentNDC);
    // // }

    // vec2 normal = normalize(vec2(-AB.y, AB.x));
    // normal = normal / halfLineWidth; //fixed size in world space //////!!!
    // normal.x = normal.x / aspect; //////!!!

    // directionToMove = normal * deltaOffset.y;
    // distanceToMove = halfLineWidth;


    // vec4 delta = vec4(directionToMove * distanceToMove, 0.0, 0.0);
    // delta.xy /= viewport;

    //currentProjected = currentProjected/currentProjected.w; //////!!!
    // gl_Position = currentProjected + delta;




    if(deltaOffset.y == 1.0){
        if(deltaOffset.x == 1.0){
            VCOL = vec3(1.0,0.0,0.0);
        }else if(deltaOffset.x == -1.0){
            VCOL = vec3(0.0,1.0,0.0);
        }
    }else if(deltaOffset.y == -1.0){
        if(deltaOffset.x == 1.0){
            VCOL = vec3(0.0,0.0,1.0);
        }else if(deltaOffset.x == -1.0){
            VCOL = vec3(0.0,0.0,0.0);
        }
    }
    // if(deltaOffset.x == 1.0){
    //     VCOL = vec3(1.0,0.0,0.0);
    // }else if(deltaOffset.x == -1.0){
    //     VCOL = vec3(0.0,1.0,0.0);
    // }else{
    //     VCOL = vec3(0.0,0.0,1.0);
    // }
    // if((MVMat * vec4(VPos, 1.0)).z < 0.0){
    //     VCOL = vec3(0.0,1.0,0.0);
    // }else{
    //     VCOL = vec3(1.0,0.0,0.0);
    // }


    #if (PLIGHTS || POINTS || CLIPPING_PLANES)
    vec4 VPos4 = MVMat * vec4(VPos, 1.0);
    #fi
    #if (PLIGHTS)
    // Pass vertex position to fragment shader
    fragVPos = vec3(VPos4) / VPos4.w;
    #fi

    #if (COLORS)
    // Pass vertex color to fragment shader
    fragVColor = VColor;
    #fi

    #if (TEXTURE)
    // Pass uv coordinate to fragment shader
    fragUV = uv;
    #fi

    #if (POINTS)
    gl_PointSize = pointSize / length(VPos4.xyz);
    if(gl_PointSize < 1.0) gl_PointSize = 1.0;
    #fi

    #if (CLIPPING_PLANES)
    vViewPosition = -VPos4.xyz;
    #fi
}
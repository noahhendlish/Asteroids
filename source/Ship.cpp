//
//  Ship.cpp
//  Asteroids
//
//  Created by Brian Summa on 6/5/15.
//
//

#include "common.h"

//Bullet bullet;

//Ship constructor
Ship::Ship(){
    //Set up initial state here
    state.cur_location = vec2(0,0);
    //front tip is at vec2(0,0.125);
    state.pointing = vec2(0,1);
};


//Called everytime an animation tick happens
void Ship::update_state(){
    // Things to do:
    //a = F
    //Force is in the direction the ship is pointing
    float accel = _ACC;
    //vec2 acc = vec2(0,accel);
    //if thruster on, update velocity
    if(state.thruster_on){
        if((length(state.velocity))<0.05) {
            //v  = old_velocity + a*dt
            state.velocity += state.pointing*accel;
        }
        //Clamp acceleration at some maximum value
        else if((length(state.velocity))>=0.05) {
            state.velocity = normalize(state.velocity)*0.05;
        }
    }
    //p  = old_position + v*dt
    state.cur_location += state.velocity;
    //update position using model view
    T =Translate(state.cur_location.x, state.cur_location.y, 0);
    // Dampen the velocity at every timestep to lessen intertia
    state.velocity *= 0.98;
    // Wrap the ship position when at the boundary
    if(state.cur_location.x <= -1){
        state.cur_location.x = 1;
    }
    else if(state.cur_location.x >= 1){
        state.cur_location.x = -1;
    }
    
    if(state.cur_location.y <= -1){
        state.cur_location.y = 1;
    }
    else if(state.cur_location.y >= 1){
        state.cur_location.y = -1;
    }
    
}

//Initialize the gl state and variables
//void Ship::gl_init(GLuint &ship, GLuint &asteroid){
void Ship::gl_init(){
    //Ship
    //!!!!!!!!Populate ship_vert and ship_color
    /*
     //vec2 ship_vert[6] = {vec2(-0.05,-0.05),vec2(-0.025,-0.025), vec2(0,-0.05),vec2(0.025,-0.025),vec2(0.05,-0.05), vec2(0, 0.125)}; //center is (0,0) HALF SIZE  W/O THRUSTER
     //vec2 ship_vert[6] = {vec2(-0.1,-0.1),vec2(-0.05,-0.05), vec2(0,-0.1),vec2(0.05,-0.05),vec2(0.1,-0.1), vec2(0, 0.25)}; //center is (0,0) ORIGINAL (FULL) W/O THRUSTER
     //vec3 ship_color[6] = {vec3(1,1,1),vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1)}; //W/O THRUSTER
     //vec2 ship_vert[9] = {vec2(-0.1,-0.1),vec2(-0.05,-0.05), vec2(0,-0.1),vec2(0.05,-0.05),vec2(0.1,-0.1), vec2(0, 0.25),vec2(0,-0.1),vec2(-0.03,-0.15), vec2(0.03,-0.15)}; //ORIGINAL (FULL) WITH THRUSTER *center is (0,0)
     //vec2 ship_vert[9] = {vec2(-0.05,0.05),vec2(-0.025,0.025), vec2(0,0.05),vec2(0.025,0.025),vec2(0.05,0.05), vec2(0, -0.125), vec2(0,0.05),vec2(-0.015, 0.075), vec2(0.015,0.075) }; //HALF SIZE WITH THRUSTER (FLIPPED -- FACING TOP)
     */
    vec2 ship_vert[9] = {vec2(-0.05,-0.05),vec2(-0.025,-0.025), vec2(0,-0.05),vec2(0.025,-0.025),vec2(0.05,-0.05), vec2(0, 0.125), vec2(0,-0.05),vec2(-0.015, -0.075), vec2(0.015,-0.075) }; //HALF SIZE WITH THRUSTER
    
    vec3 ship_color[9] = {vec3(1,1,1),vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1),vec3(1,0.8,0),vec3(1,0,0), vec3(1,0,0)};
    
    std::string vshader = shader_path + "vshader_Ship.glsl";
    std::string fshader = shader_path + "fshader_Ship.glsl";
    
    GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
    GLchar* fragment_shader_source = readShaderSource(fshader.c_str());
    
    GLvars.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(GLvars.vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
    glCompileShader(GLvars.vertex_shader);
    check_shader_compilation(vshader, GLvars.vertex_shader);
    
    GLvars.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(GLvars.fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
    glCompileShader(GLvars.fragment_shader);
    check_shader_compilation(fshader, GLvars.fragment_shader);
    
    GLvars.program = glCreateProgram();
    glAttachShader(GLvars.program, GLvars.vertex_shader);
    glAttachShader(GLvars.program, GLvars.fragment_shader);
    
    glLinkProgram(GLvars.program);
    check_program_link(GLvars.program);
    
    glBindFragDataLocation(GLvars.program, 0, "fragColor");
    
    GLvars.vpos_location   = glGetAttribLocation(GLvars.program, "vPos");
    GLvars.vcolor_location = glGetAttribLocation(GLvars.program, "vColor" );
    GLvars.M_location = glGetUniformLocation(GLvars.program, "M" );
    
    // Create a vertex array object
    glGenVertexArrays( 1, &GLvars.vao );
    //Set GL state to use vertex array object
    glBindVertexArray( GLvars.vao );
    
    //Generate buffer to hold our vertex data
    glGenBuffers( 1, &GLvars.buffer );
    //Set GL state to use this buffer
    glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
    
    //Create GPU buffer to hold vertices and color
    glBufferData( GL_ARRAY_BUFFER, sizeof(ship_vert) + sizeof(ship_color), NULL, GL_STATIC_DRAW );
    //First part of array holds vertices
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ship_vert), ship_vert );
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(ship_vert), sizeof(ship_color), ship_color );
    glBufferData( GL_ARRAY_BUFFER, sizeof(ship_vert) + sizeof(ship_color), NULL, GL_STATIC_DRAW );
    
    
    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location );
    
    glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(ship_vert)) );
    
    glBindVertexArray(0);
    
}


//Draw a ship
void Ship::draw(mat4 proj){
    
    glUseProgram( GLvars.program );
    glBindVertexArray( GLvars.vao );
    
    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj*T*R );
    
    //Draw something
    //glBindVertexArray( GLvars.vao );
    glDrawArrays(GL_LINE_LOOP, 0, 6);
    //if thruster on: glDrawArrays(GL_TRIANGLES, 6, 3);
    if(state.thruster_on){
        glDrawArrays(GL_TRIANGLES, 6, 3);
    }
    
    glBindVertexArray(0);
    glUseProgram(0);
    
}
vec2* Ship::curr_vertices(){
    vec2 ship_only_vert[6] = {vec2(-0.05,-0.05),vec2(-0.025,-0.025), vec2(0,-0.05),vec2(0.025,-0.025),vec2(0.05,-0.05), vec2(0, 0.125)};
    
    vec2* all_vertices = new vec2[sizeof(ship_vert)];
    for(int i = 0; i <6; i++){
        all_vertices[i] = ship_only_vert[i] + state.cur_location; //+ state.cur_location;
        //all_vertices[i] = asteroid_vert[i]*0.5+state.cur_location; //+ state.cur_location;
    }
    return all_vertices;
}

Bullet* Ship::pew_pew(){
    Bullet *b = new Bullet();
    b->state.cur_location = state.cur_location +state.pointing*0.125; //current location + tip;
    b->state.velocity = state.velocity*1.003 + state.pointing*0.02;
    // b->state.cur_location = vec2(0,0.125) + state.cur_location; //current location + tip;
    return b;
}

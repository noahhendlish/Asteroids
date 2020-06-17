//
//  Bullet.cpp
//  ASTEROIDS
//
//  Created by Noah Hendlish
//
//
//#include "Bullet.hpp"
#include <stdio.h>
#include "common.h"
#include <ctime>

//phase 3: bullet/laser
//Create a Bullet (or Laser) class that will the the OOP class for what the ship fires. These should be a point (or line) that has a velocity and that is also updated like the Ship and Asteroid(s). Reference the particle class from your assignment. Create a method in the Ship class that creates and returns a new Bullet/Laser:
        //Bullet pew_pew(){ }
//The bullet should emit with velocity the direction the ship is pointing and also inherit the velocity of the ship.

//bullet constructor
Bullet::Bullet(){
    bullet_vert = vec2(0,0);
    bullet_color = vec3(1,0,0);
};


//Called everytime an animation tick happens
void Bullet::update_state(){
    //p  = old_position + v*dt
    state.cur_location += state.velocity;
    //update position using model view
    //check for memory leaks**
    T_bull = Translate(state.cur_location.x, state.cur_location.y, 0);
}

//Initialize the gl state and variables
void Bullet::gl_init(){
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
    glBufferData( GL_ARRAY_BUFFER, sizeof(bullet_vert) + sizeof(bullet_color), NULL, GL_STATIC_DRAW );
    //First part of array holds vertices
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(bullet_vert), bullet_vert );
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(bullet_vert), sizeof(bullet_color), bullet_color );
    
    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location );
    
    glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(bullet_vert)) );
    
    glBindVertexArray(0);
    
}

//Draw a asteroid
void Bullet::draw(mat4 proj){
    glUseProgram( GLvars.program );
    glBindVertexArray( GLvars.vao );
    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj*T_bull);
    //Draw something
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, 1);
    glBindVertexArray(0);
    glUseProgram(0);
}

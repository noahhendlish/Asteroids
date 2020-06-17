//
//  Asteroid.cpp
//  ASTEROIDS
//
//  Created by Noah Hendlish on 9/16/18.
//
//

#include <stdio.h>
#include "common.h"
#include <ctime>

//asteroid constructor
Asteroid::Asteroid(){
    //vec2 shape_ast[12] = {vec2(0,0),vec2(0.06,0.025), vec2(0.035,0.075), vec2(-0.025,0.085),vec2(-0.04,0.065), vec2(-0.06, 0.03), vec2 (-0.07,0), vec2 (-0.06, -0.05), vec2(0, -0.075),vec2(0.025,-0.05), vec2(0.05, -0.035), vec2(0.06,0.025)};
    //state.cur_location = vec2(0,0);
    //FOR RANDOM LOCATION (change rand_loc to true to have starting locations random), otherwise sets starting loc to corner:
    bool rand_loc = true;
    if (rand_loc == true){
        //srand(time(0));
        //r = ((double) rand() / (RAND_MAX))
        float rand_x_loc = (((float)rand() / RAND_MAX) + 0.01)-(((float)rand() / RAND_MAX) + 0.01);
        float rand_y_loc = (((float)rand() / RAND_MAX) + 0.01)-(((float)rand() / RAND_MAX) + 0.01);
        //float rand_x_loc = (((rand() %1000) + 10)-((rand() % 1000) + 10))/100;
        //float rand_y_loc = (((rand() %1000) + 10)-((rand() % 1000) + 10))/100;
        state.cur_location = vec2(rand_x_loc, rand_y_loc);
    }
    else{
        //state.cur_location = vec2(-1.0, -1.0);
    }
    state.scale = 1;
    //state.shrunk = false;
    S_ast = Scale(1, 1, 0);
    float rand_x_dir = ((((float)rand() / RAND_MAX) + 0.05)-(((float)rand() / RAND_MAX) + 0.05));
    float rand_y_dir = ((((float)rand() / RAND_MAX) + 0.05)-(((float)rand() / RAND_MAX) + 0.05));
    state.velocity = (vec2(rand_x_dir, rand_y_dir))*0.005;
    state.shrunk = false;
    //state.scale = 1;
    /*
    if(state.shrunk == false){
        state.scale = 1;
    }
    else{
        state.scale = 0.5;
    }
     */
    
};

//phase 3: Extend your Asteroid code to now populate your game with a vector of Asteroids.
//std::vector < Asteroid> asteroids;

void Asteroid::curr_vertices(){
    vec2 astrver[11] = {vec2(0.06,0.025), vec2(0.035,0.075), vec2(-0.025,0.085),vec2(-0.04,0.065), vec2(-0.06, 0.03), vec2 (-0.07,0), vec2 (-0.06, -0.05), vec2(0, -0.075),vec2(0.025,-0.05), vec2(0.05, -0.035), vec2(0.06,0.025)};
    vec2* newvert = new vec2[11];
    //GLfloat half = 0.5;
    //GLfloat zero = 0;
    //GLfloat one = 1;
    //mat4 half_size = mat4(half, zero, zero, zero, zero, half, zero, zero, zero, zero, zero, zero, zero, zero, zero,one );
    //mat2 half = mat2(1,0,1,0);
    //float* all_vertices_x = new float[12];
    //float* all_vertices_y = new float[12];
    //vec2* all_vertices = new vec2[12];
    //state.scale = 1;
    for(int i = 0; i <11; i++){
        //all_vertices_x[i] = asteroid_vert[i].x;
        //all_vertices_y[i] = asteroid_vert[i].y;
        //all_vertices[i] = asteroid_vert[i] *state.scale +state.cur_location;
        newvert[i] = astrver[i]*state.scale;
        newvert[i] += state.cur_location;
        //all_vertices[i] = new vec2(all_vertices_x[i], all_vertices_y[i]);
        //*state.scale + state.cur_location; //+ state.cur_location;
        //all_vertices[i] = asteroid_vert[i]*0.5+state.cur_location; //+ state.cur_location;

    }
    state.vertices = newvert;
    //return newvert;
    //return all_vertices;
}

void Asteroid::shrink(){
    //Scales by half size
    state.shrunk = true;
    state.scale = 0.5;
    //S_ast = Scale(state.scale, state.scale, 0);
}
//Called everytime an animation tick happens
void Asteroid::update_state(){
    //FOR RANDOM MAGNITUDE
    //FOR RANDOM VELOCITY
    
    state.angle += 0.8;
    R_ast = RotateZ(state.angle);
    //p  = old_position + v*dt
    state.cur_location += state.velocity;
    //update position using model view
    curr_vertices();
    T_ast = Translate(state.cur_location.x, state.cur_location.y, 0);
    //wrap around?
    bool wrap = true;
    if(wrap == true){
        if(std::abs(state.cur_location.x)>= 1){
            state.cur_location.x *= -1;
        }
        if(std::abs(state.cur_location.y)>= 1){
            state.cur_location.y *= -1;
        }

        /*
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
         */
    }
}

//Initialize the gl state and variables
void Asteroid::gl_init(){
    //Asteroid
    //vec2 asteroid_vert[12] = {vec2(0,0),vec2(0.12,0), vec2(0.08,0.18),vec2(-0.09,0.2),vec2(-0.2,0.08), vec2(-0.12, -0.18), vec2 (-0.05, -0.04), vec2(0.09, -0.05), vec2(0.09, -0.04), vec2(0.08,-0.03), vec2(0.05, -0.01), vec2(0.12,0)}; //ALTERNATIVE SHAPE?
    //vec2 asteroid_vert[12] = {vec2(0,0),vec2(0.06,0.025), vec2(0.035,0.075), vec2(-0.025,0.085),vec2(-0.04,0.065), vec2(-0.06, 0.03), vec2 (-0.07,0), vec2 (-0.06, -0.05), vec2(0, -0.075),vec2(0.025,-0.05), vec2(0.05, -0.035), vec2(0.06,0.025)};
    //vec2 asteroid_vert[12] = {vec2(0,0),vec2(0.12,0.05), vec2(0.07,0.15), vec2(-0.05,0.17),vec2(-0.08,0.13), vec2(-0.12, 0.06), vec2 (-0.18,0), vec2 (-0.12, -0.1), vec2(0, -0.15),vec2(0.05,-0.1), vec2(0.1, -0.07), vec2(0.12,0.05)}; //center is (0,0) *DOUBLE SIZE

    //vec3 asteroid_color[12] = {vec3(1,1,1),vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1),vec3(1,1,1),vec3(1,1,1), vec3(1,1,1),vec3(1,1,1),vec3(1,1,1), vec3(1,1,1)};
    //vec2* asteroid_vert = new vec2[12];
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
    //MAYBE NOT?
    ///*
    //Set GL state to use this buffer
    glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
    if(state.shrunk == false){
    //Create GPU buffer to hold vertices and color
    glBufferData( GL_ARRAY_BUFFER, sizeof(asteroid_vert) + sizeof(asteroid_color), NULL, GL_STATIC_DRAW );
    //First part of array holds vertices
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(asteroid_vert), asteroid_vert );
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(asteroid_vert), sizeof(asteroid_color), asteroid_color );
    
    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location );
    
    glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(asteroid_vert)) );
    }
    else{
        //Create GPU buffer to hold vertices and color
        glBufferData( GL_ARRAY_BUFFER, sizeof(half_asteroid_vert) + sizeof(asteroid_color), NULL, GL_STATIC_DRAW );
        //First part of array holds vertices
        glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(half_asteroid_vert), half_asteroid_vert );
        //Second part of array hold colors (offset by sizeof(triangle))
        glBufferSubData( GL_ARRAY_BUFFER, sizeof(half_asteroid_vert), sizeof(asteroid_color), asteroid_color );
        
        glEnableVertexAttribArray(GLvars.vpos_location);
        glEnableVertexAttribArray(GLvars.vcolor_location );
        
        glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
        glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(asteroid_vert)) );
    }
    //*/
    //populate();
    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location );
    glBindVertexArray(0);
    
}


//Draw a asteroid
void Asteroid::draw(mat4 proj){
    glUseProgram( GLvars.program );
    glBindVertexArray( GLvars.vao );
    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj*T_ast*R_ast);
    //Draw something
    //glBindVertexArray( GLvars.vao );
    ///glDrawArrays(GL_TRIANGLE_FAN, 0, 12*asteroids.size());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 12);
    glBindVertexArray(0);
    glUseProgram(0);
    
}

/////////RANDOMS
/*
 float r = rand()%10+1;
 
 if(r<2){
 float rand_x_dir = ((rand() % rand()) + 0.05)-((rand() % rand()) + 0.05);
 float rand_y_dir = ((rand() % rand()) + 0.05)-((rand() % rand()) + 0.05);
 state.velocity=   normalize(vec2(rand_x_dir, rand_y_dir))*0.01;
 }
 else if (r<4){
 float rand_x_dir = rand()%20-10;
 float rand_y_dir = rand()%20-10;
 state.velocity=   normalize(vec2(rand_x_dir, rand_y_dir))*r/1000;
 
 }
 else if(r<6){
 float rand_x_dir = ((rand()%rand())-(rand()%rand()))/100;
 float rand_y_dir = ((rand()%rand())-(rand()%rand()))/100;
 state.velocity=   normalize(vec2(rand_x_dir, rand_y_dir))*r/1000;
 
 }
 else if(r<8){
 float rand_x_dir = ((rand() - rand()));
 float rand_y_dir = ((rand() - rand()));
 state.velocity=   normalize(vec2(rand_x_dir, rand_y_dir))*r/1000;
 
 }
 else if(r<=10){
 float rand_x_dir = rand()%rand()+1;
 float rand_y_dir = rand()%rand()+1;
 state.velocity=   normalize(vec2(rand_x_dir, rand_y_dir))*r/1000;
 }
 
 
 //state.pointing = normalize(vec2(rand_x_dir, rand_y_dir));
 //state.velocity=   state.pointing*0.001;
 //float rand_mag =(((rand() % 10) + 0.01))/1000;
 //state.velocity=   normalize(vec2(rand_x_dir, rand_y_dir))*rand_mag;
 //state.velocity=   normalize(vec2(rand_x_dir, rand_y_dir))*0.01;
 //float rand_x_dir = (((rand() % rand()) + 1)-((rand() % rand()) + 1))/100000000;
 //float rand_y_dir = (((rand() % rand()) + 1)-((rand() % rand()) + 1))/100000000;
 //state.velocity = (vec2(rand_x_dir, rand_y_dir))*0.001;
 //float rand_x_dir = ((rand()%100+1) - (rand()%100+1))*0.01;
 //float rand_y_dir = ((rand()%100+1) - (rand()%100+1))*0.01;
 //state.velocity = (vec2(rand_x_dir, rand_y_dir))*0.01;
 //state.velocity = normalize(vec2(rand_x_dir, rand_y_dir))*0.001;
 ////other rand:
    //float rand_x_dir = (((rand() % rand()) + 1)-((rand() % rand()) + 1));
    //float rand_y_dir = (((rand() % rand()) + 1)-((rand() % rand()) + 1));
    //float rand_x_dir = (((rand() % rand()) + 0.05)-((rand() % rand()) + 0.05));
    //float rand_y_dir = (((rand() % rand()) + 0.05)-((rand() % rand()) + 0.05));
 */

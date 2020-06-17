//
//  Asteroid.h
//  ASTEROIDS
//
//  Created by Noah Hendlish on 9/16/18.
//
//

#ifndef Asteroid_h
#define Asteroid_h
#include "common.h"


class Asteroid{
    //Placeholders so everything compiles.  Customize for your asteroid
    //vec2 asteroid_vert[12];
    //vec3 asteroid_color[12];
    vec2 asteroid_vert[12] = {vec2(0,0),vec2(0.06,0.025), vec2(0.035,0.075), vec2(-0.025,0.085),vec2(-0.04,0.065), vec2(-0.06, 0.03), vec2 (-0.07,0), vec2 (-0.06, -0.05), vec2(0, -0.075),vec2(0.025,-0.05), vec2(0.05, -0.035), vec2(0.06,0.025)};
    vec2 half_asteroid_vert[12] = {vec2(0,0),vec2(0.03,0.025/2), vec2(0.035/2,0.075/2), vec2(-0.025/2,0.085/2),vec2(-0.02,0.065/2), vec2(-0.03, 0.015), vec2 (-0.035,0), vec2 (-0.03, -0.025), vec2(0, -0.075/2),vec2(0.025/2,-0.025), vec2(0.025, -0.035/2), vec2(0.03,0.025/2)};

    vec3 asteroid_color[12] = {vec3(1,1,1),vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1), vec3(1,1,1),vec3(1,1,1),vec3(1,1,1), vec3(1,1,1),vec3(1,1,1),vec3(1,1,1), vec3(1,1,1)};
    //std::vector<Asteroid> vecAsteroids;
    //Record of the asteroid's state
  
    //OpenGL variables for a ship
    struct {
        GLuint vao;           //Vertex array object
        GLuint program;       //shader program
        GLuint buffer;        //Vertex buffer objects
        GLuint vertex_shader, fragment_shader;  //Shaders
        GLint vpos_location, vcolor_location;   //reference to pos and color in shaders
        GLint M_location;     //Reference to matrix in shader
    } GLvars;
    
    
public:
    struct {
        //vec2 asteroids_arr;
        vec3 col;
        //float num_vertices = 12;
        vec2 cur_location;   //Current position of the center
        //This function will be helpful to keep track of the direction an asteroid
        //is pointing
        //ADD ANGLE OF ROTATION
        vec2 velocity;       //Velocity
        float angle;         //Rotation angle
        vec2 pointing;       //Vector pointing to the front of the asteroid
        float scale;
        bool shrunk;
        //vec2 ast_shape[12] = {vec2(0,0),vec2(0.06,0.025), vec2(0.035,0.075), vec2(-0.025,0.085),vec2(-0.04,0.065), vec2(-0.06, 0.03), vec2 (-0.07,0), vec2 (-0.06, -0.05), vec2(0, -0.075),vec2(0.025,-0.05), vec2(0.05, -0.035), vec2(0.06,0.025)};

        //vec2 asteroid_vert[12] = {vec2(0,0),vec2(0.06,0.025), vec2(0.035,0.075), vec2(-0.025,0.085),vec2(-0.04,0.065), vec2(-0.06, 0.03), vec2 (-0.07,0), vec2 (-0.06, -0.05), vec2(0, -0.075),vec2(0.025,-0.05), vec2(0.05, -0.035), vec2(0.06,0.025)};
        vec2* vertices;
        //This function will be helpful to keep track of the direction the asteroid is pointing
        mat2 RotateZ2D( const GLfloat theta ){
            GLfloat angle = DegreesToRadians * theta;
            mat2 c;
            c[0][0] = c[1][1] = cos(angle);
            c[1][0] = sin(angle);
            c[0][1] = -c[1][0];
            return c;
        }
    } state;

    Asteroid();
    mat4 R_ast;
    mat4 T_ast;
    mat4 S_ast;
    //int num_asteroids;
    void populate();
    void update_state();
    void add_new();
    void gl_init();
    void explode();
    void curr_vertices();
    void draw(mat4 proj);
    void shrink();
};

#endif /* Asteroid_h */

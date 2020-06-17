//
//  Bullet.h
//  ASTEROIDS
//
//  Created by Noah Hendlish on 10/14/18.
//
//

#ifndef Bullet_h
#define Bullet_h
#include "common.h"

class Bullet{
    
    //Placeholders so everything compiles.  Customize for your bullet
    vec2 bullet_vert;
    vec3 bullet_color;
    
    
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
    //Record of the asteroid's state
    struct {
        vec2 cur_location;   //Current position of tip bullet (start at tip of ship)
        vec2 velocity;       //Velocity
     
    } state;

    Bullet();
    //mat4 R_bull;
    mat4 T_bull;
    void update_state();
    void gl_init();
    void draw(mat4 proj);
    //void outbounds(float dt);
};

#endif /* Bullet_h */

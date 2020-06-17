//
//  Ship.h
//  Asteroids
//
//  Created by Brian Summa on 6/5/15.
//
//

#ifndef __Asteroids__Ship__
#define __Asteroids__Ship__

#include "common.h"
#include "Bullet.h"
#define _MAX_SPEED 2
#define _DAMPING 0.98
#define _ACC 0.002
#define _ROT 15

class Ship{

  //Placeholders so everything compiles.  Customize for your ship
  
  vec3 ship_color[9];
  
  //Record of the ship's state
  struct {
    vec2 cur_location;   //Current position of the center
    float angle;         //Rotation angle
    vec2 pointing;       //Vector pointing to the front of the ship
    //This function will be helpful to keep track of the direction the ship
    //is pointing
    mat2 RotateZ2D( const GLfloat theta ){
      GLfloat angle = DegreesToRadians * theta;
      mat2 c;
      c[0][0] = c[1][1] = cos(angle);
      c[1][0] = sin(angle);
      c[0][1] = -c[1][0];
      return c;
    }
    vec2 velocity;       //Velocity
    bool thruster_on;    //Boolean if a thruster is on
  } state;
  
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
    
  Ship();
    
  mat4 R;
  mat4 T;
  vec2 ship_vert[9];
  inline void start_thruster(){ state.thruster_on= true;}
  inline void stop_thruster() { state.thruster_on= false;}

  inline void rotateLeft() {
      state.angle -= _ROT;
      R = RotateZ(state.angle);
      state.pointing = state.RotateZ2D(state.angle)*vec2(0.0,1.0);
      
      //vec2 dir = state.RotateZ2D(-15)*state.pointing;
      //state.pointing = dir;
      //state.cur_location = state.RotateZ2D(-15);
      //state.RotateZ2D(1);
  }
  inline void rotateRight(){
      //Do something
      state.angle += _ROT;
      R = RotateZ(state.angle);
      state.pointing = state.RotateZ2D(state.angle)*vec2(0.0,1.0);
      
      //std::cout << state.angle  << "\n";
      //state.RotateZ2D(5);
      //RotateZ(10);
      //state.pointing = state.pointing*state.angle;
  }
  //void Bullet pew_pew();
  void update_state();
  Bullet* pew_pew();
  vec2* curr_vertices();
  float num_vertices = 9;
  void gl_init();
  
  void draw(mat4 proj);
  
};


#endif /* defined(__Asteroids__Ship__) */

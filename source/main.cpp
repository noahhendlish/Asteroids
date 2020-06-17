#include "common.h"

using namespace Angel;
//POINT INSIDE POLYGON ALGO SLIDES 7: SLIDE # 73
Ship ship;
//Asteroid asteroid;
std::vector <Bullet *> bullet;

std::vector < Asteroid *> asteroids;

static void error_callback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    
    if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
        ship.rotateLeft();
    if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
        ship.rotateRight();
    if (key == GLFW_KEY_SPACE){
        if(action == GLFW_PRESS){
            ship.start_thruster();
        }
        if(action == GLFW_RELEASE){
            ship.stop_thruster();
        }
    }
    if (key == GLFW_KEY_Z && action == GLFW_PRESS){
        //if (key == GLFW_KEY_Z && (action == GLFW_PRESS || action == GLFW_REPEAT)){
        //fire bullet
        Bullet* b = ship.pew_pew();
        b->gl_init();
        bullet.push_back(b);
        b->update_state();
        
    }
}

void populate_asteroids(int num_asteroids){
    if(num_asteroids <= 0){
        num_asteroids = 5;
    }
    for(unsigned int i=0; i < num_asteroids; i++){
        Asteroid* a = new Asteroid();
        a->gl_init();
        //asteroid.asteroids[i] -> gl_init();
        asteroids.push_back(a);
    }
    
}

void init(){
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
    ship.gl_init();
    populate_asteroids(7);
    
    /*
     //for(int i =0; i < asteroid.asteroids.size(); i ++){
     //asteroid.asteroids[i] -> gl_init();
     //}
     for(int i =0; i <  bullet.size(); i ++){
     bullet[i]->gl_init();
     }
     */
    
}
bool PointInPoly(const vec2* polygon, const vec2 point, int num_vertices){  //used to check if bullet hits asteroid
    bool inside = false;
    vec2 p1;
    vec2 p2;
    for (int i = 0; i<num_vertices-1; i++){  // iterate through each edge
        p1 = polygon[i]; //get first edge endpoint from polygon
        p2 = polygon[i+1]; // get second edge endpoint from polygon
        //if (p1[1] > p2[1]): swap(p1, p2);
        
        if (p1.y > p2.y){ //want p1 to p2 to point in +y direction
            vec2 temp = p1;
            p1 = p2;
            p2 = temp;
            //std::swap(p1, p2);
        }
        if (point.y > p1.y){ //above lower edge endpoint
            if (point.y <= p2.y){ //below upper edge endpoint
                if (p1.y!= p2.y){  //if edge is not horizontal do half-plane check
                    // z of crossproduct(point-p1, p2-p1) > 0) means we’re to the right
                    if ((((point.x - p1.x) * (p2.y - p1.y))- ((p2.x - p1.x) * (point.y - p1.y))) > 0){
                        inside = !inside;
                        // if true, point is to right of edge (and thus in the “strip”)
                    }
                }
            }
        }
    }
    return inside;
    
}

/*
 bool PointInPolyWithBoundingBoxCull(const vec2* polygon, const vec2* BoundingBox, const vec2 point ){
 float xmin =1.0;
 float xmax =1.0;
 if ((point.x <= BoundingBox(xmin))or
 (point.x >= BoundingBox(xmax))or
 (point.y <= BoundingBox(ymin))or
 (point.y >= BoundingBox(ymax))){
 return false;
 }
 
 else{
 return PointInPoly(polygon, point, length(*polygon));
 }
 }
 */

/*
 bool SetBoundingBox(const vec2 V*,  const vec2 AABB){
 int i;
 AABB[0][0] = AABB[0][1] = V[0][0];
 AABB[1][0] = AABB[1][1] = V[1][0];
 for (i = 1; i = V*-1; i++) {
 if (AABB[0][0] > V[0][i]) AABB[0][0] = V[0][i];
 if (AABB[0][1] < V[0][i]) AABB[0][1] = V[0][i];
 if (AABB[1][0] > V[1][i]) AABB[1][0] = V[1][i];
 if (AABB[1][1] < V[1][i]) AABB[1][1] = V[1][i]}
 }
 */
bool ship_hit_asteroid(){
    //bool s_collision = false;
    bool ast_collision = false;
    vec2* ship_vertices = ship.curr_vertices();
    for(int a = asteroids.size() - 1; a >= 0; a--){
        for(int i = 0; i < 6; i ++){
            Asteroid * ast = asteroids[a];
            //ast->curr_vertices();
            //Bullet* bull = bullet[b];
            ast_collision = PointInPoly(ast->state.vertices, ship_vertices[i], 11);
            if(ast_collision == true){
                //asteroids.erase(asteroids.begin() + a);
                return true;
            }
            //break;
            
        }
    }
    return false;
}

/*
    bool s_collision = false;
    bool a_collision = false;
    vec2* ship_vectices = ship.curr_vertices();
    for(std::vector< Asteroid * >::iterator a = asteroids.begin(); a != asteroids.end();){
        for(int i = 0; i < 9; i ++){
            //if(bullet.size()>0){
            s_collision = PointInPoly((*a)->state.vertices, ship_vectices[i], 12);//12 vertices in asteroid
            if(s_collision == true){
                a_collision = true;
                return true;
            }
            
        }
        //outside of nested for loop
        if(a_collision==true){
            //a = asteroids.erase(a);
            return true;
        }
        else{
            a++;
        }
        
    }
    return false;
    
}
*/

void bullet_hit_asteroid(){
    bool a_collision = false;
    bool b_collision = false;
    for(int a = asteroids.size() - 1; a >= 0; a--){
        Asteroid * ast = asteroids[a];
        //for(std::vector< Asteroid * >::iterator a = asteroids.begin(); a != asteroids.end();){
        //a_collision = false;
        //vec2* xyzys = ast->curr_vertices();
        for(int b= bullet.size() - 1; b >= 0; b--){
            //for(std::vector< Bullet * >::iterator b = bullet.begin(); b != bullet.end();){
            if(bullet.size() >0){
                //ast->curr_vertices();
                Bullet* bull = bullet[b];
                //vec2 *curr = new vec2[12];
                //for(int z = 0; z <12; z ++){
                //curr[z] = (ast)->asteroid_vert[z]*(ast)->state.scale +(ast)->state.cur_location;
                //}
                //b_collision = PointInPoly((ast)->state.vertices, (bull)->state.cur_location, 12);//12 vertices in asteroid]
                //b_collision = PointInPoly(curr, (bull)->state.cur_location, 12);//12 vertices in asteroid
                b_collision = PointInPoly(ast->state.vertices, (bull)->state.cur_location, 11);
                if(b_collision == true){
                    bullet.erase(bullet.begin() + b);
                    a_collision = true;
                    if((ast)->state.shrunk == true){
                        asteroids.erase(asteroids.begin() + a);
                        a_collision = false;
                    }
                    else{
                        
                        //(*a)->update_state();
                        vec2 prev_loc = (ast)->state.cur_location;
                        GLfloat prev_x_state = (ast)->state.cur_location.x;
                        GLfloat prev_y_state = (ast)->state.cur_location.y;
                        asteroids.erase(asteroids.begin() + a);
                        int num_asteroids = 3;
                        
                        for(unsigned int i=0; i < num_asteroids; i++){
                            Asteroid* n = new Asteroid();
                            n->state.shrunk = true;
                            n-> state.cur_location = vec2(prev_x_state, prev_y_state);
                            n->shrink();
                            n->gl_init();
                            //n->state.cur_location = prev_loc;
                            //n->state.shrunk = true;
                            asteroids.push_back(n);
                        }
                        /*Asteroid* n1 = new Asteroid();
                         Asteroid* n2 = new Asteroid();
                         Asteroid* n3 = new Asteroid();
                         n1->state.shrunk = true;
                         n2->state.shrunk = true;
                         n3->state.shrunk = true;
                         n1-> state.cur_location = vec2(prev_x_state, prev_y_state);
                         n2-> state.cur_location = vec2(prev_x_state, prev_y_state);
                         n3-> state.cur_location = vec2(prev_x_state, prev_y_state);
                         n1->shrink();
                         n2->shrink();
                         n3->shrink();
                         asteroids.push_back(n1);
                         asteroids.push_back(n2);
                         asteroids.push_back(n3);
                         n1->gl_init();
                         n2->gl_init();
                         n3->gl_init();
                         */
                    }
                    break;
                }
                //break;
                
            }
        }
    }
}



void bull_outbounds(){
    for(std::vector< Bullet * >::iterator b = bullet.begin(); b != bullet.end();){
        if((std::abs((*b)-> state.cur_location.x) >= 1.0)){
            b = bullet.erase(b);
        }
        else if((std::abs((*b)-> state.cur_location.y) >= 1.0)){
            b = bullet.erase(b);
        }
        else{
            b ++;
        }
        
    }
    
}



//Call update function 30 times a second
void animate(){
    if(glfwGetTime() > 0.033){
        
        //if(glfwGetTime() > 0.033){
        glfwSetTime(0.0);
        ship.update_state();
        
        bullet_hit_asteroid();
        
        //deletes bullets out of bounds
        bull_outbounds();
        for(int i =0; i < asteroids.size(); i ++){
            asteroids[i] -> update_state();
            
        }
        
        //update bullet state
        for(int i =0; i < bullet.size(); i ++){
            bullet[i]->update_state();
            
        }
        
        //used to check if bullet hits asteroid
        
    }
    //check if bullet hits asteroid ALSO CHECK if asteroid hits the ship
}


int main(void)
{
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_SAMPLES, 10);
    
    
    window = glfwCreateWindow(1024, 768, "Asteroids!", NULL, NULL);
    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwSetKeyCallback(window, key_callback);
    
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);
    
    init();
    //bool game_over = false;
    while (!glfwWindowShouldClose(window)){
        //while(game_over == false){
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        //Pick a coordinate system that makes the most sense to you
        //(left, right, top, bottom)
        mat4 proj = Ortho2D(-1.0, 1.0, 1.0, -1.0);
        animate();
        //animate();
        glClear(GL_COLOR_BUFFER_BIT);
        //draw ship
        ship.draw(proj);      //draw ship
        
        //draw bullets
        for(int i =0; i < bullet.size(); i ++){
            bullet[i]->draw(proj);
        }
        //draw asteroids
        //asteroid.draw(proj);    //draw asteroid
        for(int i =0; i < asteroids.size(); i ++){
            asteroids[i] -> draw(proj);
        }
        
        
         if(ship_hit_asteroid() == true){
             //glfwWaitEvents();
             //glfwWindowShouldClose(window);
             glfwSetWindowTitle(window, "ASTEROIDS GAME OVER");
             //game_over = true;
             //break;
             glfwFocusWindow(window);
             for(int a = asteroids.size() - 1; a >= 0; a--){
                    //Asteroid * ast = asteroids[a];
                         asteroids.erase(asteroids.begin() + a);
                     }

             glClearColor(1,0,0,0);
         }
        
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
        
    
    
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
}





/*
 void bullet_hit_asteroid(){
 bool a_collision = false;
 bool b_collision = false;
 for(std::vector< Asteroid * >::iterator a = asteroids.begin(); a != asteroids.end();){
 a_collision = false;
 for(std::vector< Bullet * >::iterator b = bullet.begin(); b != bullet.end();){
 b_collision = false;
 //if(bullet.size()>0){
 b_collision = PointInPoly((*a)->curr_vertices(), (*b)->state.cur_location, 12);//12 vertices in asteroid
 if(b_collision == true){
 b = bullet.erase(b);
 b_collision = false;
 a_collision = true;
 }
 else{
 b++;
 }
 }
 if(a_collision==true){
 if((*a)->state.shrunk == true){
 a = asteroid.asteroids.erase(a);
 a_collision = false;
 }
 else{
 (*a)->update_state();
 GLfloat prev_x_state = (*a)->state.cur_location.x;
 //(*a)->state.cur_location.x;
 GLfloat prev_y_state = (*a)->state.cur_location.y;
 a = asteroid.asteroids.erase(a);
 a_collision = false;
 //explode and create new ones
 Asteroid *n1 = new Asteroid();
 Asteroid *n2 = new Asteroid();
 Asteroid *n3 = new Asteroid();
 n1->gl_init();
 n2->gl_init();
 n3->gl_init();
 n1->shrink();
 n2->shrink();
 n3->shrink();
 n1->state.cur_location = vec2(prev_x_state, prev_y_state);
 n2->state.cur_location = vec2(prev_x_state, prev_y_state);
 n3->state.cur_location = vec2(prev_x_state, prev_y_state);
 asteroid.asteroids.push_back(n1);
 asteroid.asteroids.push_back(n2);
 asteroid.asteroids.push_back(n3);
 (*n1).update_state();
 (*n2).update_state();
 (*n3).update_state();
 }
 
 }
 else{
 a++;
 }
 
 }
 }
 */

/*
 void bullet_hit_asteroid(){
 bool collision = false;
 if(bullet.size()>0){
 for(std::vector< Asteroid * >::iterator a = asteroids.begin(); a != asteroids.end();){
 collision = false;
 for(std::vector< Bullet * >::iterator b = bullet.begin(); b != bullet.end(); b++){
 collision = false;
 
 collision = PointInPoly((*a)->curr_vertices(), (*b)->state.cur_location, 12);//12 vertices in asteroid
 if(collision == true){
 if((*a)->state.shrunk == true){
 a = asteroids.erase(a);
 b = bullet.erase(b);
 collision = false;
 }
 else{
 (*a)->update_state();
 vec2 prev_loc = (*a)->state.cur_location;
 a = asteroids.erase(a);
 b = bullet.erase(b);
 int num_asteroids = 3;
 for(unsigned int i=0; i < num_asteroids; i++){
 Asteroid* n = new Asteroid();
 n->gl_init();
 n->shrink();
 n->state.cur_location = prev_loc;
 //asteroid.asteroids[i] -> gl_init();
 asteroids.push_back(n);
 (*n).update_state();
 //a++;
 }
 collision = false;
 }
 collision = false;
 }
 else{
 a++;
 
 }
 }
 }
 }
 }
 */

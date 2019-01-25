#include "main.h"
#include "timer.h"
#include "ground.h"
#include "coin.h"
#include "player.h"
#include "global.h"
#include "enemy1.h"
#include "enemy2.h"
#include "lives.h"
#include "propulsion.h"
#include "boomerang.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ground ground;
vector <Boomerang> boomerang;
vector <Propulsion> propulsion;
vector <Enemy1> enemy1;
vector <Enemy2> enemy2;
vector <Lives> lives;
Player player;
vector <Coin> coins;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    //glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye(0, 0, 5);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    
    player.draw(VP);
    ground.draw(VP);
    for(int i = 0; i < coins.size(); ++i)
        coins[i].draw(VP);
    for(int i = 0; i < enemy1.size(); ++i)
        enemy1[i].draw(VP);
    for(int i = 0; i < enemy2.size(); ++i)
        enemy2[i].draw(VP);
    for(int i = 0; i < lives.size(); ++i)
        lives[i].draw(VP);
    for(int i = 0; i < propulsion.size(); ++i)
        propulsion[i].draw(VP);
    for(int i = 0; i < boomerang.size(); ++i)
        boomerang[i].draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    float delta_x = 0.0f;
    float delta_y = 0.0f;
    if (left) {
        // Do something
        if(player.position.x >= -4)
            player.set_position(player.position.x - 0.025, player.position.y);
    }
    if(right)
    {
        if(player.position.x >= -2)
            delta_x = -0.025;
        else{
            player.set_position(player.position.x + 0.025, player.position.y);
        }
    }
    if(space){
        player.speed = 0.05;
    }
    else if(player.detect_collision_with_ground() == true)
    {
        player.speed = 0.0f;
    }
    ground.set_position(ground.position.x + delta_x, ground.position.y);
    for(int i = 0; i < coins.size(); ++i)
        coins[i].set_position(coins[i].position.x + delta_x, coins[i].position.y);
    for(int i = 0; i < enemy1.size(); ++i){
        enemy1[i].x1 += delta_x;
        enemy1[i].x2 += delta_x;
        enemy1[i].set_position(enemy1[i].position.x + delta_x, enemy1[i].position.y);
    }    
    for(int i = 0; i < enemy2.size(); ++i){
        enemy2[i].x1 += delta_x;
        enemy2[i].x2 += delta_x;
        enemy2[i].set_position(enemy2[i].position.x + delta_x, enemy2[i].position.y);
    }
}

void tick_elements() {
    ground.tick();
    for(int i = 0; i < coins.size(); ++i)
        coins[i].tick();
    for(int i = 0; i < coins.size(); ++i){
        if(detect_collision_with_coin(coins[i], player)){
            coins.erase(coins.begin() + i);
            i = i - 1;
        }
    }
    for(int i = 0; i < enemy1.size(); ++i){
        if(detect_collision_with_enemy1(enemy1[i], player))
        {
            enemy1.erase(enemy1.begin() + i);
            i = i - 1;
        }
    }
    for(int i = 0; i < enemy2.size(); ++i){
        if(detect_collision_with_enemy2(enemy2[i], player)){
            enemy2.erase(enemy2.begin() + i);
            i = i - 1;
        }
        enemy2[i].tick();
    }
    for(int i = 0; i < lives.size(); ++i){
        lives[i].tick();
        if(detect_collision_with_lives(lives[i], player)){
            lives.erase(lives.begin() + i);
            i = i - 1;
        }
    }
    for(int i = 0; i < propulsion.size(); ++i){
        propulsion[i].tick();
    }
    if(ground.position.y < player.position.y - player.length)
    {
        propulsion.push_back(Propulsion(player.position.x + player.breadth / 2, player.position.y - player.length, COLOR_YELLOW));
    }
    player.tick();
    for(int i = 0; i < boomerang.size(); ++i)
    {
        boomerang[i].tick();
        if(detect_collision_with_boomerang(boomerang[i], player)){
            boomerang.erase(boomerang.begin() + i);
            i = i - 1;
            continue;
        }
    }
    camera_rotation_angle += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    ground       = Ground(-4, -3, COLOR_BLACK, 3, 100);
    player = Player(-4, -2, COLOR_GREEN);
    enemy1.push_back(Enemy1(0, 2, COLOR_BLACK));
    coins.push_back(Coin(1, 0, COLOR_RED, 0.2));
    coins.push_back(Coin(2, 0, COLOR_RED, 0.2));
    coins.push_back(Coin(3, 0, COLOR_RED, 0.2));
    coins.push_back(Coin(4, 0, COLOR_RED, 0.2));
    enemy2.push_back(Enemy2(0, -1, COLOR_BLACK));
    boomerang.push_back(Boomerang(1, 3, COLOR_BLACK));
    // Create and compile our GLSL program from the shaders
    lives.push_back(Lives(2, 3, COLOR_RED));
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 800;
    int height = 800;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}
bool detect_collision_with_coin(Coin c, Player p)
{
    float DeltaX = c.position.x - max(p.position.x, min(c.position.x, p.position.x + p.breadth));
    float DeltaY = c.position.y - min(p.position.y, max(c.position.y, p.position.y - p.length));
    return (DeltaX * DeltaX + DeltaY * DeltaY) < (c.radius * c.radius);
}

bool detect_collision_with_enemy1(Enemy1 e, Player p)
{
    float DeltaX = e.x1 - max(p.position.x, min(e.x1, p.position.x + p.breadth));
    float DeltaY = e.y1 - min(p.position.y, max(e.y1, p.position.y - p.length));
    int tmp = (DeltaX * DeltaX + DeltaY * DeltaY) < (e.radius * e.radius);
    DeltaX = e.x2 - max(p.position.x, min(e.x2, p.position.x + p.breadth));
    DeltaY = e.y2 - min(p.position.y, max(e.y2, p.position.y - p.length));
    tmp = tmp | ((DeltaX * DeltaX + DeltaY * DeltaY) < (e.radius * e.radius));
    Point p1 = {e.x1, e.y1};
    Point q1 = {e.x2, e.y2};
    // Top of player
    Point p2 = {p.position.x, p.position.y};
    Point q2 = {p.position.x + p.breadth, p.position.y};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    // Bottom of player
    p2 = {p.position.x, p.position.y - p.length};
    q2 = {p.position.x + p.breadth, p.position.y - p.length};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    // Left of player
    p2 = {p.position.x, p.position.y};
    q2 = {p.position.x, p.position.y - p.length};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    // Right of player
    p2 = {p.position.x + p.breadth, p.position.y};
    q2 = {p.position.x + p.breadth, p.position.y - p.length};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    if(tmp){
        return true;
    }
    return false;
}

bool detect_collision_with_enemy2(Enemy2 e, Player p)
{
    float DeltaX = e.x1 - max(p.position.x, min(e.x1, p.position.x + p.breadth));
    float DeltaY = e.y1 - min(p.position.y, max(e.y1, p.position.y - p.length));
    int tmp = (DeltaX * DeltaX + DeltaY * DeltaY) < (e.radius * e.radius);
    DeltaX = e.x2 - max(p.position.x, min(e.x2, p.position.x + p.breadth));
    DeltaY = e.y2 - min(p.position.y, max(e.y2, p.position.y - p.length));
    tmp = tmp | ((DeltaX * DeltaX + DeltaY * DeltaY) < (e.radius * e.radius));
    Point p1 = {e.x1, e.y1};
    Point q1 = {e.x2, e.y2};
    // Top of player
    Point p2 = {p.position.x, p.position.y};
    Point q2 = {p.position.x + p.breadth, p.position.y};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    // Bottom of player
    p2 = {p.position.x, p.position.y - p.length};
    q2 = {p.position.x + p.breadth, p.position.y - p.length};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    // Left of player
    p2 = {p.position.x, p.position.y};
    q2 = {p.position.x, p.position.y - p.length};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    // Right of player
    p2 = {p.position.x + p.breadth, p.position.y};
    q2 = {p.position.x + p.breadth, p.position.y - p.length};
    tmp = tmp | (doIntersect(p1, q1, p2, q2));
    if(tmp){
        return true;
    }
    return false;
}

bool detect_collision_with_boomerang(Boomerang b, Player p)
{
    float pi = 3.141;
    int tmp = 0;
    for(int i = 0; i < 4; ++i){
        Point P1 = b.p1; P1.x += (b.p1.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p1.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); P1.y += (b.p1.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p1.y - b.position.y) * cos(b.rotation1 * pi / 180.0f); 
        Point Q1 = b.p2; Q1.x += (b.p2.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p2.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); Q1.y += (b.p2.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p2.y - b.position.y) * cos(b.rotation1 * pi / 180.0f);
        Point P2;
        Point Q2;
        if(i == 0){
            // Top of the player
            P2 = {p.position.x, p.position.y};
            Q2 = {p.position.x + p.breadth, p.position.y};
        }
        else if(i == 1){
            // Bottom of the player
            P2 = {p.position.x, p.position.y - p.length};
            Q2 = {p.position.x + p.breadth, p.position.y - p.length};
        }
        else if(i == 2){
            // Left of the player
            P2 = {p.position.x, p.position.y};
            Q2 = {p.position.x, p.position.y - p.length};
        }
        else{
            // Right of player
            P2 = {p.position.x + p.breadth, p.position.y};
            Q2 = {p.position.x + p.breadth, p.position.y - p.length};
        }
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }
        P1 = b.p2; P1.x += (b.p2.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p2.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); P1.y += (b.p2.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p2.y - b.position.y) * cos(b.rotation1 * pi / 180.0f);
        Q1 = b.p3; Q1.x += (b.p3.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p3.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); Q1.y += (b.p3.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p3.y - b.position.y) * cos(b.rotation1 * pi / 180.0f);
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }
        P1 = b.p3; P1.x += (b.p3.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p3.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); P1.y += (b.p3.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p3.y - b.position.y) * cos(b.rotation1 * pi / 180.0f);
        Q1 = b.p4; Q1.x += (b.p4.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p4.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); Q1.y += (b.p4.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p4.y - b.position.y) * cos(b.rotation1 * pi / 180.0f);
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }
        P1 = b.p4; P1.x += (b.p4.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p4.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); P1.y += (b.p4.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p4.y - b.position.y) * cos(b.rotation1 * pi / 180.0f);
        Q1 = b.p1; Q1.x += (b.p1.x - b.position.x) * cos(b.rotation1 * pi / 180.0f) - (b.p1.y - b.position.y) * sin(b.rotation1 * pi / 180.0f); Q1.y += (b.p1.x - b.position.x) * sin(b.rotation1 * pi / 180.0f) + (b.p1.y - b.position.y) * cos(b.rotation1 * pi / 180.0f);
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }

        P1 = b.q1; P1.x += (b.q1.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q1.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); P1.y += (b.q1.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q1.y - b.position.y) * cos(b.rotation2 * pi / 180.0f); 
        Q1 = b.q2; Q1.x += (b.q2.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q2.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); Q1.y += (b.q2.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q2.y - b.position.y) * cos(b.rotation2 * pi / 180.0f);
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }
        P1 = b.q2; P1.x += (b.q2.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q2.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); P1.y += (b.q2.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q2.y - b.position.y) * cos(b.rotation2 * pi / 180.0f);
        Q1 = b.q3; Q1.x += (b.q3.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q3.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); Q1.y += (b.q3.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q3.y - b.position.y) * cos(b.rotation2 * pi / 180.0f);
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }
        P1 = b.q3; P1.x += (b.q3.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q3.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); P1.y += (b.q3.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q3.y - b.position.y) * cos(b.rotation2 * pi / 180.0f);
        Q1 = b.q4; Q1.x += (b.q4.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q4.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); Q1.y += (b.q4.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q4.y - b.position.y) * cos(b.rotation2 * pi / 180.0f);
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }
        P1 = b.q4; P1.x += (b.q4.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q4.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); P1.y += (b.q4.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q4.y - b.position.y) * cos(b.rotation2 * pi / 180.0f);
        Q1 = b.q1; Q1.x += (b.q1.x - b.position.x) * cos(b.rotation2 * pi / 180.0f) - (b.q1.y - b.position.y) * sin(b.rotation2 * pi / 180.0f); Q1.y += (b.q1.x - b.position.x) * sin(b.rotation2 * pi / 180.0f) + (b.q1.y - b.position.y) * cos(b.rotation2 * pi / 180.0f);
        tmp = tmp | (doIntersect(P1, Q1, P2, Q2));
        if(tmp)
        {
            return true;
        }
    }
    return false;
}

bool detect_collision_with_lives(Lives l, Player p)
{
    float DeltaX = l.x1 - max(p.position.x, min(l.x1, p.position.x + p.breadth));
    float DeltaY = l.y1 - min(p.position.y, max(l.y1, p.position.y - p.length));
    int tmp = (DeltaX * DeltaX + DeltaY * DeltaY) < (l.radius * l.radius);
    DeltaX = l.x2 - max(p.position.x, min(l.x2, p.position.x + p.breadth));
    DeltaY = l.y2 - min(p.position.y, max(l.y2, p.position.y - p.length));
    tmp = tmp | ((DeltaX * DeltaX + DeltaY * DeltaY) < (l.radius * l.radius));
    return tmp;
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
  
// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
float orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    float val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    float o1 = orientation(p1, q1, p2); 
    float o2 = orientation(p1, q1, q2); 
    float o3 = orientation(p2, q2, p1); 
    float o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 
#define GLM_ENABLE_EXPERIMENTAL
#include "player.h"
#include "ring.h"
#include "main.h"
#include "global.h"
#include "iostream"
Player::Player(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0;
    this->length = 1.0f;
    this->breadth = 1.0f;
    static const GLfloat vertex_buffer_data[] = {
        0.0f, 0.0f, 0.0f, // triangle 1 : begin
        0.0f, -this->length, 0.0f,
        this->breadth, -this->length, 0.0f, // triangle 1 : end
        0.0f, 0.0f, 0.0f, // triangle 2 : begin
        this->breadth, -this->length, 0.0f,
        this->breadth, 0.0f, 0.0f, // triangle 2 : end
    };
    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);
}

void Player::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Player::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

bool Player::detect_collision_with_ground(){
    if(ground.position.y >= this->position.y - this->length)
        return true;
    return false;
}

float dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int Player::insideRing(Ring r){
    Point p = {this->position.x, this->position.y};
    Point q = {r.position.x, r.position.y};
    int fl = 0;
    if(dist(p, q) <= r.radius && p.y >= q.y){
        fl += 1;
    }
    p = {this->position.x + this->breadth, this->position.y};
    if(dist(p, q) <= r.radius && p.y >= q.y){
        fl += 1;
    }
    return fl;
}

void Player::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    int inside = 0;
    for(int i = 0; i < ring.size(); ++i)
    {
        if(insideRing(ring[i]) == 2){
            float tmp = 0.01;
            this->speed = 0.0f;
            this->position.y += tmp;
            return;
        }
        if(insideRing(ring[i]) == 1 && abs(this->position.y - ring[i].position.y) <= 0.08)
        {
            this->speed = 0.0f;
            return;
        }
    }
    if(detect_collision_with_ground() == false){
        this->speed -= 0.001;
    }
    this->position.y += this->speed;
}


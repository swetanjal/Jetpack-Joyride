#define GLM_ENABLE_EXPERIMENTAL
#include "player.h"
#include "main.h"
#include "global.h"
Player::Player(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0;
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

void Player::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    if(detect_collision_with_ground() == false){
        speed -= 0.001;
    }
    this->position.y += speed;
}


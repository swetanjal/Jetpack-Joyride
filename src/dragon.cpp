#define GLM_ENABLE_EXPERIMENTAL
#include "dragon.h"
#include "main.h"
#include "global.h"
#include "water.h"

Dragon::Dragon(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this -> timer = 0;
    speed = 1;
    this->breadth = 0.5f;
    this->length = 2.0f;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,0.0f, // triangle 1 : begin
        this->breadth * 1.0f, 0.0f, 0.0f,
        this->breadth * 1.0f, -this->length * 1.0f, 0.0f, // triangle 1 : end
        this->breadth * 1.0f, -this->length * 1.0f, 0.0f, // triangle 2 : begin
        0.0f, -this->length * 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, // triangle 2 : end

    };
    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);
}

void Dragon::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Dragon::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Dragon::tick() {
    this->timer += 1;
    this->timer = this -> timer % 250;
    if(this->timer == 0 && sqrt((player.position.x - this->position.x) * (player.position.x - this->position.x)) <= 5){
        water.push_back(Water(this->position.x, this->position.y, COLOR_BLACK));
        water[water.size() - 1].speedx = -0.02f * (this->position.x - player.position.x);
        water[water.size() - 1].speedy = -0.02f * (this->position.y - player.position.y);
    }
    //this->rotation += speed;
    // this->position.x -= speed;
    if((this->position.y - this->length) > (player.position.y - player.length))
        this->position.y -= 0.01;
    else if(this->position.y < player.position.y)
        this->position.y += 0.01;

}


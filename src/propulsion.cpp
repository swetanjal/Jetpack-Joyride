#define GLM_ENABLE_EXPERIMENTAL
#include "propulsion.h"
#include "main.h"

Propulsion::Propulsion(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = rand() % 21;
    if(rand() % 2)
        this->rotation = -this->rotation;
    this->speed = 0.05;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    this->delta = 0.035;
    this->length = 0.5;
    static const GLfloat vertex_buffer_data[] = {
       0.0f, 0.0f, 0.0f,
       this->delta, 0.0f, 0.0f,
       this->delta, -this->length, 0.0f,
       0.0f, -this->length, 0.0f,
       0.0f, 0.0f, 0.0f,
       this->delta, -this->length, 0.0f
    };
    if(rand() % 9 == 0)
        this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_ORANGERED, GL_FILL);
    else
        this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
}

void Propulsion::draw(glm::mat4 VP) {
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

void Propulsion::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Propulsion::tick() {
    float pi = 3.141;
    //this->rotation += speed;
    this->position.x += (this->speed * sin(this->rotation * pi / 180.0f));
    // this->position.y -= speed;
    this->position.y -= (this->speed * cos(this->rotation * pi / 180.0f) + 0.088);
}


#define GLM_ENABLE_EXPERIMENTAL
#include "boomerang.h"
#include "main.h"

Boomerang::Boomerang(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation1 = 30;
    this->rotation2 = -30;
    this->rotation3 = 0;
    this->speed = 5;
    this->speed_x = 0.1f;
    this->speed_y = 0.0f;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        0.0f, 0.0f, 0.0f,
        0.8f, 0.0f, 0.0f,
        0.8f, 0.2f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.8f, 0.2f, 0.0f,
        0.0f, 0.2f, 0.0f
    };
    float pi = 3.141;
    this->p1 = {x + 0.0f, y + 0.0f};
    this->p2 = {x + 0.8f, y + 0.0f};
    this->p3 = {x + 0.8f, y + 0.2f};
    this->p4 = {x + 0.0f, y + 0.2f};
    static const GLfloat vertex_buffer_data2[] = {
        0.0f, 0.0f, 0.0f,
        0.8f, 0.0f, 0.0f,
        0.8f, -0.2f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.8f, -0.2f, 0.0f,
        0.0f, -0.2f, 0.0f
    };
    this->q1 = {x + 0.0f, y + 0.0f};
    this->q2 = {x + 0.8f, y + 0.0f};
    this->q3 = {x + 0.8f, y -0.2f};
    this->q4 = {x + 0.0f, y -0.2f};
    static const GLfloat vertex_buffer_data3[] = {
        0.0f, 0.0f, 0.0f,
        -0.1f, 0.2f, 0.0f,
        -0.1f, -0.2f, 0.0f
    };
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data2, color, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data3, color, GL_FILL);
}

void Boomerang::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate1 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate1    = glm::rotate((float) (this->rotation1 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate1 * rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate2 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate2 * rotate2);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate3 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate3    = glm::rotate((float) (this->rotation3 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate3 * rotate3);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object3);
}

void Boomerang::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Boomerang::tick() {
    this->rotation1 += this->speed;
    this->rotation2 += this->speed;
    this->rotation3 += this->speed;
    this->speed_y += 0.00008;
    if(this->rotation1 >= 360)
        this->rotation1 -= 360;
    if(this->rotation2 >= 360)
        this->rotation2 -= 360;
    if(this->rotation3 >= 360)
        this->rotation3 -= 360;
    float DX = this->position.x - ((this->position.y * this->position.y) - 4);
    DX = -DX;
    this->position.x = (this->position.y * this->position.y) - 4;
    this->position.y -= this->speed_y;
    p1.x += DX;
    p2.x += DX;
    p3.x += DX;
    p4.x += DX;
    q1.x += DX;
    q2.x += DX;
    q3.x += DX;
    q4.x += DX;

    p1.y -= this->speed_y;
    p2.y -= this->speed_y;
    p3.y -= this->speed_y;
    p4.y -= this->speed_y;
    q1.y -= this->speed_y;
    q2.y -= this->speed_y;
    q3.y -= this->speed_y;
    q4.y -= this->speed_y;

}


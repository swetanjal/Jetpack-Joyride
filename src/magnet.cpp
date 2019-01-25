#define GLM_ENABLE_EXPERIMENTAL
#include "magnet.h"
#include "main.h"

Magnet::Magnet(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = rand() % 30;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -0.4f, 1.0f, 0.0f,
        -0.4f, 0.0f, 0.0f,
        -0.55f, 0.0f, 0.0f,
        -0.55f, 0.0f, 0.0f,
        -0.55f, 1.0f, 0.0f,
        -0.4f, 1.0f, 0.0f
    };
    static const GLfloat vertex_buffer_data2[] = {
        0.4f, 1.0f, 0.0f,
        0.4f, 0.0f, 0.0f,
        0.55, 0.0f, 0.0f,
        0.55f, 0.0f, 0.0f,
        0.55, 1.0f, 0.0f,
        0.4f, 1.0f, 0.0f
    };

    this->radius = 0.55;
    const int N = 180;
	float deg = 180 * 1.0f / N;
	float theta = 0.0f;
	float pi = 3.141;
	static GLfloat vertex_buffer_data3[3 * 3 * N];
	for(int i = 0; i < N; ++i){
		vertex_buffer_data3[9 * i] = 0.0f;
		vertex_buffer_data3[9 * i + 1] = 0.0f;
		vertex_buffer_data3[9 * i + 2] = 0.0f;

		vertex_buffer_data3[9 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 5] = 0.0f;

		theta -= deg;
		vertex_buffer_data3[9 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 8] = 0.0f;
	}
    this->object = create3DObject(GL_TRIANGLES, 3 * 2, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 3 * 2, vertex_buffer_data2, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3 * N, vertex_buffer_data3, color, GL_FILL);
}

void Magnet::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}

void Magnet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Magnet::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}


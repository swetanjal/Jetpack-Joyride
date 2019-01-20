#define GLM_ENABLE_EXPERIMENTAL
#include "coin.h"
#include "main.h"

Coin::Coin(float x, float y, color_t color, float r) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = r;
    speed = 1;
    const int N = 100;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	float pi = 22 * 1.0f / 7;
	static GLfloat vertex_buffer_data[3 * 3 * N];
	for(int i = 0; i < N; ++i){
		vertex_buffer_data[9 * i] = 0.0f;
		vertex_buffer_data[9 * i + 1] = 0.0f;
		vertex_buffer_data[9 * i + 2] = 0.0f;

		vertex_buffer_data[9 * i + 3] = this->radius * cos(theta * pi / 180);
		vertex_buffer_data[9 * i + 4] = this->radius * sin(theta * pi / 180);
		vertex_buffer_data[9 * i + 5] = 0.0f;

		theta += deg;
		vertex_buffer_data[9 * i + 6] = this->radius * cos(theta * pi / 180);
		vertex_buffer_data[9 * i + 7] = this->radius * sin(theta * pi / 180);
		vertex_buffer_data[9 * i + 8] = 0.0f;
	}
    this->object = create3DObject(GL_TRIANGLES, 3 * 3 * N, vertex_buffer_data, color, GL_FILL);
}

void Coin::draw(glm::mat4 VP) {
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

void Coin::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Coin::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}


#define GLM_ENABLE_EXPERIMENTAL
#include "lives.h"
#include "main.h"

Lives::Lives(float x, float y, color_t color) {
    float pi = 3.141;
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = 0.3;
    this->dist = 0.4;
    this->x1 = x;
    this->y1 = y;
    this->x2 = x + 0.4;
    this->y2 = y;
    this->speed_x = 0.03;
    this->speed_y = -0.05;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	
	static GLfloat vertex_buffer_data[3 * 3 * N + 3 * 3 * N + 3];
	for(int i = 0; i < N; ++i){
		vertex_buffer_data[9 * i] = 0.0f;
		vertex_buffer_data[9 * i + 1] = 0.0f;
		vertex_buffer_data[9 * i + 2] = 0.0f;

		vertex_buffer_data[9 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 5] = 0.0f;

		theta += deg;
		vertex_buffer_data[9 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 8] = 0.0f;
	}
    for(int i = 0; i < N; ++i){
		vertex_buffer_data[9 * N + 9 * i] = this->dist + 0.0f;
		vertex_buffer_data[9 * N + 9 * i + 1] = 0.0f;
		vertex_buffer_data[9 * N + 9 * i + 2] = 0.0f;

		vertex_buffer_data[9 * N + 9 * i + 3] = this->dist + this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * N + 9 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * N + 9 * i + 5] = 0.0f;

		theta += deg;
		vertex_buffer_data[9 * N + 9 * i + 6] = this->dist + this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * N + 9 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * N + 9 * i + 8] = 0.0f;
	}
    vertex_buffer_data[18 * N] = this->radius * -1.0f + 0.059; vertex_buffer_data[18 * N + 1] = -0.2f; vertex_buffer_data[18 * N + 2] = 0.0f;
    vertex_buffer_data[18 * N + 3] = this->radius + this->dist - 0.059;  vertex_buffer_data[18 * N + 4] = -0.2f; vertex_buffer_data[18 * N + 5] = 0.0f;
    vertex_buffer_data[18 * N + 6] = this->dist / 2; vertex_buffer_data[18 * N + 7] = (2 * radius) * -1.0f; vertex_buffer_data[18 * N + 8] = 0.0f;

    this->object = create3DObject(GL_TRIANGLES, 3 * N + 3 * N + 3, vertex_buffer_data, color, GL_FILL);
}

void Lives::draw(glm::mat4 VP) {
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

void Lives::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Lives::tick() {
    //this->rotation += speed;
    this->position.x -= this->speed_x;
    this->speed_y += 0.001;
    this->position.y -= this->speed_y;
    this->x1 -= this->speed_x;
    this->y1 -= this->speed_y;
    this->x2 -= this->speed_x;
    this->y2 -= this->speed_y;
}


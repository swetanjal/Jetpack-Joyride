#define GLM_ENABLE_EXPERIMENTAL
#include "enemy1.h"
#include "main.h"

Enemy1::Enemy1(float x, float y, color_t color) {
    float pi = 3.141;
    this->position = glm::vec3(x, y, 0);
    this->rotation = rand() % 45 + 5;
    if(rand() % 2)
        this->rotation *= -1.0f;
    this->radius = 0.2;
    this->dist = 2;
    this -> delta = 0.05;
    this->x1 = x;
    this->y1 = y;
    this->x2 = x + this->dist * cos(this->rotation * pi * 1.0f / 180);
    this->y2 = y + this->dist * sin(this->rotation * pi * 1.0f / 180);
    speed = 1;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	
	static GLfloat vertex_buffer_data[3 * 3 * N + 3 * 3 * N + 2 * 9];
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
    vertex_buffer_data[18 * N] = this->radius * 1.0f; vertex_buffer_data[18 * N + 1] = 0.0f; vertex_buffer_data[18 * N + 2] = 0.0f;
    vertex_buffer_data[18 * N + 3] = this->radius * 1.0f;  vertex_buffer_data[18 * N + 4] = this->delta * 1.0f; vertex_buffer_data[18 * N + 5] = 0.0f;
    vertex_buffer_data[18 * N + 6] = this->radius + (this->dist - 2 * this->radius); vertex_buffer_data[18 * N + 7] = this->delta * 1.0f; vertex_buffer_data[18 * N + 8] = 0.0f;

    vertex_buffer_data[18 * N + 9] = this->radius + (this->dist - 2 * this->radius); vertex_buffer_data[18 * N + 10] = this->delta * 1.0f; vertex_buffer_data[18 * N + 11] = 0.0f;
    vertex_buffer_data[18 * N + 12] = this->radius + (this->dist - 2 * this->radius);  vertex_buffer_data[18 * N + 13] = 0.0f; vertex_buffer_data[18 * N + 14] = 0.0f;
    vertex_buffer_data[18 * N + 15] = this->radius * 1.0f; vertex_buffer_data[18 * N + 16] = 0.0f; vertex_buffer_data[18 * N + 17] = 0.0f;
    this->object = create3DObject(GL_TRIANGLES, 3 * 2 * N + 3 * 2, vertex_buffer_data, color, GL_FILL);
}

void Enemy1::draw(glm::mat4 VP) {
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

void Enemy1::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Enemy1::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}


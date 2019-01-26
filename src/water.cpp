#define GLM_ENABLE_EXPERIMENTAL
#include "water.h"
#include "main.h"

Water::Water(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->radius = 0.15;
    this->speedx = 0.0f;
    this->speedy = 0.0f;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	float pi = 3.141;
	static GLfloat vertex_buffer_data[N][3 * 3 * N];
	for(int i = 0; i < N; ++i){
		vertex_buffer_data[i][0] = 0.0f;
		vertex_buffer_data[i][1] = 0.0f;
		vertex_buffer_data[i][2] = 0.0f;

		vertex_buffer_data[i][3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[i][4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[i][5] = 0.0f;

		theta += deg;
		vertex_buffer_data[i][6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[i][7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[i][8] = 0.0f;
	}
    for(int i = 0; i < N; ++i){
        if((i % 90) <= 45)
            this->object[i] = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data[i], COLOR_LIGHT_BLUE, GL_FILL);
        else
            this->object[i] = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data[i], COLOR_LIGHT_BLUE, GL_FILL);
    }
}

void Water::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(int i = 0; i < 360 ; ++i)
    draw3DObject(this->object[i]);
}

void Water::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Water::tick() {
    this->rotation += 1.5;
    if(this->rotation >= 360)
        this->rotation -= 360;
    this->position.x += this->speedx;
    this->position.y += this->speedy;
    // this->position.y -= speed;
}


#define GLM_ENABLE_EXPERIMENTAL
#include "shield.h"
#include "main.h"

Shield::Shield(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed_x = 0.03;
    this->speed_y = -0.05;
    speed = 1;
    this->radius = 0.4;
    speed = 1;
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
        if((i % 23) <= 10)
            this->object[i] = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data[i], COLOR_BLACK, GL_FILL);
        else
            this->object[i] = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data[i], COLOR_BACKGROUND, GL_FILL);
    }
}

void Shield::draw(glm::mat4 VP) {
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

void Shield::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Shield::tick() {
    //this->rotation += speed;
    this->rotation += 1;
    if(this->rotation > 360)
        this->rotation = this->rotation - 360;
    this->position.x -= this->speed_x;
    this->speed_y += 0.001;
    this->position.y -= this->speed_y;
    // this->position.x -= speed;
    // this->position.y -= speed;
}


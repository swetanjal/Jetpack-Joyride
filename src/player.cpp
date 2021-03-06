#define GLM_ENABLE_EXPERIMENTAL
#include "player.h"
#include "ring.h"
#include "main.h"
#include "global.h"
#include "iostream"
Player::Player(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed = 0;
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

    this->radius = 0.2;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	float pi = 3.141;
	static GLfloat vertex_buffer_data2[3 * 3 * N];
	for(int i = 0; i < N; ++i){
		vertex_buffer_data2[9 * i] = (this->breadth / 2) + 0.0f;
		vertex_buffer_data2[9 * i + 1] = -(this->length / 3) + 0.0f;
		vertex_buffer_data2[9 * i + 2] = 0.0f;

		vertex_buffer_data2[9 * i + 3] = (this->breadth / 2) + this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 4] = -(this->length / 3) + this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 5] = 0.0f;

		theta += deg;
		vertex_buffer_data2[9 * i + 6] = (this->breadth / 2) + this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 7] = -(this->length / 3) + this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 8] = 0.0f;
	}
    static const GLfloat vertex_buffer_data3[] = {
        0.0f, -this->length, 0.0f, // triangle 1 : begin
        this->breadth, -this->length, 0.0f,
        this->breadth / 2, -this->length / 2, 0.0f, // triangle 1 : end
    };

    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, COLOR_BLUE, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, COLOR_MAGENTA, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, N*3, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data3, COLOR_SKIN, GL_FILL);
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
    if(protect == 0)
        draw3DObject(this->object);
    else
        draw3DObject(this->object1);
    if(life > 0){
        draw3DObject(this->object2);
    }
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}

void Player::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

bool Player::detect_collision_with_ground(){
    if(ground.position.y >= this->position.y - this->length){
        this->position.y = ground.position.y + this->length;
        return true;
    }
    return false;
}

float dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int Player::insideRing(Ring r){
    Point p = {this->position.x, this->position.y};
    Point q = {r.position.x, r.position.y};
    int fl = 0;
    if(dist(p, q) <= r.radius && p.y >= q.y){
        fl += 1;
    }
    p = {this->position.x + this->breadth, this->position.y};
    if(dist(p, q) <= r.radius && p.y >= q.y){
        fl += 1;
    }
    return fl;
}

void Player::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    for(int i = 0; i < magnets.size(); ++i){
        if(abs(magnets[i].position.x - this->position.x) <= 0.5)
        {
            if(magnets[i].position.y > player.position.y)
                player.position.y += 0.1;
            if(magnets[i].position.y < player.position.y)
                player.position.y -= 0.1;
            //magnets.erase(magnets.begin() + i);
            //i = i - 1;
            return;
        }
    }
    int inside = 0;
    for(int i = 0; i < ring.size(); ++i)
    {
        if(insideRing(ring[i]) == 2){
            float tmp = 0.01;
            this->speed = 0.0f;
            this->position.y += tmp;
            return;
        }
        if(insideRing(ring[i]) == 1 && abs(this->position.y - ring[i].position.y) <= 0.08)
        {
            this->speed = 0.0f;
            return;
        }
    }
    if(detect_collision_with_ground() == false){
        this->speed -= 0.001;
    }
    this->position.y += this->speed;
}


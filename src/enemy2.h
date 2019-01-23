#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef ENEMY2_H
#define ENEMY2_H


class Enemy2 {
public:
    Enemy2() {}
    Enemy2(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float radius;
    float delta;
    float dist;
    float x1;
    float y1;
    float x2;
    float y2;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // BALL_H

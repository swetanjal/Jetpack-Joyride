#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef LIVES_H
#define LIVES_H


class Lives {
public:
    Lives() {}
    Lives(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float dist;
    float radius;
    float x1;
    float y1;
    float x2;
    float y2;
    float speed_x;
    float speed_y;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // BALL_H

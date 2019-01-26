#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef WATER_H
#define WATER_H


class Water {
public:
    Water() {}
    Water(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float radius;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speedx;
    double speedy;
private:
    VAO *object[360];
};

#endif // BALL_H

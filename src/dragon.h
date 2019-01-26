#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef DRAGON_H
#define DRAGON_H


class Dragon {
public:
    Dragon() {}
    Dragon(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float length;
    float breadth;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    int timer;
private:
    VAO *object;
};

#endif // BALL_H

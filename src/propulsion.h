#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef PROPULSION_H
#define PROPULSION_H


class Propulsion {
public:
    Propulsion() {}
    Propulsion(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float length;
    float delta;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    float speed;
private:
    VAO *object;
};

#endif // BALL_H

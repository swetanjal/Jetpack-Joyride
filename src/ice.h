#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef ICE_H
#define ICE_H


class Ice {
public:
    Ice() {}
    Ice(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float radius;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object[360];
};

#endif // BALL_H

#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef SHIELD_H
#define SHIELD_H


class Shield {
public:
    Shield() {}
    Shield(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float radius;
    float speed_x, speed_y;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object[360];
};

#endif // BALL_H

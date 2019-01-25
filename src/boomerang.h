#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef BOOMERANG_H
#define BOOMERANG_H


class Boomerang {
public:
    Boomerang() {}
    Boomerang(float x, float y, color_t color);
    glm::vec3 position;
    float rotation1;
    float rotation2;
    float rotation3;
    Point p1, p2, p3, p4, q1, q2, q3, q4;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    double speed_x;
    double speed_y;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H

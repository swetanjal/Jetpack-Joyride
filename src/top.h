#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef TOP_H
#define TOP_H


class Top {
public:
    Top() {}
    Top(float x, float y, color_t color, float l, float b);
    glm::vec3 position;
    float length;
    float breadth;
    float rotation;
    double speed;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
private:
    VAO *object;
};

#endif // GROUND_H

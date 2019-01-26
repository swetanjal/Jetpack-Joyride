#include "main.h"
#include "ring.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
    Player() {}
    Player(float x, float y, color_t color);
    glm::vec3 position;
    float length;
    float breadth;
    float rotation;
    float radius;
    void draw(glm::mat4 VP);
    bool detect_collision_with_ground();
    int insideRing(Ring r);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif // PLAYER_H

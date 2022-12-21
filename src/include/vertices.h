#ifndef __VERTICES_H__
#define __VERTICES_H__
#include <glplayground.h>

const float vertices_tri[] = {
    -0.5f, -0.5f, 0.0f,  // left
     0.5f, -0.5f, 0.0f,  // right
     0.0f,  0.5f, 0.0f   // top
};

const float vertices_rect[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};

const unsigned int indices[] = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  

GLuint initVertexArray();
void loadVertexData(const float vertices[], size_t verticesSize);
void loadElementData();

#endif // __VERTICES_H__
#ifndef __SHADERS_H__
#define __SHADERS_H__
#include <glplayground.h>

const char* const vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main() {\n"
    "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* const fragmentShaderSource = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

GLuint createVertexShader();
int compileVertexShader(GLuint vertexShader);

GLuint createFragmentShader();
int compileFragmentShader(GLuint fragmentShader);

GLuint createShaderProgram();
int linkShaderProgram(GLuint program, GLuint vertexShader, GLuint fragmentShader);

void deleteShader(GLuint shader);

int checkShaderCompileStatus(GLuint shader, const char *msgType);
int checkProgramLinkStatus(GLuint program);

#endif // __SHADERS_H__
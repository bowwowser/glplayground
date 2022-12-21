#include <shaders.h>
#include <iostream>

GLuint createVertexShader() {
    // Bind a vertex shader
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    return vertexShader;
}

int compileVertexShader(GLuint vertexShader) {
    // Attach & compile shader source
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    return checkShaderCompileStatus(vertexShader, "VERTEX");
}

GLuint createFragmentShader() {
    // Bind a fragment shader
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    return fragmentShader;
}

int compileFragmentShader(GLuint fragmentShader) {
    // Attach & compile shader source
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    return checkShaderCompileStatus(fragmentShader, "FRAGMENT");
}

GLuint createShaderProgram() {
    // Bind a shader program
    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    return shaderProgram;
}

int linkShaderProgram(GLuint program, GLuint vertexShader, GLuint fragmentShader) {
    // Attach & link vertex & fragment shaders
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    return checkProgramLinkStatus(program);
}

void deleteShader(GLuint shader) {
    glDeleteShader(shader);
}

int checkShaderCompileStatus(GLuint shader, const char* msgType) {
    int  success;
    char infoLog[512];
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << msgType << "::COMPILATION_FAILED\n" << std::endl;
    }
    return success;
}

int checkProgramLinkStatus(GLuint program) {
    int  success;
    char infoLog[512];
    
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << std::endl;
    }
    return success;
}

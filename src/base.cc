#include <iostream>
#include <glplayground.h>
#include <shaders.h>
#include <vertices.h>

// Prototypes
void processInput(GLFWwindow* window);
void setWindowColour();
GLuint compileShaderProgram();

void error_callback(int, const char* err_str);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);  

bool initGLFW();
bool initGLAD();


GLFWwindow* createWindow();
GLFWwindow* createWindow() {
    // Create window 
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Playground", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create a window\n";
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

int main() {    
    if (!initGLFW()) {
        return -1;
    }
    GLFWwindow *window = createWindow();
    if (window == NULL) {
        return -1;
    }
    if (!initGLAD()) {
        return -1;
    }

    glViewport(0, 0, 800, 600);

    // Initializers
    GLuint shaderProgram = compileShaderProgram();
    if (shaderProgram == -1) {
        glfwTerminate();
        return -1;
    }
    GLuint VAO = initVertexArray();
    loadVertexData(vertices_rect, sizeof(vertices_rect));
    // loadElementData();

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        setWindowColour();

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // bind every time for organization
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

bool initGLFW() {
    int ret = glfwInit();
    if (GL_FALSE == ret)
    {
        std::cerr << "GLFW Error!\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    // glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    return true;
}

bool initGLAD() {
    // Init GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    return true;
}

GLuint compileShaderProgram() {
    GLuint vertexShader = createVertexShader();
    if (!compileVertexShader(vertexShader)) {
        return -1;
    }

    GLuint fragmentShader = createFragmentShader();
    if (!compileFragmentShader(fragmentShader)) {
        return -1;
    }

    GLuint shaderProgram = createShaderProgram();
    if (!linkShaderProgram(shaderProgram, vertexShader, fragmentShader)) {
        return -1;
    }

    deleteShader(vertexShader);
    deleteShader(fragmentShader);

    return shaderProgram;
}

void setWindowColour() {
    glClearColor(0.1f, 0.6f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

// Prototype definitions
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void error_callback(int, const char* err_str) {
    std::cout << "GLFW Error: " << err_str << std::endl;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    } else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
}
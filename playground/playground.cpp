#include "playground.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <cmath>

using namespace std;

static GLuint CompileShader(const string& source, GLuint type)
{
  GLuint id = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(id, 1, &src, 0);
  glCompileShader(id);

  return id;
}

static GLuint CreateShader(const string& vertexShader, const string& fragmentShader)
{
  GLuint shaderProgram = glCreateProgram();

  GLuint vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
  GLuint fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);
  glAttachShader(shaderProgram, vs);
  glAttachShader(shaderProgram, fs);
  glLinkProgram(shaderProgram);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return shaderProgram;
}



int main(int argc, char *argv[])
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
  GLFWwindow* win = glfwCreateWindow(800, 800, "Test", 0, 0);
  if (win == nullptr)
  {
    throw std::exception();
  }
  glfwMakeContextCurrent(win);
  if (glewInit() != GLEW_OK)
  {
  }
  glGetError();
  // TODO put shaders into a separate file
  string vertexShader =
    "#version 430 core\n"
    "\n"
    "layout(location = 0) in vec2 position;\n"
    "\n"
    "layout(location = 1) in vec3 aColor;\n"
    "\n"
    "out vec3 ourColor;"
    "\n"
    "uniform float xOffset;"
    "\n"
    "void main()\n"
    "{\n"
    " gl_Position = vec4(position.x + xOffset, position.y, 0.0, 1.0);\n"
    " ourColor = aColor;\n"
    "}\n";

  string fragmentShader =
    "#version 430 core\n"
    "\n"
    "out vec4 color;"
    "\n"
    "in vec3 ourColor;"
    "\n"
    "void main()\n"
    "{\n"
    " color = vec4(ourColor, 1.0f);\n"
    "}\n";

  string fragmentShader2 =
    "#version 430 core\n"
    "\n"
    "out vec4 color;"
    "\n"
    "in vec3 ourColor;"
    "\n"
    "void main()\n"
    "{\n"
    " color = vec4(ourColor, 1.0f);\n"
    "}\n";


  float triangle[] = {
    -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.3f, 0.5f, 0.4f
  };
  GLuint indices[] = {
    0, 1, 2,
    0, 2, 3
  };


  GLuint vao, vbo;
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 20, triangle, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(2 * sizeof(float)));

  GLuint ebo;
  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * 6, indices, GL_STATIC_DRAW);


  GLuint shader = CreateShader(vertexShader, fragmentShader);


  while (!glfwWindowShouldClose(win)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader);
    //float time = glfwGetTime();
    //float greenValue = sin(time) / 2.0f + 0.5f;
    //int location = glGetUniformLocation(shader, "our");
    //glUniform4f(location, 0.0f, greenValue, 0.0f, 1.0f);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);


    glfwSwapBuffers(win);
    glfwPollEvents();

  }
  glfwTerminate();
  return 0;
}
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm.h"
#include <FreeImage.h> //*** Para Textura: Incluir librería

class Dibujar
{
private:
    GLMmodel* modelo;           // Modelo 3D cargado
    cwc::glShader* shader;      // Shader utilizado para el modelo
    GLuint textura;             // Textura aplicada al modelo

public:
    // Constructor para inicializar el modelo, el shader y la textura
    Dibujar(char* rutaModelo, cwc::glShader* shaderProgram, GLuint idTextura);

    // Método para dibujar el modelo en una posición específica
    void dibujar(float posX, float posY, float posZ);
};




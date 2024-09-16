#include "Dibujar.h"

Dibujar::Dibujar(char* rutaModelo, cwc::glShader* shaderProgram, GLuint idTextura) : shader(shaderProgram), textura(idTextura) {

    this->modelo = glmReadOBJ(rutaModelo);
    if (!this->modelo) {
        exit(0); // Si no se puede cargar el modelo, salir de la aplicaci�n
    }

    // Preparar el modelo
    glmUnitize(this->modelo);
    glmFacetNormals(this->modelo);
    glmVertexNormals(this->modelo, 90.0);
}

void Dibujar::dibujar(float posX, float posY, float posZ)
{
    if (this->shader) this->shader->begin(); // Activar el shader si est� disponible
    glPushMatrix(); // Guardar el estado actual de la matriz

    glTranslatef(posX, posY, posZ); // Transladar el modelo a la posici�n especificada

    if (this->textura != -1) {
        glBindTexture(GL_TEXTURE_2D, this->textura); // Aplicar la textura si est� disponible
    }

    // Dibujar el modelo
    glmDraw(this->modelo, GLM_SMOOTH | GLM_MATERIAL | ((this->textura != -1) ? GLM_TEXTURE : 0));

    glPopMatrix(); // Restaurar el estado de la matriz
    if (this->shader) this->shader->end(); // Desactivar el shader si estaba activado
}
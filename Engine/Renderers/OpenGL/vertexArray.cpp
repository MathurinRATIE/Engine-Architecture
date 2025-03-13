#include "vertexArray.h"
#include <glew.h>

VertexArray::VertexArray(const float* pVertices, unsigned int pVerticeCount) :
    mVerticeCount(pVerticeCount), mVertexArrayId(0), mVertexBufferId(0)
{
    //Generate VAO
    glGenVertexArrays(1, &mVertexArrayId);
    glBindVertexArray(mVertexArrayId);

    //Generate VBO
    glGenBuffers(1, &mVertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, mVerticeCount * 8 * sizeof(float), pVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 6));
}

VertexArray::~VertexArray()
{
    glDeleteBuffers(1, &mVertexBufferId);
    glDeleteBuffers(1, &mVertexArrayId);
}

void VertexArray::SetActive()
{
    glBindVertexArray(mVertexArrayId);
}

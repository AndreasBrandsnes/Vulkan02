#include "VkTriangle.h"
#include "vertex.h"
#include "opg1.h"
#include "opg2.h"
#include "opg3.h"

VkTriangle::VkTriangle() : VisualObject() {
    // Y up, front = CCW
    //          X,      Y,      Z,      R,      G,      B,      U,      V
    /*
    Vertex v1 ( -1.0f,  0.0f,   0.0f,   1.0f,   0.0f,   0.0f,   0.0f,   0.0f);
    Vertex v2 (  1.0f,  0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   0.0f,   0.0f);
    Vertex v3 (  0.0f,  1.0f,   0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   0.0f);
    Vertex v4 (  1.0f,  1.0f,   0.0f,   1.0f,   1.0f,   0.0f,   0.0f,   0.0f);



    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
    mVertices.push_back(v3);
    mVertices.push_back(v2);
    mVertices.push_back(v4);*/


    //mVertices = genVertices1();
    //mVertices = genVertices2();
    mVertices = genVertices3(); //change RendererWindow.cpp 281 "topology" to line_list
}

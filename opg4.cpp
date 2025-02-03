#include <stdlib.h>
#include "opg4.h"
#include "vertex.h"
#include <vector>

std::vector<Vertex> genVertices4(){

    std::vector<Vertex> vertices;
    float cubeSize = 3.0f;
    float side_x = 3.0f, side_y = 3.0f;

    //floor abcd
    Vertex a(0,0,0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Vertex b(side_x,0,0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Vertex c(0,side_x, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Vertex d(side_x, side_x,0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    //front side abef
    //Vertex a(0,0,0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    //Vertex b(0,0,0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Vertex e(0,0,side_x, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Vertex f(side_x,0,side_x, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    //side side bcfh
    Vertex g(0,side_x,side_x, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Vertex h(side_x,side_x,side_x, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    //Floor
    vertices.push_back(a);
    vertices.push_back(b);
    vertices.push_back(c);

    vertices.push_back(b);
    vertices.push_back(c);
    vertices.push_back(d);

    //Roof
    vertices.push_back(e);
    vertices.push_back(f);
    vertices.push_back(g);

    vertices.push_back(f);
    vertices.push_back(g);
    vertices.push_back(h);

    //Front
    vertices.push_back(a);
    vertices.push_back(b);
    vertices.push_back(e);

    vertices.push_back(e);
    vertices.push_back(f);
    vertices.push_back(b);

    //Back
    vertices.push_back(c);
    vertices.push_back(d);
    vertices.push_back(g);

    vertices.push_back(g);
    vertices.push_back(h);
    vertices.push_back(d);

    //Side, right
    vertices.push_back(b);
    vertices.push_back(d);
    vertices.push_back(f);

    vertices.push_back(f);
    vertices.push_back(h);
    vertices.push_back(d);

    //Side, left
    vertices.push_back(a);
    vertices.push_back(c);
    vertices.push_back(g);

    vertices.push_back(g);
    vertices.push_back(e);
    vertices.push_back(a);

    // write file
    FILE* dataFile = fopen("data3.txt", "w+");

    fprintf(dataFile, "%s%zu\n", "#", vertices.size());

    for (const Vertex& v : vertices)
    {
        fprintf(dataFile, "%f %f %f %f %f %f%s", v.x, v.y, v.z, v.r, v.g, v.b, "\n");
    }

    fclose(dataFile);

    return vertices;

}

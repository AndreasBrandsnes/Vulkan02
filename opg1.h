#ifndef OPG1_H
#define OPG1_H

#include <vector>
#include "vertex.h"

struct Df{
    float a, b;
};

double f(const double x);


double df(double x);

std::vector<Vertex> genVertices();


#endif // OPG1_H

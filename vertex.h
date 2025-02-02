#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <fstream>

struct Vertex {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float u;
    float v;

    Vertex(float x_, float y_, float z_, float r_, float g_, float b_, float u_ = 0, float v_ = 0)
    {
        x = x_;
        y = y_;
        z = z_;
        r = r_;
        g = g_;
        b = b_;
        u = u_;
        v = v_;
    }

    // !Overloaded ostream operator which writes all vertex data on an open textfile stream
    friend std::ostream& operator<<(std::ostream&, const Vertex&);

    // !Overloaded ostream operator which writes all vertex data on an open textfile stream
    friend std::istream& operator>> (std::istream, const Vertex&);

};

/*
class vertex
{
public:
    vertex();
};
*/

#endif // VERTEX_H

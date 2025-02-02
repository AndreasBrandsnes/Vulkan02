#include "opg3.h"


// Velg funksjonen av to variable som vi kaller apesadelen, f (x) = x2y, et passende
// område i xy-planet (eller xz-planet), og en oppdeling. Velg en oppløsning h (bruk
// en grov oppløsning til å begynne med) og regn ut funksjonsverdier over området, som på figur 2.2. Lag en tekstl med xyz (eventuelt også rgb og uv-koordinater)linjevis.
// Antall linjer skal stå øverst i fila

double f(const double x, const double y)
{
    // f(x, y) = x^2y
    return pow(x, 2*y);
}

std::vector<Vertex> genVertices3(){

    const float M_PI = 3.141593;

    std::vector<Vertex> vertices;

    float xmin=0.0f, xmax=1.0f, ymin=0.0f, ymax=1.0f, h=0.01f;

    for (auto x=xmin; x<xmax; x+=h)
    {
        for (auto y=ymin; y<ymax; y+=h)
        {
            //float z = sin(M_PI*x)*sin(M_PI*y);
            float z = f(x,y);
            vertices.push_back(Vertex{x,y,z,x,y,z});

            //z = sin(M_PI*(x+h))*sin(M_PI*y);
            z = f(x+h, y);
            vertices.push_back(Vertex{x+h,y,z,x,y,z});

            //z = sin(M_PI*x)*sin(M_PI*(y+h));
            z = f(x, y+h);
            vertices.push_back(Vertex{x,y+h,z,x,y,z});
            vertices.push_back(Vertex{x,y+h,z,x,y,z});

            //z = sin(M_PI*(x+h))*sin(M_PI*y);
            z = f(x+h, y);
            vertices.push_back(Vertex{x+h,y,z,x,y,z});

            //z = sin(M_PI*(x+h))*sin(M_PI*(y+h));
            z = f(x+h, y+h);
            vertices.push_back(Vertex{x+h,y+h,z,x,y,z});
        }
    }

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

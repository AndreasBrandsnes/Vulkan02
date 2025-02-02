#include <stdlib.h>
#include "opg1.h"
#include "vertex.h"
#include <vector>


double f(const double x)
{
    return (x*x*x)-(6*x*x)+(11*x)-6;
}

double df(double x)
{
    return (3*x*x)-(12*x) + 11;
}



std::vector<Vertex> genVertices()
{
    // Velg en egen funksjon f (x) og en passende denisjonsmengde Df = [a, b].

    Df d_f = Df{-1000,1000};

    // Velg antall intervaller n slik at du får n + 1 punkter x0, x1, . . . , xn og oppløsning h = ∆x = (b−a)/n
    int n = 10000;
    float h = (d_f.b - d_f.a) / n;

    // Regn ut funksjonsverdier f (xi) i hvert punkt. Regn også ut f ′(x) eller
    // Newton's diverenskvotient i hvert punkt.

    double x = d_f.a;

    float green, red;

    std::vector<Vertex> vertices;

    for (unsigned int i = 0; i < n+1; i++)
    {
        if (df(x) > 0.0)
        {
            green = 1.0;
            red = 0.0;
        }
        else
        {
            green = 0.0;
            red = 1.0;
        }


        // Beregn funksjonsverdi og skriv ut verteksdata for hvert punkt på en tekstfil.
        // På første linje i len skal antall punkter stå. Deretter følger verteksdata
        // for hvert punkt linje for linje.

        vertices.push_back(Vertex(x, f(x), 0.0f, red, green, 0.0f));

        x+=h;
    }


    // write file
    FILE* dataFile = fopen("data.txt", "w+");

    fprintf(dataFile, "%s%zu\n", "#", vertices.size());

    for (const Vertex& v : vertices)
    {
        fprintf(dataFile, "%f %f %f %f %f %f%s", v.x, v.y, v.z, v.r, v.g, v.b, "\n");
    }

    fclose(dataFile);

    return vertices;
}

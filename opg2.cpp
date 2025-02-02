#include <stdlib.h>
#include "opg2.h"
#include "vertex.h"
#include <vector>

std::vector<Vertex> genVertices2()
{


    //Lag en fil med datapunkter for en tredimensjonal spiral, som forklart i forelesningsnotater 2.4
    // Bestem selv en steglengde for parameteren t og verteksfarger.
    // Benytt samme filformat som i forrige oppgave 1

    float n = (2 * 3.141519) *5;

    float x = 0.0f;
    float y = 0.0f;

    float radius = 1.0f;
    float height = 0.0f;

    float step = 0.1f;

    std::vector<Vertex> vertices;

    for (float i = 0; i < n; i+= step)
    {
        x = radius - cos(i);
        y = radius - sin(i);

        height += 0.05;

        // Beregn funksjonsverdi og skriv ut verteksdata for hvert punkt på en tekstfil.
        // På første linje i len skal antall punkter stå. Deretter følger verteksdata
        // for hvert punkt linje for linje.

        vertices.push_back(Vertex(x, y, height, 1, 1, 0.0f));
    }


    // write file
    FILE* dataFile = fopen("data2.txt", "w+");

    fprintf(dataFile, "%s%zu\n", "#", vertices.size());

    for (const Vertex& v : vertices)
    {
        fprintf(dataFile, "%f %f %f %f %f %f%s", v.x, v.y, v.z, v.r, v.g, v.b, "\n");
    }

    fclose(dataFile);

    return vertices;
}

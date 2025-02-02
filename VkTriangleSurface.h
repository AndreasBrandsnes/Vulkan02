#ifndef VKTRIANGLESURFACE_H
#define VKTRIANGLESURFACE_H

#include <vector>
#include <string>
#include "vertex.h"
#include "visualobject.h"


class VkTriangleSurface : public VisualObject
{
public:
    // std::vector<Vertex> mVertecies;
    // std::vector<Vertex> getVertecies() {return mVertices;}
    VkTriangleSurface();
    VkTriangleSurface(const std::string& filename);
};

#endif // VKTRIANGLESURFACE_H

#ifndef MODEL_H
#define MODEL_H 4

#include <vector>
#include "vector.h"

class OBJParser;

class Model {
public:
    class Mesh;
private:
    //public:
    Model();
    friend class OBJParser;
    std::vector<Mesh> meshes;
public:
    virtual ~Model();
    const std::vector<Mesh>& getMeshes();
};

class Model::Mesh {
public:
    class Face;
private:
//public:
    Mesh();
    friend class OBJParser;
    std::vector<Vector3> vertices;
    std::vector<Vector3> normals;
    std::vector<Vector2> UVs;
    std::vector<Face> faces;
public:
    virtual ~Mesh();
    void draw() const;
};

class Model::Mesh::Face {
private:
//public:
    Face();
    friend class OBJParser;
    friend class Model::Mesh;
    unsigned int vertexIndices[3];
    unsigned int normalIndices[3];
    unsigned int UVIndices[3];
public:
    virtual ~Face();
};

#endif //MODEL_H

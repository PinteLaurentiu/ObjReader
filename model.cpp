#include "model.h"

Model::Model() {}

Model::~Model() {}

Model::Mesh::Mesh() {}

Model::Mesh::~Mesh() {}

const std::vector<Model::Mesh>& Model::getMeshes() {
    return meshes;
}

void Model::Mesh::draw() const {}

Model::Mesh::Face::Face() {}

Model::Mesh::Face::~Face() {}

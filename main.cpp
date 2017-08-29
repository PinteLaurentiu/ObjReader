
#include <iostream>
#include "vector.h"
#include "file_data.h"
#include "obj_parser.h"
using namespace std;

int main() {

    FileData fd("untitled.obj");
    OBJParser o(fd);
    Model m = o.parse();
    for (const Model::Mesh& m : m.getMeshes()) {

    }
    return 0;
}

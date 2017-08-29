#include "obj_parser.h"
#include <string>
#include <sstream>

OBJParser::OBJParser(const FileData& fd) {
    create(fd);
}

OBJParser::OBJParser(const char* fn) {
    try {
        FileData fd(fn);
        create(fd);
    }
    catch (FileData::Exception& ex) {
        throw ex; //todo change ex type
    }
}

OBJParser::~OBJParser() {

}

void OBJParser::create(const FileData& file) {
    fileData = file;
}

void OBJParser::parseLine(const std::string& line) {
    std::istringstream ss(line);
    std::string s;
    ss >> s;
    if (s == "#")
        return;
    if (s == "")
        return;
    if (s == "o") {
        md.meshes.push_back(Model::Mesh());
        return;
    }
    if (s == "v") {
        std::string vertexData;
        std::getline(ss, vertexData);
        parseVertex(vertexData);
        return;
    }
    if (s == "vt") {
        std::string UVData;
        std::getline(ss, UVData);
        parseUV(UVData);
        return;
    }
    if (s == "vn") {
        std::string NormalData;
        std::getline(ss, NormalData);
        parseNormal(NormalData);
        return;
    }
    if (s == "s") {
        //TODO:
        return;
    }
    if (s == "f") {
        std::string FaceData;
        std::getline(ss, FaceData);
        parseFace(FaceData);
        return;
    }
    throw 1;
}

void OBJParser::parseVertex(const std::string& line) {
    std::istringstream ss(line);
    float x,y,z;
    ss >> x;
    ss >> y;
    ss >> z;
    if (!ss)
        return;
    md.meshes.back().vertices.push_back(Vector3(x,y,z));
}

void OBJParser::parseUV(const std::string& line) {
    std::istringstream ss(line);
    float x,y;
    ss >> x;
    ss >> y;
    if (!ss)
        return;
    md.meshes.back().UVs.push_back(Vector2(x,y));
}

void OBJParser::parseNormal(const std::string& line) {
    std::istringstream ss(line);
    float x,y,z;
    ss >> x;
    ss >> y;
    ss >> z;
    if (!ss)
        return;
    md.meshes.back().normals.push_back(Vector3(x,y,z));
}

void OBJParser::parseFace(const std::string& line) {
    std::istringstream ss(line);
    std::string sv[3];
    ss >> sv[0];
    ss >> sv[1];
    ss >> sv[2];
    if (!ss)
        return;
    Model::Mesh::Face f;
    std::istringstream ssv[] = {std::istringstream(sv[0]),
                                std::istringstream(sv[1]),
                                std::istringstream(sv[2])};
    for (int i = 0; i < 3; i++) {
        ssv[i] >> f.vertexIndices[i];
        if (!ssv[i])
            return;

        if (ssv[i].peek() != '/')
            continue;
        ssv[i].ignore();

        if (ssv[i].peek() != '/') {
            ssv[i] >> f.UVIndices[i];
            if (!ssv[i])
                return;
        }

        if (ssv[i].peek() != '/')
            continue;
        ssv[i].ignore();

        ssv[i] >> f.normalIndices[i];
        if (!ssv[i])
            return;
    }
    md.meshes.back().faces.push_back(f);
}

Model OBJParser::parse() {
    std::istringstream ss((char*)fileData.getData());
    while (ss) {
        std::string s;
        std::getline(ss, s);
        parseLine(s);
    }
    return md;
}

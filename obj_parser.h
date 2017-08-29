#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H 4

#include "model.h"
#include "file_data.h"
#include <string>

class OBJParser {
private:
    void create(const FileData& file);
    void parseLine(const std::string& line);
    void parseVertex(const std::string& line);
    void parseUV(const std::string& line);
    void parseNormal(const std::string& line);
    void parseFace(const std::string& line);
    FileData fileData;
    Model md;
public:
    OBJParser(const FileData& file);
    OBJParser(const char* filename);
    virtual ~OBJParser();
    Model parse();
};

#endif //OBJ_PARSER_H

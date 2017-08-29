#include "file_data.h"
#include <fstream>

FileData::FileData() : size(0), data(nullptr) {}

FileData::FileData(const std::string& path) : size(0), data(nullptr) {
    if (path.empty())
        throw Exception("Invalid path!");

    std::ifstream f(path, std::ios::in | std::ios::binary | std::ios::ate);

    if (!f)
        throw Exception(std::string("File <") +
                        path +
                        "> could not be opened!");

    size = (Size)f.tellg();
    f.seekg(0, f.beg);
    data = new Byte[size];
    f.read((char*)data, size);
    f.close();
}

FileData& FileData::operator=(const FileData& fd) {
    if (data)
        delete[] data;
    size = fd.size;
    data = new Byte[size];
    Byte* current = data;
    Byte* end = fd.data + fd.size;
    for (Byte* begin = fd.data; begin != end; begin++)
    {
        *current = *begin;
        current++;
    }
    return *this;
}

FileData::FileData(Byte* data, Size size) : size(size),  data(data) {}

FileData::FileData(const FileData& fd) : size(fd.size) {
    data = new Byte[size];
    Byte* current = data;
    Byte* end = fd.data + fd.size;
    for (Byte* begin = fd.data; begin != end; begin++)
    {
        *current = *begin;
        current++;
    }
}

FileData::~FileData() {
    if (data) {
        delete[] data;
    }
    data = nullptr;
    size = 0;
}

void FileData::writeToFile(const std::string& path) {
    if (path.empty())
        throw Exception("Invalid path!");
    std::ofstream f(path, std::ios::out | std::ios::binary);
    if (!f)
        throw Exception(std::string("File <") + path + "> could not be opened!");
    f.write((char*)data, size);
    if (!f)
        throw Exception(std::string("File <") + path + "> could not be opened!");
    f.close();
    return;
}

Size FileData::getSize() const {
    return size;
}

Byte* FileData::getData() {
    return data;
}

const Byte* FileData::getData() const {
    return data;
}

FileData::Exception::Exception(const std::string& error) : error(error) {}

FileData::Exception::~Exception() {}

const char* FileData::Exception::what() const throw() {
    return error.c_str();
}

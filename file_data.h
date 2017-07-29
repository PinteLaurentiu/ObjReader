#ifndef FILE_DATA_H
#define FILE_DATA_H

#include <string>
#include <exception>

typedef unsigned char Byte;
typedef unsigned long Size;

class FileData {
public:
    class Exception;
    FileData();
    FileData(const std::string&);
    FileData(Byte* data, Size dataLength);
    FileData(const FileData&);
    FileData& operator=(const FileData&);
    ~FileData();
    void writeToFile(const std::string& path = "");
    Size getSize() const;
    Byte* getData();
    const Byte* getData() const;
private:
    Size size;
    Byte* data;
};

class FileData::Exception : public std::exception {
public:
    Exception(const std::string& error);
    ~Exception();
    const char* what() const throw() override;
private:
    std::string error;
};

#endif //FILE_DATA_H

#pragma once

#include <string>
#include <filesystem>
#include <fstream>

class FileManagerCore {
private:
    std::filesystem::path currentPath;

public:
    bool isValid(const std::filesystem::path&) const;

    bool isFolder(const std::filesystem::path&) const;

    void changePath(const std::string&);

    void appendPath(const std::string&);

    FileManagerCore();

    FileManagerCore(const std::string&);

    std::string getPath() const;

    std::string getFileContent(const std::string&) const;

    std::filesystem::directory_iterator getFolderContent() const;

    void createFile(const std::string&) const;

    void createFolder(const std::string&) const;

    void remove(const std::string&) const;

};

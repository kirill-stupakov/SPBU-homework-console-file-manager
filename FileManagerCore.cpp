#include "FileManagerCore.h"

bool FileManagerCore::isValid(const std::filesystem::path& path) const {
    return std::filesystem::exists(path);
}

bool FileManagerCore::isFolder(const std::filesystem::path &path) const {
    return std::filesystem::is_directory(path);
}

void FileManagerCore::changePath(const std::string& path) {
    const std::filesystem::path newPath = path;
    if (isValid(newPath) && isFolder(newPath)) {
        currentPath = newPath;
    } else {
        throw std::runtime_error("This folder does not exist!");
    }
}

void FileManagerCore::appendPath(const std::string& path) {
    changePath(currentPath / path);
}

FileManagerCore::FileManagerCore() {
    currentPath = std::filesystem::current_path();
}

FileManagerCore::FileManagerCore(const std::string& path) {
    changePath(path);
}

std::string FileManagerCore::getPath() const {
    return currentPath;
}

std::filesystem::directory_iterator FileManagerCore::getFolderContent() const {
    return std::filesystem::directory_iterator(currentPath);
}

void FileManagerCore::createFile(const std::string &name) const {
    if (isValid(currentPath / name)) {
        throw std::runtime_error("This file already exists!");
    } else {
        std::ofstream file(currentPath / name);
        file.close();
    }
}

void FileManagerCore::createFolder(const std::string &name) const {
    if (!std::filesystem::create_directory(currentPath / name)) {
        throw std::runtime_error("Can't create folder!");
    }
}

void FileManagerCore::remove(const std::string &name) const {
    if (isValid(currentPath / name)) {
        std::filesystem::remove_all(currentPath / name);
    } else {
        throw std::runtime_error("This file doesn't exist!");
    }
}

std::string FileManagerCore::getFileContent(const std::string &name) const {
    if (isValid(currentPath / name)) {
        std::ifstream file(currentPath / name);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    } else {
        throw std::runtime_error("This file doesn't exist!");
    }
}

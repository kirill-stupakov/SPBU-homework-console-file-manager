#pragma once

#include <string>
#include <functional>

class FileManagerOption {
public:
    std::string label;
    std::function<void()> action;
    FileManagerOption(std::string, std::function<void()>);
};

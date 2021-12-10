#include "FileManagerOption.h"

FileManagerOption::FileManagerOption(std::string label, std::function<void()> action) : label(label), action(action) {}

#include "ConsoleFileManager.h"

ConsoleFileManager::ConsoleFileManager() {
    options.emplace_back("Change path", changeFolder);
    options.emplace_back("List content", listContent);
    options.emplace_back("Create folder", createFolder);
    options.emplace_back("Create file", createFile);
    options.emplace_back("Remove", remove);
    options.emplace_back("Show file content", showFileContent);
    options.emplace_back("Exit", exit);
}

ConsoleFileManager::ConsoleFileManager(const std::string &path) : ConsoleFileManager() {
    fileManager.changePath(path);
}

std::string ConsoleFileManager::userInput(std::string alert) {
    std::cout << alert << ": ";
    std::string input;
    std::cin >> input;
    return input;
}

void ConsoleFileManager::changeFolder() {
    std::string newPath = userInput("Destination");
    try {
        fileManager.changePath(newPath);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void ConsoleFileManager::listContent() {
    const auto content = fileManager.getFolderContent();
    for (const auto& file: content) {
        std::cout << "[" << (file.is_directory() ? "DIR" : "FIL") << "] ";
        std::cout << file.path().filename() << "\n";
    }
}

void ConsoleFileManager::createFolder() {
    std::string name = userInput("Folder name");
    try {
        fileManager.createFolder(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void ConsoleFileManager::createFile() {
    std::string name = userInput("File name");
    try {
        fileManager.createFile(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void ConsoleFileManager::remove() {
    std::string name = userInput("Name");
    try {
        fileManager.remove(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void ConsoleFileManager::showFileContent() {
    std::string name = userInput("Name");
    try {
        std::cout << fileManager.getFileContent(name);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void ConsoleFileManager::exit() {
    shouldExit = true;
}

void ConsoleFileManager::renderCurrentPath() const {
    std::cout << "Current path: " << fileManager.getPath() << "\n";
}

void ConsoleFileManager::renderOptions() const {
    int counter = 1;
    for (const auto &option: options) {
        std::cout << "[" << counter << "] " << option.label << "\n";
        counter++;
    }
}


void ConsoleFileManager::chooseOption() {
    int option = std::stoi(userInput("Choose option"));
    while (option < 1 || option > options.size()) {
        option = std::stoi(userInput("Wrong option. Please, try again"));
    }
    selectedOption = option - 1;
}

void ConsoleFileManager::executeOption() {
    options[selectedOption].action();
}

void ConsoleFileManager::drawSeparator() {
    std::cout << "\n";
    for (int i = 0; i < 70; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void ConsoleFileManager::start() {
    while (!shouldExit) {
        drawSeparator();
        renderCurrentPath();
        renderOptions();
        chooseOption();
        executeOption();
    }
}


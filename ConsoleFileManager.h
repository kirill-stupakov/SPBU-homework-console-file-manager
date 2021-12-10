#pragma once

#include "FileManagerCore.h"
#include "FileManagerOption.h"
#include <iostream>
#include <vector>

class ConsoleFileManager {
private:
    inline static FileManagerCore fileManager;
    int selectedOption = 1;
    inline static bool shouldExit = false;

    static std::string userInput(const char *);

    static void changeFolder();
    static void listContent();
    static void createFolder();
    static void createFile();
    static void remove();
    static void showFileContent();
    static void exit();

    std::vector<FileManagerOption> options;

    void renderCurrentPath() const;

    void renderOptions() const;

    void chooseOption();

    void executeOption();

    static void drawSeparator();

public:
    ConsoleFileManager();

    explicit ConsoleFileManager(const std::string&);

    void start();
};

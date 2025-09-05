#include <iostream>
#include <fstream>
#include <limits>
#include <filesystem>

void OPEN(const std::string& filename) {
    std::string name = filename + ".txt";
    std::ifstream file(name);

    if(!file.is_open()) {
        std::cerr << "Failed to open:" << name << std::endl;
        return;
    }

    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }

}

void WRITE(const std::string& filename) {
    std::string name = filename + ".txt";
    std::ofstream file(name);

    if(!file.is_open()) {
        std::cerr << "Failed to open:" << name << std::endl;
        return;
    }
    
    std::string str;
    std::getline(std::cin, str);

    file.write(str.c_str(), str.size());
}

namespace fs = std::filesystem;

void DELETE(const std::string& filename) {
    std::string name = filename + ".txt";

    if(fs::exists(name)) {
        fs::remove(name);
        std::cout << "File deleted:" << name << std::endl;
    } else {
        std::cout << "File does not exist" << std::endl;
    }
}

int main() {
    int choice;
    std::string filename;
    while(true) {
        std::cout << "[1] open [2] write [3] delete [4] exit" << std::endl << "> ";

        while(!(std::cin >> choice)) {
            std::cout << "Invalid input. Please try again" << std::endl << "> ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(choice == 1) {
            std::cout << "File name : ";
            std::getline(std::cin, filename);
            OPEN(filename);
        } else if(choice == 2) {
            std::cout << "File name : ";
            std::getline(std::cin, filename);

            WRITE(filename);
        } else if(choice == 3) {
            std::cout << "File name : ";
            std::getline(std::cin, filename);

            DELETE(filename);
        } else if(choice == 4) {
            break;
        }
        else {
            std::cout << "Invaild input" << std::endl;
        }
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

std::ifstream file;

int find(std::string);

int main(int argc, char **argv)
{
    std::ofstream out_file("output.txt");

    if (2 == argc) {

        if (!std::strcmp(argv[1], "--help")) {
            std::cout << "Pass 3 arguments:\n[filename] - name of the file to look in\n"
                      << "[word] - word to look for in file\n"
                      << "[count] - count of \"word\" in file]\n";
            return 0;
        }
    } else if (argc != 4) {
        std::cerr << "Command line arguments count must be 3!\nPass [--help] to see more.\n";
        exit(1);
    }
    int count = atoi(argv[3]);

    if (0 == count) {
        std::cerr << "Count must not be zero!\n";
        exit(2);
    }
    char *file_name = argv[1];
    char *word = argv[2];
    file.open(file_name);

    if (count == find(word)) {
        out_file << word << ' ' << count << std::endl;
        //std::clog << "test succesfully passed!\n";
    } else {
        //std::clog << "test faild.\n";
        out_file << "test faild" << std::endl;
    }

    return 0;
}

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>
#include <string>
#include <vector>
#include "./generation.hpp"
#include "./parser.hpp"
#include "./tokenization.hpp"
using namespace std;

const string RESET = "\033[0m";
const string ERROR = "\033[31m";
const string GREEN = "\033[32m";
const string GREY = "\033[90m";
const string BLUE = "\033[34m";
const string PINK = "\033[95m";

bool hasExtension(const string& filename) {
    // Check if the file name ends with ".cal"
    const string extension = ".cal";
    if (filename.length() >= extension.length()) {
        return (0 == filename.compare(filename.length() - extension.length(), extension.length(), extension));
    }
    return false;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << ERROR << "[Improper Compile]" << endl;
    cerr << ERROR << "Usage: " << argv[0] << " <input.cal>" << endl;
    exit(EXIT_FAILURE);
  }

  
  string filename = argv[1];

      if (!hasExtension(filename)) {
          cerr << ERROR << "[Invalid file]" << endl;
          cerr << PINK << "Usage: " << argv[0] << " <input.cal>" << endl;
          exit(EXIT_FAILURE);
          // Handle the error accordingly
      }

    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();

    Parser parser(std::move(tokens));
    std::optional<NodeProg> prog = parser.parse_prog();

    if (!prog.has_value()) {
        std::cerr << "Invalid program" << std::endl;
        exit(EXIT_FAILURE);
    }

    Generator generator(prog.value());
    {
        std::fstream file("out.asm", std::ios::out);
        file << generator.gen_prog();
    }

    system("nasm -felf64 out.asm");
    system("ld -o out out.o");

    cout << GREEN << "Compiled successfully.." << endl;
    cout << BLUE << "Executable ./out is ready." << endl;
    

    return EXIT_SUCCESS;
}

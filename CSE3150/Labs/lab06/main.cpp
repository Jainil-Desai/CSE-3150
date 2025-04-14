#include "tokenizer.h"
#include <iostream>

int main() {
    Tokenizer tokenizer; 

    try {
        tokenizer.load_file("the-verdict.txt"); 
        tokenizer.print_all_tokens(); 

        std::string query;

        std::cout <<"Please enter a word to find its token: (or 'exit' to quit)" << std::endl;
        while(std::cin >> query && query != "exit") {
            int token = tokenizer.get_token(query); 
            if(token != -1) {
                std::cout << "Token for '" << query << "' is: " << token << std::endl; 
            } else {
                std::cout << "Word not found!" << std::endl; 
            }
            std::cout <<"\n Please enter a word to find its token: (or 'exit' to quit)" << std::endl;
        }
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl; 
    }

    return 0;
}
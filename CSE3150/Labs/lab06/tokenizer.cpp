#include "tokenizer.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <iostream>

Tokenizer::Tokenizer() : nextToken(1) {}

void Tokenizer::load_file(const std::string& filename) { 
    std::ifstream file(filename); 
    if(!file) { 
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf(); 
    std::string text = buffer.str();


    std::regex word_regex("\\b\\w+\\b"); 

    std::sregex_iterator begin(text.begin(), text.end(), word_regex), end;
    
    for(auto it = begin; it != end; it++) {
        std::string word = it->str(); 
        if(word2Token.find(word) == word2Token.end()) { 
            word2Token[word] = nextToken; 
            token2Word[nextToken] = word;
            nextToken++;
        }
    }
}

int Tokenizer::get_token(const std::string& word) {
    auto it = word2Token.find(word); 
    if(it != word2Token.end()) { 
        return it->second; 
    }
    return -1;
}

std::string Tokenizer::get_word(int token) { 
    auto it = token2Word.find(token); 
    if(it != token2Word.end()) {
        return it->second; 
    }
    return "";
}

void Tokenizer::print_all_tokens() {
    for(const auto& pair : word2Token) { 
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

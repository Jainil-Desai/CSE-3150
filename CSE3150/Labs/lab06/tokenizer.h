#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>

class Tokenizer {
    private:
        std::unordered_map<std::string, int> word2Token;
        std::unordered_map<int, std::string> token2Word;
        int nextToken;

public:
    Tokenizer();

    void load_file(const std::string& filename); 
    int get_token(const std::string& word); 
    std::string get_word(int token); 
    void print_all_tokens();
};

#endif

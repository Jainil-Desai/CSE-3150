#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tokenizer.h"
#include <cassert>
#include <iostream>

TEST_CASE("Tokenizer basic functionality") {
    Tokenizer tokenizer;

    tokenizer.load_file("the-verdict.txt");

    SUBCASE("Token exists for common words") {
        CHECK(tokenizer.get_token("the") != -1);
        CHECK(tokenizer.get_token("exquisitely") != -1);
    }

    SUBCASE("Token does not exist for gibberish") {
        CHECK(tokenizer.get_token("qwertyasdf") == -1);
    }

    SUBCASE("Reverse lookup returns correct word") {
        int token_for_the = tokenizer.get_token("the");
        if (token_for_the != -1) {
            CHECK(tokenizer.get_word(token_for_the) == "the");
        }
    }
}

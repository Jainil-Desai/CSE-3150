#ifndef NFT_H
#define NFT_H

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <vector>
#include <memory>

class NFToken{
    private:
        std::string asset;
        std::string hash_val;

    public:
        NFToken(const std::string& asset_name, const std::string& hash_value );

        std::string get_asset();
        std::string get_hash();

};

class NFT_wallet{
    public:
        using Wallet = std::vector<std::unique_ptr<NFToken>>;

        static std::unique_ptr<NFToken> minting(const std::string& asset);

        static void NFTtransfer(Wallet& source, Wallet& destination, size_t index);

        static std::string compute_sha(const std::string& input);
};

#endif
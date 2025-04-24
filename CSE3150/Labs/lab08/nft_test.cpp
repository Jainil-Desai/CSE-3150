#include "doctest.h"
#include "nft.h"
#include <iostream>

TEST_CASE("Functions test")
{
    NFT_wallet::Wallet wallet1;
    NFT_wallet::Wallet wallet2;

    auto token1 = NFT_wallet::minting("jainil");
    auto token2 = NFT_wallet::minting("desai");

    std::string hash1 = token1->get_hash();
    std::string hash2 = token2->get_hash();


    wallet1.push_back(std::move(token1));
    wallet1.push_back(std::move(token2));
    
    CHECK(wallet1.size() == 2);
    CHECK(wallet2.size() == 0);

    NFT_wallet::NFTtransfer(wallet1, wallet2, 0);
    CHECK(wallet1.size() == 1);
    CHECK(wallet2.size() == 1);

    CHECK(wallet2[0]->get_hash() == hash1 );


}
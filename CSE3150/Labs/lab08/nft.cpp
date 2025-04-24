#include "nft.h"
#include <chrono>

NFToken::NFToken(const std::string& asset_name, const std::string& hash_value ): asset(asset_name), hash_val(hash_value){}

std::string NFToken::get_asset()
{
    return asset;
}

std::string NFToken::get_hash()
{
    return hash_val;
}

std::string NFT_wallet::compute_sha(const std::string& input)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);

    std::ostringstream oss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++ ) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return oss.str();
}

void NFT_wallet::NFTtransfer(Wallet& source, Wallet& destination, size_t index)
{
    if(index < source.size()) {
        destination.push_back(std::move(source[index]));
        source.erase(source.begin() + index);
    }
}

std::unique_ptr<NFToken> NFT_wallet::minting(const std::string& asset)
{
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::string input_new = asset + std::to_string(now);

    std::string input_hash = compute_sha(input_new);

    return std::make_unique<NFToken>(asset, input_hash);

}
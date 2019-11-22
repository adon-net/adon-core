// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>

namespace Crypto {


struct Hash
{
    bool operator==(const Hash &other) const
    {
        return std::equal(std::begin(data), std::end(data), std::begin(other.data));
    }

    bool operator!=(const Hash &other) const
    {
        return !(*this == other);
    }

    uint8_t data[32];
};

struct PublicKey
{
    bool operator==(const PublicKey &other) const
    {
        return std::equal(std::begin(data), std::end(data), std::begin(other.data));
    }

    bool operator!=(const PublicKey &other) const
    {
        return !(*this == other);
    }

    uint8_t data[32];
};

struct SecretKey
{
    bool operator==(const SecretKey &other) const
    {
        return std::equal(std::begin(data), std::end(data), std::begin(other.data));
    }
    
    bool operator!=(const SecretKey &other) const
    {
        return !(*this == other);
    }

    uint8_t data[32];
};

struct KeyDerivation
{
    bool operator==(const KeyDerivation &other) const
    {
        return std::equal(std::begin(data), std::end(data), std::begin(other.data));
    }

    bool operator!=(const KeyDerivation &other) const
    {
        return !(*this == other);
    }

    uint8_t data[32];
};

struct KeyImage
{
    bool operator==(const KeyImage &other) const
    {
        return std::equal(std::begin(data), std::end(data), std::begin(other.data));
    }

    bool operator!=(const KeyImage &other) const
    {
        return !(*this == other);
    }

    uint8_t data[32];
};

struct Signature
{
    bool operator==(const Signature &other) const
    {
        return std::equal(std::begin(data), std::end(data), std::begin(other.data));
    }

    bool operator!=(const Signature &other) const
    {
        return !(*this == other);
    }

    uint8_t data[64];
};


}

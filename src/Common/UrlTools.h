// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <stdint.h>
#include <string>

namespace Common {

bool parseUrlAddress(const std::string& url, std::string& host, uint16_t& port, std::string& path, bool& ssl);

}

// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2018, The TurtleCoin Developers
// Please see the included LICENSE file for more information.

#pragma once

#include <Config/AsciiArt.h>
#include <CryptoNoteConfig.h>
#include <sstream>
#include <version.h>

namespace CryptoNote
{
    inline std::string getProjectCLIHeader()
    {
        std::stringstream programHeader;
        programHeader
            << std::endl << asciiArt << std::endl
            << " " << CryptoNote::CRYPTONOTE_NAME << " v" << PROJECT_VERSION_LONG << std::endl;

        return programHeader.str();
    }
} // namespace CryptoNote
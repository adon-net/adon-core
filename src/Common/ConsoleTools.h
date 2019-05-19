// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdint>

#pragma once

namespace Common { namespace Console {

enum class Color : uint8_t {
  Default,

  Blue,
  Green,
  Red,
  Yellow,
  White,
  Cyan,
  Magenta,

  BrightBlue,
  BrightGreen,
  BrightRed,
  BrightYellow,
  BrightWhite,
  BrightCyan,
  BrightMagenta
};

void setTextColor(Color color);
bool isConsoleTty();

}}

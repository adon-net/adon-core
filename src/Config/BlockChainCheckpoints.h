// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote
{
    struct CheckpointData
    {
        uint32_t height;
        const char *blockId;
    };

    // You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  {   5000, "f6ecfb7fd0527cf7baf51e6626cc921fa6db73403d9e33f2e8c78465926c3d0b" },
  {  10000, "fe3cee2b2853395a19c3d4c9f15e5e354460f8e6e868313c9539016985498780" },
  {  20000, "5c2bc247683f369d6aca1ddb1407e0d38f3cfda22d712f66acaac246514fa88e" },
  {  30000, "2bbdf4349ae1a94d3178b4fa36f1fa8bb35caa518300a8f0be3a52ed4f057f22" },
  {  40000, "8b70c42d72e9e4d36737d4c7d12fa3151db15426b6b20fc0c7aa112b2f53a095" },
  {  50000, "42c5bc70a7aeeade1ec9853ab55c34a26e16bbe49c5fa3fa366c8a3a1258f6d7" },
  {  60000, "9055e1a362c9711761cbcceb8c5d6fc993f896a9ec9e254807824462320dd782" },
  {  65000, "1eaade74fee6f70821dee24260ef0deb67a0d9ba1dd58de4c8c6d09621894371" },
  {  70000, "2f98f5b14df2d6c8c72fcc86ddcbaeee56c02475c0037ac1feca727e40f39d58" },
  {  75000, "89072402a6df5bcbcb371aa134d2398c8cf39383b7cb52fb070896bfe8e4032b" },
  {  80000, "0ce43923733968f955fc5f711e7832bb01602ad3265bf0bb0e57ce286df52147" },
  {  85000, "3f4afe4f61881e0964d27a90da13184c3b468c552be101b03d3c8affdb0a27d7" },
  {  90000, "2ca13ebc203a45e55e03bf3219902a17dfadbbfa404825a21409034d273481ad" },
  {  95000, "9cc046be2697115366370eaa4c3b225bc2e62a18ed2f2d250da12ec0ee6de00d" },
  { 100000, "5bd8e3329aa0dbae36163cfb42f5b99fb82aaed5b90fb64138b714bed94c767f" },
  { 105000, "28f303d23d0068d86fc4a56e13fb9c7aac4d8a656ede189044f8fc2984556421" },
  { 110000, "d303269c5138e604b4cdbfae801c78d341c47801c964376688cf2c2c1def2115" },
  { 115000, "4b4bbe730f1918adb703796f4956dd94d61d779a4323200d6cffd3c7f7ffcc42" },
  { 120000, "223fbc9587668fc446156f29d1e8d2bc3edf77425017c1ae1c0da8d06e874da7" },
  { 125000, "6b33303f16920ac2f0509c75fea2554faf7be684a2c0e957fe8be12a720fc2d0" },
  { 130000, "d2b92bdbde612414689c9628afcb4d80af42f39cb86738ea01e9818d1df13566" }
};

} // namespace CryptoNote

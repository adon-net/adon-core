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
  {  15000, "dfd89f7f13273364642c21db613e299cdb70d58b3cca0e990a47b2a4c71b50e8" },
  {  20000, "5c2bc247683f369d6aca1ddb1407e0d38f3cfda22d712f66acaac246514fa88e" },
  {  25000, "8d01c39e778d5bb101dbe01773f5c5d4d0330968d06b907111aba6bfa001287e" },
  {  30000, "2bbdf4349ae1a94d3178b4fa36f1fa8bb35caa518300a8f0be3a52ed4f057f22" },
  {  35000, "507a49614b81e0424a619c87d121d527525b6eea6fbcf06778e73784fabaff31" },
  {  40000, "8b70c42d72e9e4d36737d4c7d12fa3151db15426b6b20fc0c7aa112b2f53a095" },
  {  45000, "b23ee60c888fb6adeb76c1f100a57d594d35288050776953162314dd6519a201" },
  {  50000, "42c5bc70a7aeeade1ec9853ab55c34a26e16bbe49c5fa3fa366c8a3a1258f6d7" },
  {  55000, "d538806531bd8047a697b374e6cb7a6a38aa3bf366fc2105b21b08ce3f9f9a9d" },
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
  { 130000, "d2b92bdbde612414689c9628afcb4d80af42f39cb86738ea01e9818d1df13566" },
  { 135000, "f9fa4b68881836eb5fd3ec412f361c6b5f2d30ded5a537c946ae4db4738cea7b" },
  { 140000, "d3913158bebb7010694c6504bdd56c5eb7d494483dc5f20260ffdf5b4d2b509c" },
  { 145000, "e5e4174f16f6fc94ff1a47f04f2cc58b6d4f94a422189a2d4b56a2a44b5501fa" },
  { 150000, "666017c96c440980ce53ddc036e23b8cf32aef3e09d574cdbacfbf566894d091" },
  { 155000, "0002f647428f1b7f70eb9a9721aa972f31d1f3d6f39f961461ddc7fc3c610e51" },
  { 160000, "45d8d1c90c50c87e5300e179a5da98ecc9c5cafd7906e4ff19453b6a4115ff1b" },
  { 165000, "56a471423f85e9ae106859c383b753aaea0af61f0c6762d2d1c854a099b9d94e" },
  { 170000, "65ef27ae906b8854646c0bcf2ab316b794ff550c73e59387469d7ba6cc53cc30" },
  { 175000, "90c558fba7d266850f58223b5e6c86998af88f227ad02e5aa410da83abc6f930" },
  { 180000, "842d744225e527c92daac791dd9cf06b8a680a155bbd62e21426945910e667f7" },
  { 185000, "3668219288d3f3989af92a94cb15760124c4c08259e611a27c273b5eb8c3ccbc" },
  { 190000, "3ba634fb0076769a1bbeafe6d44046503fc0712bf500ee5a92288af56df6932c" },
  { 195000, "6c5bb30d01e3428ee9e8720511fea8cfeb515f125460a5a2098ce596b28d1a70" },
  { 200000, "9c6c10b86fc1c82b79c5abdce6b2e3aeaea04a81adeaccb59b9c3df184951299" },
  { 205000, "e68cccf7b0d38e18038fc0e50e61e39af81d10a0515c49aa898d95fdf39121bb" },
  { 210000, "3b0cfd9bd12c9b2155a8282745aea790009912ad346cce632b2c1a335d937101" },
  { 215000, "5c5f36bf32abfa4cf2ba46bd8b11d64055a1503fe5d15ba8c28a9354c4051548" },
  { 220000, "49533685303281c16bd9d90e47b27afecf270d02ca6cf6e4d36e2bcaaf1bb30b" },
  { 225000, "cb1b9cdbde53ffd642af3b1faee244f3ced286c45d28cc9937956cc77ba69613" },
  { 230000, "91dd8168c13cb8513db2283f864d4c3f88a7f79c0696c0f219bcf970c943d38a" },
  { 235000, "2ec96f6f5fd53518ce56b403643ed2d2f215edd11112132652dc83de06856f67" },
  { 240000, "fe4f1a3239d41e2519b282a2ae402741699d4f07c655655abdab412d66d89405" },
  { 245000, "a4f28776ff61ce6b56d22f18bb7a3ff1ca25c40cb749cc6b3baef45defcd4a35" },
  { 250000, "9c17ca85df4233454d18dafbcb3543f3812a103a373f5f482497babf5926ee0e" },
  { 255000, "c35c4942d3b39dca261a06093fce2f59cc072f80cbaeb245e4bf5b6a4e911d0c" },
  { 260000, "70a56aca2b89aa07ca812658b1b52df38d3412f04d49de8fd550c04bea6e5d44" },
  { 265000, "5ce44f18ea58b0546fc2e28343e747e167961a954501e4db21326c42f3e14791" }
};

} // namespace CryptoNote

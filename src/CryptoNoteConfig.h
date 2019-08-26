// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdint>
#include <initializer_list>

#pragma once

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0xf0ec6; // addresses start with "aDon"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;

const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1				 = 360; /* changed for LWMA3 */

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1					 = 11; /* changed for LWMA3 */

const uint64_t MONEY_SUPPLY				                           = UINT64_C(18446744000000000);
const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(6456360400000000);
const unsigned EMISSION_SPEED_FACTOR_V1                      = 19;
const unsigned EMISSION_SPEED_FACTOR_V2                      = 20;
const unsigned EMISSION_SPEED_FACTOR_V3                      = 21;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 20000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;

const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
// COIN - number of smallest units in one coin
const uint64_t COIN                                          = UINT64_C(100000000);   // pow(10, 8)
const uint64_t MINIMUM_FEE                                   = UINT64_C(1000000);     // pow(10, 6)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(1000000);     // pow(10, 6)
const uint64_t MAX_TRANSACTION_SIZE_LIMIT                    = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT / 4 - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;
const uint64_t MIN_TX_MIXIN_SIZE                             = 3;
const uint64_t MAX_TX_MIXIN_SIZE                             = 12;

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 240; // blocks
const size_t   DIFFICULTY_WINDOW_V1													 = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2													 = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V3													 = 60; /* changed for LWMA3 */
const size_t   DIFFICULTY_BLOCKS_COUNT											 = DIFFICULTY_WINDOW_V3 + 1; /* added for LWMA3 */
const size_t   DIFFICULTY_CUT                                = 30;  // timestamps to cut after sorting
const size_t   DIFFICULTY_CUT_V1														 = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2														 = DIFFICULTY_CUT;

const size_t   DIFFICULTY_LAG                                = 15;
const size_t   DIFFICULTY_LAG_V1														 = DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2														 = DIFFICULTY_LAG;

static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

// const uint64_t POISSON_CHECK_TRIGGER                         = 10; // Reorg size that triggers poisson timestamp check
// const uint64_t POISSON_CHECK_DEPTH                           = 60;   // Main-chain depth of the poisson check. The attacker will have to tamper 50% of those blocks
// const double   POISSON_LOG_P_REJECT                          = -75.0; // Reject reorg if the probablity that the timestamps are genuine is below e^x, -75 = 10^-33

const uint64_t NUMBER_OF_BLOCKS_PER_DAY                      = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;

const uint64_t DEPOSIT_MIN_AMOUNT                            = 5000 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 1 * NUMBER_OF_BLOCKS_PER_DAY * 30;
const uint32_t DEPOSIT_MAX_TERM                              = 1 * 12 * DEPOSIT_MIN_TERM;
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0;
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 3;
const double   REMOTE_NODE_MIN_FEE                           = .0025;
const int64_t  REMOTE_NODE_MAX_FEE                           = COIN * 100;
static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 12); //seconds, 14 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); //seconds, one day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_V3                             = 2;
const uint32_t UPGRADE_HEIGHT_V4                             = 75000;
const uint32_t UPGRADE_HEIGHT_V5                             = 100000;
const uint32_t UPGRADE_HEIGHT_V6                             = 999999999;

const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "adon";
const char     CRYPTONOTE_TICKER[]                           = "ADON";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff000180a8bce1e880bc0b024d940423823cd51fa2351f38f0f999f1ad2e80350ae07944ab8f15728edac9352101a930bd071c6d28bb938e3224b272226c550bc4a381505db82d43b4e9e6140ba8";

const uint32_t GENESIS_NONCE                                 = 70;

const uint8_t  TRANSACTION_VERSION_1                         = 1;
const uint8_t  TRANSACTION_VERSION_2                         = 2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         = 1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         = 2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         = 3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         = 4;
const uint8_t  BLOCK_MAJOR_VERSION_5                         = 5;
const uint8_t  BLOCK_MAJOR_VERSION_6                         = 6;
const uint8_t  BLOCK_MINOR_VERSION_0                         = 0;
const uint8_t  BLOCK_MINOR_VERSION_1                         = 1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        = 10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            = 100;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         = 1000;

const int      P2P_DEFAULT_PORT                              = 19900;
const int      RPC_DEFAULT_PORT                              = 19901;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                = 2000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 = 8000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 256 * 1024 * 1024; // 256 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "0000000000000000000000000000000000000000000000000000000011111111";

const std::initializer_list<const char*> SEED_NODES = {
   "01.seed.adon.network:19900",
   "02.seed.adon.network:19900"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  {  5000, "f6ecfb7fd0527cf7baf51e6626cc921fa6db73403d9e33f2e8c78465926c3d0b" },
  { 10000, "fe3cee2b2853395a19c3d4c9f15e5e354460f8e6e868313c9539016985498780" },
  { 20000, "5c2bc247683f369d6aca1ddb1407e0d38f3cfda22d712f66acaac246514fa88e" },
  { 30000, "2bbdf4349ae1a94d3178b4fa36f1fa8bb35caa518300a8f0be3a52ed4f057f22" },
  { 40000, "8b70c42d72e9e4d36737d4c7d12fa3151db15426b6b20fc0c7aa112b2f53a095" },
  { 50000, "42c5bc70a7aeeade1ec9853ab55c34a26e16bbe49c5fa3fa366c8a3a1258f6d7" },
  { 60000, "9055e1a362c9711761cbcceb8c5d6fc993f896a9ec9e254807824462320dd782" },
  { 65000, "1eaade74fee6f70821dee24260ef0deb67a0d9ba1dd58de4c8c6d09621894371" }

};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS

// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#pragma once

#include <array>
#include <string>
#include <vector>

#include "CryptoTypes.h"
#include "CryptoNote.h"
#include "BlockchainExplorerData.h"
#include <boost/variant.hpp>

namespace CryptoNote {

struct TransactionOutputDetailsEx {
	TransactionOutput output;
	uint64_t globalIndex;
};

struct BaseInputDetails {
  BaseInput input;
  uint64_t amount;
};

struct KeyInputDetails {
  KeyInput input;
  uint64_t mixin;
  std::vector<TransactionOutputReferenceDetails> outputs;
};

struct MultisignatureInputDetails {
  MultisignatureInput input;
  TransactionOutputReferenceDetails output;
};

typedef boost::variant<BaseInputDetails, KeyInputDetails, MultisignatureInputDetails> transaction_input_details;

struct TransactionExtraDetailsEx {
  Crypto::PublicKey publicKey;
  BinaryArray nonce;
  BinaryArray raw;
};

struct TransactionDetailsEx {
  Crypto::Hash hash;
  uint64_t size = 0;
  uint64_t fee = 0;
  uint64_t totalInputsAmount = 0;
  uint64_t totalOutputsAmount = 0;
  uint64_t mixin = 0;
  uint64_t unlockTime = 0;
  uint64_t timestamp = 0;
  Crypto::Hash paymentId;
  bool hasPaymentId = false;
  bool inBlockchain = false;
  Crypto::Hash blockHash;
  uint32_t blockHeight = 0;
  TransactionExtraDetailsEx extra;
  std::vector<std::vector<Crypto::Signature>> signatures;
  std::vector<transaction_input_details> inputs;
  std::vector<TransactionOutputDetailsEx> outputs;
};

struct BlockDetailsEx {
  uint8_t majorVersion = 0;
  uint8_t minorVersion = 0;
  uint64_t timestamp = 0;
  Crypto::Hash prevBlockHash;
  uint32_t nonce = 0;
  bool isOrphaned = false;
  uint32_t height = 0;
  Crypto::Hash hash;
  uint64_t difficulty = 0;
  uint64_t reward = 0;
  uint64_t baseReward = 0;
  uint64_t blockSize = 0;
  uint64_t transactionsCumulativeSize = 0;
  uint64_t alreadyGeneratedCoins = 0;
  uint64_t alreadyGeneratedTransactions = 0;
  uint64_t sizeMedian = 0;
  double penalty = 0.0;
  uint64_t totalFeeAmount = 0;
  std::vector<TransactionDetailsEx> transactions;
};

}

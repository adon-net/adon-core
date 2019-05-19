// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2011-2016 The Cryptonote developers

#pragma once

#include "BlockchainExplorerData.h"
#include "BlockchainExplorerDataEx.h"

#include "Serialization/ISerializer.h"

namespace CryptoNote {

void serialize(TransactionOutputDetailsEx& output, ISerializer& serializer);
void serialize(TransactionOutputReferenceDetails& outputReference, ISerializer& serializer);

void serialize(BaseInputDetails& inputBase, ISerializer& serializer);
void serialize(KeyInputDetails& inputToKey, ISerializer& serializer);
void serialize(MultisignatureInputDetails& inputMultisig, ISerializer& serializer);
void serialize(transaction_input_details& input, ISerializer& serializer);

void serialize(TransactionExtraDetails& extra, ISerializer& serializer);
void serialize(TransactionExtraDetailsEx& extra, ISerializer& serializer);
//void serialize(TransactionDetails& transaction, ISerializer& serializer);
void serialize(TransactionDetailsEx& transaction, ISerializer& serializer);

//void serialize(BlockDetails& block, ISerializer& serializer);
void serialize(BlockDetailsEx& block, ISerializer& serializer);

} //namespace CryptoNote

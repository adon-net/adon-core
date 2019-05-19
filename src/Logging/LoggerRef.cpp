// Copyright (c) 2018-2019 Adon Network developers 
// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "LoggerRef.h"

namespace Logging {

LoggerRef::LoggerRef(ILogger& logger, const std::string& category) 
	: m_logger(&logger)
	, m_sCategory(category)
{}

LoggerMessage LoggerRef::operator()(Level level, const std::string& color) const
{
	return LoggerMessage(*m_logger, m_sCategory, level, color);
}

ILogger& LoggerRef::getLogger() const
{
	return *m_logger;
}

} //Logging

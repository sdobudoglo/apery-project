/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "log_manager.h"

ASharedPointer<LogManager>::type LogManager::m_log;

LogManager::LogManager(AString file_path, LogLevel level, bool flush_enable) : m_filePath(file_path)
  , m_level(level)
  , m_flushEnable(flush_enable)
{}

void LogManager::log(LogLevel level, AString msg)
{
    if (m_log.isNull())
    {
        //log data get from  settings
        m_log = ASharedPointer<LogManager>::type(new LogManager("log/front.txt", LogManager::Error, true));
    }

    if (level > m_log->m_level)
        return;

    //log ro file
    //m_log->writeLog(m_log->prepareLogMsg(msg));
}

void LogManager::writeLog(AString msg)
{
    AMutexLocker locker(this);
}

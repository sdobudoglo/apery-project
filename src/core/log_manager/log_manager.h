/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include "base_types.h"

class LogManager : public AMutex
{
public:
    enum LogLevel
    {
        Debug = 0,
        Information,
        Warning,
        Error,
        Fatal
    };

    static void log(LogLevel level, AString msg);

private:
    LogManager(AString file_path, LogLevel level = LogManager::Warning, bool flush_enable = true);
    AString prepareLogMsg(AString msg, LogLevel level);
    void writeLog(AString msg);

private:
    AString m_filePath;
    LogLevel m_level;
    bool m_flushEnable;

    static ASharedPointer<LogManager>::type m_log;
};

#endif /*LOG_MANAGER_H*/

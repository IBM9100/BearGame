-----------------------
---- Logging.lua
---- 日志打印
-----------------------


local LogLevel = {
    TRACE = 0,
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5
}

function LOG_TRACE(str)
    local fileName, line, funcName = getCallerInfo()
    CLog(fileName, line, funcName, LogLevel.TRACE, str)
end

function LOG_DEBUG(str)
    local fileName, line, funcName = getCallerInfo()
    CLog(fileName, line, funcName, LogLevel.DEBUG, str)
end

function LOG_INFO(str)
    local fileName, line, funcName = getCallerInfo()
    CLog(fileName, line, funcName, LogLevel.INFO, str)
end

function LOG_WARN(str)
    local fileName, line, funcName = getCallerInfo()
    CLog(fileName, line, funcName, LogLevel.WARN, str)
end

function LOG_ERROR(str)
    local fileName, line, funcName = getCallerInfo()
    CLog(fileName, line, funcName, LogLevel.ERROR, str)
end

function LOG_FATAL(str)
    local fileName, line, funcName = getCallerInfo()
    CLog(fileName, line, funcName, LogLevel.FATAL, str)
end

-- return fileName, line, funcName
function getCallerInfo(f)
    f = f or 3
    local tb = debug.getinfo(3)
    -- what: Lua, C, main
    if not tb or tb.what ~= "Lua" then
        return ""
    end
    local fileName = string.gsub(tb.source, "(.+)/(.+.lua)", "%2")
    return fileName, tb.currentline, tb.name
end
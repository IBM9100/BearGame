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

function TableToString(tb)
    local nSize = tb.n or 0;
    for i = 1, nSize do
        tb[i] = tostring(tb[i]) or ""; 
    end
    
    if #tb == 0 then
        return  "";
     end
     
    return string.format("[%s] %s", "GAME", tb);
end

function LOG_TRACE(str)
    local fileName, line, funcName = getCallerInfo()
    CLog(fileName, line, funcName, LogLevel.TRACE, str)
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
-----------------------
---- Boot.lua
---- 启动脚本
-----------------------

package.path = package.path .. ";" .. CGetWorkDir() .. "/BGScript/?.lua;"

-- require 如果找不到 则会直接 抛出异常
-- 使用这个函数 会比较安全
function RequireFile(fileName, isReload)
    isReload = isReload or false
    
    if isReload then
        package.loaded[fileName] = nil
    end
    local ok, err = xpcall(require, debug.traceback, fileName)
    if not ok then
        print(err .. tostring(fileName))
    end

end


function ReloadFile(fileName)
    package.loaded[fileName] = nil
    RequireFile(fileName, true)
end

function test()
    LOG_TRACE("Test the log.")
end
function main()
    math.randomseed(os.time())

    print("Welcome to the main function in lua.")

    RequireFile("log/Logging")
    test()
end
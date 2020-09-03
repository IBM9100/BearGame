-----------------------
---- main.lua
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


function RegisterModule(modules)
    local tbBase = { ModuleName = "__ModuleName"  }
    local tbMT = { __index = tbBase }
    local func = function(sz)
        assert(not _G[sz], string.format("Duplicated Table: %s", sz))
        if not _G[sz] then
            _G[sz] = setmetatable({ ModuleName = sz }, tbMT)
        end
    end
    
    local moduleType = type(modules)

    if moduleType == "string" then
        func(modules)
    elseif moduleType == "table" then
        for _, module in ipairs(modules) do
            func(module)
        end
    end
end


function ReloadFile(fileName)
    package.loaded[fileName] = nil
    RequireFile(fileName, true)
end


function ProtectGlobal()
    local tbMetaTable = {
        __newindex = function (tb, k, v)
            error("Attemp to create global value: " .. tostring(k), 2)
        end
    }
    setmetatable(_G, tbMetaTable)
end

function main()

    RequireFile("log/Logging")

    LOG_INFO("Welcome to the main function in lua.")
    math.randomseed(os.time())
    RequireFile("gm/GMCommand")

    ProtectGlobal()

end
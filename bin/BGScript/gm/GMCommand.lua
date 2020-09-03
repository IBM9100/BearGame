-----------------------
---- GMCommand.lua
---- GM指令
-----------------------

local GM = {}


function test()
    LOG_DEBUG("Welcom to GM")
    -- local b = "test"
    local func, err = load("333 b")
    if not func then
        LOG_DEBUG(string.format("Do [GMCmd]: %s failed.", err))
        return
    end

    -- local a = fncmd()
    -- print(fncmd())
end

test()
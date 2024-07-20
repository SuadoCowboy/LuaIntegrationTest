package.path = package.path .. ";../subjects/tst.lua"
local module = require("tst")

out = module.out
out.jamas = "JAMAS"
out.k = "k"
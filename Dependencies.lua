-- Ludus Depends

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Ludus/3rdparty/GLFW/include"

LibraryDir = {}

Library = {}

-- Windows depends
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"
#include <iostream>

#include <lua.hpp>

void setupLuaState(lua_State* L) {
    // Add a number variable
    lua_pushnumber(L, 42);
    lua_setglobal(L, "age");

    // Add a string variable
    lua_pushstring(L, "Suado Cowboy");
    lua_setglobal(L, "name");
}

int main(int argc, char** argv) {
	if (argc == 0) {
		std::cout << "ERROR: Missing path to file parameter." << std::endl;
		return 1;
	}

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	
	setupLuaState(L);

	if (luaL_dofile(L, argv[1]) != LUA_OK) {
        const char* error = lua_tostring(L, -1);
        std::cerr << "ERROR: " << error << std::endl;
        lua_pop(L, 1); // Remove error message from stack
    }

	lua_getglobal(L, "out");
	if (lua_type(L, -1) != LUA_TTABLE) {
		std::cout << "ERROR: Output table is nil." << std::endl;
		return 1;
	}

	lua_gettable(L, -1);
	lua_pushnil(L);

	while (lua_next(L, -2)) {
		const char* key = lua_tostring(L, -1);
		const char* value = lua_tostring(L, -2);
		
		std::cout << key << " = " << value << "\n";
		
		lua_pop(L, 1);
	}

	lua_pop(L, 1);
	lua_close(L);
}

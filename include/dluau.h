#pragma once
#ifdef DLUAU_LIB_EXPORT
#define DLUAU_API extern "C" __declspec(dllexport)
#else
#define DLUAU_API extern "C" __declspec(dllexport)
#endif
#define LUA_API DLUAU_API 
#define LUACODE_API DLUAU_API 
#define LUACODEGEN_API DLUAU_API 
#include "luau/luacode.h"
#include "luau/lualib.h"
#include "luau/luacodegen.h"
#include <stdint.h>
#include <stdbool.h>


typedef struct lua_State lua_State;
typedef struct luaL_Reg luaL_Reg;
DLUAU_API int dluau_newuserdatatag();
DLUAU_API int dluau_newlightuserdatatag();
DLUAU_API int dluau_gettagfromtname(const char* tname);
DLUAU_API int dluau_registertypetagged(const char* tname);
DLUAU_API bool dluau_istyperegistered(const char* tname);
DLUAU_API void dluau_registertype(const char* tname);
DLUAU_API int dluau_stringatom(lua_State* L, const char* key);
DLUAU_API int dluau_lstringatom(lua_State* L, const char* key, size_t len);
DLUAU_API lua_State* dluau_newstate();
struct dluau_RunOptions {
    const char* scripts;
    const char* args;
    const luaL_Reg* global_functions;
    int debug_level;
    int optimization_level;
};
DLUAU_API int dluau_run(const dluau_RunOptions* opts);
DLUAU_API void dluau_loadfuncs(lua_State* L);
DLUAU_API void dluau_openlibs(lua_State* L);
DLUAU_API void dluauopen_dlimport(lua_State* L);
DLUAU_API int dluauload_dlimport(lua_State* L);

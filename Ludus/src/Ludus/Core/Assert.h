#pragma once

#include "Ludus/Core/Base.h"
#include "Ludus/Core/Log.h"
#include <filesystem>

#ifdef LD_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define LD_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { LD##type##ERROR(msg, __VA_ARGS__); LD_DEBUGBREAK(); } }
#define LD_INTERNAL_ASSERT_WITH_MSG(type, check, ...) LD_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define LD_INTERNAL_ASSERT_NO_MSG(type, check) LD_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", LD_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define LD_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define LD_INTERNAL_ASSERT_GET_MACRO(...) LD_EXPAND_MACRO( LD_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, LD_INTERNAL_ASSERT_WITH_MSG, LD_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define LD_ASSERT(...) LD_EXPAND_MACRO( LD_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define LD_CORE_ASSERT(...) LD_EXPAND_MACRO( LD_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define LD_ASSERT(...)
#define LD_CORE_ASSERT(...)
#endif
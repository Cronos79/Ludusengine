#pragma once

#include "Ludus/Core/PlatformDetection.h"

#include <memory>

#ifdef LD_DEBUG
#if defined(LD_PLATFORM_WINDOWS)
#define LD_DEBUGBREAK() __debugbreak()
#elif defined(HZ_PLATFORM_LINUX)
#include <signal.h>
#define LD_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define LD_ENABLE_ASSERTS
#else
#define LD_DEBUGBREAK()
#endif

#define LD_EXPAND_MACRO(x) x
#define LD_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define LD_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Ludus {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Ludus/Core/Log.h"
#include "Ludus/Core/Assert.h"
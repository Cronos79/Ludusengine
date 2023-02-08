#pragma once

#include "Ludus/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Ludus {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define LD_CORE_TRACE(...)    ::Ludus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LD_CORE_INFO(...)     ::Ludus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LD_CORE_WARN(...)     ::Ludus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LD_CORE_ERROR(...)    ::Ludus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LD_CORE_CRITICAL(...) ::Ludus::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LD_TRACE(...)         ::Ludus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LD_INFO(...)          ::Ludus::Log::GetClientLogger()->info(__VA_ARGS__)
#define LD_WARN(...)          ::Ludus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LD_ERROR(...)         ::Ludus::Log::GetClientLogger()->error(__VA_ARGS__)
#define LD_CRITICAL(...)      ::Ludus::Log::GetClientLogger()->critical(__VA_ARGS__)
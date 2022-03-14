#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include "spdlog/fmt/ostr.h"

namespace GameEngine {
	class GAMEENGINE_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log Macros
#define GE_CORE_TRACE(...)  ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)   ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)   ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)  ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)  ::GameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log Macors
#define GE_CLIENT_TRACE(...)  ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CLIENT_INFO(...)   ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CLIENT_WARN(...)   ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CLIENT_ERROR(...)  ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CLIENT_FATAL(...)  ::GameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Dream {

	class DREAM_API Log
	{
	public:
		static void Init();

		inline static  std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static  std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define DM_CORE_FATAL(...)    ::Dream::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define DM_CORE_ERROR(...)    ::Dream::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DM_CORE_WARN(...)     ::Dream::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DM_CORE_INFO(...)     ::Dream::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DM_CORE_TRACE(...)    ::Dream::Log::GetCoreLogger()->trace(__VA_ARGS__)


//Client log macros
#define DM_FATAL(...)    ::Dream::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define DM_ERROR(...)    ::Dream::Log::GetClientLogger()->error(__VA_ARGS__)
#define DM_WARN(...)     ::Dream::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DM_INFO(...)     ::Dream::Log::GetClientLogger()->info(__VA_ARGS__)
#define DM_TRACE(...)    ::Dream::Log::GetClientLogger()->trace(__VA_ARGS__)
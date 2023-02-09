#include "ldpch.h"
#include "Ludus/Core/Window.h"

#ifdef LD_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Ludus
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef LD_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		LD_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}
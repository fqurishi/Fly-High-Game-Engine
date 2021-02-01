#pragma once

#include "Definitions.h"

namespace fh {

	class FLYHIGH_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();
	};

	// made in projects/games/applications using engine
	Application* CreateApplication();

}
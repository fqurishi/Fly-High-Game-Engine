#pragma once

#ifdef FH_PLATFORM_WINDOWS

extern fh::Application* fh::CreateApplication();

int main(int argc, char** argv) 
{
	fh::Log::Init();
	FH_CORE_WARN("Initialized log");
	FH_INFO("Welcome to the Fly High Game Engine");
	auto application = fh::CreateApplication();
	application->Run();
	delete application;
}

#endif
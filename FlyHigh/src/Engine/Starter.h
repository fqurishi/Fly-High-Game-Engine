#pragma once

#ifdef FH_PLATFORM_WINDOWS

extern fh::Application* fh::CreateApplication();

int main(int argc, char** argv) {

	printf("Welcome to the Fly High Game Engine\n");
	auto application = fh::CreateApplication();
	application->Run();
	delete application;
}

#endif
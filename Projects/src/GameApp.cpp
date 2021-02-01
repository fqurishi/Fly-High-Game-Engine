#include <FHEngine.h>

class Game : public fh::Application
{
public:
	Game()
	{

	}
	~Game()
	{

	}

};

fh::Application* fh::CreateApplication()
{
	return new Game();
}
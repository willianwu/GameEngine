#include <GameEngine.h>

//定义一个新类Sanbox，继承于Game::Application（称为基类）
class Sandbox:public GameEngine::Application {
public:
	Sandbox()
	{
	
	}

	~Sandbox()
	{

	}

};


GameEngine::Application* GameEngine::CreateApplication()
{
	return new Sandbox();
}

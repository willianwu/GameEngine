#include <GameEngine.h>

//����һ������Sanbox���̳���Game::Application����Ϊ���ࣩ
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

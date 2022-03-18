#include <GameEngine.h>
#include "GameEngine/LayerStack.h"

class ExampleLayer :public GameEngine::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}
	void OnUpdate() override
	{
		GE_CORE_INFO("ExampleLayer::Update");

	}
	void OnEvent(GameEngine::Event& event) override
	{
		GE_CORE_TRACE("{0}", event);
	}
};

//定义一个新类Sanbox，继承于Game::Application（称为基类）
class Sandbox:public GameEngine::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverLay(new GameEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};


GameEngine::Application* GameEngine::CreateApplication()
{
	return new Sandbox();
}

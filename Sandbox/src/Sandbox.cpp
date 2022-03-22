#include <GameEngine.h>
#include "GameEngine/LayerStack.h"

//定义了一个example类，
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
		//首先创造一个Layer
		PushLayer(new ExampleLayer());
		//在上面Layer的基础上加入一个ImGuiLayer
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

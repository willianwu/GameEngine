#include <GameEngine.h>
#include "GameEngine/LayerStack.h"

//������һ��example�࣬
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

//����һ������Sanbox���̳���Game::Application����Ϊ���ࣩ
class Sandbox:public GameEngine::Application 
{
public:
	Sandbox()
	{
		//���ȴ���һ��Layer
		PushLayer(new ExampleLayer());
		//������Layer�Ļ����ϼ���һ��ImGuiLayer
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

#pragma once
#include <sstream>
#include <functional>

namespace GameEngine {
	enum class EventType
	{
		None = 0,
		WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,
		AppTick,AppUpdate,AppRender,
		KeyPressed,KeyReleased,
        MouseMoved,MouseScrolled,
		MouseButtonPressed,MouseButtonReleased
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication =BIT(0),
		EventCategoryInput       =BIT(1),
		EventCategoryKeyboard    =BIT(2),
		EventCategoryMouse       =BIT(3),
		EventCategoryMouseButton =BIT(4)
	};


#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::##type;}\
								virtual EventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;}
	//单个#的作用是将type转换为字符串形式，加上双引号
	//两个##的作用则是表示连接

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class GAMEENGINE_API Event
	{
		friend class EventDispatcher;
	public:
		//声明了几个纯虚函数，需要在派生类中进行定义
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string Tostring() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event){}
	
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled |= func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.Tostring();
	}

}
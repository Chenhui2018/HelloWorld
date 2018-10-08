
#include <iostream>
#include <string>
#include <vector>
#include <memory>



class base
{
public:
	base() {}
	~base() {}

	// 被调用目标
	template <class T>
	void SetVariable(std::string Name, T value)
	{
		AddVariable(Name, value);
	}

protected:
	template <class T>
	void AddVariable(std::string Name, T value)
	{
		std::cout << Name << ", " << value << std::endl;
	}

};

//template <class T>
//struct Type
//{
//	typedef void(*FunType)(std::string name, T value);
//};
typedef void(*FunType)(std::string name, double value);

class common
{
public:
	common() {}
	~common() {}

	//
	//template<class T>
	void callSetVariable(/*typename Type<double>::*/FunType pfun, std::string name, double value)
	{
		pfun(name, value);
	}
};

class object : base
{
public:
	object() { pc = std::make_shared<common>(); }
	object() {}

	void doSomething() { pc->callSetVariable(SetVariable, "Score", 90.09); }

private:
	std::shared_ptr<common> pc;
};

int main()
{
	//SetVariable("Score: ", 128); // call function
	//SetVariable("Score: ", 123.98); // call template
	//SetVariableByFunPtr(SetVariable, "Score: ", 123);			// 函数形参类型固定  函数指针
	//SetVariableByFunPtr(SetVariable, "Score: ", 129.98);		// 函数形参类型固定  129.98被截断成129，调用情况同上
	//SetVariableByTemplatePtr(SetVariable, "Score: ", 109.98);	// 函数形参类型不固定  模板指针，109.98不会截断。


	return 0;
}
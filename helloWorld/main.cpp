
#include <iostream>
#include <string>
#include <vector>


template <class T>
void AddVariable(std::string Name ,T value)
{
	std::cout << Name << ", " << value << std::endl;
}

template <class T>
void SetVariable(std::string Name, T value)
{
	AddVariable(Name, value);
}

template <class T> // 测试模板指针 Parameter 和 variable 是同级的
void AddParameter(std::string Name, T value)
{
	std::cout << Name << ", " << value << std::endl;
}

template <class T> // 测试模板指针 Parameter 和 variable 是同级的
void SetParameter(std::string Name, T value)
{
	AddParameter(Name, value);
}


// 函数和模板同名，先调用符合的函数
void AddVariable(std::string Name, int value)
{
	std::cout << Name << ", " << value << std::endl;
}

void SetVariable(std::string Name, int value)
{
	AddVariable(Name, value);
}

// 函数指针  这里的 pfun 的形参是确定的。
// 为了代表一系列相同形参的函数
typedef void(*FunType)(std::string, int);
void SetVariableByFunPtr (FunType pfun, std::string name, int value)
{
	pfun(name, value);
}

// 模板指针  不能使用函数指针，因为这里的 pfun 的形参应该是不确定的。
// 所以 FunType 的定义要改变
// 为了代表一系列相同形参的模板
template <class T>
struct Type 
{
	typedef void (*FunType)(std::string name, T value);
};

// template <class T> typedef void(*FunType)(std::string name, T value); // 错！typedef 模板，非法


// typename 用于说明这是一个 type(可以定义变量) 而不是成员（不可以定义变量）。
template <class T>
void SetVariableByTemplatePtr(typename Type<T>::FunType pfun, std::string name, T value)
{
	std::vector<T> vecT(10);
	pfun(name, value);
}


int main()
{
	//SetVariable("Score: ", 128); // call function
	//SetVariable("Score: ", 123.98); // call template
	//SetVariableByFunPtr(SetVariable, "Score: ", 123);			// 函数形参类型固定  函数指针
	//SetVariableByFunPtr(SetVariable, "Score: ", 129.98);		// 函数形参类型固定  129.98被截断成129，调用情况同上
	SetVariableByTemplatePtr(SetVariable, "Score: ", 109.98);	// 函数形参类型不固定  模板指针，109.98不会截断。


	return 0;
}
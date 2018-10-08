
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

template <class T> // ����ģ��ָ�� Parameter �� variable ��ͬ����
void AddParameter(std::string Name, T value)
{
	std::cout << Name << ", " << value << std::endl;
}

template <class T> // ����ģ��ָ�� Parameter �� variable ��ͬ����
void SetParameter(std::string Name, T value)
{
	AddParameter(Name, value);
}


// ������ģ��ͬ�����ȵ��÷��ϵĺ���
void AddVariable(std::string Name, int value)
{
	std::cout << Name << ", " << value << std::endl;
}

void SetVariable(std::string Name, int value)
{
	AddVariable(Name, value);
}

// ����ָ��  ����� pfun ���β���ȷ���ġ�
// Ϊ�˴���һϵ����ͬ�βεĺ���
typedef void(*FunType)(std::string, int);
void SetVariableByFunPtr (FunType pfun, std::string name, int value)
{
	pfun(name, value);
}

// ģ��ָ��  ����ʹ�ú���ָ�룬��Ϊ����� pfun ���β�Ӧ���ǲ�ȷ���ġ�
// ���� FunType �Ķ���Ҫ�ı�
// Ϊ�˴���һϵ����ͬ�βε�ģ��
template <class T>
struct Type 
{
	typedef void (*FunType)(std::string name, T value);
};

// template <class T> typedef void(*FunType)(std::string name, T value); // ��typedef ģ�壬�Ƿ�


// typename ����˵������һ�� type(���Զ������) �����ǳ�Ա�������Զ����������
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
	//SetVariableByFunPtr(SetVariable, "Score: ", 123);			// �����β����͹̶�  ����ָ��
	//SetVariableByFunPtr(SetVariable, "Score: ", 129.98);		// �����β����͹̶�  129.98���ضϳ�129���������ͬ��
	SetVariableByTemplatePtr(SetVariable, "Score: ", 109.98);	// �����β����Ͳ��̶�  ģ��ָ�룬109.98����ضϡ�


	return 0;
}
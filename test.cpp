#include <iostream>
#include <string>

class Test
{
public:
	void run(void) const
	{
		int (Test::*foo[])(char) const = {
			&Test::aa,
			&Test::AA,
			&Test::xx
		};

		int (Test::*bar)(char) const = &Test::aa;
	}
	Test(void) {}
	~Test(void) {}

private:
	int aa(char c) const
	{
		return (int)c;
	}
	int AA(char c) const
	{
		return (int)c;
	}
	int xx(char c) const
	{
		return (int)c;
	}
};

/*
	void (Harl::*methods[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

This block of code is defining an array of pointers to member functions of class Harl.
The array is named methods and it has four elements. Each element is a pointer to a member function of class Harl
that takes no arguments and returns void.
The four member functions are debug, info, warning, and error.

The syntax for declaring a pointer to a member function is as follows:

return_type (class_name::*pointer_name)(parameter_list) = &class_name::function_name;

In this case, the return type is void, the class name is Harl, the pointer name is methods,
and the parameter list is empty.
The address of each member function is assigned to the corresponding element in the array.
*/



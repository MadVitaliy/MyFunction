#include "MyFunction.h"

#include <iostream>
#include <functional>


void func() {
	std::cout << "func" << std::endl;
}

struct functor {
	void operator()() {
		std::cout << "functor" << std::endl;
	}
};

int main()
{
	
	std::function<void()> f;
	std::cout << "sizeof(f) == " << sizeof(f) << std::endl;

	std::cout << "Stl std::function" << std::endl;
	f = func;
	f();
	f = functor();
	f();
	f = []() {std::cout << "lambda" << std::endl; };
	f();

	MyFunction<void()> mf;
	mf = func;
	mf();
	mf = functor();
	mf();
	mf = []() {std::cout << "lambda" << std::endl; };
	mf();

}


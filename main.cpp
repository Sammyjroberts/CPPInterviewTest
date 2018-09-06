// Howdy!
//
// Thank you for your interest in xxx and taking the time to apply.
//
// This file is a coding exercise. Please follow the instructions explicitly -
// you may only write code where specified. We've included reference material
// with information to produce a working solution. This is not a trick problem;
// it is solvable within the given constraints.
//
// You may use your choice of environment to develop your solution, but we will
// test and evaluate it with http://cpp.sh (an online gcc compiler) using
// C++14 and optimization level set to None.
//
//
// Instructions:
//
// Only writing code where indicated (the bodies of the `extract_x`,
// `extract_y`, `call_foo`, and `call_bar` functions), make this program output
// the values of:
//
//   * `thing->x`
//   * `thing->y`
//   * `thing->foo()`
//   * `thing->bar()`
//
// Some useful references:
//
// https://en.wikipedia.org/wiki/Virtual_method_table
// http://www.openrce.org/articles/full_view/23
// https://en.wikipedia.org/wiki/Pointer_(computer_programming)#C_arrays
// https://en.wikipedia.org/wiki/Pointer_(computer_programming)#Function_pointer


#include <cstdio>
#include <iostream>
class Thing
{
private:
	int x;
	int y;
	virtual int foo() 
	{
		return x+y;
	}
	virtual int bar()
	{
		return x*y;
	}
public:
	Thing(){
		x = 2;
		y = 10;
	}
};

int extract_x(void *thing)
{
    // --- Begin your code
	Thing* tempThing = (Thing*)thing;
	int* ptr = ((int *)(tempThing));
	return ptr[2];
    // --- End your code   ---
}

int extract_y(void *thing)
{
    // --- Begin your code ---
	Thing* tempThing = (Thing*)thing;
	int* ptr = ((int *)(tempThing));
	return ptr[3];
    // --- End your code   ---
}

int call_foo(void *thing)
{
    // --- Begin your code ---
	Thing* real = reinterpret_cast<Thing*>(thing);
	int(*f)(void*) = nullptr;
	f = (int(*)(void*))((long**)real)[0][0];
	int i = f(real);
	return i;
    // --- End your code   ---
}

int call_bar(void* thing)
{
    // --- Begin your code ---
	Thing* real = reinterpret_cast<Thing*>(thing);
	int(*f)(void*) = nullptr;
	f = (int(*)(void*))((long**)real)[0][1];
	int i = f(real);
	return i;
    // --- End your code   ---
}

int main()
{
	Thing thing;
    std::printf("%d %d %d %d\n",
                extract_x(&thing),
                extract_y(&thing),
                call_foo(&thing),
                call_bar(&thing));
	system("pause");
	return 0;
}

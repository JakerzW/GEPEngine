#include <iostream>

#include <engine\gameObject.h>

int main()
{
	gameObject *go = new gameObject();
	int test = 1;
	go->addComponent(test);

	return 0;
}
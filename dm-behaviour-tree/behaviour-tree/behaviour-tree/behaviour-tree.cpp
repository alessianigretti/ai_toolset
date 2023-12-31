#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "builder.h"
#include <memory>

using namespace std;

int main()
{
	shared_ptr<builder> tree_builder = shared_ptr<builder>(new builder());
	tree_builder->build_tree();

	float current_stamina = 1.0f;

	while (true)
	{
		cout << "Current stamina: " << current_stamina << ". Press Enter to continue..." << endl;
		cin.clear();
		cin.get();

		tree_builder->run(current_stamina);
	}
}
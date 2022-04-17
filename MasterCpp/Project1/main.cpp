#include "base.h"
#include "controller.h"
#include "ui.h"
#include "tests.h"
#include <iostream>

int main() {

	{
		bub::tests t;
		t.test_all();

		/*bub::tutorial_repo repo;
		bub::tutorial_controller ctrl{ repo };
		bub::ui ui{ ctrl };

		ui.start();*/
	}

	int res = _CrtDumpMemoryLeaks();
	if (res)
		std::cout << "!!!!!!!!!!!!!!!!\nMEMORY LEAKS FOUND\n";
	else std::cout << "Memory correctly deallocated.";
}
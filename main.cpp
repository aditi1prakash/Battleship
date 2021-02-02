//! Standard (system) header files
#include <iostream>
#include <stdlib.h>

//! User include files
#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Board.h"
#include "part1tests.hpp"
#include "ConsoleView.h"

//! Main program
int main (void)
{
	//! Perform first set of tests
	part1tests();

	//! Perform second set of tests
	part2tests();
	part2tests_a();

	//! Perform third set of tests
	part3tests();

	return 0;
}

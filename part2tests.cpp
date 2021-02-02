/*
 * part2tests.cpp
 *
 *  Created on: 16-Jan-2021
 *      Author: Aditi Prakash
 */

#include "part1tests.hpp"

#include "ConsoleView.h"

void part2tests()
{
	//Test #2 for board creation
	Board battleShip1(5,5);
	ConsoleView console(&battleShip1);

	console.print();

	//Test #2: Create the board of 10 x 10 grid and print the empty board
	Board battleShip(10,10);
	ConsoleView console1(&battleShip);
	console1.print();

	//Check for placeShip method
	assertTrue(!battleShip.getOwnGrid().placeShip(Ship{GridPosition{"C5"}, GridPosition{"F8"}}), "Ship is not aligned in a straight line, cannot place the ship");
	assertTrue(battleShip.getOwnGrid().placeShip(Ship{GridPosition{"A5"}, GridPosition{"A9"}}), "Ship cannot be placed on row A");
	assertTrue(battleShip.getOwnGrid().placeShip(Ship{GridPosition{"A1"}, GridPosition{"C1"}}), "Ship cannot be placed on column 1");
	assertTrue(battleShip.getOwnGrid().placeShip(Ship{GridPosition{"J1"}, GridPosition{"J3"}}), "Ship cannot be placed on row J");
	assertTrue(battleShip.getOwnGrid().placeShip(Ship{GridPosition{"E10"}, GridPosition{"F10"}}), "Ship cannot be placed on column 10");

	//Check for ships can touch each other
	assertTrue(!battleShip.getOwnGrid().placeShip(Ship{GridPosition{"B5"},GridPosition{"B7"}}),"Ships can touch each other");
}

void part2tests_a()
{
	Board battleShip(10,10);
	ConsoleView console1(&battleShip);

	//Check for number of ships that can be placed of particular length

	// Check if more than 1 ship of length 5 can be created
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"A4"},GridPosition{"A8"}});

	assertTrue(!battleShip.getOwnGrid().placeShip(Ship{GridPosition{"I1"}, GridPosition{"I5"}}), "Another ship of length 5 can be created.");

	// Check if more than 2 ships of length 4 can be created
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"B2"},GridPosition{"E2"}});
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"F5"},GridPosition{"F8"}});

	assertTrue(!battleShip.getOwnGrid().placeShip(Ship{GridPosition{"J3"},GridPosition{"J6"}}),
			"Extra ship of length 4 can be created");

	//Check if more than 3 ships of length 3 can be created
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"G1"},GridPosition{"G3"}});
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"H5"}, GridPosition{"J5"}});
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"I8"}, GridPosition{"I10"}});
	assertTrue(!battleShip.getOwnGrid().placeShip(Ship{GridPosition{"C4"},GridPosition{"C6"}}),
			"Extra ship of length 3 can be created");

	//Check if more than 4 ships of length 2 can be created
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"C6"},GridPosition{"C7"}});
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"C4"},GridPosition{"D4"}});
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"D9"},GridPosition{"D10"}});
	battleShip.getOwnGrid().placeShip(Ship{GridPosition{"J1"},GridPosition{"J2"}});

	assertTrue(!battleShip.getOwnGrid().placeShip(Ship{GridPosition{"F9"},GridPosition{"F10"}}),
			"Extra ship of length 2 can be created");
}

/*
 * part3tests.cpp
 *
 *  Created on: 16-Jan-2021
 *      Author: Aditi Prakash
 */

#include "part1tests.hpp"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Board.h"
#include "ConsoleView.h"


void part3tests ()
{
	Board board(10,10);
	ConsoleView console(&board);

	//! Check for shots (misses, hits, final shot)^
	board.getOwnGrid().placeShip(Ship{GridPosition{"C3"},GridPosition{"C7"}});
	board.getOwnGrid().placeShip(Ship{GridPosition{"E8"},GridPosition{"H8"}});

	assertTrue((board.getOwnGrid().takeBlow(Shot{GridPosition{"C4"}}) == Shot::Impact::HIT),
			"Hit not detected");
	assertTrue((board.getOwnGrid().takeBlow(Shot{GridPosition{"C7"}}) == Shot::Impact::HIT),
			"Hit not detected");
	assertTrue((board.getOwnGrid().takeBlow(Shot{GridPosition{"F8"}}) == Shot::Impact::HIT),
			"Hit not detected");
	assertTrue((board.getOwnGrid().takeBlow(Shot{GridPosition{"E8"}}) == Shot::Impact::HIT),
			"Hit not detected");
	assertTrue((board.getOwnGrid().takeBlow(Shot{GridPosition{"H8"}}) == Shot::Impact::HIT),
			"Hit not detected");
	//! Check final shot detection
	assertTrue((board.getOwnGrid().takeBlow(Shot{GridPosition{"G8"}}) == Shot::Impact::SUNKEN),
			"Last hit not detected");

	//! Check if ship can be hit twice
	assertTrue(!(board.getOwnGrid().takeBlow(Shot{GridPosition{"F8"}}) == Shot::Impact::HIT),
			"Hit detected twice");


	board.getOpponentGrid().updateOpponentDatabase();

	//! Check for detection of misses
	board.getOpponentGrid().shotResult(Shot(GridPosition("E3")), Shot::Impact::NONE);
	board.getOpponentGrid().shotResult(Shot(GridPosition("I5")), Shot::Impact::NONE);

	//! Check for hit
	board.getOpponentGrid().shotResult({GridPosition{"C6"}}, Shot::HIT);
	board.getOpponentGrid().shotResult({GridPosition{"C7"}}, Shot::HIT);

	//! Check for sunken ships
	board.getOpponentGrid().shotResult(Shot(GridPosition("F5")), Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("F6")), Shot::Impact::HIT);
	board.getOpponentGrid().shotResult(Shot(GridPosition("F7")), Shot::Impact::SUNKEN);

	console.print();
}

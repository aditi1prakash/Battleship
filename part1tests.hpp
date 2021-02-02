/*
 * part1tests.hpp
 *
 *  Created on: 04-Jan-2021
 *      Author: aditi
 */

#ifndef PART1TESTS_HPP_
#define PART1TESTS_HPP_

#include <set>
#include "Board.h"
#include "GridPosition.h"
#include "Ship.h"

void assertTrue(bool condition, std::string failedMessage);

void part1tests ();

void part2tests ();
void part2tests_a();

void part3tests ();






//	opponentGridShips.push_back(Ship{GridPosition{"F5"},GridPosition{"F8"}});
//	opponentGridShips.push_back(Ship{GridPosition{"G1"},GridPosition{"G3"}});
//	opponentGridShips.push_back(Ship{GridPosition{"H5"},GridPosition{"J5"}});
//	opponentGridShips.push_back(Ship{GridPosition{"I8"},GridPosition{"I10"}});
//	opponentGridShips.push_back(Ship{GridPosition{"C4"},GridPosition{"D4"}});
//	opponentGridShips.push_back(Ship{GridPosition{"D9"},GridPosition{"D10"}});
//	opponentGridShips.push_back(Ship{GridPosition{"J1"},GridPosition{"J2"}});

//TODO: Remove the following methods, added only for testing purpose
//friend std::ostream &operator<<(std::ostream &os, const Ship &other);


//std::ostream &operator<<(std::ostream &os, const Ship &other)
//{
//	os << other.getBow() << other.getStern();
//	return os;
//}


//void testInsert(GridPosition const& obj, std::set<GridPosition> & blockedGrids) const;

//	std::cout << "start my test...." << std::endl;
//
//	std::cout << "====================================C1" << std::endl;
//	blockedGrids.insert(GridPosition('C',1));
//	std::cout << "====================================C2" << std::endl;
//	blockedGrids.insert(GridPosition('C',2));
//	std::cout << "====================================D2" << std::endl;
//	blockedGrids.insert(GridPosition('D',2));
//	std::cout << "====================================D1" << std::endl;
//	blockedGrids.insert(GridPosition('D',1));
//	std::cout << "====================================A1" << std::endl;
//	blockedGrids.insert(GridPosition('A',1));
//	std::cout << "start set ourput...." << std::endl;
//	//TODO: Remove the below for loop - added only for testing purposes
//	for(auto it = blockedGrids.begin(); it != blockedGrids.end(); it++)
//	{
//		std::cout << &(*it) << "  " << *it <<std::endl;
//	}
//	std::cout << "stop...." << std::endl;
//
//	return blockedGrids;


//void Ship::testInsert(const GridPosition &obj,
//		std::set<GridPosition> &blockedGrids) const
//{
//	std::cout << "Adding " << obj << " at " << &obj <<std::endl;
//	blockedGrids.insert(obj);
//
//	std::cout << "Resulting set " <<std::endl;
//	for(auto it = blockedGrids.begin(); it != blockedGrids.end(); it++)
//	{
//		std::cout << "   " << &(*it) << "  " << *it <<std::endl;
//	}
//
//}

//std::cout << &(*it) << "  " << *it <<std::endl;

//
//testInsert(GridPosition(obj.getRow(), obj.getColumn() - 1), blockedGrids);
//testInsert(GridPosition(obj.getRow(), obj.getColumn() + 1), blockedGrids);
//
//testInsert(GridPosition((char)(obj.getRow() + one), obj.getColumn()), blockedGrids);
//testInsert(GridPosition(obj.getRow() + one, obj.getColumn() + 1), blockedGrids);
//testInsert(GridPosition(obj.getRow() + one, obj.getColumn() - 1), blockedGrids);
//
//testInsert(GridPosition(obj.getRow() - one, obj.getColumn()), blockedGrids);
//testInsert(GridPosition(obj.getRow() - one, obj.getColumn() - 1), blockedGrids);
//testInsert(GridPosition(obj.getRow() - one, obj.getColumn() + 1), blockedGrids);


//bool GridPosition::operator<(GridPosition other) const
//{
//	std::cout << "comparing - "  <<  *this << " and " << other << std::endl;
//	if(this->row < other.row )
//	{
//		std::cout << "row - "  <<  *this << " < " << other << std::endl;
//		return true;
//	}
//	if (this->row == other.row && this->column < other.column)
//	{
//		std::cout << "column - "  <<  *this << " < " << other << std::endl;
//		return true;
//	}
//	std::cout << "else - "  <<  *this << " not < " << other << std::endl;
//	return false;
//}

//std::ostream &operator<<(std::ostream &os, const GridPosition &other)
//{
//	os << other.getRow() << other.getColumn() <<  "( " << (int)other.getRow()  << ", "  << (int)other.getColumn() << ")";
//	return os;
//}


//A ship object is passed which will have the values of bow and stern.
//The values of bow and stern are (most probably) stored in a vector of ship type.
//Vector could have global scope since getShips() method also returns a vector type of ship.
//Since there are 10 ships that are to be placed, there should be a loop which loops for 10 times (diff
//loops based on the diff number/types of ships available).
//ConsoleView() will have access to board class which in turn has access to ownGrid and oppositionGrid,
//ConsoleView() will print the board by using board object/pointer to board instance

//		blockedGrids.insert(GridPosition(obj.getRow(), obj.getColumn() - 1));
//		blockedGrids.insert(GridPosition(obj.getRow(), obj.getColumn() + 1));
//
//		blockedGrids.insert(GridPosition((char)(obj.getRow() + one), obj.getColumn()));
//		blockedGrids.insert(GridPosition(obj.getRow() + one, obj.getColumn() + 1));
//		blockedGrids.insert(GridPosition(obj.getRow() + one, obj.getColumn() - 1));
//
//		blockedGrids.insert(GridPosition(obj.getRow() - one, obj.getColumn()));
//		blockedGrids.insert(GridPosition(obj.getRow() - one, obj.getColumn() - 1));
//		blockedGrids.insert(GridPosition(obj.getRow() - one, obj.getColumn() + 1));

#endif /* PART1TESTS_HPP_ */

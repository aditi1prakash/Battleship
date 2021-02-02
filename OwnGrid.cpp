/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file OwnGrid.cpp
 *	\brief Source file for Ship class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

//System Include Files
#include <iostream>

#include <algorithm>
#include <iterator>

//Own Include Files
#include "OwnGrid.h"

/********************** Method Implementations ******************************/

/**
 * \brief		: Parametrised Constructor for OwnGrid class
 * \param [IN]	: int rows - Number of rows in the own grid
 * \param [IN]	: int columns - Number of columns in the own grid
 * \return		: NONE
 */
OwnGrid::OwnGrid(int rows, int columns)
	:rows{rows}, columns{columns}
{
	this->ownGridShips = ownGridShips;

	//! Initialise the map with its key and values
	shipDatabase[5] = 1;
	shipDatabase[4] = 2;
	shipDatabase[3] = 3;
	shipDatabase[2] = 4;
}

/**
 * \brief		: Getter method for number of rows on own grid
 * \param		: NONE
 * \return		: int - Number of rows on own grid
 */
int OwnGrid::getRows() const
{
	return rows;
}

/**
 * \brief		: Getter method for number of columns on own grid
 * \param		: NONE
 * \return		: int - Number of columns on own grid
 */
int OwnGrid::getColumns() const
{
	return columns;
}

/**
 * \brief		: Method to place ship
 * \details		: The method checks if the ship is valid and iterates through the length of the ship.
 * 				  Updates the ship if the grid positions are valid and if it does not intersect with the earlier placed ships
 * \param [IN]	: const Ship& ship - reference object from Ship
 * \return		: bool - True: Ship is placed successfully in the Database
 * 						 False: If the ship is invalid and does not obey the rules of placement
 */
bool OwnGrid::placeShip(const Ship& ship)
{
	//! Set to store the intersection of occupied area and blocked area
	std::vector<GridPosition>intersectionSet;

	if(ship.isValid())
	{
		for(size_t i = 0; i < ships.size(); i++)
		{
			//! Set which stores the occupied area of the existing ship
			std::set<GridPosition>occupiedGrids = ship.occupiedArea();

			//! Set which obtains the blocked area of the grid
			std::set<GridPosition>blockedGrids = ships[i].blockedArea();

			//! Finds the intersection and updates the result in the intersectionSet
			set_intersection(occupiedGrids.begin(), occupiedGrids.end(),
											   blockedGrids.begin(), blockedGrids.end(),
											   inserter(intersectionSet, intersectionSet.begin()));

			//! Return false if the intersection set is not empty
			if(!intersectionSet.empty())
			{
//				std::cout << "Intersection detected" << std::endl;
				return false;
			}
		}

		//! Get the value (number of ships) from the map to check the remaining ships of particular length
		if(shipDatabase[ship.length()] == 0)
		{
			return false;
		}

		//! Ship is still available - Push the ship into the database and decrement the number of ships of particular length
		ships.push_back(ship);
		shipDatabase[ship.length()] = shipDatabase[ship.length()] - 1;

		return true;
	}
	else
	{
		return false;
	}
}

/**
 * \brief		: Method to get the ships on own grid
 * \param		: NONE
 * \return		: vector<Ship> - The ships that are placed on own grid
 */
const std::vector<Ship> OwnGrid::getShips() const
{
	return ships;
}

/**
 * \brief		: Method to update the Grid Position for the shot taken
 * \param[IN]	: const Shot& shot - The grid position of the shot
 * \return		: Impact - enum value that indicates below states of the ship
 * 				  NONE - No ship position is hit
 * 				  HIT - There is a hit for a grid position
 * 				  SUNKEN - A ship is sunken
 */
Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	//! Iterate through the positions to check if the ship is already HIT, if yes then return NONE
	for(auto shipPosition: shotAt)
	{
		if(shipPosition == shot.getTargetPosition())
		{
			return Shot::Impact::NONE;
		}
	}

	//! Insert the target position of the shot
	shotAt.insert(shot.getTargetPosition());

	//! For each ship iterate through the ship positions and find the SUNKEN or HIT ships
	for (auto eachShip: ships)
	{
		for(auto shipPosition: eachShip.occupiedArea())
		{
			if(shipPosition == shot.getTargetPosition())
			{
				std::set<GridPosition>intersectionSet;
				std::set<GridPosition>::iterator intersectionItr;

				set_intersection(eachShip.occupiedArea().begin(), eachShip.occupiedArea().end(),
								shotAt.begin(), shotAt.end(),
								inserter(intersectionSet, intersectionSet.begin()));

				if(eachShip.length() - intersectionSet.size() == 0)
				{
					return Shot::Impact::SUNKEN;
				}
				return Shot::Impact::HIT;
			}
		}
	}
	return Shot::Impact::NONE;
}

/**
 * \brief		: Getter method for the positions that are shot at on the own grid
 * \param 		: NONE
 * \return		: std::set<GridPosition> - A set of grid positions that are shot at
 */
const std::set<GridPosition> OwnGrid::getShotAt() const
{
	return shotAt;
}

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file Ship.cpp
 *	\brief Source file for Ship class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

//System Include Files
#include <iostream>
#include <algorithm>

//Own Include Files
#include "Ship.h"
#include "GridPosition.h"

//enumeration to hold the alignment position of the ship
typedef enum{
	INVALID_ALIGNMENT,				//0
	HORIZONTAL_ALIGNMENT,			//1
	VERTICAL_ALIGNMENT				//2
}alignment_t;

//! A static variable that stores the Alignment of the particular ship
static alignment_t shipAlignment{INVALID_ALIGNMENT};

//! A 2D array to hold the offset values required for the 8 diagonal elements of a particular grid position
const int neighborArray[8][2] =
{{-1, -1}, {-1, 0}, {-1, +1},
 {0, -1},            {0, +1},
 {+1, -1}, {+1, 0}, {+1, +1}
};

/********************** Method Implementations ******************************/

/**
 * \brief		: Parametrised Constructor for ship class
 * \param[IN]	: const GridPosition& bow - Reference to the bow of the ship
 * \param[IN]	: const GridPosition& stern - Reference to the stern of the ship
 * \return		: NONE
 */
Ship::Ship(const GridPosition& bow, const GridPosition& stern)
	:bow(bow), stern(stern)
{}

/**
 * \brief		: To check the validity of the bow and stern grid positions
 * \details		: Checks for validity of bow and stern
 * 				  Checks if the length lies between 2 and 5
 * 				  Checks if the alignment of the ship is not Invalid
 * \param		: NONE
 * \return		: True - If all the above conditions are satisfied (Ship is Valid)
 * 				  False - If otherwise
 */
bool Ship::isValid() const
{
	//! A local variable to store the length of the ship
	unsigned int shipLength = length();

	if(bow.isValid() && stern.isValid())
		if (shipLength >= 2 && shipLength <= 5)
			if(shipAlignment != INVALID_ALIGNMENT)
				return true;

	return false;
}

/**
 * \brief		: Getter method for Bow attribute
 * \param		: NONE
 * \return		: GridPosition - Bow of the ship
 */
GridPosition Ship::getBow() const
{
	return bow;
}

/**
 * \brief		: Getter method for Stern attribute
 * \param		: NONE
 * \return		: GridPosition - Stern of the ship
 */
GridPosition Ship::getStern() const
{
	return stern;
}

/**
 * \brief		: Method to calculate the length of the Ship and set the alignment flag
 * \param		: NONE
 * \return		: int - Length of the ship
 */
int Ship::length() const
{
	//! A local variable to store the length of the ship
	unsigned int length {0};

	//! Same row value for Bow and Stern indicate Horizontal Alignment --> Only column values are required to calculate the length
	if((bow.getRow() - stern.getRow() == 0))
	{
		length = (abs)(bow.getColumn() - stern.getColumn()) + 1;
		shipAlignment = HORIZONTAL_ALIGNMENT;
	}
	//! Same column value for Bow and Stern indicate Vertical Alignment --> Only row values are required to calculate the length
	else if ((bow.getColumn() - stern.getColumn() == 0))
	{
		length = (abs)(bow.getRow() - stern.getRow()) + 1;
		shipAlignment = VERTICAL_ALIGNMENT;
	}
	//! If neither row nor column are similar then the alignment is not on a straight line --> Set the flag the invalid
	else
		shipAlignment = INVALID_ALIGNMENT;

	return length;
}

/**
 * \brief		: Method to calculate the grid positions occupied by the ship
 * \param		: NONE
 * \return		: std::set<GridPosition> - Grid positions occupied by the ship
 */
const std::set<GridPosition> Ship::occupiedArea() const
{
	//! Get row and column of the bow into local variables
	char bowRow = bow.getRow();
	int bowColumn = bow.getColumn();

	//! Get row and column of the stern into local variables
	char sternRow = stern.getRow();
	int sternColumn = stern.getColumn();

	//! A local set to store the co-ordinates of the ship on the Grid
	std::set<GridPosition> shipCoordinates;

	//! If the ship is valid and horizontally aligned then increment the column of the bow until it reaches the stern
	if(Ship::isValid())
	{
		if (shipAlignment == HORIZONTAL_ALIGNMENT)
		{
			while (bowColumn <= sternColumn)
			{
				shipCoordinates.insert(GridPosition{bowRow,bowColumn});
				bowColumn += 1;
			}
		}
		//! If the ship is valid and vertically aligned then increment the row of the bow until it reaches the stern
		else if (shipAlignment == VERTICAL_ALIGNMENT)
		{
			while (bowRow <= sternRow)
			{
				shipCoordinates.insert(GridPosition{bowRow,bowColumn});
				bowRow += 1;
			}
		}
		//! Ship position is invalid
		else
		{
			std::cout << "Invalid Ship positions" <<std::endl;
		}
	}
	return shipCoordinates;
}

/**
 * \brief		: Method to calculate the 8 diagonal elements of each grid position of the ship
 * \param		: NONE
 * \return		: std::set<GridPosition> - Invalid grid positions
 */
const std::set<GridPosition> Ship::blockedArea() const
{
	//! Obtain the occupied area of the ship into a local set
	std::set<GridPosition>shipCoordinates = occupiedArea();

	//! Set to update the blocked grids
	std::set<GridPosition> blockedGrids;

	//! For each position of the ship iterate through the set
	for(auto it = shipCoordinates.begin(); it != shipCoordinates.end(); it++)
	{
		//! GridPosition object holds the value pointed by the iterator
		GridPosition obj = *it;

		//! For each position of the ship update the diagonal elements corresponding to that position
		for (int row = 0; row < 8; row++)
		{
			//! Check for the boundary condition (invalid if row becomes <A and column becomes <1) using isValid() function
			if (GridPosition((obj.getRow() + neighborArray[row][0]), (obj.getColumn() + neighborArray[row][1])).isValid())
			{
				//! Update the blockedGrids set based on the neighborArray that holds the offset values for the neighboring grid positions
				blockedGrids.insert(GridPosition((obj.getRow() + neighborArray[row][0]), (obj.getColumn() + neighborArray[row][1])));
			}
		}
	};

	return blockedGrids;
}

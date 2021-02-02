/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file OpponentGrid.cpp
 *	\brief Source file for OpponentGrid class
 *
 *  Created on	: 02-01-2020
 *  Author		: Aditi Prakash
 */
/****************************************************************************/

//System Include Files
#include <iostream>

//Own Include Files
#include "OpponentGrid.h"
#include "GridPosition.h"

/********************** Method Implementations ******************************/

/**
 * \brief		: Parametrised Constructor for OpponentGrid class
 * \param[IN]	: int rows - Number of rows in the opponent grid
 * \param[IN]	: int columns - Number of columns in the opponent grid
 * \return		: NONE
 */
OpponentGrid::OpponentGrid(int rows, int columns)
	:rows{rows},columns{columns}
{
	this->ship = ship;
}

/**
 * \brief		: Getter method for number of rows on opponent grid
 * \param		: NONE
 * \return		: int - Number of rows on opponent grid
 */
int OpponentGrid::getRows()
{
	return rows;
}

/**
 * \brief		: Getter method for number of columns on opponent grid
 * \param		: NONE
 * \return		: int - Number of rows on opponent grid
 */
int OpponentGrid::getColumns()
{
	return columns;
}

/**
 * \brief		: Method to check the shot result and update the sunken ships
 * \param[IN]	: const Shot& shot - An object reference to the shot class
 * \param[IN]	: Shot::Impact impact - Impact of the shot
 * \return		: NONE
 */
void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	//! Insert the shots inside the map
	  shots.emplace(shot.getTargetPosition(), impact);

	  //! A vector of ships to store the ships of opponent grid
	  std::vector<Ship>shipDatabase = getOpponentGridShips();

	  //! Iterate through each ship in the database
	  for(auto ship:shipDatabase)
	  {
		  //! Get the occupied area of each ship
		  std::set<GridPosition> occupiedArea = ship.occupiedArea();

		  //! For each position in occupied area check if the position is sunken
		  for(auto eachPosition: occupiedArea)
		  {
			  auto it = shots.find(eachPosition);
			  if(it->second == Shot::SUNKEN)
			  {
				  sunkenShips = ship.occupiedArea();
			  }
		  }
	  }

	  //TODO: Comment this code - Only required if sunken ships are to be displayed
//	  for(auto sunkenShip: sunkenShips)
//	  {
//		  std::cout << sunkenShip.getRow() << sunkenShip.getColumn() << "  " << std::endl;
//	  }
}

/**
 * \brief		: Method that returns the shots taken by the opponent grid
 * \param		: NONE
 * \return		: map<GridPosition, Shot::Impact> - The GridPosition of the shot taken and the state of the grid position
 */
const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{
	return shots;
}

/**
 * \brief		: Method to obtain the sunken ships
 * \param		: NONE
 * \return		: std::set<GridPosition> - A set of grid positions that hold the sunken ships
 */
const std::set<GridPosition> OpponentGrid::getSunkenShips() const
{
	return sunkenShips;
}

/**
 * \brief		: Method to maintain the ships of the opponent
 * \param		: NONE
 * \return		: NONE
 */
void OpponentGrid::updateOpponentDatabase()
{
	opponentGridShips.push_back(Ship{GridPosition{"A4"},GridPosition{"A8"}});
	opponentGridShips.push_back(Ship{GridPosition{"F5"},GridPosition{"F7"}});
	opponentGridShips.push_back(Ship{GridPosition{"C6"},GridPosition{"C8"}});
}

/**
 * \brief		: Getter method to access the opponent grid database
 * \param		: NONE
 * \return		: vector<Ship> - A vector of ships
 */
std::vector<Ship> OpponentGrid::getOpponentGridShips() const
{
	return opponentGridShips;
}

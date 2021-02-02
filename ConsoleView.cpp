/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file ConsoleView.cpp
 *	\brief Source file for ConsoleView class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

//System Include Files
#include <iomanip>

//Own Include Files
#include "ConsoleView.h"

/********************** Method Implementations ******************************/

/**
 * \brief		: Parametrised Constructor for ConsoleView class
 * \param[IN]	: Board* board - Reference to the board object
 * \return		: NONE
 */
ConsoleView::ConsoleView(Board* board)
{
	this->board = board;

	//! Initialize the grids to default/empty
	for(int i = 0; i < (board->getRows() * board->getColumns()); i++)
	{
		ownGridVector.push_back('~');
		opponentGridVector.push_back('~');
	}

	//! Resize the vectors for memory optimization
	ownGridVector.resize(board->getRows() * board->getColumns());
	opponentGridVector.resize(board->getRows() * board->getColumns());
}

/**
 * \brief		: Method to updates the own grid vector
 * \param		: NONE
 * \return 		: NONE
 */
void ConsoleView::updateOwnGrid()
{
	//! For each shot update the grid with MISS
	for (auto shotsTaken: board->getOwnGrid().getShotAt())
	{
		char row = shotsTaken.getRow();
		int rowIndex = row - 65;
		int columnIndex = (shotsTaken.getColumn() - 1);

		ownGridVector.at(rowIndex * board->getRows() + columnIndex) = '^';
	}

	//! For each ship from the own grid, update the grid with HIT or SUNKEN
	for(auto ships: board->getOwnGrid().getShips())
	{
		//! Iterate through all the gridPositions of the ship's occupied area
		for (auto shipPosition: ships.occupiedArea())
		{
			char row = shipPosition.getRow();
			int rowIndex = row - 65;
			int columnIndex = (shipPosition.getColumn() - 1);

			//! Update the grid with '#' to indicate the placement of the ship
			ownGridVector.at(rowIndex * board->getRows() + columnIndex) = '#';

			//! For each shots taken, update the grid
			for (auto shotsTaken: board->getOwnGrid().getShotAt())
			{
				if(shipPosition == shotsTaken)
				{
					ownGridVector.at(rowIndex * board->getRows() + columnIndex) = 'O';
				}
			}
		}
	}
}

/**
 * \brief		: Method to update the opponent grid vector
 * \param		: NONE
 * \return 		: NONE
 */
void ConsoleView::updateOpponentGrid()
{
	//! Iterate through each shot, get the rows and column of the of the shots
	for (auto shots: board->getOpponentGrid().getShotsAt())
	{
		int rowIndex = shots.first.getRow() - 65;
		int columnIndex = shots.first.getColumn() - 1;

		std::vector<Ship> shipDatabase = board->getOpponentGrid().getOpponentGridShips();

		for(auto ship:shipDatabase)
		{
			std::set<GridPosition> occupiedArea = ship.occupiedArea();
			if((occupiedArea.count(shots.first)) && (shots.second == Shot::Impact::HIT))
			{
				opponentGridVector.at(rowIndex * board->getRows() + columnIndex) = 'O';
			}

			//! If the shot is missed update the grid with '^'
			if((!occupiedArea.count(shots.first)) && (shots.second == Shot::Impact::NONE))
			{
				opponentGridVector.at(rowIndex * board->getRows() + columnIndex) = '^';
			}
		}
//		//! If the grid position is HIT and a ship is available in that position then update the grid with '#'
//		if((shots.second == Shot::Impact::HIT) && (shipDatabase.count(shots.first)))
//		{
//			opponentGridVector.at(rowIndex * board->getRows() + columnIndex) = 'O';
//		}
	}

	//! For each sunken ship update the grid position with '#'
	for (auto sunkenShip: board->getOpponentGrid().getSunkenShips())
	{
		int rowIndex = sunkenShip.getRow() - 65;
		int columnIndex = sunkenShip.getColumn() - 1;

		opponentGridVector.at(rowIndex * board->getRows() + columnIndex) = '#';
	}
}

/**
 * \brief		: Method to print the own grid and opponent grids
 * \param		: NONE
 * \return		: NONE
 */
void ConsoleView::print()
{
	//! Update own grid and opponent grid
	updateOwnGrid();
	updateOpponentGrid();

	//! Local variable initialised to first character
	char charRow = 'A';

	//! To print the column numbers of own grid
	for (auto i = 1; i <= board->getColumns(); ++i)
		std:: cout << std::setw(2) << i;

	std::cout << "\t\t";

	//! To print the column numbers of opponent grid
	for (auto i = 1; i <= board->getColumns(); ++i)
		std:: cout << std::setw(2) << i;

	std::cout << std::endl;

	//! Iterate through the number of rows and print the grids
    for (int i = 0; i < board->getRows(); i++,charRow++)
    {
    	//! Print own grid
        std::cout << charRow << std::setw(2);
        for (int j = 0; j < board->getColumns(); j++)
        	std::cout << std::setw(2) << ownGridVector.at(i * board->getColumns() + j);

        std::cout << "\t\t";

        //! Print opponent grid
        std::cout << charRow << std::setw(2);
        for (int j = 0; j < board->getColumns(); j++)
           std::cout << std::setw(2) << opponentGridVector.at(i * board->getColumns() + j);

        std::cout << std::endl;
    }
}

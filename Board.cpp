/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file Board.cpp
 *	\brief Header file for OpponentGrid class
 *
 *  Created on	: 02-01-2020
 *  Author		: Aditi Prakash
 */
/****************************************************************************/

//System Include Files
#include <iostream>

//Own Include Files
#include "Board.h"

/********************** Method Implementations ******************************/

/**
 * \brief		: Parametrised Constructor for Board class
 * \param[IN]	: int rows - Number of rows in the board
 * \param[IN]	: int columns - Number of columns in the board
 * \return		: NONE
 */
Board::Board(int rows, int column)
	:ownGrid(rows, column), opponentGrid(rows, column)
{
	this->row = rows;
	this->column = column;
}

/**
 * \brief		: Getter method for rows
 * \param		: NONE
 * \return		: Number of rows
 */
int Board::getRows() const
{
	return row;
}

/**
 * \brief		: Getter method for columns
 * \param		: NONE
 * \return		: Number of columns
 */
int Board::getColumns() const
{
	return column;
}


/**
 * \brief		: Getter method for Own grid
 * \param		: NONE
 * \return		: OwnGrid& - Reference to the own grid object
 */
OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

/**
 * \brief		: Getter method for Opponent grid
 * \param		: NONE
 * \return		: OpponentGrid& - Reference to the opponent grid object
 */
OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}






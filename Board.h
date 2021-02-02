///***************************************************************************
//*============= Copyright by Darmstadt University of Applied Sciences =======
//****************************************************************************
//* Filename        : Board.h
//* Author          : Aditi Prakash
//* Description     : Header file for Opponent Grid class
//* Date 		   	: 02-01-2020
//*
//****************************************************************************/

#ifndef BOARD_H
#define BOARD_H

//! User include files
#include "OwnGrid.h"
#include "OpponentGrid.h"

class Board {

private:

	//! An object of own grid
    OwnGrid ownGrid;

    //! An object of opponent grid
    OpponentGrid opponentGrid;

    //! The number of rows on the board
    int row;

    //! The number of columns on the board
    int column;

public:

    /**
     * \brief		: Parametrised Constructor for Board class
     * \param[IN]	: int rows - Number of rows in the board
     * \param[IN]	: int columns - Number of columns in the board
     * \return		: NONE
     */
    Board(int rows, int column);

    /**
     * \brief		: Getter method for rows
     * \param		: NONE
     * \return		: Number of rows
     */
    int getRows() const;

    /**
     * \brief		: Getter method for columns
     * \param		: NONE
     * \return		: Number of columns
     */
    int getColumns() const;

    /**
     * \brief		: Getter method for Own grid
     * \param		: NONE
     * \return		: OwnGrid& - Reference to the own grid object
     */
    OwnGrid& getOwnGrid();

    /**
     * \brief		: Getter method for Opponent grid
     * \param		: NONE
     * \return		: OpponentGrid& - Reference to the opponent grid object
     */
    OpponentGrid& getOpponentGrid();
};
/********************
**  CLASS END
*********************/
#endif /* BOARD_H */

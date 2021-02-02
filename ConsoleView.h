/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file ConsoleView.h
 *	\brief Header file for ConsoleView class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "Board.h"

class ConsoleView {

private:
	//! A reference object to the board class
    Board* board;

    //! A vector to store the own grid values
    std::vector<char>ownGridVector;

    //! A vector to store the opponent grid values
    std::vector<char>opponentGridVector;

public:

    /**
     * \brief		: Parametrised Constructor for ConsoleView class
     * \param[IN]	: Board* board - Reference to the board object
     * \return		: NONE
     */
    ConsoleView(Board* board);

    /**
     * \brief		: Method to updates the own grid vector
     * \param		: NONE
     * \return 		: NONE
     */
    void updateOwnGrid();

    /**
     * \brief		: Method to updates the opponent grid vector
     * \param		: NONE
     * \return 		: NONE
     */
    void updateOpponentGrid();

    /**
     * \brief		: Method to print the own grid and opponent grids
     * \param		: NONE
     * \return		: NONE
     */
    void print();
};
/********************
**  CLASS END
*********************/
#endif /* CONSOLEVIEW_H */

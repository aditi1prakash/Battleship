/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file OpponentGrid.h
 *	\brief Header file for OpponentGrid class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

#ifndef OPPONENTGRID_H
#define OPPONENTGRID_H

//! System Include files
#include <map>
#include <vector>

//! User include files
#include "Ship.h"
#include "Shot.h"

class OpponentGrid {

private:
	//! Number of rows in the opponent grid
    int rows;
    //! Number of columns in the opponent grid
    int columns;

    //! A map of <GridPosition, Shot::Impact> to store the shots taken
    std::map<GridPosition, Shot::Impact>shots;

    //! A set of GridPosition to store the sunken ships in the opponent grid
    std::set<GridPosition> sunkenShips;

    //! A vector of Ships to store the ships present in the opponent grid
    std::vector<Ship>opponentGridShips;

    Ship *ship;

public:

    /**
     * \brief		: Parametrised Constructor for OpponentGrid class
     * \param [IN]	: int rows - Number of rows in the opponent grid
     * \param [IN]	: int columns - Number of columns in the opponent grid
     * \return		: NONE
     */
    OpponentGrid(int rows, int columns);

    /**
     * \brief		: Getter method for number of rows on opponent grid
     * \param		: NONE
     * \return		: int - Number of rows on opponent grid
     */
    int getRows();

    /**
     * \brief		: Getter method for number of columns on opponent grid
     * \param		: NONE
     * \return		: int - Number of rows on opponent grid
     */
    int getColumns();

    /**
     * \brief		: Method to check the shot result and update the sunken ships
     * \param [IN]	: const Shot& shot - An object reference to the shot class
     * \param [IN]	: Shot::Impact impact - Impact of the shot
     * \return		: NONE
     */
    void shotResult(const Shot& shot, Shot::Impact impact);

    /**
     * \brief		: Method that returns the shots taken by the opponent grid
     * \param		: NONE
     * \return		: map<GridPosition, Shot::Impact> - The GridPosition of the shot taken and the state of the grid position
     */
    const std::map<GridPosition, Shot::Impact>& getShotsAt() const;

    /**
     * \brief		: Method to obtain the sunken ships
     * \param		: NONE
     * \return		: std::set<GridPosition> - A set of grid positions that hold the sunken ships
     */
    const std::set<GridPosition> getSunkenShips() const;

    /**
     * \brief		: Method to maintain the ships of the opponent
     * \param		: NONE
     * \return		: NONE
     */
    void updateOpponentDatabase();

    /**
     * \brief		: Getter method to access the opponent grid database
     * \param		: NONE
     * \return		: vector<Ship> - A vector of ships
     */
    std::vector<Ship> getOpponentGridShips() const;
};
/********************
**  CLASS END
*********************/
#endif /* OPPONENTGRID_H */

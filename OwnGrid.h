/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file OwnGrid.h
 *	\brief Header file for OwnGrid class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

#ifndef OWNGRID_H
#define OWNGRID_H

#include <vector>
#include <map>
#include <set>

#include "Ship.h"
#include "Shot.h"

class OwnGrid {

private:
	//! Number of rows in the own grid
    int rows;
    //! Number of columns in the own grid
    int columns;

    //! A vector of ships that holds the ship positions
    std::vector<Ship> ships;

    //! A map of <int, int> to store the length and number of ships available for the player
    std::map<int, int> shipDatabase;

    //! A set of grid position to store the grid positions that are shot at on the own grid
    std::set<GridPosition> shotAt;

    Ship *ownGridShips;

public:
    /**
     * \brief		: Parametrised Constructor for ship class
     * \param[IN]	: int rows - Number of rows in the own grid
     * \param[IN]	: int columns - Number of columns in the own grid
     * \return		: NONE
     */
    OwnGrid(int rows, int columns);

    /**
     * \brief		: Getter method for number of rows on own grid
     * \param		: NONE
     * \return		: int - Number of rows on own grid
     */
    int getRows() const;

    /**
     * \brief		: Getter method for number of columns on own grid
     * \param		: NONE
     * \return		: int - Number of columns on own grid
     */
    int getColumns() const;

    /**
     * \brief		: Method to place ship
     * \param[IN]	: const Ship& ship - reference object from Ship
     * \return		: bool - Success or Failure in placing a ship
     */
    bool placeShip(const Ship& ship);

    /**
     * \brief		: Method to get the ships on own grid
     * \param		: NONE
     * \return		: vector<Ship> - The ships that are placed on own grid
     */
    const std::vector<Ship> getShips() const;

    /**
     * \brief		: Method to update the Grid Position for the shot taken
     * \param [IN]	: const Shot& shot - The grid position of the shot
     * \return		: Impact - enum value that indicates below states of the ship
     * 				  NONE - No ship position is hit
     * 				  HIT - There is a hit for a grid position
     * 				  SUNKEN - A ship is sunken
     */
    Shot::Impact takeBlow(const Shot& shot);

    /**
     * \brief		: Getter method for the positions that are shot at on the own grid
     * \param 		: NONE
     * \return		: std::set<GridPosition> - A set of grid positions that are shot at
     */
    const std::set<GridPosition> getShotAt() const;


};
/********************
**  CLASS END
*********************/
#endif /* OWNGRID_H */

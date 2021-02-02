/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file Ship.h
 *	\brief Header file for Ship class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

#ifndef SHIP_H
#define SHIP_H

//! System Include files
#include <iostream>
#include <set>

//! Own includes
#include "GridPosition.h"


class Ship {

private:
	//! Initial GridPosition of the ship
    GridPosition bow;

    //! Final GridPosition of the ship
    GridPosition stern;

public:

    /**
     * \brief		: Parametrised Constructor for ship class
     * \param [IN]	: const GridPosition& bow - Reference to the bow of the ship
     * \param [IN]	: const GridPosition& stern - Reference to the stern of the ship
     * \return		: NONE
     */
    Ship(const GridPosition& bow, const GridPosition& stern);

    /**
     * \brief		: To check the validity of the bow and stern grid positions
     * \details		: Checks for validity of bow and stern
     * 				  Checks if the length lies between 2 and 5
     * 				  Checks if the alignment of the ship is not Invalid
     * \param		: NONE
     * \return		: True - If all the above conditions are satisfied (Ship is Valid)
     * 				  False - If otherwise
     */
    bool isValid() const;

    /**
     * \brief		: Getter method for Bow attribute
     * \param		: NONE
     * \return		: GridPosition - Bow of the ship
     */
    GridPosition getBow() const;

    /**
     * \brief		: Getter method for Stern attribute
     * \param		: NONE
     * \return		: GridPosition - Stern of the ship
     */
    GridPosition getStern() const;

    /**
     * \brief		: Method to calculate the length of the Ship and set the alignment flag
     * \param		: NONE
     * \return		: int - Length of the ship
     */
    int length() const;

    /**
     * \brief		: Method to calculate the grid positions occupied by the ship
     * \param		: NONE
     * \return		: std::set<GridPosition> - Grid positions occupied by the ship
     */
    const std::set<GridPosition> occupiedArea() const;

    /**
     * \brief		: Method to calculate the 8 diagonal elements for each grid position
     * \param		: NONE
     * \return		: std::set<GridPosition> - Invalid grid positions
     */
    const std::set<GridPosition> blockedArea() const;

};

/********************
**  CLASS END
*********************/
#endif /* SHIP_H */

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file Shot.h
 *	\brief Header file for Shot class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

class Shot
{
private:
	//! Grid position object to hold the target position
	GridPosition targetPosition;

public:
    /**
     * \brief 		: Parametrised constructor
     * \param[IN]	: GridPosition targetPosition - An object of grid position
     * \return		: NONE
     */
	Shot(GridPosition targetPosition);

	//! Enum to store the state of the ship
	typedef enum
	{
		NONE,
		HIT,
		SUNKEN
	}Impact;

	/**
	 * \brief		: Function to get the target position that has to be shot
	 * \param		: NONE
	 * \return		: GridPosition - Returns the grid position of the target that is to be shot
	 */
	GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file Shot.cpp
 *	\brief Source file for Shot class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

//! User include files
#include "Shot.h"

/********************** Method Implementations ******************************/

/**
 * \brief 		: Parametrised constructor
 * \param [IN]	: GridPosition targetPosition - An object of grid position
 * \return		: NONE
 */
Shot::Shot(GridPosition targetPosition)
	:targetPosition(targetPosition)
{}

/**
 * \brief		: Function to get the target position that has to be shot
 * \param		: NONE
 * \return		: GridPosition - Returns the grid position of the target that is to be shot
 */
GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}

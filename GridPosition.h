/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file GridPosition.h
 *	\brief Header file for GridPosition class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

#ifndef GRIDPOSITION_H
#define GRIDPOSITION_H

//! System Include files
#include <iostream>
#include <string>

class GridPosition {

private:

	//! Position of the row in the grid
    char row;

    //! Position of the column in the grid
    int column;

public:
    /*!
     * \brief 		: Constructor to update the row and column position of the Grid
     * \param [IN] 	: char row - Row of the grid position
     * \param [IN]	: int column - column of the grid position
     * \return		: NONE
     */
    GridPosition(char row, int column);

    /*!
     * \brief 		: Constructor that updates the position in the Grid as a string
     * \param [IN]	: std::string position - string position from the overloaded std::string operator
     * \return		: NONE
     */
    GridPosition(std::string position);

    /*!
     * \brief		: To check the validity of the row and column
     * \param		: NONE
     * \return		: bool - True if the parameters are valid
     * 				   		 False if the parameters are invalid
     */
    bool isValid() const;

    /*!
     * \brief		: Getter method for row
     * \param		: NONE
     * \return		: char - Row of the grid position
     */
    char getRow() const;

    /*!
     * \brief		: Getter method for column
     * \param		: NONE
     * \return		: int - Column value of the grid position
     */
    int getColumn() const;

    /*!
     * \brief		: Overloading operator ==
     * \param [IN]	: GridPosition other - An object of type GridPosition
     * \return		: bool - True: If the row and column are equal
     * 						 False: If they are unequal
     */
    bool operator==(GridPosition other) const;

    /*!
     * \brief		: Overloading operator <
     * \details		: The overloaded operator < is used by STL "set container" and "map container"
     * 			 	  to compare the grid positions and order the elements in ascending order.
     * \param [IN] 	: GridPosition other - An object of type GridPosition
     * \return		: bool - True: If the row is less than the row of other object,
     * 							   If the row are equal, and if the column is less than the column of the other object
     * 						 False: If both row and column are greater than other objects row and column
     */
    bool operator<(GridPosition other) const;

    /*!
     * \brief		: Overloaded cast to string method
     * \details		: The following method when called returns the concatenated string to the method that expects a string
     * \param		: NONE
     * \return 		: position - Row and column are concatenated and a string that holds the Grid Position is returned
     */
    operator std::string() const;
};

/********************
**  CLASS END
*********************/
#endif /* GRIDPOSITION_H */

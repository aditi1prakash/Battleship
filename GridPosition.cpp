/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
/*! \file GridPosition.cpp
 *	\brief Source file for GridPosition class
 *
 *  Created on: 02-01-2020
 *  Author: Aditi Prakash
 */
/****************************************************************************/

//! System Include Files
#include <iostream>
#include <string>

//! Own Include Files
#include "GridPosition.h"

/********************** Method Implementations ******************************/

/*!
 * \brief 		: Constructor to update the row and column position of the Grid
 * \param 		: NONE
 * \return		: NONE
 */
GridPosition::GridPosition(char row, int column)
	:row{row},column{column}
{
	//! Check for validity of row and column before converting it to a string
	if(isValid())
	{
		//! To convert row and column into a Grid Position
		(*this).operator std::string();
	}
}

/*!
 * \brief 		: Constructor that updates the position in the Grid as a string
 * \param[IN]	: std::string position - string position from the overloaded std::string operator
 * \return		: NONE
 */
GridPosition::GridPosition(std::string position)
{
	//! Create a local copy of the position
	std::string str = position;

	//! Assign the first position to row
	this->row = position.at(0);

	//!The remaining characters of the string to the column
	this->column = std::stoi(str.substr(1,2));
}

/*!
 * \brief		: To check the validity of the row and column
 * \param		: NONE
 * \return		: bool - True if the parameters are valid
 * 				   		 False if the parameters are invalid
 */
bool GridPosition::isValid() const
{
	//! Row is invalid if it does not belong to the alphabet set
	//! Column is invalid if the value is negative
	if (getRow() < 'A' || getRow() > 'Z' || getColumn() <= 0)
		return false;
	return true;
}

/*!
 * \brief		: Getter method for row
 * \param		: NONE
 * \return		: char - Row of the grid position
 */
char GridPosition::getRow() const
{
	return row;
}

/*!
 * \brief		: Getter method for column
 * \param		: NONE
 * \return		: int - Column value of the grid position
 */
int GridPosition::getColumn() const
{
	return column;
}

/*!
 * \brief		: Overloading operator ==
 * \param		: GridPosition other - An object of type GridPosition
 * \return		: bool - True: If the row and column are equal
 * 						 False: If they are unequal
 */
bool GridPosition::operator==(GridPosition other) const
{
	if(this->row == other.row && this->column == other.column)
		return true;
	return false;
}

/*!
 * \brief		: Overloading operator <
 * \details		: The overloaded operator < is used by STL "set container" and "map container"
 * 			 	  to compare the grid positions and order the elements in ascending order.
 * \param		: GridPosition other - An object of type GridPosition
 * \return		: bool - True: If the row is less than the row of other object,
 * 							   If the row are equal, and if the column is less than the column of the other object
 * 						 False: If both row and column are greater than other objects row and column
 */
bool GridPosition::operator<(GridPosition other) const
{
	if(this->row < other.row )
	{
		return true;
	}
	if (this->row == other.row && this->column < other.column)
	{
		return true;
	}
	return false;
}

/*!
 * \brief		: Overloaded cast to string method
 * \details		: The following method when called returns the concatenated string to the method that expects a string
 * \param		: NONE
 * \return 		: position - Row and column are concatenated and a string that holds the Grid Position is returned
 */
GridPosition::operator std::string() const
{
	std::string position = row + std::to_string(column);
	return position;
}

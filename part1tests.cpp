/*
 * part1tests.cpp
 *
 *  Created on: 15.11.2019
 *      Author: mnl
 */

#include <iostream>

using namespace std;

#include "part1tests.hpp"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition - the condition
 * @param failedMessage - the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 */
void part1tests () {

    // Test GridPosition constructor
    assertTrue(GridPosition{'A', 1}.isValid(), "A1 not considered valid");
    assertTrue(!GridPosition{'A', -1}.isValid(), "A-1 considered valid");
    assertTrue(!GridPosition{'@', 1}.isValid(), "@1 considered valid");
    GridPosition fromRowCol{'A', 1};
    GridPosition fromString{"A1"};
    assertTrue(fromRowCol.getRow() == fromString.getRow()
            && fromRowCol.getColumn() == fromString.getColumn(),
            "different constructors return different objects");

    // Test getters and cast to string
    GridPosition pos1 = GridPosition{'B', 13};
    assertTrue(pos1.getRow() == 'B',
            "GridPosition::GridPosition doesn't set row properly.");
    assertTrue(pos1.getColumn() == 13,
            "GridPosition::GridPosition doesn't set column properly.");
    assertTrue((string)pos1 == "B13", "Conversion to string fails.");

    // Test comparison
    assertTrue(!(GridPosition{"A1"} < GridPosition{"A1"}),
            "Same positions considered different by '<'");
    assertTrue(GridPosition{"A1"} < GridPosition{"B1"},
            "Position with bigger row not considered greater");
    assertTrue(GridPosition{"A1"} < GridPosition{"A2"},
            "Position with bigger column not considered greater");
    assertTrue(GridPosition{"C21"} == GridPosition{"C21"},
            "Equal positions not considered equal.");

    // Test Ship Constructor
    assertTrue(!(Ship{GridPosition{"B2"}, GridPosition{"C3"}}.isValid()),
            "Can create non-aligned ship.");
    assertTrue(!(Ship{GridPosition{"B2"}, GridPosition{"B2"}}.isValid()),
            "Can create ship of size 1.");
    assertTrue(!(Ship{GridPosition{"B2"}, GridPosition{"B7"}}.isValid()),
            "Can create ship of size 6.");
    assertTrue(!(Ship{GridPosition{"E3"}, GridPosition{"E5"}}.isValid()),
    		"Can create ship of size 3.");

    // Length
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.length() == 3,
            "Length is not 3");
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.length() == 4,
            "Length is not 4");

    //Occupied area
    assertTrue(Ship{GridPosition{"B4"}, GridPosition{"B6"}}.occupiedArea()
            == set<GridPosition>{GridPosition{"B4"}, GridPosition{"B5"},
                    GridPosition{"B6"}},
            "Occupied area not correct");

    assertTrue(Ship{GridPosition{"D6"}, GridPosition{"H6"}}.occupiedArea()
    		== set<GridPosition>{GridPosition{"D6"}, GridPosition{"E6"}, GridPosition{"F6"}, GridPosition{"G6"}, GridPosition{"H6"}},
				"Occupied area not correct");

    //Blocked area
   assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.blockedArea()
		   == set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"}, GridPosition{"A3"}, GridPosition{"A4"}, GridPosition{"A5"},
	          GridPosition{"B1"}, GridPosition{"B2"}, GridPosition{"B3"}, GridPosition{"B4"}, GridPosition{"B5"},
		      GridPosition{"C1"}, GridPosition{"C2"}, GridPosition{"C3"}, GridPosition{"C4"}, GridPosition{"C5"}}, "Incorrect blocked area");

   assertTrue(Ship{GridPosition{"E7"}, GridPosition{"F7"}}.blockedArea()
  		   == set<GridPosition>{GridPosition{"D6"}, GridPosition{"E6"}, GridPosition{"F6"}, GridPosition{"G6"},
	   	   	  GridPosition{"D7"}, GridPosition{"E7"}, GridPosition{"F7"}, GridPosition{"G7"},
			  GridPosition{"D8"}, GridPosition{"E8"}, GridPosition{"F8"}, GridPosition{"G8"}}, "Incorrect blocked area");

}



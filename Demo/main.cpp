//
//  main.cpp
//  Demo
//
//  Created by Felix Morgner on 23.03.11.
//  Copyright 2011 Bühler AG. All rights reserved.
//

#include <iostream>

#include "FMMP4Atom.h"

int main (int argc, const char * argv[])
	{
	FMMP4Atom atom1(" one");
	FMMP4Atom atom2(" two");
	FMMP4Atom atom22(" two");
	FMMP4Atom atom3("thre");
	
	atom1.ChildAdd(&atom2);
	atom1.ChildAdd(&atom22);
	atom1.ChildAdd(&atom3);

	FMMP4Atom *found = atom1.ChildGet(&atom2);
	std::vector<FMMP4Atom*> otherFound = atom1.ChildrenGet(" two");

	return 0;
	}


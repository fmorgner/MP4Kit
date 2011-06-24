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
	FMMP4Atom atom3("thre");
	
	atom1.AtomChildAdd(&atom2);

	FMMP4Atom *found = atom1.AtomChildGet(&atom2);
	
	return 0;
	}


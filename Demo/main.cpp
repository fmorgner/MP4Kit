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

	std::cout << "address of atom1: " << &atom1 << std::endl;
	std::cout << "address of atom2: " << &atom2 << std::endl;
	std::cout << "address of atom22: " << &atom22 << std::endl;
	std::cout << "address of atom3: " << &atom3 << std::endl << std::endl;
	
	atom1.ChildAdd(&atom2);
	atom1.ChildAdd(&atom22);
	atom1.ChildAdd(&atom3);

	FMMP4Atom *found = atom1.ChildGet(&atom3);
	std::vector<FMMP4Atom*> otherFound = atom1.ChildrenGet(" two");

	std::cout << "found " << found << " for search for atom3"<< std::endl;

	for(std::vector<FMMP4Atom*>::iterator it = otherFound.begin(); it != otherFound.end(); it++)
		{
		std::cout << "found " << *it << " for search for atom with name being \" two\"" << std::endl;
		}

	return 0;
	}


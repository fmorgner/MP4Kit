//
//  main.cpp
//  Demo
//
//  Created by Felix Morgner on 23.03.11.
//  Copyright 2011 Bühler AG. All rights reserved.
//

#include <iostream>

#include "CAtom.h"

int main (int argc, const char * argv[])
	{
	char dataArray[] = {0x73, 0x6F, 0x6D, 0x65, 0x64, 0x61, 0x74, 0x61};
	std::vector<unsigned char> dataVector = std::vector<unsigned char>(dataArray, dataArray+8);
	std::vector<unsigned char> secondDataVector = std::vector<unsigned char>(dataArray, dataArray+8);
	
	CAtom atom1(" one");
	CAtom atom2(" two");
	CAtom atom22(" two");
	CAtom atom3("thre");

	CAtom dataAtom("four", dataVector);

	std::cout << "address of atom1: " << &atom1 << std::endl;
	std::cout << "address of atom2: " << &atom2 << std::endl;
	std::cout << "address of atom22: " << &atom22 << std::endl;
	std::cout << "address of atom3: " << &atom3 << std::endl;
	std::cout << "address of dataAtom: " << &dataAtom << std::endl << std::endl;
	
	atom1.ChildAdd(&atom2);
	atom1.ChildAdd(&atom22);
	atom1.ChildAdd(&atom3);
	atom1.ChildAdd(&dataAtom);

	CAtom *atom3found = atom1.ChildGet(&atom3);
	CAtom *dataAtomFound = atom1.ChildGet(secondDataVector);
	std::vector<CAtom*> atom2and22found = atom1.ChildrenGet(" two");

	std::cout << "found " << atom3found << " for search for atom3"<< std::endl;
	std::cout << "found " << dataAtomFound << " for search for atom containing secondDataVector"<< std::endl;

	for(std::vector<CAtom*>::iterator it = atom2and22found.begin(); it != atom2and22found.end(); it++)
		{
		std::cout << "found " << *it << " for search for atom with name being \" two\"" << std::endl;
		}

	return 0;
	}


/*
 *  FMMP4Atom.h
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

#ifndef __FMMP4ATOM_H
#define __FMMP4ATOM_H

#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FMMP4Atom
	{
	public:
		 FMMP4Atom();
		 FMMP4Atom(string sName);
		 FMMP4Atom(string sName, int nLength);
		~FMMP4Atom();
	
	public:
		string NameGet();
		int LengthGet();
		FMMP4Atom* ChildGet(FMMP4Atom* poAtom);
		FMMP4Atom* ChildGet(string sAtomName);

	public:
		void ChildAdd(FMMP4Atom* child);


	protected:
		string m_sName;
		vector<FMMP4Atom*> m_vChildren;
		int m_nLength;
	};

#endif

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

class FMMP4Atom
	{
	public:
		 FMMP4Atom();
		 FMMP4Atom(std::string sName);
		 FMMP4Atom(std::string sName, std::vector<unsigned char> vData);
		~FMMP4Atom();
	
	public:
		std::string NameGet();

		unsigned long LengthGet();

		void        ChildAdd(FMMP4Atom*  poAtom);
		
		FMMP4Atom*  ChildGet(FMMP4Atom*  poAtom);
		FMMP4Atom*  ChildGet(std::string sAtomName);

	protected:
		std::string m_sName;
		
		std::vector<FMMP4Atom*>    m_vChildren;
		std::vector<unsigned char> m_vData;
		
		int m_nLength;
	};

#endif

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

class FMMP4Atom
	{
	public:
		FMMP4Atom();
		FMMP4Atom(std::string atomName);
		~FMMP4Atom();
	
	public:
		std::string AtomNameGet();
		int AtomLengthGet();
		void AtomChildAdd(FMMP4Atom* child);
		FMMP4Atom* AtomChildGet(std::string atomName);

	protected:
		std::string m_sAtomName;
		int m_nAtomLength;
		std::vector<FMMP4Atom*> m_lChildren;
	};

#endif

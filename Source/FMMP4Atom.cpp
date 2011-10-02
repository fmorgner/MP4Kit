/*
 *  FMMP4Atom.cpp
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

#include "FMMP4Atom.h"

#pragma mark Construction and Deconstruction:

FMMP4Atom::FMMP4Atom()
	{
	m_sName = string("");
	}

FMMP4Atom::FMMP4Atom(string sName)
	{
	m_sName = sName;
	}

FMMP4Atom::~FMMP4Atom()
	{
	}

#pragma mark 
#pragma mark Public accessors:

std::string FMMP4Atom::NameGet()
	{
	return m_sName;
	}

int FMMP4Atom::LengthGet()
	{
	return m_nLength;
	}

void FMMP4Atom::ChildAdd(FMMP4Atom* child)
	{
	m_vChildren.push_back(child);
	}

FMMP4Atom* FMMP4Atom::ChildGet(FMMP4Atom* poAtom)
	{
	std::vector<FMMP4Atom*>::iterator it;
	
	it = find(m_vChildren.begin(), m_vChildren.end(), poAtom);
	
	return *it;
	}

FMMP4Atom* FMMP4Atom::ChildGet(string sAtomName)
	{
	FMMP4Atom* foundAtom;
	
	for(std::vector<FMMP4Atom*>::iterator it = m_vChildren.begin(); it != m_vChildren.end(); it++)
		{
		if(!((FMMP4Atom*)*it)->NameGet().compare(sAtomName))
			{
			foundAtom = *it;
			break;
			}
		}
	
	return foundAtom;
	}

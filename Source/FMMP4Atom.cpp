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
	m_sAtomName = std::string("");
	}

FMMP4Atom::FMMP4Atom(std::string atomName)
	{
	m_sAtomName = atomName;
	}

FMMP4Atom::~FMMP4Atom()
	{
	}

#pragma mark 
#pragma mark Public accessors:

std::string FMMP4Atom::AtomNameGet()
	{
	return m_sAtomName;
	}

int FMMP4Atom::AtomLengthGet()
	{
	return m_nAtomLength;
	}

void FMMP4Atom::AtomChildAdd(FMMP4Atom* child)
	{
	m_lChildren.push_back(child);
	}

FMMP4Atom* FMMP4Atom::AtomChildGet(std::string atomName)
	{
	return NULL;
	}

/*
 *  FMMP4Atom.cpp
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

#include "FMMP4Atom.h"

using namespace std;

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
	m_lChildren.push_back(child);
	}

FMMP4Atom* FMMP4Atom::ChildGet(FMMP4Atom* atom)
	{
	vector<FMMP4Atom*>::iterator it;
	
	it = find(m_lChildren.begin(), m_lChildren.end(), atom);
	
	return *it;
	}

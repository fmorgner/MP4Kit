/*
 *  MP4Atom.cpp
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Bühler AG. All rights reserved.
 *
 */

#include "MP4Atom.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma mark Construction and Deconstruction:

MP4Atom::MP4Atom()
	{
	m_acAtomName = (char*)malloc(4*sizeof(char));
	}

MP4Atom::MP4Atom(char* atomName, bool bIsParent)
	: m_acAtomName(atomName),
		m_bIsParent(bIsParent){
	}

MP4Atom::~MP4Atom()
	{
	}

#pragma mark 
#pragma mark Public accessors:

char* MP4Atom::getAtomName()
	{
	return this->m_acAtomName;
	}

int MP4Atom::getAtomLength()
	{
	return this->m_nAtomLength;
	}

#pragma mark 
#pragma mark Protected accessors:

void MP4Atom::setAtomName(const char* atomName)
	{
	memcpy(this->m_acAtomName, atomName, 4);
	}

void MP4Atom::setIsParent(bool bIsParent)
	{
	this->m_bIsParent = bIsParent;
	}

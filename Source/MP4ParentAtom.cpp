/*
 *  MP4ParentAtom.cpp
 *  MP4Kit
 *
 *  Created by Felix Morgner on 25.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

#include "MP4ParentAtom.h"

#pragma mark Construction / Desconstruction:

MP4ParentAtom::MP4ParentAtom()
	{
	}

MP4ParentAtom::MP4ParentAtom(MP4Atom* childAtom, bool isChildAtom, MP4ParentAtom* parentAtom)
	{
	addChildAtom(childAtom);
	}

MP4ParentAtom::MP4ParentAtom(atomname_t atomName, bool isChildAtom, MP4ParentAtom* parentAtom)
	{
	setAtomName(atomName);
	m_bIsChildAtom = isChildAtom;
	if(isChildAtom && parentAtom != NULL)
		{
		parentAtom->addChildAtom(this);
		}
	}

MP4ParentAtom::~MP4ParentAtom()
	{
	}

#pragma mark 
#pragma mark Public accessors:

void MP4ParentAtom::addChildAtom(MP4Atom* childAtom)
	{
	m_lpChildAtoms.push_back(childAtom);
	}

void MP4ParentAtom::addChildAtom(MP4ParentAtom* childAtom)
	{
	m_lpChildAtoms.push_back(childAtom);
	}

bool MP4ParentAtom::getIsChildAtom()
	{
	return m_bIsChildAtom;
	}

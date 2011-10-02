/*
 *  FMMP4Atom.cpp
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

#include "FMMP4Atom.h"

#pragma mark 
#pragma mark Construction and Destruction:
#pragma mark 

FMMP4Atom::FMMP4Atom()
	{
	m_sName = std::string();
	m_vData = std::vector<unsigned char>();
	m_nLength = m_vData.size();
	}

FMMP4Atom::FMMP4Atom(std::string sName)
	{
	m_sName = sName;
	m_vData = std::vector<unsigned char>();
	m_nLength = m_vData.size();
	}

FMMP4Atom::FMMP4Atom(std::string sName, std::vector<unsigned char> vData)
	{
	m_sName = sName;
	m_vData = vData;
	m_nLength = m_vData.size();
	}

FMMP4Atom::~FMMP4Atom()
	{
	}

#pragma mark 
#pragma mark General accessors:
#pragma mark 

std::string FMMP4Atom::NameGet()
	{
	return m_sName;
	}

unsigned long FMMP4Atom::LengthGet()
	{
	return m_nLength;
	}

#pragma mark 
#pragma mark Children accessors:
#pragma mark 

void FMMP4Atom::ChildAdd(FMMP4Atom* poAtom)
	{
	m_vChildren.push_back(poAtom);
	}

FMMP4Atom* FMMP4Atom::ChildGet(FMMP4Atom* poAtom)
	{
	std::vector<FMMP4Atom*>::iterator it;
	
	it = find(m_vChildren.begin(), m_vChildren.end(), poAtom);
	
	return *it;
	}

FMMP4Atom* FMMP4Atom::ChildGet(std::vector<unsigned char> vData)
	{
	FMMP4Atom* foundAtom = NULL;
	
	for(std::vector<FMMP4Atom*>::iterator it = m_vChildren.begin(); it != m_vChildren.end(); it++)
		{
		if(!equal(((FMMP4Atom*)*it)->DataGet().begin() , ((FMMP4Atom*)*it)->DataGet().end() , vData.begin()))
			{
			foundAtom = *it;
			break;
			}
		}
	
	return foundAtom;
	}

std::vector<FMMP4Atom*> FMMP4Atom::ChildrenGet(std::string sAtomName)
	{
	std::vector<FMMP4Atom*> vFoundAtoms = std::vector<FMMP4Atom*>();
	
	for(std::vector<FMMP4Atom*>::iterator it = m_vChildren.begin(); it != m_vChildren.end(); it++)
		{
		if((*it)->NameGet() == sAtomName)
			{
			vFoundAtoms.push_back(*it);
			}
		}
	
	return vFoundAtoms;
	}

#pragma mark 
#pragma mark Data accessors:
#pragma mark 

void FMMP4Atom::DataSet(std::vector<unsigned char> vData)
	{
	m_vData = vData;
	m_nLength = m_vData.size();
	}

void FMMP4Atom::DataAppend(std::vector<unsigned char> vData)
	{
	for(std::vector<unsigned char>::iterator it = vData.begin(); it != vData.end(); it++)
		{
		m_vData.push_back(*it);
		}
	m_nLength = m_vData.size();
	}

std::vector<unsigned char> FMMP4Atom::DataGet()
	{
	return m_vData;
	}

/*
 *  CAtom.cpp
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

#include "CAtom.h"

CAtom::CAtom()
  {
  m_sName = std::string();
  m_vData = std::vector<unsigned char>();
  m_nLength = m_vData.size();
  }

CAtom::CAtom(std::string sName)
  {
  m_sName = sName;
  m_vData = std::vector<unsigned char>();
  m_nLength = m_vData.size();
  }

CAtom::CAtom(std::string sName, std::vector<unsigned char> vData)
  {
  m_sName = sName;
  m_vData = vData;
  m_nLength = m_vData.size();
  }

CAtom::~CAtom()
  {
  }

std::string CAtom::NameGet()
  {
  return m_sName;
  }

unsigned long CAtom::LengthGet()
  {
  return m_nLength;
  }

void CAtom::ChildAdd(CAtom* poAtom)
  {
  m_vChildren.push_back(poAtom);
  }

CAtom* CAtom::ChildGet(CAtom* poAtom)
  {
  std::vector<CAtom*>::iterator it;

  it = find(m_vChildren.begin(), m_vChildren.end(), poAtom);

  return *it;
  }

CAtom* CAtom::ChildGet(std::vector<unsigned char> vData)
  {
  CAtom* foundAtom = NULL;

  for(std::vector<CAtom*>::iterator it = m_vChildren.begin(); it != m_vChildren.end(); it++)
    {
    if(!equal(((CAtom*)*it)->DataGet().begin() , ((CAtom*)*it)->DataGet().end() , vData.begin()))
      {
      foundAtom = *it;
      break;
      }
    }

  return foundAtom;
  }

std::vector<CAtom*> CAtom::ChildrenGet(std::string sAtomName)
  {
  std::vector<CAtom*> vFoundAtoms = std::vector<CAtom*>();

  for(std::vector<CAtom*>::iterator it = m_vChildren.begin(); it != m_vChildren.end(); it++)
    {
    if((*it)->NameGet() == sAtomName)
      {
      vFoundAtoms.push_back(*it);
      }
    }

  return vFoundAtoms;
  }

void CAtom::DataSet(std::vector<unsigned char> vData)
  {
  m_vData = vData;
  m_nLength = m_vData.size();
  }

void CAtom::DataAppend(std::vector<unsigned char> vData)
  {
  for(std::vector<unsigned char>::iterator it = vData.begin(); it != vData.end(); it++)
    {
    m_vData.push_back(*it);
    }
  m_nLength = m_vData.size();
  }

std::vector<unsigned char> CAtom::DataGet()
  {
  return m_vData;
  }


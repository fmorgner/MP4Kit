/*
 *  CAtom.h
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

class CAtom
  {
  public:
    CAtom();
    CAtom(std::string sName);
    CAtom(std::string sName, std::vector<unsigned char> vData);
    ~CAtom();

    void NameSet();
    std::string NameGet();

    void DataSet(std::vector<unsigned char> vData);
    void DataAppend(std::vector<unsigned char> vData);
    std::vector<unsigned char> DataGet();

    unsigned long LengthGet();

    void ChildAdd(CAtom*  poAtom);
    void ChildRemove(CAtom* poAtom);
    void ChildRemove(std::string sAtomName);

    CAtom* ChildGet(CAtom* poAtom);
    CAtom* ChildGet(std::vector<unsigned char> vData);
    std::vector<CAtom*> ChildrenGet(std::string sAtomName);

  protected:
    std::string m_sName;

    std::vector<CAtom*>    m_vChildren;
    std::vector<unsigned char> m_vData;

    unsigned long m_nLength;
  };

#endif

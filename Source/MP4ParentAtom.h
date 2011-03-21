/*
 *  MP4ParentAtom.h
 *  MP4Kit
 *
 *  Created by Felix Morgner on 25.10.10.
 *  Copyright 2010 Bühler AG. All rights reserved.
 *
 */

#include "MP4Atom.h"
#include <list>

class MP4ParentAtom : public MP4Atom
	{
	public:
		MP4ParentAtom();
		MP4ParentAtom(MP4Atom* childAtom, bool isChildAtom, MP4ParentAtom* parentAtom);
		MP4ParentAtom(atomname_t atomName, bool isChildAtom, MP4ParentAtom* parentAtom);
		~MP4ParentAtom();
		
		void addChildAtom(MP4Atom* childAtom);
		void addChildAtom(MP4ParentAtom* childAtom);
		bool getIsChildAtom();
		
	protected:
		std::list<MP4Atom*> m_lpChildAtoms;
		bool m_bIsChildAtom; 
	};
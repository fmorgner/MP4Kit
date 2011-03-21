/*
 *  MP4Container.h
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Bühler AG. All rights reserved.
 *
 */
#include "MP4ParentAtom.h"

#include <string.h>
#include <map>
#include <list>

using namespace std;

class MP4Container
	{
	public:
		MP4Container();
		~MP4Container();
		
	protected:
		map<char*, int> m_atomPositionMap;
		list<MP4ParentAtom*> m_loParentAtoms;

	protected:
		unsigned int bytesToInt(char* bytes);
		bool isParentAtom(const char* atomName);
		
	public:
		int preflight(const char* filename);
	};

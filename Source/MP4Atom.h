/*
 *  MP4Atom.h
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

typedef char atomname_t[4];

class MP4Atom
	{
	public:
		MP4Atom();
		MP4Atom(char* atomName, bool bIsParent);
		~MP4Atom();
		char* getAtomName();
		int getAtomLength();
		
	protected:
		void setAtomName(const char* atomName);
		void setIsParent(bool bIsParent);

	protected:
		char* m_acAtomName;
		int m_nAtomLength;
		bool m_bIsParent;
		MP4Atom* childAtom;
	};

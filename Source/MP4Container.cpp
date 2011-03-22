/*
 *  MP4Container.cpp
 *  MP4Kit
 *
 *  Created by Felix Morgner on 21.10.10.
 *  Copyright 2010 Felix Morgner. All rights reserved.
 *
 */

#include "MP4Container.h"
#include <algorithm>

#pragma mark Construction / Deconstruction:

MP4Container::MP4Container()
	{
//	MP4ParentAtom* moovAtom = new MP4ParentAtom((char[4]){0x6D, 0x6F, 0x6F, 0x76}, false, NULL); // The moov atom is a root atom with several children.
//	MP4ParentAtom* udtaAtom = new MP4ParentAtom((char[4]){0x75, 0x64, 0x74, 0x61}, false, NULL); // The udta atom is a root atom with several children.
//	
//	m_loParentAtoms.push_back(moovAtom);
//	m_loParentAtoms.push_back(udtaAtom);
//
//	MP4ParentAtom* trakAtom = new MP4ParentAtom((char[4]){0x74, 0x72, 0x61, 0x6B}, true, moovAtom);
//	MP4ParentAtom* edtsAtom = new MP4ParentAtom((char[4]){0x65, 0x64, 0x74, 0x73}, true, trakAtom);
//	MP4ParentAtom* mdiaAtom = new MP4ParentAtom((char[4]){0x6D, 0x64, 0x69, 0x61}, true, trakAtom);
//	MP4ParentAtom* minfAtom = new MP4ParentAtom((char[4]){0x6D, 0x69, 0x6E, 0x66}, true, mdiaAtom);
//	MP4ParentAtom* dinfAtom = new MP4ParentAtom((char[4]){0x64, 0x69, 0x6E, 0x66}, true, minfAtom);
//	MP4ParentAtom* stblAtom = new MP4ParentAtom((char[4]){0x73, 0x74, 0x62, 0x6C}, true, minfAtom);
//	MP4ParentAtom* metaAtom = new MP4ParentAtom((char[4]){0x6D, 0x65, 0x74, 0x61}, true, udtaAtom);
//	
//	m_loParentAtoms.push_back(trakAtom);
//	m_loParentAtoms.push_back(edtsAtom);
//	m_loParentAtoms.push_back(mdiaAtom);
//	m_loParentAtoms.push_back(minfAtom);
//	m_loParentAtoms.push_back(dinfAtom);
//	m_loParentAtoms.push_back(stblAtom);
//	m_loParentAtoms.push_back(metaAtom);
	}
	
MP4Container::~MP4Container()
	{
	}

#pragma mark 
#pragma mark Methods:

int MP4Container::preflight(const char* filename)
	{	
	FILE* pFile = fopen(filename, "rb");
	fseek(pFile, 0, SEEK_SET);
	printf("%s\n", filename);
	
	char* atomBytes = (char*)malloc(8);
	char* sizeInformation = (char*)malloc(4);
	char* atomName = (char*)malloc(4);

	char stopAtom[4] = {0x6D, 0x64, 0x61, 0x74};

	while(memcmp(atomName, stopAtom, 4))
		{
		fread(atomBytes, 8, 1, pFile);
		
		memcpy(sizeInformation, atomBytes, 4);
		memcpy(atomName, atomBytes + 4, 4);
	
		int atomSize = bytesToInt(atomBytes);

		this->m_atomPositionMap[atomName] = ftell(pFile);
		
		
		
		if(isParentAtom(atomName))
			{
			printf("found parent atom \"%s\" of size %i at position %i.\n", atomName, atomSize, (int)ftell(pFile)-8);
			fseek(pFile, 0, SEEK_CUR);			
			}
		else
			{
			printf("found atom \"%s\" of size %i at position %i.\n", atomName, atomSize, (int)ftell(pFile)-8);
			fseek(pFile, atomSize-8, SEEK_CUR);
			}
		}
	fclose(pFile);
	
	free(atomBytes);
	free(atomName);
	free(sizeInformation);
	return 0;
	}

#pragma mark 
#pragma mark Helper methods:

unsigned int MP4Container::bytesToInt(char *bytes)
	{
	unsigned int result = 0;
	unsigned char singleByte;
	
	unsigned char* uBytes = reinterpret_cast<unsigned char*>(bytes);
	
	singleByte = uBytes[0];
	result = uBytes[0] << 24;
	singleByte = uBytes[1];
	
	result |= uBytes[1] << 16;
	singleByte = uBytes[2];
	result |= uBytes[2] <<  8;
	singleByte = uBytes[3];
	result |= uBytes[3];
	
	return result;
	}

bool MP4Container::isParentAtom(const char* atomName)
	{	
	list<MP4ParentAtom*>::iterator it;
	
	for(it = m_loParentAtoms.begin(); it != m_loParentAtoms.end(); it++)
		{
		if(memcmp(atomName, (*it)->getAtomName(), 4) == 0)
			return true;
		}
	
	return false;
	}

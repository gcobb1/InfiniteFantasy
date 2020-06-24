/*****
Author: Gavin Cobb
Date: February 2020

*****/

#define OLC_PGE_APPLICATION
#include "Menu.h"
#include "olcPixelGameEngine.h"
#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>
constexpr int32_t nPatch = 8;


//Creation of the flappy sprite and and the drawing of it on the screen depending on position of x and y
//Created in patches
class flappy
{
public:
	flappy(){
	}

	void DrawFlappy(olc::PixelGameEngine& pge, olc::Sprite* sprGFX, olc:: vi2d vScreenOffset){
	
	
	olc::Pixel::Mode currentPixelMode = pge.GetPixelMode();
	pge.SetPixelMode(olc::Pixel::MASK);

	olc::vi2d vPatchPos = { 0,0 };
	
	for(vPatchPos.x = 0; vPatchPos.x < vSizeInPatches.x; vPatchPos.x++){
		
		for(vPatchPos.y = 0; vPatchPos.y < vSizeInPatches.y; vPatchPos.y++){
			olc::vi2d vScreenLocation = vPatchPos * nPatch + vScreenOffset;
			olc::vi2d vSourcePatch = { 0, 0};

			vSourcePatch.x = vPatchPos.x;
			vSourcePatch.y = vPatchPos.y;
			pge.DrawPartialSprite(vScreenLocation, sprGFX, vSourcePatch * nPatch, vPatchSize);
		}
	}
}
protected:
	olc::vi2d vSizeInPatches = {4,4};
	const olc::vi2d vPatchSize = { nPatch, nPatch };


};


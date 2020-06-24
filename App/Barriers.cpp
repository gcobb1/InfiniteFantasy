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

//Creation of the barrier sprites and the drawing of it on the screen depending on the vertical offset and screen position 
//It is important to note that each barrier correlates to a new second barrier that is directly opposite, and that it contains a height that is inversely proporational in size
class Barriers
{
public:
	Barriers(){
	}
	
	void DrawBarriers(olc::PixelGameEngine& pge, olc::Sprite* sprGFX2, olc:: vi2d vScreenOffset, int lengthMults){
	
		olc::Pixel::Mode currentPixelMode = pge.GetPixelMode();
		pge.SetPixelMode(olc::Pixel::MASK);
	
		olc::vi2d vPatchPos = { 0,0 };
		int flag = 0;
		int i = 1;
		int j = 1;
		for(vPatchPos.x = 0; vPatchPos.x < vSizeInPatches.x; vPatchPos.x++){
			for(vPatchPos.y = 0; vPatchPos.y < vSizeInPatches.y; vPatchPos.y++){
				olc::vi2d vScreenLocation = vPatchPos * nPatch + vScreenOffset;
				olc::vi2d vSourcePatch = { 0, 0};
				vSourcePatch.x = vPatchPos.x;
				vSourcePatch.y = vPatchPos.y;
				if(vPatchPos.y == 1){
					for(i = 1; i <= lengthMults; i++){
						vScreenLocation.y = (vPatchPos.y * nPatch) * i + vScreenOffset.y;
						pge.DrawPartialSprite(vScreenLocation, sprGFX2, vSourcePatch * nPatch, vPatchSize);
					}
					flag = 1;
				}	
				else{
					if(flag == 0){
						pge.DrawPartialSprite(vScreenLocation, sprGFX2, vSourcePatch * nPatch, vPatchSize);
					}
					else if(flag == 1){
						j = lengthMults + 1;
						vScreenLocation.y = ((vPatchPos.y * nPatch)/2) * j + vScreenOffset.y;
						pge.DrawPartialSprite(vScreenLocation, sprGFX2, vSourcePatch * nPatch, vPatchSize);
					}
				}
			}
		}
	}

protected:
	olc::vi2d vSizeInPatches = {12,3};
	const olc::vi2d vPatchSize = { nPatch, nPatch };
};


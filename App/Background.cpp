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

//Creation of the background sprite
class background
{
public:
background() { }
 
void DrawBackground(olc::PixelGameEngine& pge, olc::Sprite* sprGFX4, olc:: vi2d vScreenOffset){
 
// Record current pixel mode user is using
	olc::Pixel::Mode currentPixelMode = pge.GetPixelMode();
	pge.SetPixelMode(olc::Pixel::MASK);
 
// Draw Panel & Border
	olc::vi2d vPatchPosB = { 0,0 };
	for (vPatchPosB.x = 0; vPatchPosB.x < vSizeInPatchesB.x; vPatchPosB.x++){
		for (vPatchPosB.y = 0; vPatchPosB.y < vSizeInPatchesB.y; vPatchPosB.y++){
			olc::vi2d vScreenLocationB = vPatchPosB * nPatch + vScreenOffset;
			olc::vi2d vSourcePatchB = { 0, 0};
                                vSourcePatchB.x = vPatchPosB.x;
 
                                vSourcePatchB.y = vPatchPosB.y;
                        	pge.DrawPartialSprite(vScreenLocationB, sprGFX4, vSourcePatchB * nPatch, vPatchSizeB);
                	}
		}
        }
protected:
        olc::vi2d vSizeInPatchesB = { 48, 38 };
	int32_t nTopVisibleRowB = 0;
	int32_t nTotalRowsB = 0;
	const olc::vi2d vPatchSizeB = { nPatch, nPatch };
 
};
// Override base class with your custom functionality


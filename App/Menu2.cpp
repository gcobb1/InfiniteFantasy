/*****
Author: Gavin Cobb
Date March 2020

Description: The purpose of this file is to the hold the class for creating the Menu object used for the leaderboard and game over sections
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

class Menu
{
public:
	Menu(){
	}
	N::menuobject mo;
	N::menumanager mm;
	void CreateMenu(){
		mo["main"].SetTable(1, 2);
        	mo["main"]["Play Again"].SetID(101);
 
        	mo["main"]["LeaderBoard"].SetID(102);
 		mo.Build();
		mm.Open(&mo["main"]);	 
	}
	
};


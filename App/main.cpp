
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










class olcFlappy : public olc::PixelGameEngine
{
public:
	olcFlappy()
	{
		sAppName = "Flappy Dude";
	}
	olc::Sprite* sprGFX = nullptr;
	olc::Sprite* sprGFX2 = nullptr;
	olc::Sprite* sprGFX3 = nullptr;
	olc::Sprite* sprGFX4 = nullptr;
	olc::Sprite* sprGFX5 = nullptr;
	Menu men;
	flappy flap;
	Barriers bar;
	background back;
	void Tofile(){
		outfile.open("HighScore.txt", std::ios::app);
		outfile << GetScounter() << std::endl;
		outfile.close();
		
	}
	std::string GetScounter(){
		return Scounter;
	}

	
	std::string infileMax3(){
		int max = stoi(Smax2);
		int max3 = stoi(Smax3);
		int max4 = 0;
		int counterish2 = 0;
		int counterish3 = 0;
		int number3;
		std::string Snumber3;
		infile.open("HighScore.txt");
		while(getline(infile,Snumber3)){
			number3 = stoi(Snumber3);
			if(number3 == max3 && max3 != max){
				counterish2++;
				if(counterish2 > 1){
					max4 = number3;
				}
			}
			else if(number3 == max){
				counterish3++;
				if(counterish3 > 2){
					max4 = number3;
				}
			}
			else if(number3 > max4){
				max4 = number3;
			}
		}
		infile.close();
		return std::to_string(max4);

	}
	std::string infileMax2(){
		int max = stoi(Smax2);
		int max2 = 0;
		int counterish = 0;
		int number2;
		std::string Snumber2;
		infile.open("HighScore.txt", std::ios::beg);
		while(getline(infile,Snumber2)){
			number2 = stoi(Snumber2);
			if(number2 == max){
				counterish ++;
				if(counterish > 1){
					max2 = number2;
				}
			}
			else if(number2 > max2){
				max2 = number2;
			}
		}
		infile.close();
		return std::to_string(max2);
	}
	std::string AverageScore(){
	int average = 0;
	std::string Snumber5;
	int total = 0;
	int Snum5;
	int numNums = 0;
	infile.open("Highscore.txt", std::ios::beg);
	while(getline(infile, Snumber5)){
		Snum5 = stoi(Snumber5);
		total = total + Snum5;
		numNums++;
	}
	if(numNums == 0){
		return std::to_string(0);
	}
	average = total / numNums;
	infile.close();
	return std::to_string(average);
	



	}				
	std::string infileMax(){
		int max7 = 0;
		std::string Snumber;
		int number;
		infile.open("HighScore.txt", std::ios::beg);
		while(getline(infile, Snumber)){
			number = stoi(Snumber);
			if(number > max7){
				max7 = number;
			}
		}
		infile.close();
		return std::to_string(max7);
	}
public:
	bool OnUserCreate() override
	{	
		
	//	outfile.open("HighScore.txt", std::ios::app);
		Smax2 = infileMax();
		Smax3 = infileMax2();
		Smax4 = infileMax3();
		Average = AverageScore();
		resetGame = false;
		flag4 = 0;
		men.CreateMenu();
		sprGFX5 = new olc::Sprite("./Images/RetroMenu3.png");
		sprGFX4 = new olc::Sprite("./Images/backgroundFlappy1.png");
		sprGFX3 = new olc::Sprite("./Images/barriers2.png");
		sprGFX = new olc::Sprite("./Images/uniCorn1.png");
		sprGFX2 = new olc::Sprite("./Images/uniCorn2.png");
		listSection = { 1, 1, 1, 1 };
		fSectionWidth = (float)ScreenWidth() / ((float)listSection.size());
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if(resetGame){
		//	flag2 = 0;	
			//Clear(olc::BLACK);
			
			flag4 = 0;
			resetGame = false;
			flag2 = 0;
			listSection = {1, 1, 1, 1};
			fBirdVelocity = 0.0f;
			fBirdPosition = 100.0f;
			
			fBirdAccel = 0.0f;
		//	outfile << Scounter << std::endl;
			Tofile();
			counter = 0;
				
			Smax2 = infileMax();
			Smax3 = infileMax2();
			Smax4 = infileMax3();
			Average = AverageScore();
			sectionspopped = 0;
			nSection = 0;
			fLevelPosition = 100.0f;
			command = nullptr;			 
//			olc::Key::SPACE.bPressed = false;
		} 
		back.DrawBackground(*this, sprGFX4, {0, 0});
		if(flag4 == 1){		//if collided
			resetGame = true;
			
		}
		if(flag4 == 0){
		
		if ((GetKey(olc::Key::SPACE).bPressed) && fBirdVelocity > 10){
			fBirdAccel = 0.0f;
			fBirdVelocity = -fGravity / 2.5f;
		}
		else{
			fBirdAccel += fGravity * fElapsedTime;
			if(fBirdAccel >= fGravity){
				fBirdAccel = fGravity;
			}
		}
		fBirdVelocity += fBirdAccel * fElapsedTime;
		fBirdPosition += fBirdVelocity * fElapsedTime;
		
		fLevelPosition += 14.0f * fElapsedTime;
		if((fLevelPosition + 36) > fSectionWidth * 4){
			fLevelPosition -= fSectionWidth;
			listSection.pop_front();
			sectionspopped++;
			int highBar = rand() % 16 +1;
			listSection.push_back(highBar);

		}

		nSection = 0;
		for(auto s : listSection){
			bar.DrawBarriers(*this, sprGFX3, {384 - (int)fLevelPosition + (nSection * 96), 0}, s);
			int kMinus = s -12;
			int lowBar = 12 - kMinus;
			int32_t offsetY = (2 * nPatch) + (nPatch * s) + 76;
			
				if(nSection == 0){
					if(((2* nPatch) + (nPatch * s)) > int(fBirdPosition)){	
						if((384 - (int)fLevelPosition + 32) < 133){
							if((384 - (int)fLevelPosition + 64) > 133){
							flag2 = 1;
						
							}
						}	
						else if((384 - (int)fLevelPosition + 32) < 165){
							if((384 - (int)fLevelPosition + 64) > 165){
								flag2 = 1;
							}
						}
					}
					else if(int(fBirdPosition) +32 > offsetY){
						
						if((384 - (int)fLevelPosition + 32) < 133){
							if((384 - (int)fLevelPosition + 64) > 133){
							flag2 = 1;
						
							}
						}	
						else if((384 - (int)fLevelPosition + 32) < 165){
							if((384 - (int)fLevelPosition + 64) > 165){
								flag2 = 1;
							}
						}
					}
				}
				if(384-(int)fLevelPosition + 32 + (nSection * 96) == 133){
					if(counter == sectionspopped && flag2 == 0){
						counter++;
					}
					
				}
				
				Scounter = std::to_string(counter);
				DrawString(0, 200, Scounter, olc::WHITE, 2);
				
				
						
				
			
			if(flag2 == 1){
				DrawString(0,150 , "GAME OVER!!", olc::WHITE, 4);
				score = "Your Score is: " + Scounter;
				//Smax2 = std::to_string(max2);
				
				Highscore3 = "3. " + Smax4;
				Highscore = "1. " + Smax2;
				Highscore2 = "2. " + Smax3;
			//	DrawString(0, 10, Highscore, olc::RED, 2);
				DrawString(0, 50, score,olc::WHITE, 2);	
				men.mm.Draw(*this, sprGFX5, {30, 30});		
				
				if(GetKey(olc::Key::UP).bPressed)  men.mm.OnUp();
				
				if(GetKey(olc::Key::DOWN).bPressed)  men.mm.OnDown();	
		//		if(GetKey(olc::Key::LEFT).bPressed)  men.mm.OnLeft();

		//		if(GetKey(olc::Key::RIGHT).bPressed)  men.mm.OnRight();
				if(GetKey(olc::Key::SPACE).bPressed)  command = men.mm.OnConfirm();
				if(command != nullptr){
				//	DrawString(10, 275, std::to_string(command->GetID()), olc::WHITE, 1);
					ID = command->GetID();
					if(ID == 101){
					
					//flaggerss = OnUserUpdate(fElapsedTime);
					//	return 0;
					//	flag4 = 0;
						flag4 = 1;
					}
					else if(ID == 102){
						flag4 = 2;
					}
					else{
						flag4 = 0;
					}	
				}
					
			}
						
			bar.DrawBarriers(*this, sprGFX3, {384 - (int)fLevelPosition + (nSection *96), offsetY}, lowBar);
			
			nSection++;
		}	

		
		if(fBirdVelocity > 0){
			flap.DrawFlappy(*this, sprGFX2, {133, int(fBirdPosition)});
		}
		else{
			
			flap.DrawFlappy(*this, sprGFX, {133, int(fBirdPosition)});

		}
		}
		else if(flag4 == 2){
			//command = nullptr;	
			stringAve = "average Score: " + Average;
			DrawString(20, 115, stringAve, olc::RED, 2);
			DrawString(20, 140, stringer, olc::WHITE, 1);
			DrawString(20, 285, score, olc::WHITE, 2);
			DrawString(20, 40, Highscore, olc::RED, 2);	
			DrawString(20, 65, Highscore2, olc::RED, 2);
			DrawString(20, 90, Highscore3, olc::RED, 2);
			if(GetKey(olc::Key::SPACE).bPressed) flag4 =1;
		//	}
			
		}	
//		else{
//			Clear(olc::BLACK);
//			flag4 = 1;
//		}
		return true;
		
	}
protected:
	std::ifstream infile;
	std::ofstream outfile;
	bool flaggerss;
	bool resetGame;
	int nSection;
	int ID;
	int flag4 = 0;
	N::menuobject* command = nullptr;
	std::string score;
	std::string Scounter;
	float fBirdPosition = 0.0f;
	float fBirdVelocity = 0.0f;
	float fBirdAccel = 0.0f;
	float fGravity = 100.0f;
	int flag2 = 0;
	int32_t counter = 0;
	int flag3;	
	float fSectionWidth;
	std::list<int> listSection;
	float fLevelPosition = 100.0f;
	int flagger3 = 0;
	float counterflag = 0;
	int sectionspopped = 0;
	//std::string max2 = "0";
	std::string Highscore;
	std::string Smax2;
	std::string Highscore2;
	std::string Smax3;
	std::string Highscore3;
	std::string Smax4;
	std::string stringer = "(Press space to save Score)";
	std::string stringAve;
	std::string Average;
/*	int max7;
	int number;
	int number2;
	int number3;
	std::Snumber;
	std::Snumber2;
	std::Sunumber3*/
};

int main()
{
	olcFlappy demo;
	if (demo.Construct(384, 300, 2, 2))
		demo.Start();
//	demo.toFile();
	return 0;
}

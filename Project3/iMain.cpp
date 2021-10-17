#include "iGraphics.h"
#include<iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

bool musicOn = true;
char music[14][20] = { "images/onn2.png", "images/off22.png"};
int mus = 0;
int gameState = 0;
//pause
int pause = 0;

string line;

//highscore
int highScore = 0;
//settings
int setting = 2;

//gameover
int gameover = 0;

//points
int points = 0;

//diamond
struct din{
	int diamond = 0;
	int diamondCount = 0;
}dia;

//word count
int wordCount = 1;
//info
int info = 0;
//try
struct tri{
	int difi = 4;
	int MAX_TRIES = difi;
	int num_of_wrong_guesses = 0;
}tryy;

//win
int win = 0;
//part2



int random = 0;
//character
int charac = 0;
char character[5][100] = { "images/character/11.bmp", "images/character/22.bmp", "images/character/33.bmp",
"images/character/44.bmp", "images/character/55.bmp", };
int playBgIndex = 0;
char guessWord='0';

char capital[10][100] = { "Capital City : New Delhi", "Capital City : Washington, D.C.", "Capital City : Dhaka",
"Capital City : Kuala Lumpur", "Capital City : Manila", "Capital City : Canberra",
"Capital City : Tehran", "Capital City : Addis Ababa", "Capital City : Muscat",
"Capital City : Jakarta" };
string name;
char letter;
char showText[20];

string words[] =
{
	"india",
	"america",
	"bangladesh",
	"malaysia",
	"philippines",
	"australia",
	"iran",
	"ethiopia",
	"oman",
	"indonesia"
};


int n;
string word = words[n];
string s5 = "*************************";

string unknownn=word;
string unknown= unknownn.replace(0, word.length(), s5, 0, word.length());

int matches;
int letterFill(char guess, string secretword, string &guessword)
{
	int i;
	matches = 0;
	int len = secretword.length();
	for (i = 0; i< len; i++)
	{
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
int guessing=10;
void playGame(char gWord){

	cout << showText[1];
	if (guessWord != '0'){

		int l = 0;
		
		for (int ms = 0; ms < word.length() + 1; ms++) {
			if (gWord == showText[ms]){
				l++;
			}
		}
	
		
		if (tryy.num_of_wrong_guesses < tryy.MAX_TRIES && l <= 0)
	{
	
		if (letterFill(gWord, word, unknown) == 0)
		{
			if (points > 0){
				points -= 1;
			}
			
			tryy.num_of_wrong_guesses++;
			
			charac++;
			guessing = 0;
			

		}
		else
		{
			guessing = 1;
			points += 2;
			
		}
		if (word == unknown)
		{
			guessing = 2;
			win = 1;
			random++;
		}
		if (tryy.num_of_wrong_guesses == tryy.MAX_TRIES)
		{
			guessing = 3;
			random++;
		}
		
	}
	}
}

char guessLeft[] = " ";

char pointShow[2];
void set()
{

	if (points >= 10){
		pointShow[0] = (points / 10) + 48;
		pointShow[1] = (points % 10)+48;
	}
	else{
		pointShow[0] = '0';

		pointShow[1] = points + 48;
	}
}
char hiScore[20];
char worddCount[] = " ";
char diamonds[] = " ";
void iDraw()
{
	iClear();

	
	
	iSetColor(0, 0, 0);
	
	cout << n;
	if (highScore <= points){
		highScore = points;
	}
	
	
	
		iShowBMP2(0, 0, "images/bg.bmp", 255);

		iShowBMP2(510, 130, "menu.bmp", 255);
		iShowBMP2(510, 450, "logo.bmp", 255);
	
	if (gameState == 1){
		iShowBMP2(0, 0, "images/background/back.bmp", 255);
	
		int ns = 0;
		for (int nm = 0; nm <= 10; nm++){
			iShowImage(0+ns, -50, 128, 128, iLoadImage("images/background/tiles/2.png"));
			ns += 128;
		}
	
		//showing gallow and character
		iShowBMP2(850, 28, "images/background/gallo.bmp", 0);
		iShowBMP2(650, 120, character[charac], 255);




		iShowImage(320, 595, 150, 73, iLoadImage("images/background/heartt.png"));
	
		//iShowBMP2(572, 595, "images/background/sta.bmp", 0);
		iShowImage(572, 595, 150, 73, iLoadImage("images/background/starr.png"));
		
		
		//diamond
		iShowImage(825, 595, 150, 73, iLoadImage("images/background/diamonds.png"));
		diamonds[0] = dia.diamond + 48;
		iText(900, 630, diamonds, GLUT_BITMAP_TIMES_ROMAN_24);


		
	


		//hint
		iShowImage(400, 450, 400, 110, iLoadImage("images/background/hint1.png"));
		if (random == 0){
			iText(459, 492, capital[0], GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else{
			iText(459, 492, capital[n], GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		//iShowImage(100, 250, 800, 500, iLoadImage("images/capital/india.png"));
		
		///wordcount
		iShowImage(80, 600, 200, 70, iLoadImage("images/background/word1.png"));
		iShowImage(110, 623, 125, 26, iLoadImage("images/background/wordDone.png"));
		worddCount[0] = wordCount + 48;
		iText(226, 627, worddCount, GLUT_BITMAP_TIMES_ROMAN_24);
	

		
		//converting text to char array
		

		int i;
		for (i = 0; i < word.length()+1; i++) {
			showText[i] = unknown[i];
		}

		//logics for wrong and right guesses
		if (guessing == 0)
		{
			guessLeft[0] = tryy.MAX_TRIES - tryy.num_of_wrong_guesses + 48;
		}
		else if (guessing==1)
		{
		//	iText(300, 520, "You found a letter! Isn't that exciting!", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (guessing == 2)
		{
		//	iText(300, 520, "Yeah! You got it!", GLUT_BITMAP_TIMES_ROMAN_24);
			

		}
		else if (guessing == 3)
		{
			guessLeft[0] = tryy.MAX_TRIES - tryy.num_of_wrong_guesses + 48;
		}
		else{
			guessLeft[0] = tryy.MAX_TRIES - tryy.num_of_wrong_guesses + 48;
			
			
		}
		//showing how many guesses left
		iText(432, 628, guessLeft, GLUT_BITMAP_TIMES_ROMAN_24);
		
		
		//banner and secret word
		iShowImage(400, 75, 400, 100, iLoadImage("images/background/5.png"));
		iText(570, 125, showText, GLUT_BITMAP_TIMES_ROMAN_24);

		//point show
		set();
		iText(670, 628, pointShow, GLUT_BITMAP_TIMES_ROMAN_24);

		//pause
		iShowBMP2(1150, 590, "images/background/pause1.bmp", 0);
		//pause codes
		if (pause == 1){
			iShowImage(0, 0, 1300, 700, iLoadImage("images/highscore/back.png"));
			iShowImage(480, 150, 359, 460, iLoadImage("images/background/pause.png"));
		}
		//gameover codes
		if (tryy.num_of_wrong_guesses == tryy.MAX_TRIES){
			gameover = 1;
		}
		if (gameover == 1){
		
			iShowImage(0, 0, 1300, 700, iLoadImage("images/highscore/back.png"));
			iShowImage(180, 550, 928, 111, iLoadImage("images/background/gameover/gameover.png"));
			iShowImage(250, 30, 830, 500, iLoadImage("images/settings/f3.png"));
			iShowImage(475, 200, 350, 80, iLoadImage("images/settings/dificolour.png"));
			iShowImage(475, 100, 350, 80, iLoadImage("images/settings/dificolour.png"));
			iShowImage(535, 404, 204, 48, iLoadImage("images/background/win/score2.png"));
			iShowImage(555, 220, 180, 38, iLoadImage("images/background/gameover/restart.png"));
			iShowImage(735, 220, 34, 38, iLoadImage("images/background/gameover/t.png"));
			iShowImage(595, 120, 102, 38, iLoadImage("images/background/win/exit.png"));
			iText(614, 347, pointShow, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//win codes
		if (win == 1){
			
			iShowImage(0, 0, 1300, 700, iLoadImage("images/highscore/back.png"));
			iShowImage(255, 550, 791, 97, iLoadImage("images/background/win/win.png"));
			iShowImage(250, 30, 830, 500, iLoadImage("images/settings/f3.png"));
			iShowImage(475, 200, 350, 80, iLoadImage("images/settings/dificolour.png"));
			iShowImage(475, 100, 350, 80, iLoadImage("images/settings/dificolour.png"));
			iShowImage(535,404, 204, 48, iLoadImage("images/background/win/score2.png"));
			iShowImage(585, 220, 122, 38, iLoadImage("images/background/win/next2.png"));
			iShowImage(595, 120, 102, 38, iLoadImage("images/background/win/exit.png"));
			iText(614, 347, pointShow, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
	//highscore codes
	if (gameState == 2){
		iShowImage(0, 0, 1300, 700, iLoadImage("images/highscore/back.png"));
		iShowImage(200, 450, 885, 109, iLoadImage("images/highscore/high5.png"));
		iText(664, 347, hiScore, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//setting codes
	if (gameState == 3){
		iShowImage(0, 0, 1300, 700, iLoadImage("images/highscore/back.png"));
		iShowImage(300, 550, 746, 110, iLoadImage("images/settings/settings.png"));
		iShowImage(250, 30, 830, 500, iLoadImage("images/settings/f3.png"));
		iShowImage(475, 300, 350, 80, iLoadImage("images/settings/dificolour.png"));
		iShowImage(475, 200, 350, 80, iLoadImage("images/settings/dificolour.png"));
		iShowImage(475, 100, 350, 80, iLoadImage("images/settings/dificolour.png"));
		if (setting == 1){
			iShowImage(475, 300, 350, 80, iLoadImage("images/settings/dificolour2.png"));
		}
		else if (setting == 2){
			iShowImage(475, 200, 350, 80, iLoadImage("images/settings/dificolour2.png"));
		}
		else if (setting == 3){
			iShowImage(475, 100, 350, 80, iLoadImage("images/settings/dificolour2.png"));
		}	
		iShowImage(440, 420, 431, 33, iLoadImage("images/settings/difilvl.png"));
		iShowImage(585, 320, 115, 31, iLoadImage("images/settings/easy.png"));
		iShowImage(560, 220, 168, 29, iLoadImage("images/settings/medium.png"));
		iShowImage(585, 120, 120, 30, iLoadImage("images/settings/hard.png"));
	}
	//exit codes
	if (gameState == 4){
		
	}
	
	
//	iShowBMP2(50, 575, music[mus], 0);
	if (gameover == 0){
		iShowImage(1065, 600, 80, 81, iLoadImage(music[mus]));
	}
	
	if (gameState != 1){
		iShowImage(1160, 600, 80, 81, iLoadImage("images/info.png"));
		
	}
	if (info == 1){
		iShowImage(0, 0, 1300, 700, iLoadImage("images/highscore/back.png"));
		iShowImage(250, 100, 800, 500, iLoadImage("images/infotext2.png"));
	}
	
	if (gameState == 2 || gameState == 3 || info==1){
		iShowBMP2(50, 600, "images/backbutton.bmp", 0);
	}
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	//word = word[n];
	unknown.replace(0, word.length(), s5, 0, word.length());
	
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << mx<<endl;
		cout << my<<endl;
		if (gameState == 0){
			if (mx >= 538 && mx <= 728 && my >= 130 + 16 && my <= 130 + 64){
				gameState = 4;
				exit(0);
			}
			if (mx >= 538 && mx <= 728 && my >= 130 + 92 && my <= 130 + 143){
				gameState = 3;
			}
			if (mx >= 538 && mx <= 728 && my >= 130 + 166 && my <= 130 + 216){
				gameState = 2;
				
				ifstream file("example.txt");

				while (getline(file, line))
				{

					cout << line << endl;
				}
				file.close();
				
				int i;
				for (i = 0; i <line.length() + 1; i++) {
					hiScore[i] = line[i];
				}
				cout << hiScore;
			}
			if (mx >= 538 && mx <= 728 && my >= 130 + 240 && my <= 130 + 293){
				gameState = 1;
				
			}
		}
		
		if (mx >= 1073 && mx <= 1128 && my >= 616 && my <= 672){
			if (musicOn){
				mus = 1;
			}
			else{
				mus = 0;
			}
			if (musicOn){
				musicOn = false;
				PlaySound(0, 0, 0);
			}
			else{
				musicOn = true;
				PlaySound("music\\chil.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		//back button work
		if (gameState != 1 && mx >= 50 + 20 && mx <= 50 + 83 && my >= 575 + 21 && my <= 575 + 81){
			gameState = 0;
			info = 0;
		}
		//for info
		if (gameState != 1 && mx >= 1174 && mx <= 1222 && my >= 614 && my <= 671){
			info = 1;
		}
		//for pause
		if (gameState==1 && mx >= 1172 && mx <= 1226 && my >= 621 && my <= 667){
			pause = 1;
		}
		//for resume from pause
		if (gameState == 1 &&pause==1 && mx >= 560 && mx <= 741 && my >= 431 && my <= 481){
			pause = 0;
		}
		//for exiting from pause
		if (gameState == 1 && pause == 1 && mx >= 561 && mx <= 741 && my >= 269 && my <= 314){
			gameState = 0;
			points = 0;
			tryy.MAX_TRIES = tryy.difi;
			tryy.num_of_wrong_guesses = 0;
			win = 0;
			n = n + 1;
			word = words[n];
			unknown = word;
			wordCount = 1;
			pause = 0;
			charac = 0;

			if (highScore >= points){
				ofstream myfile;
				myfile.open("example.txt");
				myfile << highScore;
				myfile.close();
			}
			
		}
		//diamonds
		if (gameState == 1 && dia.diamond >= 1 && mx >= 876 && mx <= 952 && my >= 621 && my <= 653){
			tryy.MAX_TRIES = tryy.difi;
			tryy.num_of_wrong_guesses = 0;
		}
		//for chosing difficulty
		if (gameState == 3 && mx >= 506 && mx <= 788 && my >= 315 && my <= 370){
			setting = 1;
			tryy.difi = 5;
		}
		else if (gameState == 3 && mx >= 506 && mx <= 788 && my >= 215 && my <= 270){
			setting = 2;
			tryy.difi = 4;
		}
		else if (gameState == 3 && mx >= 506 && mx <= 788 && my >= 115 && my <= 170){
			setting = 3;
			tryy.difi = 3;
		}
		//afterwin
		//exit
		if (win == 1 && mx >= 506 && mx <= 788 && my >= 115 && my <= 170){
			gameState = 0;
			points = 0;
			tryy.MAX_TRIES = tryy.difi;
			tryy.num_of_wrong_guesses = 0;
			win = 0;
			n = n + 1;
			word = words[n];
			unknown = word;
			wordCount=1;
			charac = 0;

			if (highScore >= points){
				ofstream myfile;
				myfile.open("example.txt");
				myfile << highScore;
				myfile.close();
			}
		}
		//next
		if (win == 1 && mx >= 506 && mx <= 788 && my >= 215 && my <= 270){
			gameState = 1;
			tryy.MAX_TRIES = tryy.difi;
			tryy.num_of_wrong_guesses = 0;
			win = 0;
			n=n+1;
			word = words[n];
			unknown = word;
			wordCount++;
			dia.diamondCount++;
			if (dia.diamondCount==2){
				dia.diamond++;
				dia.diamondCount = 0;
			}
			charac = 0;

		}
		//after gameover
		if (gameover == 1 && mx >= 506 && mx <= 788 && my >= 115 && my <= 170){
			
			gameState = 0;
			points = 0;
			tryy.MAX_TRIES = tryy.difi;
			tryy.num_of_wrong_guesses = 0;
			gameover = 0;
			n = n + 1;
			word = words[n];
			unknown = word;
			wordCount=1;
			charac = 0;

			if (highScore >= points){
				ofstream myfile;
				myfile.open("example.txt");
				myfile << highScore;
				myfile.close();
			}
		}
		if (gameover== 1 && mx >= 506 && mx <= 788 && my >= 215 && my <= 270){
			points = 0;
			gameover = 0;
			gameState = 1;
			tryy.MAX_TRIES = tryy.difi;
			tryy.num_of_wrong_guesses = 0;
			n = n + 1;
			word = words[n];
			unknown = word;
			wordCount=1;
			charac = 0;

			if (highScore >= points){
				ofstream myfile;
				myfile.open("example.txt");
				myfile << highScore;
				myfile.close();
			}

		}
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (gameState = 1){

	
		if (key == 'a')
		{
			/*int l = 0;
			
			for (int ms = 0; ms < word.length() + 1; ms++) {
				if (guessWord == showText[ms]){
					l++;
				}
			}
			if (l == 0){
				
			}*/
			guessWord = 'a';
			playGame(guessWord);
			
		
	}
	if (key == 'b')
	{
		
			guessWord = 'b';
			playGame(guessWord);
		
	}
	if (key == 'c')
	{

		guessWord = 'c';
		playGame(guessWord);

	}
	if (key == 'd')
	{

		guessWord = 'd';
		playGame(guessWord);

	}
	if (key == 'e')
	{

		guessWord = 'e';
		playGame(guessWord);

	}
	if (key == 'f')
	{

		guessWord = 'f';
		playGame(guessWord);

	}
	if (key == 'g')
	{

		guessWord = 'g';
		playGame(guessWord);

	}
	if (key == 'h')
	{

		guessWord = 'h';
		playGame(guessWord);

	}
	if (key == 'i')
	{

		guessWord = 'i';
		playGame(guessWord);

	}
	if (key == 'j')
	{

		guessWord = 'j';
		playGame(guessWord);

	}
	if (key == 'k')
	{

		guessWord = 'k';
		playGame(guessWord);

	}
	if (key == 'l')
	{

		guessWord = 'l';
		playGame(guessWord);

	}
	if (key == 'm')
	{

		guessWord = 'm';
		playGame(guessWord);

	}
	if (key == 'n')
	{

		guessWord = 'n';
		playGame(guessWord);

	}
	if (key == 'o')
	{

		guessWord = 'o';
		playGame(guessWord);

	}
	if (key == 'p')
	{

		guessWord = 'p';
		playGame(guessWord);

	}if (key == 'q')
	{

		guessWord = 'q';
		playGame(guessWord);

	}if (key == 'r')
	{

		guessWord = 'r';
		playGame(guessWord);

	}if (key == 's')
	{

		guessWord = 's';
		playGame(guessWord);

	}if (key == 't')
	{

		guessWord = 't';
		playGame(guessWord);

	}if (key == 'u')
	{

		guessWord = 'u';
		playGame(guessWord);

	}if (key == 'v')
	{

		guessWord = 'v';
		playGame(guessWord);

	}if (key == 'w')
	{

		guessWord = 'w';
		playGame(guessWord);

	}if (key == 'x')
	{

		guessWord = 'x';
		playGame(guessWord);

	}if (key == 'y')
	{

		guessWord = 'y';
		playGame(guessWord);

	}if (key == 'z')
	{

		guessWord = 'z';
		playGame(guessWord);

	}
	
	
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
	/*	*/
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}
void funchu(){
	if (playBgIndex > 3){
		playBgIndex = 0;
	}
	else{
		playBgIndex++;
	}
}



int main()
{
	
	ifstream file("example.txt");

	while (getline(file, line))
	{

		cout << line << endl;
	}
	file.close();

	int i;
	for (i = 0; i <line.length() + 1; i++) {
		hiScore[i] = line[i];
	}
	cout << hiScore;
	
	
	///srand((unsigned)time(NULL));
	iInitialize(1300, 700, "Project Title");
	//iSetTimer(1000, funchu);
	srand(time(NULL));
	n = rand() % 10;
	if (musicOn){
		PlaySound("music\\chil.wav", NULL, SND_LOOP|SND_ASYNC);
	
	}
	///updated see the documentations
	iStart();
	return 0;
}
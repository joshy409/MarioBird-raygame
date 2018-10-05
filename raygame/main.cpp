/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <vector>
#include <string>

struct Triangle {
	Vector2 vertex1;
	Vector2 vertex2;
	Vector2 vertex3;
};

bool collisionCheckRectangle(Rectangle player, std::vector<Rectangle> pipes) {
	for (auto &pipe : pipes) {
		if (CheckCollisionRecs(player, pipe)) {
			return true;
		}
	}
	return false;
}

bool collisionCheckTriangle(Rectangle player, std::vector<Triangle> pipes) {
	for (auto &pipe : pipes) {
		if (CheckCollisionPointTriangle(Vector2{ player.x + 22, player.y+2 }, pipe.vertex1, pipe.vertex2, pipe.vertex3)) {
			return true;
		}
		else if (CheckCollisionPointTriangle(Vector2{ player.x + 22, player.y + 22 }, pipe.vertex1, pipe.vertex2, pipe.vertex3)) {
			return true;
		}
	}
	return false;
}

void printPipes(std::vector<Rectangle>& pipes) {
	for (auto &pipe : pipes) {
		DrawRectangleRec(pipe, BLACK);
	}
}

void printBricks(std::vector<Triangle>& bricks) {
	for (auto &brick : bricks) {
		DrawTriangle(brick.vertex1,brick.vertex2,brick.vertex3, BLACK);
	}
}


void printPoints(std::vector<Rectangle>& points) {
	for (auto &point : points) {
		DrawRectangleRec(point, BLACK);
	}
}

void movePipes(std::vector<Rectangle>& pipes, int speed) {
	for (auto &pipe : pipes) {
		pipe.x -= speed;
	}
}

void moveBricks(std::vector<Triangle>& bricks, int speed) {
	for (auto &brick : bricks) {
		brick.vertex1.x -= speed;
		brick.vertex2.x -= speed;
		brick.vertex3.x -= speed;
	}
}

//initializing pipes
void pipeClear(std::vector<Rectangle>& pipes) {
	pipes.clear();
	Rectangle pipe1d = { 449,170 + 100,30,30 };
	pipes.push_back(pipe1d);
	Rectangle pipe1u = { 449,0 + 100,30,60 };
	pipes.push_back(pipe1u);
	Rectangle pipe2d = { 610,154 + 100,30,50 };
	pipes.push_back(pipe2d);
	Rectangle pipe2u = { 610,0 + 100,30,93 };
	pipes.push_back(pipe2u);
	Rectangle pipe3d = { 737,138 + 100,30,67 };
	pipes.push_back(pipe3d);
	Rectangle pipe3u = { 737,0 + 100,30,58 };
	pipes.push_back(pipe3u);
	Rectangle pipe4d = { 914,138 + 100,30,67 };
	pipes.push_back(pipe4d);
	Rectangle pipe4u = { 914,0 + 100,30,70 };
	pipes.push_back(pipe4u);
	Rectangle pipe5d = { 1043,114 + 100,30,95 };
	pipes.push_back(pipe5d);
	Rectangle pipe5u = { 1043,0 + 100,30,52 };
	pipes.push_back(pipe5u);
	Rectangle pipe6d = { 1188,137 + 100,30,63 };
	pipes.push_back(pipe6d);
	Rectangle pipe6u = { 1188,0 + 100,30,79 };
	pipes.push_back(pipe6u);
	Rectangle pipe7d = { 1322,161 + 100,30,39 };
	pipes.push_back(pipe7d);
	Rectangle pipe7u = { 1322,0 + 100,30,104 };
	pipes.push_back(pipe7u);
	Rectangle pipe8d = { 1441,178 + 100,30,22 };
	pipes.push_back(pipe8d);
	Rectangle pipe8u = { 1441,0 + 100,30,126 };
	pipes.push_back(pipe8u);
	Rectangle pipe9d = { 1625,93 + 100,30,107 };
	pipes.push_back(pipe9d);
	Rectangle pipe9u = { 1625,0 + 100,30,35 };
	pipes.push_back(pipe9u);
	Rectangle pipe10d = { 1764,160 + 100,30,40 };
	pipes.push_back(pipe10d);
	Rectangle pipe10u = { 1764,0 + 100,30,87 };
	pipes.push_back(pipe10u);
	Rectangle pipe11d = { 1906,119 + 100,30,81 };
	pipes.push_back(pipe11d);
	Rectangle pipe11u = { 1906,0 + 100,30,52 };
	pipes.push_back(pipe11u);
	Rectangle pipe12d = { 2053,119 + 100,30,81 };
	pipes.push_back(pipe12d);
	Rectangle pipe12u = { 2053,0 + 100,30,54 };
	pipes.push_back(pipe12u);
	Rectangle pipe15d = { 2866,170 + 100,30,30 };
	pipes.push_back(pipe15d);
	Rectangle pipe15u = { 2865,0 + 100,30,112 };
	pipes.push_back(pipe15u);
	Rectangle pipe13d = { 2610,169 + 100,30,30 };
	pipes.push_back(pipe13d);
	Rectangle pipe14d = { 2785,154 + 100,30,48 };
	pipes.push_back(pipe14d);
	Rectangle ground = { 380 ,200 + 100,20,5 };
	pipes.push_back(ground);
	Rectangle top = { 380 ,100,20,5 };
	pipes.push_back(top);
	Rectangle goal = { 3176,0 + 100,3,200 };
	pipes.push_back(goal);
}

//initializing bricks
void brickClear(std::vector<Triangle>& bricks) {
	bricks.clear();
	Triangle brick1 = { Vector2{ 2207,235 }, Vector2{ 2145,300 }, Vector2{ 2207,300 } };
	bricks.push_back(brick1);
	Triangle brick2 = { Vector2{ 2238,235 }, Vector2{ 2238,300 }, Vector2{ 2303,300 } };
	bricks.push_back(brick2);
	Triangle brick3 = { Vector2{ 2142,100 }, Vector2{ 2205,62 + 100 }, Vector2{ 2205,100 } };
	bricks.push_back(brick3);
	Triangle brick4 = { Vector2{ 2236,100 }, Vector2{ 2236,62 + 100 }, Vector2{ 2301,100 } };
	bricks.push_back(brick4);
	Triangle brick5 = { Vector2{ 2343,100 }, Vector2{ 2343,103 + 100 }, Vector2{ 2453,100 } };
	bricks.push_back(brick5);
	Triangle brick6 = { Vector2{ 2509,173 }, Vector2{ 2382,300 }, Vector2{ 2509,300 } };
	bricks.push_back(brick6);
	Triangle brick7 = { Vector2{ 2600,100 }, Vector2{ 2735,128 + 100 }, Vector2{ 2735,100 } };
	bricks.push_back(brick7);
	Triangle brick8 = { Vector2{ 3022,173 }, Vector2{ 2897,300 }, Vector2{ 3022,300 } };
	bricks.push_back(brick8);
}

//initializing scores
void pointsClear(std::vector<Rectangle>&pipes, std::vector<Rectangle>& points) {
	points.clear();
	for (int i = 0; i < 26; i++) {
		Rectangle point = { pipes[i].x + 14, pipes[i + 1].y + pipes[i + 1].height, 1, pipes[i].y - (pipes[i + 1].y + pipes[i + 1].height) };
		points.push_back(point);
		i++;
	}
}

void movePoints(std::vector<Rectangle>& points, int speed) {
	for (auto &point : points) {
		point.x -= speed;
	}
}

//alternate runR and slideR image so that mario looks like its running
void runAnimation(int& alternate, Rectangle player, Texture2D runR, Texture2D slideR) {
	if (alternate % 10 > 5) {
		DrawTexture(runR, int(player.x) - 1, (int)player.y - 1, WHITE);
		alternate++;
	}
	else {
		DrawTexture(slideR, int(player.x) - 1, (int)player.y - 1, WHITE);
		alternate++;
		if (alternate > 10000) {
			alternate = 0;
		}
	}
}

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	int yoffset = 100;

	InitWindow(screenWidth, screenHeight, "Super Mario raylib");

	//initialize images
	Image mariostandR = LoadImage("marioimage/mariostandR.png");
	ImageResize(&mariostandR, 24, 24);
	Texture2D standR = LoadTextureFromImage(mariostandR);

	Image mariorunR = LoadImage("marioimage/mariorunR.png");
	ImageResize(&mariorunR, 24, 24);
	Texture2D runR = LoadTextureFromImage(mariorunR);

	Image marioslideR = LoadImage("marioimage/marioslideR.png");
	ImageResize(&marioslideR, 24, 24);
	Texture2D slideR = LoadTextureFromImage(marioslideR);

	Image mariojumpR = LoadImage("marioimage/mariojumpR.png");
	ImageResize(&mariojumpR, 24, 24);
	Texture2D jumpR = LoadTextureFromImage(mariojumpR);

	Image mariolevel = LoadImage("marioimage/mariobird.png");
	Texture2D level = LoadTextureFromImage(mariolevel);

	Image mariodead = LoadImage("marioimage/mariodead.png");
	ImageResize(&mariodead, 24, 24);
	Texture2D dead = LoadTextureFromImage(mariodead);

	Image over = LoadImage("marioimage/over.png");
	Texture2D endscreen = LoadTextureFromImage(over);

	Image start = LoadImage("marioimage/startred.png");
	Texture2D startred = LoadTextureFromImage(start);

	Image start1 = LoadImage("marioimage/startblue.png");
	Texture2D startblue = LoadTextureFromImage(start1);

	Image youwin = LoadImage("marioimage/youwin.png");
	Texture2D winscreen = LoadTextureFromImage(youwin);

	//audio loading
	InitAudioDevice();
	Music bgm = LoadMusicStream("mariosound/mariotheme.ogg");
	Sound win = LoadSound("mariosound/win.ogg");
	Sound clear = LoadSound("mariosound/clear.ogg");
	Sound jump = LoadSound("mariosound/jump.ogg");
	SetSoundVolume(jump, .3f);
	Sound death = LoadSound("mariosound/death.ogg");
	Sound gover = LoadSound("mariosound/gover.ogg");

	//initialize player collision box
	float x = 0;
	Rectangle player = { 250, 225, 22, 22 };

	//initialize collision boxes
	std::vector<Rectangle> pipes;
	pipeClear(pipes);
	
	std::vector<Triangle> bricks;
	brickClear(bricks);

	std::vector<Rectangle> points;
	pointsClear(pipes, points);

	//start button
	Rectangle button = { 298, 142 + yoffset, 167, 53 };

	//variables to control loop speed
	int delay = 0;
	int alternate = 0;

	//variable to control click speed
	bool click = false;

	//intial game setting
	int speed = 2;
	bool gameover = false;
	bool gwin = false;
	bool play = true;

	//variables used to only play sound once
	bool once1 = true;
	bool once2 = true;
	bool once3 = true;

	int jumpHeight = 8;
	int startPositonX = 389;
	int score = 0;
	int highscore = 0;

	PlayMusicStream(bgm);

	EnableCursor();
	ShowCursor();

	//--------------------------------------------------------------------------------------
	// Main game loop
	SetTargetFPS(60);

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		PlayMusicStream(bgm);
		UpdateMusicStream(bgm);

		//if play button is clicked, play the game;
		if (play) {
			
			if (CheckCollisionPointRec(GetMousePosition(), button)) {
				DrawTexture(startblue, 0, yoffset, WHITE);
				DrawText(("High Score " + (std::to_string(highscore/12))).c_str(), 100, 80, 20, BLACK);
			}
			else {
				DrawTexture(startred, 0, yoffset, WHITE);
				DrawText(("High Score " + (std::to_string(highscore/12))).c_str(), 100, 80, 20, BLACK);
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button)) {
				play = false;
				HideCursor();
			}
		}
		//play game
		else {

			//if the player collides with goal
			if (CheckCollisionRecs(player, pipes[pipes.size() - 1 ]) || gwin) {
				StopMusicStream(bgm);
				gwin = true;

				if (once1) { //play win sound
					PlaySound(win);
					once1 = false;
				}

				if (!IsSoundPlaying(win)) { //when win sound is done playing display winscreen and play clear sound
					DrawTexture(winscreen, 46, 56, WHITE);
					if (once2) {
						PlaySound(clear);
						once2 = false;
					}
				}
				else {
					if (player.y < 280) { //charcter slides down the rope
						DrawTexture(level, x * speed, yoffset, WHITE);
						DrawTexture(jumpR, int(player.x) - 1, (int)player.y - 2, WHITE);
						player.y += 2;
					}
					else {
						DrawTexture(level, x * speed, yoffset, WHITE);
						DrawTexture(jumpR, int(player.x) - 1, (int)player.y - 2, WHITE);
					}
				}

				if (!IsSoundPlaying(win) && !IsSoundPlaying(clear)) { // if both win and clear sound finished playing restart the game
					if (score > highscore) {
						highscore = score;
					}
					//resetting game variables
					x = 0; player.y = 225; player.x = 250; play = true; gameover = false; gwin = false; once1 = true; once2 = true; once3 = true; score = 0;
					ShowCursor();
					pipeClear(pipes);
					brickClear(bricks);
					PlayMusicStream(bgm);
					continue; //go to the start of the loop
				}

			//when player collides with any pipes or bricks
			} else if (collisionCheckRectangle(player, pipes) || (collisionCheckTriangle(player, bricks)) || gameover) { 
				gameover = true;
				StopMusicStream(bgm);

				if (once1) { //play the death sound once
					PlaySound(death);
					once1 = false;
				}

				if (!IsSoundPlaying(death)) { //when death sound is done playing display endscreen and play gover sound
					DrawTexture(endscreen, 0, yoffset, WHITE);
					if (once2) {
						PlaySound(gover);
						once2 = false;
					}
				}
				else {
					if (player.y < 650) { //player falls of the screen
						DrawTexture(level, x * speed, yoffset, WHITE);
						DrawTexture(dead, int(player.x) - 1, (int)player.y - 2, WHITE);
						player.y += 2;
					}
					else {
						DrawTexture(level, x * speed, yoffset, WHITE);
					}
				}

				if (!IsSoundPlaying(gover) && !IsSoundPlaying(death)) {
					if (score > highscore) {
						highscore = score;
					}
					//resetting game variables
					x = 0; player.y = 225; player.x = 250; play = true; gameover = false; gwin = false; once1 = true; once2 = true; once3 = true; score = 0;
					ShowCursor();
					pipeClear(pipes);
					brickClear(bricks);
					PlayMusicStream(bgm);
					
					continue; //go to the start of the loop
				}
			}
			else {
				//game play

				//move the background
				if (player.x < startPositonX) {
					player.x += 2;
					DrawTexture(level, x * speed, yoffset, WHITE);
					DrawText(("Score " + (std::to_string(score/12))).c_str(), 100, 80, 20, BLACK);
				}
				else {
					DrawTexture(level, x * speed, yoffset, WHITE);
					DrawText(("Score " + (std::to_string(score/12))).c_str(), 100, 80, 20, BLACK);
					movePipes(pipes, speed);
					moveBricks(bricks, speed);
					movePoints(points, speed);
					x--;
				}

				//if player successfully passes a pipe
				if (collisionCheckRectangle(player, points)) {
					score++;
				}

				//game command logic
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !click) {
					PlaySound(jump);
					runAnimation(alternate, player, runR, slideR);
					click = true;

				}
				//alternate runR and slideR image so that mario looks like its running
				else if (IsMouseButtonUp(MOUSE_LEFT_BUTTON) && !click) {
					
					runAnimation(alternate, player, runR, slideR);
					player.y += 1; //player slowly decends 
				}

				else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !click) {
					//nothing happens when the left mouse button is held down
					runAnimation(alternate, player, runR, slideR);
					player.y += 1;
				}
				else {
					DrawTexture(jumpR, int(player.x) - 1, (int)player.y, WHITE);
				}

				if (click) { //when a player click left mouse button slowly ascend mario up 8 y units
					player.y -= delay;
					delay++;
					if (delay == jumpHeight) {
						delay = 0;
						click = false;
					}
				}
			}
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	UnloadSound(win);
	UnloadSound(death);
	UnloadSound(gover);
	UnloadSound(jump);
	UnloadMusicStream(bgm);
	CloseAudioDevice();
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
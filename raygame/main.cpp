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

bool collisionCheckRectangle(Rectangle player, std::vector<Rectangle> pipes) {
	
	for (auto &pipe : pipes) {
		if (CheckCollisionRecs(player, pipe)) {
			return true;
		}
	}

	return false;
}

struct Triangle {
	Vector2 vertex1;
	Vector2 vertex2;
	Vector2 vertex3;
};

bool collisionCheckTriangle(Rectangle player, std::vector<Triangle> pipes) {

	for (auto &pipe : pipes) {
		//if (CheckCollisionPointTriangle(Vector2{ player.x, player.y }, pipe.vertex1, pipe.vertex2, pipe.vertex3)) {
			//return true;
		//}
		if (CheckCollisionPointTriangle(Vector2{ player.x + 22, player.y+2 }, pipe.vertex1, pipe.vertex2, pipe.vertex3)) {
			return true;
		}
		//else if (CheckCollisionPointTriangle(Vector2{ player.x, player.y + 24 }, pipe.vertex1, pipe.vertex2, pipe.vertex3)) {
			//return true;
		//}
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

void movePipes(std::vector<Rectangle>& pipes, int speed) {
	for (auto &pipe : pipes) {
		pipe.x -= speed;
	}
}

void printBricks(std::vector<Triangle>& bricks) {

	for (auto &brick : bricks) {
		DrawTriangle(brick.vertex1,brick.vertex2,brick.vertex3, BLACK);
	}

}

void moveBricks(std::vector<Triangle>& bricks, int speed) {

	for (auto &brick : bricks) {
		brick.vertex1.x -= speed;
		brick.vertex2.x -= speed;
		brick.vertex3.x -= speed;
	}

}
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Super Mario raylib");

	Image mariostandR = LoadImage("mariostandR.png");
	ImageResize(&mariostandR, 24, 24);
	Texture2D standR = LoadTextureFromImage(mariostandR);

	Image mariorunR = LoadImage("mariorunR.png");
	ImageResize(&mariorunR, 24, 24);
	Texture2D runR = LoadTextureFromImage(mariorunR);

	Image marioslideR = LoadImage("marioslideR.png");
	ImageResize(&marioslideR, 24, 24);
	Texture2D slideR = LoadTextureFromImage(marioslideR);

	Image mariojumpR = LoadImage("mariojumpR.png");
	ImageResize(&mariojumpR, 24, 24);
	Texture2D jumpR = LoadTextureFromImage(mariojumpR);

	Image mariolevel = LoadImage("mariobird.png");
	Texture2D level = LoadTextureFromImage(mariolevel);

	Image mariodead = LoadImage("mariodead.png");
	ImageResize(&mariodead, 24, 24);
	Texture2D dead = LoadTextureFromImage(mariodead);

	Image over = LoadImage("over.png");
	Texture2D endscreen = LoadTextureFromImage(over);

	Image start = LoadImage("startred.png");
	Texture2D startred = LoadTextureFromImage(start);

	Image start1 = LoadImage("startblue.png");
	Texture2D startblue = LoadTextureFromImage(start1);

	SetTargetFPS(60);

	//--------------------------------------------------------------------------------------
	// Main game loop

	int y = 0;
	float x = 0;
	Rectangle player = { 250, 225, 22, 22 };

	std::vector<Rectangle> pipes;
	Rectangle pipe1d = { 449,170 + 100,30,30 };
	pipes.push_back(pipe1d);
	Rectangle pipe2d = { 610,154 + 100,30,50 };
	pipes.push_back(pipe2d);
	Rectangle pipe3d = { 737,138 + 100,30,67 };
	pipes.push_back(pipe3d);
	Rectangle pipe1u = { 449,0 + 100,30,60 };
	pipes.push_back(pipe1u);
	Rectangle pipe2u = { 610,0 + 100,30,93 };
	pipes.push_back(pipe2u);
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
	Rectangle pipe13d = { 2610,169 + 100,30,30 };
	pipes.push_back(pipe13d);
	Rectangle pipe14d = { 2785,154 + 100,30,48 };
	pipes.push_back(pipe14d);
	Rectangle pipe15d = { 2866,170 + 100,30,30 };
	pipes.push_back(pipe15d);
	Rectangle pipe15u = { 2865,0 + 100,30,112 };
	pipes.push_back(pipe15u);


	Rectangle goal = { 3176,0 + 100,3,200 };
	pipes.push_back(goal);

	Rectangle button = {298, 142 + 100, 167, 53};
	


	Rectangle ground = { screenWidth / 2 - 20 / 2,200 + 100,20,5 };
	
	std::vector<Triangle> bricks;
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

	InitAudioDevice();
	
	Music bgm = LoadMusicStream("mariosound/mariotheme.ogg");
	//Sound bgm = LoadSound("mariosound/mariotheme.ogg");
	//Sound win = LoadSound("mariosound/win.ogg");
	Sound jump = LoadSound("mariosound/jump.ogg");
	SetSoundVolume(jump, .3f);
	Sound death = LoadSound("mariosound/death.ogg");
	Sound gover = LoadSound("mariosound/gover.ogg");

	int delay = 0;
	int alternate = 0;
	bool click = false;
	int speed = 2;
	bool gameover = false;
	bool play = true;
	//TODO: add mario sound
	EnableCursor();
	ShowCursor();
	PlayMusicStream(bgm);
	bool yyay = true;
	bool byay = true;
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		//TODO: win screen
		//if play button is clicked, play the game;
		if (play) {
			//PlaySound(bgm);
			if (CheckCollisionPointRec(GetMousePosition(), button)) {
				DrawTexture(startblue, 0, 100, WHITE);
			}
			else {
				DrawTexture(startred, 0, 100, WHITE);
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button)) {
				play = false;
				HideCursor();
			}

		}
		else {

			// if player collides with anything
			if (CheckCollisionRecs(player, ground) || collisionCheckRectangle(player, pipes) || (collisionCheckTriangle(player, bricks)) || gameover) {
				gameover = true;
				
				if (yyay) {
					PlaySound(death);
					yyay = false;
				}

				if (player.y < 650) {
					DrawTexture(level, x * speed, 100, WHITE);
					DrawTexture(dead, int(player.x) - 1, (int)player.y - 2, WHITE);
					player.y += 2;
				}
				else {
					if (!IsSoundPlaying(death)) {
						if (byay) {
							PlaySound(gover);
							byay = false;
						}
						DrawTexture(endscreen, 0, 100, WHITE);
					}
					else {
						DrawTexture(endscreen, 0, 100, WHITE);
					}
				}
			}
			else { //game logic

				//char buffer[20];
				//sprintf_s(buffer, 20, "%f", player.x);

				//char buffer3[20];
				//sprintf_s(buffer3, 20, "%f", player.y);

				//DrawText(buffer, 0, 400, 3, BLACK);
				//DrawText(buffer3, 0, 410, 3, BLACK);

				if (player.x < 389) {
					player.x += 2;
					DrawTexture(level, x * speed, 100, WHITE);
				}
				else {
					DrawTexture(level, x * speed, 100, WHITE);
					movePipes(pipes, speed);
					//printPipes(pipes);
					//DrawRectangleRec(ground, BLACK);

					moveBricks(bricks, speed);
					//printBricks(bricks);
					x--;
				}


				//background
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !click) {
					PlaySound(jump);
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

					//DrawRectangleRec(player, BLACK);
					click = true;

				}
				else if (IsMouseButtonUp(MOUSE_LEFT_BUTTON) && !click) {
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

					//DrawRectangleRec(player, BLACK);
					player.y += 1;
				}
				else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !click) {
					if (alternate % 10 > 5) {
						DrawTexture(runR, int(player.x) - 1, (int)player.y - 2, WHITE);
						alternate++;
					}
					else {
						DrawTexture(slideR, int(player.x) - 1, (int)player.y - 2, WHITE);
						alternate++;
						if (alternate > 10000) {
							alternate = 0;
						}
					}

					//DrawRectangleRec(player, BLACK);
					player.y += 1;
				}
				else {
					DrawTexture(jumpR, int(player.x) - 1, (int)player.y, WHITE);
					//DrawRectangleRec(player, BLACK);
				}

				if (click) {
					player.y -= delay;
					delay++;
					if (delay == 8) {
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

		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}


	
	// De-Initialization
	//--------------------------------------------------------------------------------------   
	//UnloadSound(bgm);
	//UnloadSound(win);
	UnloadSound(death);
	UnloadSound(gover);
	UnloadSound(jump);
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}


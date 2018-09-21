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

bool collisionCheck(Rectangle player, std::vector<Rectangle> pipes) {
	
	for (auto &pipe : pipes) {
		if (CheckCollisionRecs(player, pipe)) {
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

void movePipes(std::vector<Rectangle>& pipes) {
	for (auto &pipe : pipes) {
		pipe.x -= 2;
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

	Image mariostandL = LoadImage("mariostandL.png");
	ImageResize(&mariostandL, 24, 24);
	Texture2D standL = LoadTextureFromImage(mariostandL);

	Image mariorunL = LoadImage("mariorunL.png");
	ImageResize(&mariorunL, 24, 24);
	Texture2D runL = LoadTextureFromImage(mariorunL);

	Image marioslideL = LoadImage("marioslideL.png");
	ImageResize(&marioslideL, 24, 24);
	Texture2D slideL = LoadTextureFromImage(marioslideL);

	Image mariojumpL = LoadImage("mariojumpL.png");
	ImageResize(&mariojumpL, 24, 24);
	Texture2D jumpL = LoadTextureFromImage(mariojumpL);

	Image mariolevel = LoadImage("mariobird.png");
	Texture2D level = LoadTextureFromImage(mariolevel);
	SetTargetFPS(60);

	//--------------------------------------------------------------------------------------
	// Main game loop

	int y = 0;
	float x = 0;
	Rectangle player = { screenWidth / 2 - 20 / 2, (screenHeight / 2 - 20 / 2), 20, 20 };
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


	Rectangle ground = { 0,200 + 100,3392,5 };
	

	int delay = 0;
	int alternate = 0;
	bool click = false;
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		if (CheckCollisionRecs(player, ground) || collisionCheck(player, pipes)) {
			//game over/ restart screen
			DrawTexture(level, x * 2, 150, WHITE);
		}
		else {

			char buffer[20];
			sprintf_s(buffer, 20, "%f", player.x);

			char buffer2[20];
			sprintf_s(buffer2, 20, "%f", x);
			DrawText(buffer, 0, 400, 3, BLACK);
			DrawText(buffer2, 0, 410, 3, BLACK);

			DrawTexture(level, x * 2, 100, WHITE);
			movePipes(pipes);
			x--;

			DrawRectangleRec(ground, BLACK);




			//background
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !click) {
				if (alternate % 10 > 5) {
					DrawTexture(runR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);
					alternate++;
				}
				else {
					DrawTexture(slideR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);
					alternate++;
					if (alternate > 10000) {
						alternate = 0;
					}
				}

				printPipes(pipes);
				DrawRectangleRec(player, BLACK);
				click = true;

			}
			else if (IsMouseButtonUp(MOUSE_LEFT_BUTTON) && !click) {
				if (alternate % 10 > 5) {
					DrawTexture(runR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);
					alternate++;
				}
				else {
					DrawTexture(slideR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);
					alternate++;
					if (alternate > 10000) {
						alternate = 0;
					}
				}

				printPipes(pipes);
				DrawRectangleRec(player, BLACK);
				player.y += 1;
			}
			else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !click) {
				if (alternate % 10 > 5) {
					DrawTexture(runR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);
					alternate++;
				}
				else {
					DrawTexture(slideR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);
					alternate++;
					if (alternate > 10000) {
						alternate = 0;
					}
				}

				printPipes(pipes);
				DrawRectangleRec(player, BLACK);
				player.y += 1;
			}
			else {
				DrawTexture(jumpR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);

				printPipes(pipes);
				DrawRectangleRec(player, BLACK);
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
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}


//
//char buffer[20];
//sprintf_s(buffer, 20, "%f", player.x);
//
//char buffer2[20];
//sprintf_s(buffer2, 20, "%f", x);
//DrawText(buffer, 0, 400, 3, BLACK);
//DrawText(buffer2, 0, 410, 3, BLACK);
//
//
//
////background
//if (IsKeyDown(KEY_RIGHT) && !CheckCollisionRecs(player, pipe1)) {
//	DrawTexture(level, x * 3, 37, WHITE);
//	DrawRectangleRec(pipe1, BLACK);
//	DrawRectangleRec(player, BLACK);
//	player.x += 3;
//	x--;
//}
//else if (IsKeyDown(KEY_LEFT) && !CheckCollisionRecs(player, pipe1)) {
//	DrawTexture(level, x * 3, 37, WHITE);
//	DrawRectangleRec(pipe1, BLACK);
//	DrawRectangleRec(player, BLACK);
//	player.x -= 3;
//	x++;
//
//	/*if (x * 3 > 0) {
//	x = 0;
//	}*/
//}
//else if (IsKeyDown(KEY_RIGHT) && CheckCollisionRecs(player, pipe1)) {
//	DrawRectangleRec(pipe1, BLACK);
//	DrawRectangleRec(player, BLACK);
//	DrawTexture(level, x * 3, 37, WHITE);
//
//}
//else if (IsKeyDown(KEY_LEFT) && CheckCollisionRecs(player, pipe1)) {
//	DrawRectangleRec(pipe1, BLACK);
//	DrawRectangleRec(player, BLACK);
//	DrawTexture(level, x * 3, 37, WHITE);
//}
//else {
//	DrawTexture(level, x * 3, 37, WHITE);
//	DrawRectangleRec(player, BLACK);
//	DrawRectangleRec(pipe1, BLACK);
//}
//
//
//if (IsKeyDown(KEY_RIGHT) && IsKeyUp(KEY_SPACE)) { // when only right key is pressed
//	if (delay % 10 > 5) {
//		DrawTexture(runR, screenWidth / 2 - runR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
//		delay++;
//	}
//	else {
//		DrawTexture(slideR, screenWidth / 2 - slideR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
//		delay++;
//		if (delay > 10000) {
//			delay = 0;
//		}
//	}
//	player.y += 2;
//	if (player.y > (screenHeight / 2 - jumpR.height / 2)) {
//		player.y = (screenHeight / 2 - jumpR.height / 2);
//	}
//	y++;
//	if (y > 0) {
//		y = 0;
//	}
//}
//else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_SPACE)) { // when right and space key is pressed
//	DrawTexture(jumpR, screenWidth / 2 - jumpR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
//	player.y -= 2;
//	y--;
//	/*if (y * 2 < -100) {
//	y = 0;
//	}*/
//}
//else if (IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_SPACE)) { // when only left key is pressed
//	if (delay % 10 > 5) {
//		DrawTexture(runL, screenWidth / 2 - runR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
//		delay++;
//	}
//	else {
//		DrawTexture(slideL, screenWidth / 2 - slideR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
//		delay++;
//		if (delay > 10000) {
//			delay = 0;
//		}
//	}player.y += 2;
//	if (player.y > (screenHeight / 2 - jumpR.height / 2)) {
//		player.y = (screenHeight / 2 - jumpR.height / 2);
//	}
//	y++;
//	if (y > 0) {
//		y = 0;
//	}
//}
//else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_SPACE)) { // when left and space key is pressed
//	DrawTexture(jumpL, screenWidth / 2 - jumpL.width / 2, (screenHeight / 2 - jumpL.height / 2) + y * 2, WHITE);
//	player.y -= 2;
//	y--;
//	/*if (y * 2 < -100) {
//	y = 0;
//	}*/
//}
//else if (IsKeyDown(KEY_SPACE)) { // when just space is pressed
//	DrawTexture(standR, screenWidth / 2 - slideR.width / 2, (screenHeight / 2 - slideR.height / 2) + y * 2, WHITE);
//	player.y -= 2;
//	y--;
//	/*if (y * 2 < -100) {
//	y = 0;
//	}*/
//}
//else { // when nothing is pressed
//	DrawTexture(standR, screenWidth / 2 - slideR.width / 2, (screenHeight / 2 - slideR.height / 2) + y * 2, WHITE);
//	player.y += 2;
//	if (player.y > (screenHeight / 2 - jumpR.height / 2)) {
//		player.y = (screenHeight / 2 - jumpR.height / 2);
//	}
//	y++;
//	if (y > 0) {
//		y = 0;
//	}
//}
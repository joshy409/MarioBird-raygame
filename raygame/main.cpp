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

	Image mariolevel = LoadImage("mariolevel.png");
	Texture2D level = LoadTextureFromImage(mariolevel);
	SetTargetFPS(60);

	//--------------------------------------------------------------------------------------
	// Main game loop

	int y = 0;
	int x = 0;
	Rectangle player = { (screenWidth / 2 - jumpR.width) / 2, (screenHeight / 2 - jumpR.height / 2), 24, 24 };
	Rectangle pipe1 = { 450,170+37,30,30 };

	int delay = 0;
	bool collision = false;
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		if (CheckCollisionRecs(player, pipe1)) {
			DrawTexture(level, 0, 90, WHITE);
		}

		//background
		if (IsKeyDown(KEY_RIGHT))  {
			DrawTexture(level,x * 3, 37, WHITE);
			player.x -= x * 3;
			x--;
		}
		else if (IsKeyDown(KEY_LEFT)) {
			DrawTexture(level, x * 3, 37, WHITE);
			player.x += x * 3;
			x++;

			/*if (x * 3 > 0) {
				x = 0;
			}*/
		}
		else {
			DrawTexture(level, x * 3, 37, WHITE);
		}


		if (IsKeyDown(KEY_RIGHT) && IsKeyUp(KEY_SPACE)) { // when only right key is pressed
			if (delay % 10 > 5) {
				DrawTexture(runR, screenWidth / 2 - runR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
				delay++;
			}
			else {
				DrawTexture(slideR, screenWidth / 2 - slideR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
				delay++;
				if (delay > 10000) {
					delay = 0;
				}
			}
			y++;
			if (y > 0) {
				y = 0;
			}
		}
		else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_SPACE)) { // when right and space key is pressed
			DrawTexture(jumpR, screenWidth / 2 - jumpR.width / 2, (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
			y--;
			if (y * 2 < -100) {
				y = 0;
			}
		}
		else if (IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_SPACE)) { // when only left key is pressed
				if (delay % 10 > 5) {
				DrawTexture(runL, screenWidth / 2 - runR.width/ 2 , (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
				delay++;
				}
				else {
					DrawTexture(slideL, screenWidth / 2 - slideR.width / 2 , (screenHeight / 2 - jumpR.height / 2) + y * 2, WHITE);
					delay++;
					if (delay > 10000) {
						delay = 0;
					}
				}
				y++;
				if (y > 0) {
					y = 0;
				}
		}
		else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_SPACE)) { // when left and space key is pressed
			DrawTexture(jumpL, screenWidth / 2 - jumpL.width / 2, (screenHeight / 2 - jumpL.height / 2) + y * 2, WHITE);
			y--;
			if (y * 2 < -100) {
				y = 0;
			}
		}
		else if (IsKeyDown(KEY_SPACE)) { // when just space is pressed
			DrawTexture(standR, screenWidth / 2 - slideR.width / 2, (screenHeight / 2 - slideR.height / 2) + y * 2, WHITE);
			y--;
			if (y * 2 < -100) {
				y = 0;
			}
		}
		else { // when nothing is pressed
			DrawTexture(standR, screenWidth / 2 - slideR.width / 2, (screenHeight / 2 - slideR.height / 2) + y * 2, WHITE);
			y++;
			if (y > 0) {
				y = 0;
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
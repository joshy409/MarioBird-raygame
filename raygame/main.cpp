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

bool collisionCheckTritangle(Rectangle player, std::vector<Triangle> pipes) {

	for (auto &pipe : pipes) {
		
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

void printBricks(std::vector<Triangle>& bricks) {

	for (auto &brick : bricks) {
		DrawTriangle(brick.vertex1,brick.vertex2,brick.vertex3, BLACK);
	}

}

void moveBricks(std::vector<Triangle>& bricks) {

	for (auto &brick : bricks) {
		brick.vertex1.x -= 2;
		brick.vertex2.x -= 2;
		brick.vertex3.x -= 2;
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

	/*Image mariostandL = LoadImage("mariostandL.png");
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
	Texture2D jumpL = LoadTextureFromImage(mariojumpL);*/

	Image mariolevel = LoadImage("mariobird.png");
	Texture2D level = LoadTextureFromImage(mariolevel);
	SetTargetFPS(60);

	//--------------------------------------------------------------------------------------
	// Main game loop

	int y = 0;
	float x = 0;
	Rectangle player = { screenWidth / 2 - 20 / 2, (screenHeight / 2 - 20 / 2), 10, 10 };
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


	int delay = 0;
	int alternate = 0;
	bool click = false;
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{

		//if (CheckCollisionRecs(player, ground) || collisionCheckRectangle(player, pipes) ){
			//game over/ restart screen
			//DrawTexture(level, x * 2, 150, WHITE);
		//}	
		//else {

			char buffer[20];
			sprintf_s(buffer, 20, "%f", player.x);

			char buffer2[20];
			sprintf_s(buffer2, 20, "%f", x);
			DrawText(buffer, 0, 400, 3, BLACK);
			DrawText(buffer2, 0, 410, 3, BLACK);

			DrawTexture(level, x * 2, 100, WHITE);
			movePipes(pipes);
			printPipes(pipes);
			DrawRectangleRec(ground, BLACK);


			moveBricks(bricks);
			printBricks(bricks);



			x--;

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

				DrawRectangleRec(player, BLACK);
				player.y += 1;
			}
			else {
				DrawTexture(jumpR, screenWidth / 2 - jumpR.width / 2, (int)player.y, WHITE);
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
		//}
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
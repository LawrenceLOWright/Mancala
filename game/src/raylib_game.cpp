#include "raylib.h"
#include <cstdlib>
#include <random>

int end = 0;
int score_array[14];
int back_array[14];
bool done;
bool pextraTurn = false;
Image board;
Image ball1;
Image ball2;
Image ball3;
Image ball4;
Image ball5;
Image ball6;
Image ball7;
Image ball8;
Image end1;
Image end2;
Image end3;
Image end4;
Image end5;
Image end6;
Image end7;
Image end8;
Image end9;
Image end10;
Image end11;

Texture2D texture;
Texture2D ball1_text;
Texture2D ball2_text;
Texture2D ball3_text;
Texture2D ball4_text;
Texture2D ball5_text;
Texture2D ball6_text;
Texture2D ball7_text;
Texture2D ball8_text;
Texture2D end1_text;
Texture2D end2_text;
Texture2D end3_text;
Texture2D end4_text;
Texture2D end5_text;
Texture2D end6_text;
Texture2D end7_text;
Texture2D end8_text;
Texture2D end9_text;
Texture2D end10_text;
Texture2D end11_text;

int updateboard() {
    int i;
    int x;
    int y;



    for (i = 0; i < 14; ++i) {

        //IF I IS A PIT
        if (i != 6 && i != 13) {
            if (i < 6) {
                x = (i * 170) + 325;
                y = 265;
            }
            if (i > 6) {
                x = 1175 - ((i - 7) * 170);
                y = 75;
            }

            if (score_array[i] == 0) {
                //remove current image

                DrawText("0", x, y, 32, BLACK);
            }
            if (score_array[i] == 1) {


                //DrawTexture(ball1_text, x, y, WHITE);

                DrawText("1", x, y, 32, BLACK);

            }
            if (score_array[i] == 2) {

                //DrawTexture(ball2_text, x, y, WHITE);

                DrawText("2", x, y, 32, BLACK);

            }
            if (score_array[i] == 3) {
                //DrawTexture(ball3_text, x, y, WHITE);

                DrawText("3", x, y, 32, BLACK);

            }
            if (score_array[i] == 4) {

                //DrawTexture(ball4_text, x, y, WHITE);

                DrawText("4", x, y, 32, BLACK);

            }
            if (score_array[i] == 5) {

                //DrawTexture(ball5_text, x, y, WHITE);

                DrawText("5", x, y, 32, BLACK);

            }
            if (score_array[i] == 6) {

                //DrawTexture(ball6_text, x, y, WHITE);

                DrawText("6", x, y, 32, BLACK);

            }
            if (score_array[i] == 7) {

                //DrawTexture(ball7_text, x, y, WHITE);

                DrawText("7", x, y, 32, BLACK);

            }
            if (score_array[i] == 8) {

                //DrawTexture(ball8_text, x, y, WHITE);

                DrawText("8", x, y, 32, BLACK);

            }

            if (score_array[i] > 8) {

                //DrawTexture(ball8_text, x, y, WHITE);

                DrawText(TextFormat("%i\n", score_array[i]), x, y, 32, BLACK);

            }
            else {
                DrawText(TextFormat("%i\n", score_array[i]), x, y, 32, BLACK);
            }



        }

        //IF I IS A SCORE POT
        if (i == 6 || i == 13) {
            if (i == 6) {
                x = 1360;
                y = 160;
            }

            if (i == 13) {
                x = 132;
                y = 160;
            }

            if (score_array[i] == 1) {
                //DrawTexture(end1_text, x, y, WHITE);

                DrawText("1", x, y, 50, BLACK);
            }
            if (score_array[i] == 2) {
                //DrawTexture(end2_text, x, y, WHITE);

                DrawText("2", x, y, 50, BLACK);
            }
            if (score_array[i] == 3) {
                //DrawTexture(end3_text, x, y, WHITE);

                DrawText("3", x, y, 50, BLACK);
            }
            if (score_array[i] == 4) {
                //DrawTexture(end4_text, x, y, WHITE);

                DrawText("4", x, y, 50, BLACK);
            }
            if (score_array[i] == 5) {
                //DrawTexture(end5_text, x, y, WHITE);

                DrawText("5", x, y, 50, BLACK);
            }
            if (score_array[i] == 6) {
                //DrawTexture(end6_text, x, y, WHITE);

                DrawText("6", x, y, 50, BLACK);
            }
            if (score_array[i] == 7) {
                //DrawTexture(end7_text, x, y, WHITE);

                DrawText("7", x, y, 50, BLACK);
            }
            if (score_array[i] == 8) {
                //DrawTexture(end8_text, x, y, WHITE);

                DrawText("8", x, y, 50, BLACK);
            }
            if (score_array[i] == 9) {
                //DrawTexture(end9_text, x, y, WHITE);

                DrawText("9", x, y, 50, BLACK);
            }
            if (score_array[i] == 10) {
                //DrawTexture(end10_text, x, y, WHITE);

                DrawText("10", x, y, 50, BLACK);
            }
            if (score_array[i] >= 11) {
                //DrawTexture(end11_text, x, y, WHITE);

                DrawText(TextFormat("%i\n", score_array[i]), x, y, 50, BLACK);
            }
            else {
                DrawText(TextFormat("%i\n", score_array[i]), x, y, 50, BLACK);
            }

        }

    }
    return 1;
}





bool gameover_check() {

    // if all of the tokens have been put in the score pits
    int player_sum = 0;
    int comp_sum = 0;
    for (int i = 0; i < 6; ++i) {
        player_sum = player_sum + score_array[i];
    }
    for (int i = 7; i < 13; ++i) {
        comp_sum = comp_sum + score_array[i];
    }

    if (player_sum == 0 || comp_sum == 0) {  // if the player won
        return true;
    }

    // If not done
    else {
        return false;
    }
}

void next_turn(int position) {

    // pick up tokens from the hole
    int tokens = score_array[position];
    int turn = -1;

    score_array[position] = 0;

    // if we're starting on player turn, turn = 0
    if (position < 6) {
        turn = 0;
    }
    // if we're starting on computer turn, turn = 1
    if (position > 7) {
        turn = 1;
    }

    while (tokens != 0) {
        // Next space
        position = position + 1;

        // AKA if the next spot is out of the array
        if (position > 13) {
            position = 0;
        }

        // Skip the space if it's the other player's pit
        if ((position == 6 && turn == 1) || (position == 13 && turn == 0)) {
            position = position + 1;
        }


        // Put a bead into the current spot
        if (position != 6 || position != 13) {
            score_array[position] = score_array[position] + 1;
        }

        tokens = tokens - 1;
    }

    // Check if bead landed in an empty spot to take stuff
    if (turn == 0) {
        // If it landed in the player's pit
        if (position == 6) {
        }
        else if (score_array[position] == 1 && score_array[position + (2 * (6 - position))] != 0) {
            score_array[6] = score_array[6] + score_array[position + (2 * (6 - position))] + 1;
            score_array[position + (2 * (6 - position))] = 0;
            score_array[position] = 0;
        }
    }

    updateboard();

    if (turn == 1) {
        if (position == 13) {
        }

        else if (score_array[position] == 1 && score_array[position - (2 * (position - 6))] != 0) {
            score_array[13] = score_array[13] + score_array[position - (2 * (position - 6))] + 1;
            score_array[position - (2 * (position - 6))] = 0;
            score_array[position] = 0;
        }
    }

    else {
        if (turn == 1) {
            turn = 0;
            // Player turn
        }

        if (turn == 0) {
            turn = 1;
            // Computer turn
        }
    }
    updateboard();
}


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1520;
    const int screenHeight = 450;
    int player_input = -1;
    int computer_went = 0;
    int turn = 0;
    int timer = 0;
    int wsec = 1;


    for (int i = 0; i < 15; i++) { //initialize the array
        if (i == 6 || i == 13) {
            score_array[i] = 0;
        }
        else {
            score_array[i] = 4;
        }
    }

    for (int i = 0; i < 14; i++) {
        back_array[i] = score_array[i];
    }


    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image drawing");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)


    Image board = LoadImage("../../resources/MancalaBoard.png");             // Load image in CPU memory (RAM)
    Image ball1 = LoadImage("../../resources/1token.png");
    Image ball2 = LoadImage("../../resources/2token.png");
    Image ball3 = LoadImage("../../resources/3token.png");
    Image ball4 = LoadImage("../../resources/4token.png");
    Image ball5 = LoadImage("../../resources/5token.png");
    Image ball6 = LoadImage("../../resources/6token.png");
    Image ball7 = LoadImage("../../resources/7token.png");
    Image ball8 = LoadImage("../../resources/8token.png");
    Image end1 = LoadImage("../../resources/end1token.png");
    Image end2 = LoadImage("../../resources/end2token.png");
    Image end3 = LoadImage("../../resources/end3token.png");
    Image end4 = LoadImage("../../resources/end4token.png");
    Image end5 = LoadImage("../../resources/end5token.png");
    Image end6 = LoadImage("../../resources/end6token.png");
    Image end7 = LoadImage("../../resources/end7token.png");
    Image end8 = LoadImage("../../resources/end8token.png");
    Image end9 = LoadImage("../../resources/end9token.png");
    Image end10 = LoadImage("../../resources/end10token.png");
    Image end11 = LoadImage("../../resources/end11token.png");
    ImageResize(&board, 1495, 410);                            // Resize flipped-cropped image
    ImageResize(&ball1, 60, 60);
    ImageResize(&ball2, 60, 60);
    ImageResize(&ball3, 60, 60);
    ImageResize(&ball4, 60, 60);
    ImageResize(&ball5, 60, 60);
    ImageResize(&ball6, 60, 60);
    ImageResize(&ball7, 60, 60);
    ImageResize(&ball8, 60, 60);
    ImageResize(&end1, 60, 60);
    ImageResize(&end2, 60, 60);
    ImageResize(&end3, 60, 60);
    ImageResize(&end4, 60, 60);
    ImageResize(&end6, 60, 60);
    ImageResize(&end7, 60, 60);
    ImageResize(&end8, 60, 60);
    ImageResize(&end9, 60, 60);
    ImageResize(&end10, 60, 60);
    ImageResize(&end11, 60, 60);


    Vector2 ballPosition = { -100.0f, -100.0f };
    Color ballColor = DARKBLUE;


    Texture2D texture = LoadTextureFromImage(board);      // Image converted to texture, uploaded to GPU memory (VRAM)
    Texture2D ball1_text = LoadTextureFromImage(ball1);
    Texture2D ball2_text = LoadTextureFromImage(ball2);
    Texture2D ball3_text = LoadTextureFromImage(ball3);
    Texture2D ball4_text = LoadTextureFromImage(ball4);
    Texture2D ball5_text = LoadTextureFromImage(ball5);
    Texture2D ball6_text = LoadTextureFromImage(ball6);
    Texture2D ball7_text = LoadTextureFromImage(ball7);
    Texture2D ball8_text = LoadTextureFromImage(ball8);
    Texture2D end1_text = LoadTextureFromImage(end1);
    Texture2D end2_text = LoadTextureFromImage(end2);
    Texture2D end3_text = LoadTextureFromImage(end3);
    Texture2D end4_text = LoadTextureFromImage(end4);
    Texture2D end5_text = LoadTextureFromImage(end5);
    Texture2D end6_text = LoadTextureFromImage(end6);
    Texture2D end7_text = LoadTextureFromImage(end7);
    Texture2D end8_text = LoadTextureFromImage(end8);
    Texture2D end9_text = LoadTextureFromImage(end9);
    Texture2D end10_text = LoadTextureFromImage(end10);
    Texture2D end11_text = LoadTextureFromImage(end11);
    UnloadImage(board);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
    UnloadImage(ball1);
    UnloadImage(ball2);
    UnloadImage(ball3);
    UnloadImage(ball4);
    UnloadImage(ball5);
    UnloadImage(ball6);
    UnloadImage(ball7);
    UnloadImage(ball8);
    UnloadImage(end1);
    UnloadImage(end2);
    UnloadImage(end3);
    UnloadImage(end4);
    UnloadImage(end5);
    UnloadImage(end6);
    UnloadImage(end7);
    UnloadImage(end8);
    UnloadImage(end9);
    UnloadImage(end10);
    UnloadImage(end11);

    InitAudioDevice();      // Initialize audio device

    Sound click = LoadSound("../../resources/click.wav");         // Load WAV audio file
    Sound win = LoadSound("../../resources/win.wav");        // Load OGG audio file
    Sound lose = LoadSound("../../resources/lose.wav");         // Load WAV audio file
    Sound BONE = LoadSound("../../resources/tie.wav");        // Load OGG audio file

    SetSoundVolume(click, 0.2f);
    SetSoundVolume(win, 0.2f);
    SetSoundVolume(lose, 0.2f);
    SetSoundVolume(BONE, 0.2f);

    SetTargetFPS(60);
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------




        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 40, WHITE);
        /* DrawTexture(ball4_text, 300, 250, WHITE);
         DrawTexture(ball4_text, 470, 250, WHITE);
         DrawTexture(ball4_text, 640, 250, WHITE);
         DrawTexture(ball4_text, 810, 250, WHITE);
         DrawTexture(ball4_text, 980, 250, WHITE);
         DrawTexture(ball4_text, 1150, 250, WHITE);*/
        DrawRectangleLines(screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 40, texture.width, texture.height, DARKGRAY);








        int position = -1;




        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseY() > 205 && (GetMouseX() > 240 && GetMouseX() < 400)) {

            position = 0;

        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseY() > 205 && (GetMouseX() > 400 && GetMouseX() < 580)) {

            position = 1;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseY() > 205 && (GetMouseX() > 580 && GetMouseX() < 750)) {

            position = 2;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseY() > 205 && (GetMouseX() > 750 && GetMouseX() < 920)) {

            position = 3;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseY() > 205 && (GetMouseX() > 920 && GetMouseX() < 1090)) {

            position = 4;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && GetMouseY() > 205 && (GetMouseX() > 1090 && GetMouseX() < 1260)) {

            position = 5;
        }
        if (position != -1) {
            PlaySoundMulti(click);
            pextraTurn = false;
        }




        if (turn == 0) {
            if (pextraTurn == true) {
                DrawText("Extra Player Turn!", 600, 400, 40, DARKGRAY);
            }
            else {
                DrawText("Player Turn", 600, 400, 40, BLACK);
            }
            //pextraTurn = false;
            if (position != -1) {
                if ((position + back_array[position]) == 6) {
                    pextraTurn = true;
                }
                next_turn(position);
                updateboard();
                position = -1;

                if (pextraTurn == false) {
                    turn = 1;
                }
                timer = 0;
                for (int i = 0; i < 14; i++) {
                    back_array[i] = score_array[i];
                }
            }
        }

        if (turn == 1) {
            DrawText("Computer Turn", 600, 400, 40, BLACK);
            timer = timer + 1;
        }

        if (turn == 1 && timer > (60 * wsec)) {
            for (int i = 7; i < 13; i++) {
                if (score_array[i] == 13 - i) {
                    computer_went = 1;
                    next_turn(i);
                    updateboard();

                    // computer's next turn
                    int r = 7 + rand() % 6;

                    while (score_array[r] == 0) {
                        r = 7 + rand() % 6;
                        //printf("\n%d\n\n", r);
                    }

                    next_turn(r);
                    updateboard();
                    turn = 0;
                }
            }

            // computer checks if it can steal through empty space
            for (int i = 7; i < 13; i++) {
                if (score_array[i] == 0 && computer_went == 0) {
                    for (int n = 7; n < i; n++) {
                        if (score_array[n] == (i - n) && score_array[position - (2 * (position - 6))] != 0) {
                            computer_went = 1;

                            next_turn(n);
                            updateboard();
                            turn = 0;
                        }
                    }
                }
            }

            // if not extra turn or steal, computer picks random hole and moves
            if (computer_went == 0) {
                int r = 7 + rand() % 6;
                while (score_array[r] == 0) {
                    r = 7 + rand() % 6;
                }

                next_turn(r);
                turn = 0;
            }

            // rest computer_went
            computer_went = 0;

            updateboard();
            turn = 0;
        }



        updateboard();

        done = gameover_check();
        if (done == true) {
            if (score_array[6] > score_array[13]) {
                PlaySoundMulti(win);
                DrawRectangle(0, 0, screenWidth, screenHeight, DARKPURPLE);
                DrawText("YOU WIN!", 760, 225, 60, GOLD);
                DrawText(TextFormat("Your score: %i\n", score_array[6]), 760, 300, 32, GOLD);
                DrawText(TextFormat("The computer's score: %i\n", score_array[13]), 760, 375, 32, GOLD);



            }
            else if (score_array[13] > score_array[6]) {
                PlaySoundMulti(lose);
                DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                DrawText("THE COMPUTER WON...", 760, 225, 60, GRAY);
                DrawText(TextFormat("Your score: %i\n", score_array[6]), 760, 300, 32, GRAY);
                DrawText(TextFormat("The computer's score: %i\n", score_array[13]), 760, 375, 32, GRAY);



            }
            else {
                PlaySoundMulti(BONE);
                DrawRectangle(0, 0, screenWidth, screenHeight, SKYBLUE);
                DrawText("IT'S A BONE!", 760, 225, 60, DARKBLUE);
                DrawText(TextFormat("Your score: %i\n", score_array[6]), 760, 300, 32, BLACK);
                DrawText(TextFormat("The computer's score: %i\n", score_array[13]), 760, 375, 32, BLACK);



            }
        }

        //BeginDrawing();
        //DrawText("hello world", 240, 350, 10, DARKGRAY);
        //DrawText("goodbye world", 190, 370, 10, DARKGRAY);
        EndDrawing();
    }









    //  EndDrawing();
      //----------------------------------------------------------------------------------



  // De-Initialization
  //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Texture unloading

    StopSoundMulti();       // We must stop the buffer pool before unloading

    UnloadSound(win);     // Unload sound data
    UnloadSound(lose);     // Unload sound data
    UnloadSound(BONE);     // Unload sound data
    UnloadSound(click);     // Unload sound data

    CloseAudioDevice();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
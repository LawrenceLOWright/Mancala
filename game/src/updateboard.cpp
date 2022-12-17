#include <raylib.h>

int updateboard() {
    int i;
    int x;
    int y;

    for (i = 0; i < 14; ++i) {

        //IF I IS A PIT
        if (i != 6 || i != 13) {
            if (i < 6) {
                x = (i * 170) + 300;
                y = 250;
            }
            if (i > 6) {
                x = ((i - 7) * 170) + 300;
                y = 125;
            }

            if (score_array[i] == 0) {
                //remove current image
            }
            if (score_array[i] == 1) {
                DrawTexture(ball_1text, x, y);
            }
            if (score_array[i] == 2) {
                DrawTexture(ball_2text, x, y);
            }
            if (score_array[i] == 3) {
                DrawTexture(ball_3text, x, y);
            }
            if (score_array[i] == 4) {
                DrawTexture(ball_4text, x, y);
            }
            if (score_array[i] == 5) {
                DrawTexture(ball_5text, x, y);
            }
            if (score_array[i] == 6) {
                DrawTexture(ball_6text, x, y);
            }
            if (score_array[i] == 7) {
                DrawTexture(ball_7text, x, y);
            }
            if (score_array[i] == 8 || score_array[i] > 8) {
                DrawTexture(ball_8text, x, y);
            }
        }

        //IF I IS A SCORE POT
        if (i == 6 || i == 13) {
            if (i == 6) {
                x = 110;
                y = 100;
            }

            if (i == 13) {
                x = 1300;
                y = 100;
            }

            if (score_array[i] == 1) {
                DrawTexture(end_1text, x, y);
            }
            if (score_array[i] == 2) {
                DrawTexture(end_2text, x, y);
            }
            if (score_array[i] == 3) {
                DrawTexture(end_3text, x, y);
            }
            if (score_array[i] == 4) {
                DrawTexture(end_4text, x, y);
            }
            if (score_array[i] == 5) {
                DrawTexture(end_5text, x, y);
            }
            if (score_array[i] == 6) {
                DrawTexture(end_6text, x, y);
            }
            if (score_array[i] == 7) {
                DrawTexture(end_7text, x, y);
            }
            if (score_array[i] == 8) {
                DrawTexture(end_8text, x, y);
            }
            if (score_array[i] == 9) {
                DrawTexture(end_9text, x, y);
            }
            if (score_array[i] == 10) {
                DrawTexture(end_10text, x, y);
            }
            if (score_array[i] >= 11) {
                DrawTexture(end_11text, x, y);
            }

        }

    }
}
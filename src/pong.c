#include <stdio.h>
#include <stdlib.h>

void screen(int Left_racket, int Right_racket, int X_ball, int Y_ball, int Width, int Height, int P1_score,
            int P2_score);
void score_points(int P1_score, int P2_score);

int main() {
    // заведение начальных координат

    // // размеры рамки

    int Width = 80;
    int Height = 25;

    // // координаты ракетки

    int Left_racket = (Height / 2) - 1;
    int Right_racket = (Height / 2) - 1;

    // // координаты мяча

    int X_ball = Width / 2;
    int Y_ball = Height / 2;

    // // начальный счет

    int P1_score = 0;
    int P2_score = 0;

    // // начальный вектор движения мяча

    int Ball_move = 4;

    while (1) {
        screen(Left_racket, Right_racket, X_ball, Y_ball, Width, Height, P1_score, P2_score);

        // остановка цикла при достижении максимального счета

        if (P1_score == 21 || P2_score == 21) {
            break;
        }

        // обработка входящих значений

        char key;
        scanf("%c", &key);

        if (key == 'A' || key == 'a') {
            if (Left_racket > 1) {
                Left_racket--;
            }
        } else if (key == 'Z' || key == 'z') {
            if (Left_racket + 2 < Height - 1) {
                Left_racket++;
            }
        } else if (key == 'K' || key == 'k') {
            if (Right_racket > 1) {
                Right_racket--;
            }
        } else if (key == 'M' || key == 'm') {
            if (Right_racket + 2 < Height - 1) Right_racket++;

        } else if (key == 'q' || key == 'Q') {
            break;
        }

        // гол слева

        if (X_ball == 1) {
            // обнуление стартовых положений мяча и ракеток

            X_ball = 4;
            Y_ball = Height / 2 - 1;
            Left_racket = (Height / 2) - 1;
            Right_racket = (Height / 2) - 1;
            P2_score++;
            Ball_move = 3;
        }

        // гол справа

        if (X_ball == Width - 2) {
            // обнуление стартовых положений мяча и ракеток

            X_ball = Width - 4;
            Y_ball = Height / 2 + 1;
            Left_racket = (Height / 2) - 1;
            Right_racket = (Height / 2) - 1;
            P1_score++;
            Ball_move = 6;
        }

        // направления движения мяча

        if (Ball_move == 1) {
            X_ball++;
            Y_ball--;
        }
        if (Ball_move == 2) {
            X_ball++;
        }
        if (Ball_move == 3) {
            X_ball++;
            Y_ball++;
        }
        if (Ball_move == 4) {
            X_ball--;
            Y_ball++;
        }
        if (Ball_move == 5) {
            X_ball--;
        }
        if (Ball_move == 6) {
            X_ball--;
            Y_ball--;
        }

        // отскок от верха

        if (Y_ball == 1) {
            if (Ball_move == 1) Ball_move = 3;
            if (Ball_move == 6) Ball_move = 4;
        }

        // отскок от низа

        if (Y_ball == Height - 1) {
            if (Ball_move == 3) Ball_move = 1;
            if (Ball_move == 4) Ball_move = 6;
        }

        // отскок от левой ракетки

        if (X_ball == 4) {
            if (Y_ball == Left_racket) {
                Ball_move = 1;
            }
            if (Y_ball == Left_racket + 1) {
                Ball_move = 2;
            }
            if (Y_ball == Left_racket + 2) {
                Ball_move = 3;
            }
        }

        // отскок от правой ракетки

        if (X_ball == Width - 4) {
            if (Y_ball == Right_racket) {
                Ball_move = 6;
            }
            if (Y_ball == Right_racket + 1) {
                Ball_move = 5;
            }
            if (Y_ball == Right_racket + 2) {
                Ball_move = 4;
            }
        }
    }
}

// отрисовка картинки

void screen(int Left_racket, int Right_racket, int X_ball, int Y_ball, int Width, int Height, int P1_score,
            int P2_score) {
    // очистка экрана после каждого шага

    system("clear");

    for (int y = 0; y <= Height; y++) {
        for (int x = 0; x <= Width; x++) {
            if ((y == 0 || y == Height) && x != 0 && x <= Width - 1) {
                printf("#");
            } else if ((x == 0 || x == Width) && y < Height + 1) {
                printf("#");
            } else if (y >= Left_racket && y < Left_racket + 3 && x == 3) {
                printf("|");
            } else if (y >= Right_racket && y < Right_racket + 3 && x == Width - 3) {
                printf("|");
            } else if (y == Y_ball && x == X_ball) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    //отражение счета под полем

    printf("Player 1 score: %d\n", P1_score);
    printf("Player 2 score: %d\n", P2_score);
    score_points(P1_score, P2_score);
}

// ведение счета и вывод поздравлений

void score_points(int P1_score, int P2_score) {
    if (P1_score == 21) {
        printf("Player 1 is a winner!\n");
    }
    if (P2_score == 21) {
        printf("Player 2 is a winner!\n");
    }
}

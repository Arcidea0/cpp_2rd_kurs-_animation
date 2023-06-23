#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void space()
{
    double k;
    printf("   ");
    for (k = 1; k < 5e+7; k++);
}

int main() {
    const int n = 10, m = 25;
    int max, x[n];
    srand(time(0));
    COORD pos;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = 0;
    pos.Y = 0;

    for (int i = 0; i < n; i++) {
        x[i] = rand() % 99 + 2;
        pos.X = 4 * i;
        SetConsoleCursorPosition(hConsole, pos);
        printf("%3d", x[i]);
        space();
    }
    pos.Y += 2;
    pos.X = 0;
    SetConsoleCursorPosition(hConsole, pos);
    max = x[2];
    for (int i = 1; i < n; i++)
        if (x[i] > max)
            max = x[i];

    //parz tveri voroshum
    int y[m];
    int index = 2;
    y[0] = 2;
    y[1] = 3;
    for (int i = 5; i <= max; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0)
                break;
            else if (i == j + 1) {
                y[index] = i;
                index++;
            }
        }
    }
    if (index < m) 
        while (index < m)
            y[index++] = 0;
 
    //ays gorcoxutyamb voroshvum e te vor parz tvi artadrichn e tvyal tivy
    int parz[n + 1][m];
    for (int j = 0; j < m; j++)
        parz[0][j] = y[j];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            parz[i][j] = 0;

    for (int i = 0; i < n; i++) {
        index = 0;
        while (index < m) {
            if (x[i] % y[index] == 0 && x[i] != 0) {
                int a = 1;
                while (parz[a][index] != 0)
                    a++; 
                parz[a][index] = x[i];
                break;
            }
            index++;
        }
    }


    pos.Y = 2;
    for (int i = 0; i <= n; i++) {
        pos.X = 0;
        SetConsoleCursorPosition(hConsole, pos);
        for (int j = 0; j < m; j++) {
            if (i == 0 && parz[i][j] != 0)
                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
            else
                SetConsoleTextAttribute(hConsole, 15);
            if (parz[i][j] != 0) {
                printf("%3d ", parz[i][j]);
                if (j != m - 1)
                    pos.X = (j + 1) * 4;
                for (int k = 1; k < 5e+7; k++);
                SetConsoleCursorPosition(hConsole, pos);
            }
            else {
                pos.X = (j + 1) * 4;
                printf("    ");
            }

        }
        pos.Y++;
        SetConsoleCursorPosition(hConsole, pos);
    }
    pos.Y = n + 3;
    pos.X = 0;
    SetConsoleCursorPosition(hConsole, pos);

    int i, k0 = 0, ky, j = 0, k = 0, a;
    double erkar;
    for (erkar = 1; erkar < 4e+8; erkar++);
    for (j = 0; j < m; j++) {
        i = n - 1;
        pos.Y = n + 2;
        
        SetConsoleCursorPosition(hConsole, pos);
        while (i > 0) {
            if (parz[i][j] <= 0 || parz[i][j] > 100) {
                i--;
                pos.Y--;
            }
            else break;
        }
        a = i;
        SetConsoleCursorPosition(hConsole, pos);
        while (a > 0) {
            pos.X = j * 4;
            k = a - 2;
            ky = pos.Y;
            while (pos.Y != n + 4) {
               pos.Y--;
               SetConsoleCursorPosition(hConsole, pos);
               printf("   ");
               pos.Y++;
               SetConsoleCursorPosition(hConsole, pos);
               printf("%3d", parz[a][j]);
               pos.Y++;
               SetConsoleCursorPosition(hConsole, pos);
               for (erkar = 1; erkar < 3e+8; erkar++);
            }
            for (erkar = 1; erkar < 3e+8; erkar++);
            pos.Y--;
            SetConsoleCursorPosition(hConsole, pos);
            if (j <= (k + k0)) {
                while (pos.X <= (k + k0) * 4) {
                    if (j == 0 && a == 1) break;
                    SetConsoleCursorPosition(hConsole, pos);
                    space();
                    pos.X += 4;
                    SetConsoleCursorPosition(hConsole, pos);
                    printf("%3d", parz[a][j]);
                    for (erkar = 1; erkar < 3e+8; erkar++);
                }
            }
            else if (j > (k + k0 + 1)) {
                while (pos.X > (k + k0 + 1) * 4) {
                    SetConsoleCursorPosition(hConsole, pos);
                    space();
                    pos.X -= 4;
                    SetConsoleCursorPosition(hConsole, pos);
                    printf("%3d", parz[a][j]);
                    for (erkar = 1; erkar < 3e+8; erkar++);
                }
            }
            pos.Y;
            SetConsoleCursorPosition(hConsole, pos);
            space();
            pos.Y++;
            SetConsoleTextAttribute(hConsole, 11);
            SetConsoleCursorPosition(hConsole, pos);
            printf("%3d", parz[a][j]);
            SetConsoleTextAttribute(hConsole, 15);
            a--;
            pos.Y = ky - 1;
        }
        k0 += i;
    }
    pos.Y = n + 4;
    SetConsoleCursorPosition(hConsole, pos);
    return 0;
}
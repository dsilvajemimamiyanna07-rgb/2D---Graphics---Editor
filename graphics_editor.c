#include <stdio.h>

#define ROWS 25
#define COLS 60

char rectCanvas[ROWS][COLS];

void initialize()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            rectCanvas[i][j] = '_';
        }
    }
}

void display()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", rectCanvas[i][j]);
        }

        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            rectCanvas[i][j] = '*';
        }
    }
}

int main()
{
    int x, y, w, h;

    initialize();

    printf("Enter x y width height: ");
    scanf("%d%d%d%d", &x, &y, &w, &h);

    drawRectangle(x, y, w, h);

    display();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 60

char rectCanvas[ROWS][COLS];
char lineCanvas[ROWS][COLS];

/* Initialize Canvas */
void initialize(char canvas[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

/* Display Canvas */
void display(char canvas[ROWS][COLS])
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

/* Feature 1: Draw Rectangle */
void drawRectangle(char canvas[ROWS][COLS],
                   int x, int y,
                   int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

/* Feature 2: Draw Line */
void drawLine(char canvas[ROWS][COLS],
              int x1, int y1,
              int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    int i;

    for(i = 0; i <= steps; i++)
    {
        if((int)x >= 0 && (int)x < COLS &&
           (int)y >= 0 && (int)y < ROWS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xInc;
        y += yInc;
    }
}

int main()
{
    int choice;

    initialize(rectCanvas);
    initialize(lineCanvas);

    do
    {
        printf("\n===== GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Display Rectangle Canvas\n");
        printf("4. Display Line Canvas\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x, y, w, h;

                initialize(rectCanvas);

                printf("Enter x y width height: ");
                scanf("%d%d%d%d", &x, &y, &w, &h);

                drawRectangle(rectCanvas, x, y, w, h);

                printf("Rectangle Drawn Successfully\n");
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;

                initialize(lineCanvas);

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",
                      &x1, &y1,
                      &x2, &y2);

                drawLine(lineCanvas,
                         x1, y1,
                         x2, y2);

                printf("Line Drawn Successfully\n");
                break;
            }

            case 3:
                printf("\nRECTANGLE CANVAS\n");
                display(rectCanvas);
                break;

            case 4:
                printf("\nLINE CANVAS\n");
                display(lineCanvas);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 5);

    return 0;
}
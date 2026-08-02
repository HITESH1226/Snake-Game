#include<stdio.h>
#include <windows.h>
#include <stdlib.h>

	int width = 50;
	int height = 30;

	int snakeX;
	int snakeY;

	int foodX;
	int foodY;

	int tailX[100];
	int tailY[100];

	int tailLength = 0;

	int score = 0;

	char direction = 'D';

	int gameOver = 0;
	
void setup(){
	
	snakeX = width/2;
	snakeY = height/2; 
	
	foodX=5;
	foodY=8;
}

void draw()
{
	system("cls");
    int i,j,k;
	for(i=0;i<width+2;i++)
	{
		printf("#");
	}
	printf("\n");
	
	for(i=0;i<height;i++)
	{
		printf("#");
		for(j=0;j<width;j++)
		{
			if(i == snakeY && j == snakeX)
			{
    			printf("O");
			}
			else if(i == foodY && j == foodX)
			{
		    	printf("*");
			}
			else
			{
    			int isTail = 0;

    			for(k = 0; k < tailLength; k++)
    			{
        			if(i == tailY[k] && j == tailX[k])
        				{
            				printf("o");
            				isTail = 1;
            				break;
        }
    }

    if(isTail == 0)
    {
        printf(" ");
    }
}	
		}
			printf("#\n");
	}
	
	for(i=0;i<width+2;i++)
	{
		printf("#");
	}
	printf("\nScore : %d", score);
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
                direction = 'L';
                break;

            case 'd':
                direction = 'R';
                break;

            case 'w':
                direction = 'U';
                break;

            case 's':
                direction = 'D';
                break;
        }
    }
}

void logic()
{
    int prevX, prevY;
    int tempX, tempY;
    int i;
    
    prevX = snakeX;
    prevY = snakeY;

    if(direction == 'L')
        snakeX--;

    else if(direction == 'R')
        snakeX++;

    else if(direction == 'U')
        snakeY--;

    else if(direction == 'D')
        snakeY++;
        
        
	for(i = tailLength - 1; i > 0; i--)
	{
    	tailX[i] = tailX[i - 1];
    	tailY[i] = tailY[i - 1];
	}

		tailX[0] = prevX;
		tailY[0] = prevY;

    if(snakeX < 0 || snakeX >= width || snakeY < 0 || snakeY >= height)
    {
        gameOver = 1;
    }
    
    if(snakeX == foodX && snakeY == foodY)
	{
  		score++;
    	tailLength++;          

    	foodX = rand() % width;
    	foodY = rand() % height;

	}
}

int main()
{
    setup();

    while(gameOver == 0)
    {
        draw();
        input();
        logic();
        Sleep(150);
    }

    printf("\nGame Over!\n");

    return 0;
}


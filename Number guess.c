#include <stdio.h>
#include <stdlib.h>//as used rand()
#include <time.h>//as need to change starting time
int main()
{
    srand(time(NULL));
    printf("--Welcome to the number guessing game--\n");
    printf("level 'EASY' contains numbers(1-50) (7 chances)\n");
    printf("'MEDIUM' contains (1-100),(5 chances)\n");
    printf("'HARD' contains (1-150),(3 chances)\n");
    char level;
    printf("Enter E for easy,M for medium ,H for hard level and X for exit \n");
    scanf("%c", &level);
    int number, max, attempts, guess;
    attempts = 0;
    if (level == 'E')
    {
        max = 50;
        number = (rand() % max) + 1;
        printf("I have chosen a number from(1-50),\n You have 7 chances to guess the number.\n");
        printf("Let's get started!\n");

        for (int i = 0; i < 7; i++)
        {
            printf("Enter your guessed number(or -1 to quit):\n");
            scanf("%d", &guess);
            if (guess == -1)
            {
                printf("Exiting the game,See you again!\n");
                break;
            }
            else if (number == guess)
            {
                printf("You won!\n");
                break;
            }
            else if (guess < number && guess >0)
            {
                printf("Too low ! \nTry again\n");
            }
            else if (guess > number && guess <50)
            {
                printf("Too High! \nTry again\n");
            }
            else{printf("Number not in range\n");}
            attempts++;
        }
        if (attempts == 7)
        {
            printf("You lost! the number was %d\n", number);
        }
    }
    else if (level == 'M')
    {
        max = 100;
        number = (rand() % max) + 1;
        printf("I have chosen a number from(1-100),\n You have 5 chances to guess the number.\n");
        printf("Let's get started!\n");

        for (int i = 0; i < 5; i++)
        {
            printf("Enter your guessed number (or -1 to quit):\n");
            scanf("%d", &guess);
            if (guess == -1)
            {
                printf("Exiting the game,See you again!");
                break;
            }
            else if (number == guess)
            {
                printf("You won!\n");
                break;
            }
            else if (guess < number && guess >0)
            {
                printf("Too low ! \nTry again\n");
            }
            else if (guess > number && guess <100)
            {
                printf("Too High! \nTry again\n");
            }
            else{printf("Number not in range\n");}
            attempts++;
        }
        if (attempts == 5)
        {
            printf("You lost! the number was %d\n", number);
        }
    }
    else if (level == 'H')
    {
        max = 150;
        number = (rand() % max) + 1;
        printf("I have chosen a number from (1-150),\n You have 3 chances to guess the number.\n");
        printf("Let's get started\n");
        for (int i = 0; i < 3; i++)
        {
            printf("Enter your guessed number(or-1 to quit):\n");
            scanf("%d", &guess);
            if (guess == -1)
            {
                printf("Exiting the game,See you again!");
                break;
            }
            else if (number == guess)
            {
                printf("You won!\n");
                break;
            }
            else if (guess < number && guess > 0)
            {
                printf("Too low ! \nTry again\n");
            }
            else if (guess > number && guess < 150)
            {
                printf("Too High! \nTry again\n");
            }
            else{printf("Number not in range\n");}
            attempts++;
            if (attempts == 3)
            {
                printf("You Loss! the number was %d\n", number);
            }
        }
    }
    return 0;
}
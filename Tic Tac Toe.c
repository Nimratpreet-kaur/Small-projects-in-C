#include <stdio.h>
#include <windows.h> //to refresh our display or to clear the screen.

// board
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};
// drawing the board
void drawBoard();
int checkWin(); // for checking if user wins looses or draws//1 for win,2 for draw and 0 for lose
int main()
{
    int row, column, move, gameStatus;
    char sign;
    
    int player = 1;
    while (1)
    {
        drawBoard();
        if (player % 2 == 1)
        {
            player = 1;
            sign = 'X';
        }
        else if (player % 2 == 0)
        {
            player = 2;
            sign = 'O';
        };
        printf("player %d (%c) move :", player,sign);
        scanf("%d", &move);

        // defining rows and columns;{keep in mind}
        row = (move - 1) / 3;
        column = (move - 1) % 3;
        // checking validity of move
        if (move < 0 || move > 9)
        {
            printf("Invalid move!\n");
        }
        else if (board[row][column] != 'X' && board[row][column] != 'O')
        {
            board[row][column] = sign;
        }
        
        else
        {
            printf("This cell is already filled\n");
            player--;
        }

        gameStatus = checkWin();
        if (gameStatus == 1)
        {
            drawBoard();
            printf("player %d wins", player);
            break;
        }
        else if (gameStatus == 2)
        {
            drawBoard();
            printf("It's a draw.");
            break;
        }
        player ++;
    }

    return 0;
}

void drawBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c  |  %c  | %c  \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
        {
            printf("----|-----|----\n");
        }
    }
}

int checkWin()
{
    // check for win
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return 1;
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }
    // check for draw
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'O' && board[i][j] != 'X')
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        return 2;
    }
    return 0;
}
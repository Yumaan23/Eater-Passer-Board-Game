#include <stdlib.h>
#include <time.h>
int size;
int **board;

void initializeBoard() {
    printf("Enter board size between 3 to 15: ");
    scanf("%d", &size);

    // Limit the board size between 3 and 15
    while (size < 3 || size > 15) {
        printf("Invalid size. ReEnter board size: ");
        scanf("%d", &size);
    }

    board = (int**)malloc(size * sizeof(int*)); // Allocate memory for the board
    for (int i = 0; i < size; i++) {
        board[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++)  // Initialize the board to 0
        {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}


void printBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("|%2d ", board[i][j]);
        }

        printf("\n");

    }
}

void getMove(int *x, int *y) {
    printf("Enter move (x y): ");
    scanf("%d %d", x, y);
    // Decrement the coordinates by 1 to map them to the array
    (*x)--;
    (*y)--;
}

void randomMove(int *x, int *y) {
    do {
        *x = rand() % size;
        *y = rand() % size;
    } while (board[*x][*y] != 0);
}
void makeMove(int x, int y, int player) {
    board[x][y] = player;
}

int main() {
    srand(time(NULL));
    initializeBoard();

    int option;
printf("Enter 1 for human vs random player, 2 for human vs human: ");
scanf("%d", &option);

int moves = 0;
while (moves < size * size) {
    int x, y;
    int player = 1;

    if (option == 1) {
        getMove(&x, &y);
    } else if (option == 2) {
        printf("Player 1, enter your move (x y): ");
        scanf("%d %d", &x, &y);
        --x;
        --y;
    }

    while (x < 0 || y < 0 || x >= size || y >= size || board[x][y] != 0) {
        printf("Invalid move. Try again.\n");
        if (option == 1) {
            getMove(&x, &y);
        } else if (option == 2) {
            printf("Player 1, enter your move (x y): ");
            scanf("%d %d", &x, &y);
            --x;
        --y;
        }
    }
    makeMove(x, y, player);
    moves++;

    if (option == 1) {
        randomMove(&x, &y);
    } else if (option == 2) {
        printf("Player 2, enter your move (x y): ");
        scanf("%d %d", &x, &y);
        --x;
        --y;
    }

    while (x < 0 || y < 0 || x >= size || y >= size || board[x][y] != 0) {
        printf("Invalid move. Try again.\n");
        if (option == 1) {
            randomMove(&x, &y);
        } else if (option == 2) {
            printf("Player 2, enter your move (x y): ");
            scanf("%d %d", &x, &y);
            --x;
        --y;
        }
    }
    makeMove(x, y, -player);
    moves++;
    printBoard();
}

return 0;
}

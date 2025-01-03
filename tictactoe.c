#include <stdio.h>

// Global 3x3 board
char board[3][3];

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\nTic-Tac-Toe Board:\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;  // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;  // Column win
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;  // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;  // Diagonal win

    return 0;  // No winner
}

// Function to check if the board is full (no empty spaces left)
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Board is not full
            }
        }
    }
    return 1;  // Board is full
}

// Function to make a move
int makeMove(int player) {
    int row, col;
    char playerSymbol = (player == 1) ? 'X' : 'O';

    printf("Player %c, enter your move (row [0-2] and column [0-2]): ", playerSymbol);
    scanf("%d %d", &row, &col);

    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move, try again!\n");
        return 0;  // Invalid move
    }

    board[row][col] = playerSymbol;
    return 1;  // Valid move
}

// Function to switch the player
void switchPlayer(int *currentPlayer) {
    *currentPlayer = (*currentPlayer == 1) ? 2 : 1;
}

int main() {
    int currentPlayer = 1;  // Start with player 1 (X)
    int moveResult;
    int winner = 0;

    // Initialize and display the board
    initializeBoard();
    displayBoard();

    while (1) {
        moveResult = makeMove(currentPlayer);
        if (!moveResult) continue;  // If the move is invalid, ask again

        displayBoard();  // Show the updated board

        // Check if there's a winner
        winner = checkWinner();
        if (winner) {
            printf("Player %c wins!\n", (currentPlayer == 1) ? 'X' : 'O');
            break;
        }

        // Check for draw (board full and no winner)
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }

        // Switch player turn
        switchPlayer(&currentPlayer);
    }

    return 0;
}

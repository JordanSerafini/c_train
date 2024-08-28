#include <stdio.h>

#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[3][3]) {
    printf("  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  ---|---|---\n");
    }
}

int isWinner(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(char board[3][3], int row, int col, char player) {
    if (board[row][col] == EMPTY) {
        board[row][col] = player;
    }
}

int isValidMove(char board[3][3], int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return board[row][col] == EMPTY;
    }
    return 0;
}

void switchPlayer(char* currentPlayer) {
    *currentPlayer = (*currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

int main() {
    char board[3][3];
    char currentPlayer = PLAYER_X;
    int row, col;

    initializeBoard(board);

    while (1) {
        printBoard(board);
        printf("Joueur %c, entrez votre mouvement (ligne colonne): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isValidMove(board, row, col)) {
            makeMove(board, row, col, currentPlayer);
            if (isWinner(board, currentPlayer)) {
                printBoard(board);
                printf("Le joueur %c a gagné!\n", currentPlayer);
                break;
            }
            if (isDraw(board)) {
                printBoard(board);
                printf("C'est un match nul!\n");
                break;
            }
            switchPlayer(&currentPlayer);
        } else {
            printf("Mouvement invalide, essayez encore.\n");
        }
    }

    return 0;
}

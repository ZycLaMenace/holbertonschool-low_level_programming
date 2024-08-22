#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 8

typedef struct {
    int row, col;
} Position;

typedef struct {
    Position from, to;
} Move;

char board[SIZE][SIZE];
bool whiteKingMoved = false, blackKingMoved = false;
bool whiteLeftRookMoved = false, whiteRightRookMoved = false;
bool blackLeftRookMoved = false, blackRightRookMoved = false;
Position enPassantTarget = {-1, -1};

void initializeBoard() {
    char initialBoard[SIZE][SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    memcpy(board, initialBoard, sizeof(board));
}

void printBoard() {
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf(" %d\n", 8 - i);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    a   b   c   d   e   f   g   h\n");
}

bool isInBoard(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

bool isSameColor(char piece1, char piece2) {
    return (isupper(piece1) && isupper(piece2)) || (islower(piece1) && islower(piece2));
}

bool isValidPawnMove(Position from, Position to, char player) {
    int direction = (player == 'W') ? -1 : 1;
    int rowDiff = to.row - from.row;
    int colDiff = abs(to.col - from.col);

    // Move forward
    if (colDiff == 0 && rowDiff == direction && board[to.row][to.col] == ' ') {
        return true;
    }
    // Initial two-square move
    if (colDiff == 0 && rowDiff == 2 * direction && board[to.row][to.col] == ' ' &&
        board[from.row + direction][from.col] == ' ' &&
        ((player == 'W' && from.row == 6) || (player == 'B' && from.row == 1))) {
        return true;
    }
    // Capture
    if (colDiff == 1 && rowDiff == direction && 
        ((board[to.row][to.col] != ' ' && !isSameColor(board[from.row][from.col], board[to.row][to.col])) ||
         (to.row == enPassantTarget.row && to.col == enPassantTarget.col))) {
        return true;
    }
    return false;
}

bool isValidRookMove(Position from, Position to) {
    if (from.row != to.row && from.col != to.col) return false;
    int rowDir = (to.row > from.row) ? 1 : (to.row < from.row) ? -1 : 0;
    int colDir = (to.col > from.col) ? 1 : (to.col < from.col) ? -1 : 0;
    int row = from.row + rowDir, col = from.col + colDir;
    while (row != to.row || col != to.col) {
        if (board[row][col] != ' ') return false;
        row += rowDir;
        col += colDir;
    }
    return true;
}

bool isValidKnightMove(Position from, Position to) {
    int rowDiff = abs(to.row - from.row);
    int colDiff = abs(to.col - from.col);
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

bool isValidBishopMove(Position from, Position to) {
    if (abs(to.row - from.row) != abs(to.col - from.col)) return false;
    int rowDir = (to.row > from.row) ? 1 : -1;
    int colDir = (to.col > from.col) ? 1 : -1;
    int row = from.row + rowDir, col = from.col + colDir;
    while (row != to.row && col != to.col) {
        if (board[row][col] != ' ') return false;
        row += rowDir;
        col += colDir;
    }
    return true;
}

bool isValidQueenMove(Position from, Position to) {
    return isValidRookMove(from, to) || isValidBishopMove(from, to);
}

bool isValidKingMove(Position from, Position to) {
    int rowDiff = abs(to.row - from.row);
    int colDiff = abs(to.col - from.col);
    return (rowDiff <= 1 && colDiff <= 1) || 
           (rowDiff == 0 && colDiff == 2 && from.row == (isupper(board[from.row][from.col]) ? 7 : 0));
}

bool isUnderAttack(Position pos, char attacker) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != ' ' && isSameColor(board[i][j], attacker)) {
                Position from = {i, j};
                if (isValidMove((Move){from, pos}, attacker == 'W' ? 'B' : 'W')) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isValidMove(Move move, char player) {
    char piece = board[move.from.row][move.from.col];
    if (player == 'W' && !isupper(piece)) return false;
    if (player == 'B' && !islower(piece)) return false;
    if (move.from.row == move.to.row && move.from.col == move.to.col) return false;
    if (board[move.to.row][move.to.col] != ' ' && isSameColor(piece, board[move.to.row][move.to.col])) return false;

    bool valid = false;
    switch (tolower(piece)) {
        case 'p': valid = isValidPawnMove(move.from, move.to, player); break;
        case 'r': valid = isValidRookMove(move.from, move.to); break;
        case 'n': valid = isValidKnightMove(move.from, move.to); break;
        case 'b': valid = isValidBishopMove(move.from, move.to); break;
        case 'q': valid = isValidQueenMove(move.from, move.to); break;
        case 'k': valid = isValidKingMove(move.from, move.to); break;
    }

    if (valid) {
        // Check if the move puts the player's own king in check
        char tempPiece = board[move.to.row][move.to.col];
        board[move.to.row][move.to.col] = board[move.from.row][move.from.col];
        board[move.from.row][move.from.col] = ' ';

        Position kingPos;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == (player == 'W' ? 'K' : 'k')) {
                    kingPos = (Position){i, j};
                    break;
                }
            }
        }

        if (isUnderAttack(kingPos, player == 'W' ? 'B' : 'W')) {
            valid = false;
        }

        // Undo the move
        board[move.from.row][move.from.col] = board[move.to.row][move.to.col];
        board[move.to.row][move.to.col] = tempPiece;
    }

    return valid;
}

void makeMove(Move move) {
    char piece = board[move.from.row][move.from.col];
    
    // Handle en passant
    if (tolower(piece) == 'p' && move.to.col != move.from.col && board[move.to.row][move.to.col] == ' ') {
        board[move.from.row][move.to.col] = ' '; // Capture the en passant pawn
    }

    // Update en passant target
    enPassantTarget = (Position){-1, -1};
    if (tolower(piece) == 'p' && abs(move.to.row - move.from.row) == 2) {
        enPassantTarget = (Position){(move.from.row + move.to.row) / 2, move.from.col};
    }

    // Handle castling
    if (tolower(piece) == 'k' && abs(move.to.col - move.from.col) == 2) {
        int rookFromCol = (move.to.col > move.from.col) ? 7 : 0;
        int rookToCol = (move.to.col > move.from.col) ? 5 : 3;
        board[move.to.row][rookToCol] = board[move.to.row][rookFromCol];
        board[move.to.row][rookFromCol] = ' ';
    }

    // Update castling flags
    if (piece == 'K') whiteKingMoved = true;
    if (piece == 'k') blackKingMoved = true;
    if (piece == 'R') {
        if (move.from.col == 0) whiteLeftRookMoved = true;
        if (move.from.col == 7) whiteRightRookMoved = true;
    }
    if (piece == 'r') {
        if (move.from.col == 0) blackLeftRookMoved = true;
        if (move.from.col == 7) blackRightRookMoved = true;
    }

    // Make the move
    board[move.to.row][move.to.col] = board[move.from.row][move.from.col];
    board[move.from.row][move.from.col] = ' ';

    // Handle pawn promotion
    if (tolower(piece) == 'p' && (move.to.row == 0 || move.to.row == 7)) {
        board[move.to.row][move.to.col] = isupper(piece) ? 'Q' : 'q';
    }
}

Move getPlayerMove() {
    Move move;
    char input[5];
    printf("Entrez votre coup (ex: e2e4) : ");
    scanf("%s", input);
    move.from.col = input[0] - 'a';
    move.from.row = '8' - input[1];
    move.to.col = input[2] - 'a';
    move.to.row = '8' - input[3];
    return move;
}

Move getComputerMove(char player) {
    Move bestMove;
    int bestScore = -1000;

    for (int fromRow = 0; fromRow < SIZE; fromRow++) {
        for (int fromCol = 0; fromCol < SIZE; fromCol++) {
            if (board[fromRow][fromCol] != ' ' && isSameColor(board[fromRow][fromCol], player == 'W' ? 'W' : 'B')) {
                for (int toRow = 0; toRow < SIZE; toRow++) {
                    for (int toCol = 0; toCol < SIZE; toCol++) {
                        Move move = {{fromRow, fromCol}, {toRow, toCol}};
                        if (isValidMove(move, player)) {
                            int score = rand() % 100; // Simple random scoring for now
                            if (score > bestScore) {
                                bestScore = score;
                                bestMove = move;
                            }
                        }
                    }
                }
            }
        }
    }
    return bestMove;
}

bool isCheckmate(char player) {
    // First, check if the king is in check
    Position kingPos;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == (player == 'W' ? 'K' : 'k')) {
                kingPos = (Position){i, j};
                break;
            }
        }
    }

    if (!isUnderAttack(kingPos, player == 'W' ? 'B' : 'W')) {
        return false; // The king is not in check
    }

    // Check if any move can get the king out of check
    for (int fromRow = 0; fromRow < SIZE; fromRow++) {
        for (int fromCol = 0; fromCol < SIZE; fromCol++) {
            if (board[fromRow][fromCol] != ' ' && isSameColor(board[fromRow][fromCol], player == 'W' ? 'W' : 'B')) {
                for (int toRow = 0; toRow < SIZE; toRow++) {
                    for (int toCol = 0; toCol < SIZE; toCol++) {
                        Move move = {{fromRow, fromCol}, {toRow, toCol}};
                        if (isValidMove(move, player)) {
                            // Try the move
                            char tempPiece = board[toRow][toCol];
                            board[toRow][toCol] = board[fromRow][fromCol];
                            board[fromRow][fromCol] = ' ';

                            // Check if the king is still in check
                            bool stillInCheck = isUnderAttack(kingPos, player == 'W' ? 'B' : 'W');

    // Undo the move
    board[fromRow][fromCol] = board[toRow][toCol];
    board[toRow][toCol] = tempPiece;

    if (!stillInCheck) {
        return false; // Found a move that gets the king out of check
    }
}

return true; // No move can get the king out of check
}

bool isStalemate(char player) {
    // Check if the player has any legal moves
    for (int fromRow = 0; fromRow < SIZE; fromRow++) {
        for (int fromCol = 0; fromCol < SIZE; fromCol++) {
            if (board[fromRow][fromCol] != ' ' && isSameColor(board[fromRow][fromCol], player == 'W' ? 'W' : 'B')) {
                for (int toRow = 0; toRow < SIZE; toRow++) {
                    for (int toCol = 0; toCol < SIZE; toCol++) {
                        Move move = {{fromRow, fromCol}, {toRow, toCol}};
                        if (isValidMove(move, player)) {
                            return false; // Found a legal move
                        }
                    }
                }
            }
        }
    }
    
    // No legal moves, but the king is not in check
    Position kingPos;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == (player == 'W' ? 'K' : 'k')) {
                kingPos = (Position){i, j};
                break;
            }
        }
    }
    return !isUnderAttack(kingPos, player == 'W' ? 'B' : 'W');
}

int main() {
    initializeBoard();
    char currentPlayer = 'W';
    bool gameOver = false;

    while (!gameOver) {
        printBoard();
        
        if (isCheckmate(currentPlayer)) {
            printf("%s est en échec et mat! %s gagne!\n", 
                   currentPlayer == 'W' ? "Blanc" : "Noir", 
                   currentPlayer == 'W' ? "Noir" : "Blanc");
            gameOver = true;
            break;
        }
        
        if (isStalemate(currentPlayer)) {
            printf("Pat! La partie est nulle.\n");
            gameOver = true;
            break;
        }

        printf("Tour du joueur %s\n", currentPlayer == 'W' ? "Blanc" : "Noir");
        
        Move move;
        if (currentPlayer == 'W') {
            do {
                move = getPlayerMove();
                if (!isValidMove(move, currentPlayer)) {
                    printf("Mouvement invalide. Réessayez.\n");
                }
            } while (!isValidMove(move, currentPlayer));
        } else {
            move = getComputerMove(currentPlayer);
            printf("L'ordinateur joue : %c%c%c%c\n", 
                   move.from.col + 'a', '8' - move.from.row, 
                   move.to.col + 'a', '8' - move.to.row);
        }

        makeMove(move);
        currentPlayer = (currentPlayer == 'W') ? 'B' : 'W';
    }

    return 0;
}

Version 3 of 3
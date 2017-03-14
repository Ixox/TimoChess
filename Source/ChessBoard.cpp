/*
  ==============================================================================

    ChessBoard.cpp
    Created: 28 Feb 2017 10:27:05pm
    Author:  xavier

  ==============================================================================
*/

#include "BinaryData.h"
#include "ChessBoard.h"


ChessBoard::ChessBoard() {
    for (int l=0; l<8; l++) {
        for (int r= 0; r<8; r++) {
//            board[l][r] = new Case();
        }
    }
}

void ChessBoard::init() {
    Piece row[8] = { ROCK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROCK };
    for (int l = 0; l<8 ; l++) {
        board[l][0].color = WHITE;
        board[l][0].piece = row[l];
        
        board[l][1].color = WHITE;
        board[l][1].piece = PAWN;
        
        board[l][6].color = BLACK;
        board[l][6].piece = PAWN;

        board[l][7].color = BLACK;
        board[l][7].piece = row[l];

        for (int n=2 ; n< 6; n++) {
            board[l][n].color = NOCOLOR;
            board[l][n].piece = NOPIECE;            
        }
    }
}

void ChessBoard::initRacingKings() {
    Piece row1[4] = { KING, ROCK, BISHOP, KNIGHT };
    Piece row2[4] = { QUEEN, ROCK, BISHOP, KNIGHT }; 
    for (int l = 0; l<4 ; l++) {
        board[l][0].color = BLACK;
        board[l][0].piece = row2[l];
        
        board[7-l][0].color = WHITE;
        board[7-l][0].piece = row2[l];

        board[l][1].color = BLACK;
        board[l][1].piece = row1[l];
        
        board[7-l][1].color = WHITE;
        board[7-l][1].piece = row1[l];
        

        for (int n=2 ; n< 8; n++) {
            board[l][n].color = NOCOLOR;
            board[l][n].piece = NOPIECE;            
            board[7-l][n].color = NOCOLOR;
            board[7-l][n].piece = NOPIECE;            
        }
    }
}

void ChessBoard::initWithFen(String fenFull) {
    // String fenFull = "5r2/q5P1/8/8/8/3R4/1R6/6Q1 w - - 0 1"; 
    StringArray tokens;
    tokens.addTokens (fenFull, " ", "\"");

    String fen = tokens[0];
    StringArray rows;
    rows.addTokens (fen, "/", "\"");
    // Clean board
    for (int l = 0; l <8 ; l++) {
        for (int n=0 ; n < 8; n++) {
            board[l][n].color = NOCOLOR;
            board[l][n].piece = NOPIECE;            
        }
    }
    
    for (int n=0; n< rows.size(); n++) {
        String row = rows[n];
        int l = 0;
        for (int c = 0; c < row.length(); c++ ) {
            switch (row[c]) {
                case '1' ... '8' :
                    l +=  (row[c] - '0');
                    break;
                case 'k':
                    board[l][7-n].color = BLACK;
                    board[l][7-n].piece = KING;
                    l++;
                    break;
                case 'q':
                    board[l][7-n].color = BLACK;
                    board[l][7-n].piece = QUEEN;
                    l++;
                    break;
                case 'r':
                    board[l][7-n].color = BLACK;
                    board[l][7-n].piece = ROCK;
                    l++;
                    break;
                case 'b':
                    board[l][7-n].color = BLACK;
                    board[l][7-n].piece = BISHOP;
                    l++;
                    break;
                case 'n':
                    board[l][7-n].color = BLACK;
                    board[l][7-n].piece = KNIGHT;
                    l++;
                    break;
                case 'p':
                    board[l][7-n].color = BLACK;
                    board[l][7-n].piece = PAWN;
                    l++;
                    break;
                case 'K':
                    board[l][7-n].color = WHITE;
                    board[l][7-n].piece = KING;
                    l++;
                    break;
                case 'Q':
                    board[l][7-n].color = WHITE;
                    board[l][7-n].piece = QUEEN;
                    l++;
                    break;
                case 'R':
                    board[l][7-n].color = WHITE;
                    board[l][7-n].piece =ROCK;
                    l++;
                    break;
                case 'B':
                    board[l][7-n].color = WHITE;
                    board[l][7-n].piece = BISHOP;
                    l++;
                    break;
                case 'N':
                    board[l][7-n].color = WHITE;
                    board[l][7-n].piece = KNIGHT;
                    l++;
                    break;
                case 'P':
                    board[l][7-n].color = WHITE;
                    board[l][7-n].piece = PAWN;
                    l++;
                    break;                    
            }
        }
    }
}

bool ChessBoard::move(String move) {    
    int rowSource = move.toRawUTF8()[0] - 'a';
    if (rowSource < 0 || rowSource >7) {
        return false;
    }
    int colSource = move.toRawUTF8()[1] - '1';
    if (colSource < 0 || colSource >7) {
        return false;
    }
    
    int rowDest = move.toRawUTF8()[2] - 'a';
    if (rowDest < 0 || rowDest >7) {
        return false;
    }
    int colDest = move.toRawUTF8()[3] - '1';
    if (colDest < 0 || colDest >7) {
        return false;
    }
//    printf("* * * * * * * ");
//    printf(" * * * * * * Move from %i, %i TO %i, %i\n", rowSource, colSource, rowDest, colDest);
    board[rowDest][colDest].color = board[rowSource][colSource].color;
    board[rowDest][colDest].piece = board[rowSource][colSource].piece ;
    board[rowSource][colSource].color = NOCOLOR;
    board[rowSource][colSource].piece = NOPIECE;
    return true;
}

Piece ChessBoard::getPiece(String pos) {
    int rowSource = pos[0] - 'a';
    if (rowSource < 0 || rowSource >7) {
        return NOPIECE;
    }
    int colSource = pos[1] - '1';
    if (colSource < 0 || colSource >7) {
        return NOPIECE;
    }
    return board[rowSource][colSource].piece;
    
}

Color ChessBoard::getColor(String pos) {
    int rowSource = pos[0] - 'a';
    if (rowSource < 0 || rowSource >7) {
        return NOCOLOR;
    }
    int colSource = pos[1] - '1';
    if (colSource < 0 || colSource >7) {
        return NOCOLOR;
    }
    return board[rowSource][colSource].color;
    
}


Image ChessBoard::getPieceImage(String move) {
    int l = move[0] - 'a';
    int n = move[1] - '1';
    return getPieceImage(l, n);
}

Image ChessBoard::getPieceImage(int l, int n) {
    Image movingPiece = Image();

    if (l < 0 || l >7 || n < 0 || n >7) {
        return movingPiece;
    }

    switch(board[l][n].color) {
    case WHITE:
        switch (board[l][n].piece) {
            case PAWN:
                    movingPiece = ImageCache::getFromMemory(BinaryData::wPawn_png, BinaryData::wPawn_pngSize);
                    break;
            case KNIGHT:
                    movingPiece = ImageCache::getFromMemory(BinaryData::wKnight_png, BinaryData::wKnight_pngSize);
                    break;
            case BISHOP:
                    movingPiece = ImageCache::getFromMemory(BinaryData::wBishop_png, BinaryData::wBishop_pngSize);
                    break;
            case ROCK:
                    movingPiece = ImageCache::getFromMemory(BinaryData::wRock_png, BinaryData::wRock_pngSize);
                    break;
            case QUEEN:
                    movingPiece = ImageCache::getFromMemory(BinaryData::wQueen_png, BinaryData::wQueen_pngSize);
                    break;
            case KING:
                    movingPiece = ImageCache::getFromMemory(BinaryData::wking_png, BinaryData::wking_pngSize);
                    break;
        }
        break;
    case BLACK:
        switch (board[l][n].piece) {
            case PAWN:
                    movingPiece = ImageCache::getFromMemory(BinaryData::bPawn_png, BinaryData::bPawn_pngSize);
                    break;
            case KNIGHT:
                    movingPiece = ImageCache::getFromMemory(BinaryData::bKnight_png, BinaryData::bKnight_pngSize);
                    break;
            case BISHOP:
                    movingPiece = ImageCache::getFromMemory(BinaryData::bBishop_png, BinaryData::bBishop_pngSize);
                    break;
            case ROCK:
                    movingPiece = ImageCache::getFromMemory(BinaryData::bRock_png, BinaryData::bRock_pngSize);
                    break;
            case QUEEN:
                    movingPiece = ImageCache::getFromMemory(BinaryData::bQueen_png, BinaryData::bQueen_pngSize);
                    break;
            case KING:
                    movingPiece = ImageCache::getFromMemory(BinaryData::bKing_png, BinaryData::bKing_pngSize);
                    break;
        }
        break;
    }
    return movingPiece;

}


void ChessBoard::display() {       
    char pieces[] = { '.', 'P', 'R', 'B', 'N', 'Q', 'K', 'p', 'r', 'b', 'n', 'q', 'k' };

    printf("  abcdefgh\n");
    printf("\n");
     for (int n= 7; n>=0; n--) {        
        printf("%i ", n+1);
        for (int l=0; l<8; l++) {
            printf("%c", pieces[(int)board[l][n].piece + (board[l][n].color == BLACK ? 6 : 0)]);
        }
        printf("\n");
    }
    printf("\n");
    printf("  abcdefgh\n");
}
/*
  ==============================================================================

    ChessBoard.cpp
    Created: 28 Feb 2017 10:27:05pm
    Author:  xavier

  ==============================================================================
*/

#include "BinaryData.h"
#include "ChessBoard.h"


// #define CB_DEBUG 1

ChessBoard::ChessBoard() {
    board = new Case*[8]; 
    previousBoard = new Case*[8];
    for(int i = 0; i < 8; ++i) {
        board[i] = new Case[8];
        previousBoard[i] = new Case[8];
    }
}


void ChessBoard::copyBoard(Case** source, Case** destination) {
    for (int l = 0; l<8 ; l++) {
        for (int n=0 ; n< 8; n++) {
            destination[l][n] = source[l][n];
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
    copyBoard(board, previousBoard);

    int letterSrc = move.toRawUTF8()[0] - 'a';
    if (letterSrc < 0 || letterSrc >7) {
        return false;
    }
    int numberSrc = move.toRawUTF8()[1] - '1';
    if (numberSrc < 0 || numberSrc >7) {
        return false;
    }
    
    int letterDest =  move.toRawUTF8()[2] - 'a';
    if (letterDest < 0 || letterDest >7) {
        return false;
    }
    int numberDest = move.toRawUTF8()[3] - '1';
    if (numberDest < 0 || numberDest >7) {
        return false;
    }


#ifdef CB_DEBUG
    if ( board[letterSrc][numberSrc].color == WHITE ) {
        printf("En Passant ============ WHITE\n");
        printf("numberSrc  : %i  \n", numberSrc);
        printf("numberDest : %i  \n", numberDest);
        printf("board[letterSrc][numberSrc].color : %i  \n", (int)board[letterSrc][numberSrc].color);
        printf("board[letterSrc][numberSrc].piece : %i  \n", (int)board[letterSrc][numberSrc].piece);
        printf("board[letterDest][5].color : %i  \n", (int)board[letterDest][5].color);
        printf("board[letterDest][5].piece : %i  \n", (int)board[letterDest][5].piece);
    }
#endif

    if ( board[letterSrc][numberSrc].color == WHITE 
        && board[letterSrc][numberSrc].piece == PAWN
        && (numberDest == 5 && numberSrc == 4)
        && board[letterDest][4].color == BLACK 
        && board[letterDest][4].piece == PAWN) 
    {
        board[letterDest][4].color = NOCOLOR;
        board[letterDest][4].piece = NOPIECE;            
    }

#ifdef CB_DEBUG
    if ( board[letterSrc][numberSrc].color == BLACK ) {
        printf("En Passant ========== BLACK\n");
        printf("numberSrc  : %i  \n", numberSrc);
        printf("numberDest : %i  \n", numberDest);
        printf("board[letterSrc][numberSrc].color : %i  \n", (int)board[letterSrc][numberSrc].color);
        printf("board[letterSrc][numberSrc].piece : %i  \n", (int)board[letterSrc][numberSrc].piece);
        printf("board[letterDest][4].color : %i  \n", (int)board[letterDest][4].color);
        printf("board[letterDest][4].piece : %i  \n", (int)board[letterDest][4].piece);
    }
#endif

    if ( board[letterSrc][numberSrc].color == BLACK 
        && board[letterSrc][numberSrc].piece == PAWN
        && (numberSrc == 3 && numberDest == 2)
        && board[letterDest][3].color == WHITE 
        && board[letterDest][3].piece == PAWN) 
    {
        board[letterDest][3].color = NOCOLOR;
        board[letterDest][3].piece = NOPIECE;            
    }




    board[letterDest][numberDest].color = board[letterSrc][numberSrc].color;
    board[letterDest][numberDest].piece = board[letterSrc][numberSrc].piece ;
    board[letterSrc][numberSrc].color = NOCOLOR;
    board[letterSrc][numberSrc].piece = NOPIECE;

    // Promotion
    if (move.length() == 5) {
        if (board[letterDest][numberDest].piece == PAWN) {
            if (numberDest == 0 || numberDest == 7) {
                switch (move.toRawUTF8()[4]) {
                    case 'q':
                        board[letterDest][numberDest].piece = QUEEN ;
                        break;
                    case 'r':
                        board[letterDest][numberDest].piece = ROCK ;
                        break;
                    case 'n':
                        board[letterDest][numberDest].piece = KNIGHT ;
                        break;
                    case 'b':
                        board[letterDest][numberDest].piece = BISHOP ;
                        break;
                }
            }
        }
    }


    // Casttle ?
#ifdef CB_DEBUG
     printf(">> ChessBoard : move : %s\n", move.toRawUTF8());
#endif
    if (board[letterDest][numberDest].piece == KING) {
        int d = letterDest - letterSrc;
        d = d < 0 ? -d : d;
#ifdef CB_DEBUG
        printf(">> ChessBoard : KING move distance : %i \n", d);
#endif
        if (d == 2) {
            // Yes Casttle !
#ifdef CB_DEBUG
            printf(">> ChessBoard : Castle detected\n");
#endif
            String error = numberDest != numberSrc ? "# CANNOT CASTLE AND CHANGING NUMBER #" : "";
            if (letterDest == 2) { // 2 is 'c'            
                // Let's move the rock
                error += board[0][numberSrc].piece != ROCK ? "# NO ROCK ON THE LEFT #" : "";
                board[3][numberSrc].color = board[0][numberSrc].color;
                board[3][numberSrc].piece = board[0][numberSrc].piece ;                                
                board[0][numberSrc].color = NOCOLOR;
                board[0][numberSrc].piece = NOPIECE;
                
            } else if (letterDest == 6) { // 6 is 'g'
                error += board[7][numberSrc].piece != ROCK ? "# NO ROCK ON THE RIGHT #" : "";
                board[5][numberSrc].color = board[7][numberSrc].color;
                board[5][numberSrc].piece = board[7][numberSrc].piece ;
                board[7][numberSrc].color = NOCOLOR;
                board[7][numberSrc].piece = NOPIECE;                
            } else {
                error += "# WRONG KING POSITION #";
            }
            if (error.length() > 0) {
                printf("####### CASTTLE ERROR : %s \n", error.toRawUTF8());
            }
        }
    }

    return true;
}

Piece ChessBoard::getPiece(String pos) {
    int letter = pos[0] - 'a';
    if (letter < 0 || letter >7) {
        return NOPIECE;
    }
    int number = pos[1] - '1';
    if (number < 0 || number >7) {
        return NOPIECE;
    }
    return board[letter][number].piece;
    
}

Color ChessBoard::getColor(String pos) {
    int letter = pos[0] - 'a';
    if (letter < 0 || letter >7) {
        return NOCOLOR;
    }
    int number = pos[1] - '1';
    if (number < 0 || number >7) {
        return NOCOLOR;
    }
    return board[letter][number].color;
    
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

void ChessBoard::promotePawnTo(String move, Piece promotion) {
    int letter = move[0] - 'a';
    int number = move[1] - '1';
    if ( letter >= 0 && letter <=7 && number >=0 && number <= 7) {
        if (board[letter][number].piece == PAWN) {
            board[letter][number].piece = promotion;
            return;
        }
    }
    printf("### ERROR : cannot promote pawn from move %s \n", move.toRawUTF8());
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

void ChessBoard::cancelLastMove() {
    copyBoard(previousBoard, board);
}

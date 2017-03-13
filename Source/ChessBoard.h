/*
  ==============================================================================

    ChessBoard.h
    Created: 28 Feb 2017 10:27:05pm
    Author:  xavier

  ==============================================================================
*/

#ifndef CHESSBOARD_H_INCLUDED
#define CHESSBOARD_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

enum Piece {
    NOPIECE = 0,
    PAWN,
    ROCK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING
};
 enum Color {
     NOCOLOR = 0,
     WHITE,
     BLACK
};


class Case {
    public:
        Case() {
            this-> color = NOCOLOR;
            this-> piece = NOPIECE;
        }
        Color color;
        Piece piece;
};

class ChessBoard {
    public:
        ChessBoard();
        void init();
        void initRacingKings();
        bool move(String move);
        Color getColor(String pos);
        Piece getPiece(String pos);
        void display();
        Image getPieceImage(String move);
        Image getPieceImage(int l, int n);
    private:
        Case board[8][8];    
    
};


#endif  // CHESSBOARD_H_INCLUDED

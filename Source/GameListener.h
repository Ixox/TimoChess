/*
  ==============================================================================

    GameListener.h
    Created: 27 Feb 2017 10:50:35pm
    Author:  xavier

  ==============================================================================
*/

#ifndef GAMELISTENER_H_INCLUDED
#define GAMELISTENER_H_INCLUDED

class ChessBoard;

class GameListener {
    public:
    virtual void setup() = 0;
    virtual void startGame() = 0;
    virtual void resumeGame() = 0;
    virtual void showBoard(ChessBoard* chessBoard) = 0;
};


#endif  // GAMELISTENER_H_INCLUDED

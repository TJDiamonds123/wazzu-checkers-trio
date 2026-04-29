# wazzu-checkers-trio
pivoting to checkers since 1984





Pieces.hpp 


#pragma once


class Piece {
public:
    virtual void getMoves() = 0; // polymorphism
};

class RegularPiece : public Piece {
    // normal movement
};

class KingPiece : public Piece {
    // can move backwards
};



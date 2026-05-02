#pragma once
#include "Board.hpp"
#include <iostream>
#include <string>

class Test
{
public:
    bool runAllTests();

private:
    bool passedFailed(bool condition, const std::string& testName);

    bool testInitialBoardSetup();
    bool testValidMove();
    bool testInvalidMove();
    bool testCaptureMove();
    bool testKingPromotion();
};
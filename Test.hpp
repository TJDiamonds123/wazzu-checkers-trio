#pragma once
#include "Board.hpp"
#include <iostream>
#include <string>

class Test
{
public:
    bool runAllTests();//runs all the test functions and returns if they passes or not

private:
    bool passedFailed(bool condition, const std::string& testName);//prints whether the test passes or failed
//individual test cases
    bool testInitialBoardSetup();
    bool testValidMove();
    bool testInvalidMove();
    bool testCaptureMove();
    bool testKingPromotion();
};

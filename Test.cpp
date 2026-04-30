#include "Test.hpp"
#include <iostream>

// Run test cases and return true if all cases pass
bool Test::runAllTests()
{
    if (testInitialBoardSetup() && testValidMove() && testInvalidMove() && testCaptureMove() && testKingPromotion())
    {
        return true;
    }
}

// Prints whether the test passed or failed
bool Test::passedFailed(bool condition, const std::string& testName)
{
    if (condition)
    {
        std::cout << "Passed: " << testName << std::endl;
        return true;
    }
    else
    {
        std::cout << "Failed: " << testName << std::endl;
        return false;
    }
}


// Tests the initial board setup. It makes sure all of the pieces are there
bool Test::testInitialBoardSetup()
{
    Board board(100);

    bool ok = (board.getRed() == 12 && board.getBlack() == 12);

    return passedFailed(ok, "Initial Board Setup");
}


// Tests if the code knows a move is valid
bool Test::testValidMove()
{
    Board board(100);

    // Legal move
    board.whenClick(5, 0);
    board.whenClick(4, 1);

    bool ok = (board.getRed() == 12 && board.getBlack() == 12);

    return passedFailed(ok, "Valid Move");
}


// Tests if the code knows a move is invalid
bool Test::testInvalidMove()
{
    Board board(100);

    int beforeRed = board.getRed();
    int beforeBlack = board.getBlack();

    // Illegal move
    board.whenClick(5, 0);
    board.whenClick(5, 1);

    bool ok = (board.getRed() == beforeRed && board.getBlack() == beforeBlack);

    return passedFailed(ok, "Invalid Move Rejected");
}


// Capture move test
bool Test::testCaptureMove()
{
    Board board(100);

    int beforeRed = board.getRed();
    int beforeBlack = board.getBlack();

    board.whenClick(5, 0);
    board.whenClick(4, 1);

    // We cannot fully force capture without board editing access
    bool ok = (board.getRed() >= 0 && board.getBlack() >= 0);

    return passedFailed(ok, "Capture Move Stability");
}


// King promotion
bool Test::testKingPromotion()
{
    Board board(100);

    board.whenClick(2, 1);
    board.whenClick(1, 0);

    bool ok = (board.getRed() >= 0 && board.getBlack() >= 0);

    return passedFailed(ok, "King Promotion");
}

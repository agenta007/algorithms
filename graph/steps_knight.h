//
// Created by neo on 3/25/26.
//

#ifndef ALGORITHMS_STEPS_KNIGHT_H
#define ALGORITHMS_STEPS_KNIGHT_H
#include <vector>
#include <queue>
#include <iostream>
#include "../helpers.h"
using namespace std;

vector<pair<int, int>> calcPossibleMoves(int chessBoardSz, pair<int, int> currentPos) {
    //knight can have 8 moves maximum
    //forward right, forward left, flank right, flank left, backward right, backward left, backward flank right, backward flank left
    int dx[] = { 1, -1, 2, -2, 1, -1, 2, -2};
    int dy[] = { 2, 2, 1, 1, -2, -2, -1, -1};
    vector<pair<int, int>> possibleMoves;
    for (int i = 0; i < 8; i++) {
        if (currentPos.first + dx[i] > 0 &&
            currentPos.first + dx[i] < chessBoardSz &&
            currentPos.second + dy[i] > 0 &&
            currentPos.second + dy[i] < chessBoardSz
            ) {
            possibleMoves.push_back({currentPos.first + dx[i], currentPos.second + dy[i]});
        }
    }
    return possibleMoves;
}

int calcStepsByKnightIntCoords(int chessBoardSz, pair<int, int> &startPos, pair<int, int> &targetPos) {
    int steps = 0;
    queue<pair<int, int>> moves;
    moves.push(targetPos);

    while (!moves.empty()) {
        vector<pair<int,int>> possibleMoves;
        int size = moves.size();  // snapshot current size
        ++steps;
        for (int i = 0; i < size; i++) {
            auto currentPos = moves.front();
            moves.pop();

            auto newMoves = calcPossibleMoves(chessBoardSz, currentPos);
            possibleMoves.insert(possibleMoves.end(), newMoves.begin(), newMoves.end());
        }
        for (auto possibleMove : possibleMoves) {
            //cout << "Checking move " << possibleMove.first << ", " << possibleMove.second << endl;
            if (possibleMove.first == startPos.first && possibleMove.second == startPos.second) {
                //cout << "Found move.\n";
                return steps;
            }
            //cout << "Pushing move " << possibleMove.first << ", " << possibleMove.second << endl;
            moves.push(possibleMove);
        }

    }
    return steps;
}

unsigned int calcStepsByKnight(unsigned int chessBoardSz, pair<unsigned int, unsigned int> startPos) {
    vector<pair<char, int>> chessBoard;
    char startFile = 'A';
    unsigned int startRank = 1;
    for (int i = 0; i < chessBoardSz; i++) {
        pair<char, int> nextPos = {startFile + i, startRank + i};
        chessBoard.push_back(nextPos);
    }
    //printVectorOfVectors(chessBoard);
    return 0;
}
void demoStepsByKnight() {
    //printCoordinateSystem(6);
    pair<int, int> startPos = {4, 5};
    pair<int, int> targetPos = {6, 1};
    //pair<int, int> targetPos = {6, 3};
    cout << calcStepsByKnightIntCoords(6, startPos, targetPos) << endl;
}
#endif //ALGORITHMS_STEPS_KNIGHT_H
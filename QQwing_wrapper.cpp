/*
 * QQwing_client.cpp
 *
 * Copyright 2014 Parin Porecha <parinporecha@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <iostream>

#include "qqwing.hpp"
#include "QQwing_wrapper.h"

using namespace qqwing;

const int* qqwing_generate_puzzle (int difficulty)
{
    bool havePuzzle = false;
    int iterationsCount = 0;
    const int *puzzle_array;
    SudokuBoard *board = new SudokuBoard();

    board->setRecordHistory(true);
    board->setLogHistory(false);
    board->setPrintStyle(SudokuBoard::ONE_LINE);

    while (iterationsCount < MAX_ITERATION_COUNT)
    {
        havePuzzle = board->generatePuzzleSymmetry (SudokuBoard::RANDOM);
        board->solve ();
        if (havePuzzle && (SudokuBoard::Difficulty) difficulty == board->getDifficulty())
            break;

        iterationsCount++;
    }

    puzzle_array = board->getPuzzle();
    return puzzle_array;
}

void qqwing_print_stats(int *initPuzzle){
    SudokuBoard *board = new SudokuBoard();
    board->setRecordHistory(true);
    board->setLogHistory(false);
    board->setPuzzle (initPuzzle);
    board->solve ();

    int givenCount = board->getGivenCount();
    int singleCount = board->getSingleCount();
    int hiddenSingleCount = board->getHiddenSingleCount();
    int nakedPairCount = board->getNakedPairCount();
    int hiddenPairCount = board->getHiddenPairCount();
    int pointingPairTripleCount = board->getPointingPairTripleCount();
    int boxReductionCount = board->getBoxLineReductionCount();
    int guessCount = board->getGuessCount();
    int backtrackCount = board->getBacktrackCount();
    string difficultyString = board->getDifficultyAsString();

    cout << "Number of Givens: " << givenCount  << endl;
    cout << "Number of Singles: " << singleCount << endl;
    cout << "Number of Hidden Singles: " << hiddenSingleCount  << endl;
    cout << "Number of Naked Pairs: " << nakedPairCount  << endl;
    cout << "Number of Hidden Pairs: " << hiddenPairCount  << endl;
    cout << "Number of Pointing Pairs/Triples: " << pointingPairTripleCount  << endl;
    cout << "Number of Box/Line Intersections: " << boxReductionCount  << endl;
    cout << "Number of Guesses: " << guessCount  << endl;
    cout << "Number of Backtracks: " << backtrackCount  << endl;
    cout << "Difficulty: " << difficultyString  << endl;
}


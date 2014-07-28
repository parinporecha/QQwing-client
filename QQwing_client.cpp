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
#include "QQwing_client.hpp"

void printSimplePuzzle ()
{
    SudokuBoard::PrintStyle printStyle = SudokuBoard::ONE_LINE;
    int numberToGenerate = 10;
    bool havePuzzle = false;
    SudokuBoard::Difficulty difficulty = SudokuBoard::SIMPLE;
    SudokuBoard::Symmetry symmetry = SudokuBoard::RANDOM;

    SudokuBoard* ss = new SudokuBoard();
    ss->setRecordHistory(difficulty!=SudokuBoard::UNKNOWN);
    ss->setLogHistory(false);
    ss->setPrintStyle(printStyle);

    while (numberToGenerate != 0)
    {
        havePuzzle = ss->generatePuzzleSymmetry (symmetry);

        ss->solve ();
        if (!havePuzzle || difficulty != ss->getDifficulty())
            continue;

        ss->printPuzzle ();
        numberToGenerate--;
    }

    std::cout << "\nPuzzles generation complete\n";
    delete ss;
}


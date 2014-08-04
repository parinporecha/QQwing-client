/*
 * QQwing_client.vala
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


public void main() {
    stdout.printf ("Testing qqwing, generating 4 puzzles of different difficulties ...\n\n");

    int number_to_generate = 4;

    // 1 corresponds to SIMPLE difficulty
    // 2 corresponds to EASY difficulty
    // 3 corresponds to INTERMEDIATE difficulty
    // 4 corresponds to EXPERT difficulty
    int difficulty = 1;

    for (var i = 0; i < number_to_generate; i++)
    {
        int[] puzzle = QQwing.generate_puzzle (difficulty++);

        stdout.printf ("\n");
        for (var j = 0; j < 81; j++)
            stdout.printf ("%d", puzzle[j]);
        stdout.printf ("\n");

        QQwing.print_stats (puzzle);
    }
}

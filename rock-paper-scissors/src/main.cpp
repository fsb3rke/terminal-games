#include <cctype>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <random_utils.hpp>
#include <iostream>


constexpr int KEY_ROCK = 'r';
constexpr int KEY_PAPER = 'p';
constexpr int KEY_SCISSORS = 's';

enum class Choice {
    ROCK,
    PAPER,
    SCISSORS,
    NONE
};

enum class Status {
    WIN,
    LOSE,
    DRAW
};

std::string choiceToString(Choice c);
Status determineWinner(Choice playerChoice, Choice computerChoice);

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    Choice playerChoice = Choice::NONE;
    Choice computerChoice = Choice::NONE;
    std::string resultMessage = "Make your move (R)ock, (P)aper, (S)cissors or (Q)uit.";
    int playerWins = 0;
    int computerWins = 0;
    int draws = 0;

    int ch;
    while (1) {
        clear();

        mvprintw(0, 0, "--- ROCK PAPER SCISSORS ---");
        mvprintw(2, 0, "Player Wins: %d | Computer Wins: %d | Draws: %d", playerWins, computerWins, draws);
        mvprintw(4, 0, "Your last choice: %s", choiceToString(playerChoice).c_str());
        mvprintw(5, 0, "Computer last choice: %s", choiceToString(computerChoice).c_str());
        mvprintw(7, 0, "%s", resultMessage.c_str());
        mvprintw(9, 0, "Press (R)ock, (P)aper, (S)cissors to play. Press Q to quit.");

        refresh();

        ch = getch();
        if (ch != ERR) {
            ch = tolower(ch);

            if (ch == 'q') {
                break;
            }

            if (ch == KEY_ROCK || ch == KEY_PAPER || ch == KEY_SCISSORS) {
                if (ch == KEY_ROCK) playerChoice = Choice::ROCK;
                else if (ch == KEY_PAPER) playerChoice = Choice::PAPER;
                else if (ch == KEY_SCISSORS) playerChoice = Choice::SCISSORS;

                int computerNumber = randint(0, 2);
                if (computerNumber == 0) computerChoice = Choice::ROCK;
                else if (computerNumber == 1) computerChoice = Choice::PAPER;
                else if (computerNumber == 2) computerChoice = Choice::SCISSORS;


                Status winner = determineWinner(playerChoice, computerChoice);
                if (winner == Status::WIN) {
                    resultMessage = "YOU WIN! :)";
                    playerWins++;
                } else if (winner == Status::LOSE) {
                    resultMessage = "YOU LOSE! :(";
                    computerWins++;
                } else if (winner == Status::DRAW) {
                    resultMessage = "It's a DRAW! :|";
                    draws++;
                }
            } else {
                resultMessage = "Invalid input. Press (R)ock, (P)aper, (S)cissors or (Q)uit.";
            }
        }

        usleep(10000);
    }

    endwin();

    std::cout << "\n--- GAME OVER ---" << std::endl;
    std::cout << "Final Score:" << std::endl;
    std::cout << "Player Wins: " << playerWins << std::endl;
    std::cout << "Computer Wins: " << computerWins << std::endl;
    std::cout << "Draws: " << draws << std::endl;
    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}

std::string choiceToString(Choice c) {
    switch (c) {
        case Choice::ROCK: return "ROCK";
        case Choice::PAPER: return "PAPER";
        case Choice::SCISSORS: return "SCISSORS";
        default: return "NONE";
    }
}

Status determineWinner(Choice playerChoice, Choice computerChoice) {
    if (playerChoice == computerChoice) {
        return Status::DRAW;
    }

    if ((playerChoice == Choice::ROCK && computerChoice == Choice::SCISSORS) ||
        (playerChoice == Choice::PAPER && computerChoice == Choice::ROCK) ||
        (playerChoice == Choice::SCISSORS && computerChoice == Choice::PAPER)) {
            return Status::WIN;
    }

    return Status::LOSE;
}

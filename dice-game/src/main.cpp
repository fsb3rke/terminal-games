#include <sstream>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <random_utils.hpp>
#include <iostream>
#include <cctype>


enum class Status {
    WIN,
    LOSE,
    DRAW
};

std::string int2str(int num);
Status determineWinner(unsigned int playerDice, unsigned int rivalDice);

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    unsigned int round = 0;
    unsigned int playerDice = 0;
    unsigned int rivalDice = randint(1, 6);
    std::string resultMessage = "Rival rolled a " + int2str(rivalDice);
    unsigned int playerWins = 0;
    unsigned int rivalWins = 0;
    unsigned int draws = 0;
    bool wait = false;

    int ch;
    while (1) {
        clear();

        mvprintw(0, 0, "--- Dice Game ---");
        mvprintw(2, 0, "In this game you and a computer Rival will play 10 rounds");
        mvprintw(3, 0, "where you will each roll a 6-sided dice, and the player");
        mvprintw(4, 0, "with the highest dice value will win the round. The player");
        mvprintw(5, 0, "who wins the most rounds wins the game. Good luck! (Q/q to exit.)");
        mvprintw(8, 0, "Round %d", round);
        mvprintw(10, 0, "Player Wins: %d | Rival Wins: %d | Draws: %d", playerWins, rivalWins, draws);
        mvprintw(12, 0, "Your last dice: %d", playerDice);
        mvprintw(13, 0, "Rival's last dice: %d", rivalDice);
        mvprintw(15, 0, "%s", resultMessage.c_str());
        mvprintw(17, 0, "%s", !wait ? "Press any key to roll the dice..." : "Press any key to continue.");

        refresh();

        ch = getch();
        if (ch != ERR) {
            if (tolower(ch) == 'q') break;

            if (wait) {
                rivalDice = randint(1, 6);
                resultMessage = "Rival rolled a " + int2str(rivalDice);
                round++;
                wait = false;
            } else {
                playerDice = randint(1, 6);
                resultMessage = "You rolled a " + int2str(playerDice);
                if (determineWinner(playerDice, rivalDice) == Status::WIN) {
                    resultMessage = resultMessage + ". You won this round.";
                    playerWins++;
                } else if (determineWinner(playerDice, rivalDice) == Status::DRAW) {
                    resultMessage = resultMessage + ". Draw.";
                    draws++;
                } else {
                    resultMessage = resultMessage + ". Rival won this round.";
                    rivalWins++;
                }
                wait = true;
            }
        }

        usleep(20000);
    }

    endwin();

    std::cout << "\n--- GAME OVER ---" << std::endl;
    std::cout << "Final Score:" << std::endl;
    std::cout << "Round: " << round << std::endl;
    std::cout << "Player Wins: " << playerWins << std::endl;
    std::cout << "Computer Wins: " << rivalWins << std::endl;
    std::cout << "Draws: " << draws << std::endl;
    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}

std::string int2str(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

Status determineWinner(unsigned int playerDice, unsigned int rivalDice) {
    if (playerDice == rivalDice) {
        return Status::DRAW;
    } else if (playerDice > rivalDice) {
        return Status::WIN;
    }

    return Status::LOSE;
}

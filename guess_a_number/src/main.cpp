#include <ncurses.h>
#include <string>
#include <stdexcept>
#include "random_utils.hpp"


int main() {
    initscr();
    cbreak();
    echo();
    curs_set(1);
    keypad(stdscr, TRUE);

    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;

    int secret_number;
    int guess;
    int tries = 0;
    bool game_won = false;
    std::string input_str;

    secret_number = randint(MIN_NUMBER, MAX_NUMBER);

    clear();
    mvprintw(2, 2, "========== GUESS THE NUMBER GAME ==========");
    mvprintw(4, 2, "I'm thinking of a number between %d and %d.", MIN_NUMBER, MAX_NUMBER);
    mvprintw(5, 2, "Let's see how many tries it takes you!");
    mvprintw(7, 2, "Number of Tries: %d", tries);
    mvprintw(8, 2, "---------------------------------------------");
    mvprintw(10, 2, "Enter your guess (and press Enter): ");
    refresh();

    while (!game_won) {
        mvprintw(7, 19, "%d", tries);
        refresh();

        mvprintw(10, 38, "         ");
        move(10, 38);

        input_str.clear();
        echo();

        int ch;
        while ((ch = getch()) != '\n' && ch != KEY_ENTER) {
            if (ch == KEY_BACKSPACE || ch == 127) {
                if (!input_str.empty()) {
                    input_str.pop_back();
                    mvprintw(10, 38 + input_str.length(), " ");
                    move(10, 38 + input_str.length());
                }
            } else if (isdigit(ch)) {
                input_str.push_back(ch);
                mvaddch(10, 38 + input_str.length() - 1, ch);
            }
            refresh();
        }
        noecho();

        if (input_str.empty() || input_str.find_first_not_of(' ') == std::string::npos) {
            mvprintw(14, 2, "You entered an empty guess. Please enter a number.   ");
            refresh();
            continue;
        }

        try {
            guess = std::stoi(input_str);
        } catch (const std::invalid_argument& e) {
            mvprintw(14, 2, "Invalid input! Please enter a valid number.           ");
            refresh();
            continue;
        } catch (const std::out_of_range& e) {
            mvprintw(14, 2, "Number out of range! Please enter a smaller/larger number.");
            refresh();
            continue;
        }

        tries++;

        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            mvprintw(14, 2, "Out of range (%d-%d)! Try again.                        ", MIN_NUMBER, MAX_NUMBER);
        } else if (guess < secret_number) {
            mvprintw(14, 2, "HIGHER! Try again.                                    ");
        } else if (guess > secret_number) {
            mvprintw(14, 2, "LOWER! Try again.                                     ");
        } else {
            game_won = true;
            mvprintw(14, 2, "Congratulations! You found the number in %d tries!   ", tries);
        }
        refresh();
    }

    mvprintw(16, 2, "Press any key to exit the game...");
    refresh();
    getch();

    endwin();
    return 0;
}

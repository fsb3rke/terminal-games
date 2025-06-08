# 🎲 Dice Game (Terminal Game with ncurses)

This is a terminal-based **Dice Game** written in C++ using the `ncurses` library. The player and a computer rival each roll a 6-sided die over 10 rounds. The winner of each round is determined, and the overall score is tracked.

## 🚀 Features

- Real-time terminal interface (powered by `ncurses`)
- 6-sided dice simulation for both player and rival
- Score tracking over 10 rounds
- Press `q` to quit the game at any time
- Final results are displayed in the terminal after the game ends

## 🔧 Requirements

- C++17-compatible compiler (e.g., `g++`, `clang++`)
- `ncurses` library
- `CMake` (version 3.10 or higher recommended)

## 📦 Build Instructions

Make sure the required dependencies are installed.

For Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential cmake libncurses5-dev
```

### Compile the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Once compiled, the executable will be available in the `build` directory.

## ▶️ Run the Game

```bash
./dice-game
```

## 🕹️ How to Play

- Press any key to roll your die.
- The rival rolls automatically.
- Results are displayed immediately on screen.
- A total of 10 rounds will be played.
- Press `q` or `Q` to quit early.

## 🗂️ Project Structure

```
.
├── CMakeLists.txt
├── README.md
├── src/
│   ├── main.cpp
│   └── random_utils.cpp
├── include/
│   └── random_utils.hpp
└── build/ (created after compilation)
```

## 📜 License

This project is licensed under the [GNU General Public License v3.0](https://github.com/fsb3rke/terminal-games/blob/main/LICENSE).

You are free to use, modify, and distribute this software under the terms of the GPL-3.0 license.

## 🙌 Developer Note

This project is a simple terminal game built with C++ and `ncurses`. It aims to provide an interactive dice game experience in the terminal with basic mechanics and scorekeeping.

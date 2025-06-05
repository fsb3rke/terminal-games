# 🎮 Guess the Number (Terminal Game with ncurses)

This is a terminal-based "Guess the Number" game written in C++. The game picks a random number between 1 and 100, and your task is to guess it. After each guess, you'll receive hints: go higher or lower.

## 🚀 Features

- Interactive terminal UI using `ncurses`
- Live user input handling with keyboard
- Random number generation
- Input validation (empty, non-numeric, out-of-range)
- Try counter

## 🔧 Requirements

- C++17-compatible compiler (e.g., g++, clang++)
- `ncurses` library
- `CMake` (version 3.10 or higher recommended)

## 📦 Build Instructions

Make sure required dependencies are installed.

On Ubuntu/Debian:

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

After building, the executable will be available in the `build` directory.

## ▶️ Run the Game

```bash
./guess-a-number
```

## 🗂️ Project Structure

```
.
├── CMakeLists.txt
├── compile_flags.txt
├── README.md
├── src/
│   ├── main.cpp
│   └── random_utils.cpp
├── include/
│   └── random_utils.hpp
└── build/ (generated after building)
```

## 📜 License

This project is licensed under the [GNU General Public License v3.0](https://github.com/fsb3rke/terminal-games/blob/main/LICENSE).

You are free to use, modify, and distribute this software under the terms of the GPL-3.0 license.

## 🙌 Credits

Developed as a simple terminal game project using `ncurses` and C++17.

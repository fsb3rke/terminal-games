# ✊✋✌️ Rock Paper Scissors (Terminal Game with ncurses)

This is a terminal-based **Rock Paper Scissors** game written in C++. Play against the computer using real-time keyboard input in an interactive terminal UI.

## 🚀 Features

- Interactive terminal UI using `ncurses`
- Live player input: `r`, `p`, `s`, or `q` to quit
- Random choice generation for the computer
- Keeps track of wins, losses, and draws
- Input validation and feedback messages

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
./rock-paper-scissors
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

# Pakutaberu Game
Just for fun

## Requirements
- `ncurses.h`
- `cstdlib` and `unistd.h` (part of the standard C and POSIX headers and should be available in your development environment.)

## Installation

### Ubuntu/Debian-based distributions
1. Update your package list:
    ```shell
    sudo apt update
    ```
2. Install `libncurses-dev` for the `ncurses` library and headers:
    ```shell
    sudo apt install libncurses-dev
    ```

### CentOS/Fedora/Red Hat-based distributions
1. Install `ncurses-devel` for the `ncurses` library and headers:
    ```shell
    sudo dnf install ncurses-devel
    ```

### macOS
1. Install [Homebrew](https://brew.sh/):
    ```shell
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

2. Install `ncurses` using Homebrew:
    ```shell
    brew install ncurses
    ```

3. Compiling the Program
    ```shell
    make
    ```


## Clean Everything
- This will clean object files and executable
    ```shell
    make clean
    ```

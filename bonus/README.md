
# MYRPG -- Epitech First Year

## Introduction
Welcome to our MYRPG project. The objective of the project is to create a little RPG with all of ours knowledges in Graphical Programming.
This is the main project of our school year.


## Prerequisites
To compile and run this project, you will need the following:

- A Unix-like operating system (Linux, macOS)
- GCC (GNU Compiler Collection) for compiling C code
- GNU Make for automating the compilation process
- CSFML for the graphical librarie.
## File Structure

Here is a structure of the project :

```txt
├── include                     # Header files (.h)
├── lib                         # Library of functions
├── Makefile                    # Makefile to compile the project
├── save                        # Saving functionality for the project
└── src                         # Source files and subdirectories for the project
    ├── buttons                 # Button management
    ├── entities                # Entity management
    ├── events                  # Event handling
    ├── fight_system            # Fight system
    ├── hud                     # Heads-up display (HUD)
    ├── init                    # Project initialization
    ├── inventory               # Inventory management
    ├── map                     # Map management
    ├── menus                   # Menu management
    ├── player                  # Player management
    ├── scene                   # Scene management
    ├── utils                   # Utility functions
    └── window_manager          # Window management
```
## Compilation

To compile the project, use the make command at the root of the project folder. This will compile all the necessary files and create an executable named my_rpg.

```bash
make
```

To clean up the object files and dependencies generated during compilation, you can use:
```bash
make clean
```

To remove everything that has been built (including the executable), use:
```bash
make fclean
```

To recompile all the project:
```bash
make re
```
## Features


The MYRPG supports all this input behind. With it you can check all the content of the game :

Commands:
- ESC: Opens the settings menu for user customization.
- P: Allows the user to exit the game.
- Z, Q, S, D: Controls for character movements, akin to arrow keys or WASD keys.
- I: Opens the inventory screen, enabling the user to manage items and equipment.
## Usage

After compilation, you can start the game by running the executable:

```bash
./my_rpg [file_of_saving]
```

Once the game is launched, you can ride around the map and enjoy it !
## Authors

The MYRPG project was developed by a dedicated team of students at Epitech. Below are the contributors who played a key role in its creation and ongoing development:

- Mathis Bukowski - Developer. Contact: mathis.bukowski@epitech.eu
- Rafael Drouart - Developer. Contact: rafael.drouart@epitech.eu
- Raphaël Richaud - Developer. Contact: raphael.richaud@epitech.eu
- Timoté Koenig - Developer. Contact: timote.koenig@epitech.eu
  For any queries regarding the project, please feel free to reach out to any of the authors via their provided contact information.


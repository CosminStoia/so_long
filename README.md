# so_long
## Overview
The so_long project is part of the 42 School curriculum, designed to provide students with a hands-on introduction to 2D game development. The goal of the project is to create a simple 2D game using the MiniLibX library, where a player can move around a map, collect items, and reach an exit to win the game.
## Features
- 2D tile-based game engine.
- Player can move up, down, left, and right.
- Collectibles that the player must gather before reaching the exit.
- Exit that the player can only access after collecting all items.
- Map validation to ensure it meets the required specifications.
## Usage
### Controls
- W or Up Arrow: Move up
- A or Left Arrow: Move left
- S or Down Arrow: Move down
- D or Right Arrow: Move right
- ESC: Exit the game
### Map File
The map file is a simple text file with a .ber extension. The map must be rectangular and contain the following characters:
- 0: Empty space
- 1: Wall
- C: Collectible
- E: Exit
- P: Player start position
### Exemple Map
```plaintext
111111
1P0C01
100001
1C0E01
111111

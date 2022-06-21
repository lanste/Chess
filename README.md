# Simple chess

Project based on my university semestral project.

Features only terminal interface. Graphical interface is probably the last thing planned.

You can play against other player (locally)


### Run
no external libraries are currently used

use given Makefile

### Controls
Menus are navigated by typing a number of menu option and pressing enter.

Game:\
  `move [a-h][1-8][a-h][1-8]` - example: `move c2c3` , c2 - piece position, c3 - target position\
  | &nbsp;&nbsp;&nbsp;&nbsp;add `q` (queen), `b` (bishop), `r` (rook), `n` (knight), to the end of the command if pawn is about to promote

  `[a-h][1-8][a-h][1-8]` - same as move, just more comfortable to type
  
  `save [filename]`
  
  `exit` - return to the menu from which the game was started

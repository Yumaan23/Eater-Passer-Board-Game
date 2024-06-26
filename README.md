# Eater-Passer-Board-Game
A console-based Eater Passer game implemented in C
Eater is a simple board game for two players, Passer and Eater, played on an m*m grid
board (m>2). An example of a 9x9 Eater board can be found in Figure 1. Red is painted
on the top and bottom edges. Blue is painted along the left and right edges. Players may
play with an unlimited number of red or blue markers.
The rules of the game are as follows. The game is played simultaneously by two players,
each placing a marker of their own color into a cell that has not yet been occupied.
When both players choose the same cell to mark, the Eater's marker remains and the
Passer's marker is eliminated. Otherwise, the markers remain on the board until the
game is completed. From the top to the bottom, the Passer seeks to form a connected
path of its own markers, which can go down, left, right, down-left, and down-right, but
cannot return. Once a connected path has been established, the Passer wins. The game
then terminates. As long as the Passer does not have a connected path and the board is
full, the Eater wins.Note that the game continues even if the board is not full and the Passer has not won,
for instance when the Eater has built a solid line that occupies an entire column.

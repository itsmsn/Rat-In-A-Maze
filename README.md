# RAT IN A MAZE C++
Write a C++ program that solves the maze problem. It will use a 2-D dynamic array grid (as a maze). The
dimensions of array will be taken as input from the user. Following figures shows layout of maze. You will
implement the graphical user interface with highlighted blocked cells and also the final path found at end.</br>
Here are some guide lines for the solution.</br>
a. First step for the rat is to enter in maze (you can ask the user to provide source and destination cells).</br>
b. Orange and green squares in figure are squares in which the rat can move.</br>
c. Blue squares are hurdles and rat cannot move there. You can use any marking colors or values (0, 1,</br>
2) for your game.</br>
d. Move order is just in four directions: Right, Down, Left, Up</br>
e. At the end the path from destination till entry cell should be marked and printed in 2-D maze matrix.</br>
f. Placement of Hurdles should be random it should change with each instance of new game.</br>
1. Stack Based Solution: Backtracking</br>
Path from maze entry to any current position of rat must operates as a stack. Block visited squares to avoid
revisit them by any marker value or color (as shown red in figure).

Mancala

By Quinn Callahan, Ben Kiel, and Lawrence Wright

Files: 
Mancala.cpp -> the file that contains all of the game's programming
resources -> a folder of assets used in the game. Necessary for the game to run.
Mancala_Time.exe -> the game's executable. 
raylib_game.cpp -> This is where all the code we wrote is. Not to go into too much detail (that's what our final writeup is for) but the file initializes and loads all of our assets, it makes an array which represents the beads on a mancala board and modifies and reads from that array with next_turn and updateboard to facilitate a mancala game against a computer.

How to run the game:
Download the resources folder and Mancala.cpp, then double click Mancala Time.exe

We've also emailed the whole zip file of the game from the email Qcallaha@oberlin.edu if the alternatives to running the game don't work (or if you find them inconvenient). The zip file is called game-premake-main.zip. To get to the executable from the zip file go to _bin -> Debug -> game-premake-main.exe .

Known bugs:
Sometimes when clicking a spot far too many beads get added to the score pit. When we've seen it happen it seems that it directly adds the beads from the clicked pit into the score pit. We believe this can also happen on the computer's turn. We don't really know why this happens but the problem likely exists somehwere in the cases where we treat the score pits uniquely in our code.

The game rarely crashes when the computer takes its turn. The cause of this is currently unknown.

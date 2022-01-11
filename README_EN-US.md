# [Conway's Game of Life 🚀](https://pt.wikipedia.org/wiki/Jogo_da_vida)
![Conways](https://i.imgur.com/cw42u24.png)


Conway's game of life is a simple game that captures the imagination of thousands of people since it was first invented in the seventies. It's proposal is a simple one: The game is not played by a player. Between your screen and your chair sits an observer to the game. In the game's screen, we randomly select where our cells are born, and then they start interacting with their neighbors. They, like us, are social beings, they dont like loliness at all. But if the neighborhood gets too crowded...well... lets just say they begin to leave.

![Print](https://i.imgur.com/f0Zpsrh.png)
![Print](https://i.imgur.com/WiwWx3g.png)
![Print](https://i.imgur.com/JbQrbwK.png)
![Print](https://i.imgur.com/6Wh4Osj.png)
![Print](https://i.imgur.com/99r3LdX.png)
![Print](https://i.imgur.com/d5AsvU4.png)
![Print](https://i.imgur.com/c13JW0P.png)
![Print](https://i.imgur.com/kAXiXqk.png)
![Print](https://i.imgur.com/iiew6CL.png)
![Print](https://i.imgur.com/VBgzvHA.png)
![Print](https://i.imgur.com/rK4Kt4G.png)
![Print](https://i.imgur.com/uPcmzK8.png)
![Print](https://i.imgur.com/pw9oe9w.png)

These are the rules:
1. If a living cell has 0 or 1 neighbors, they die of loliness
2. If a living cell has exactly 2 or 3 neighbors, they stay alive where they are
3. If a dead cell has 3 neighbors, they come back to life
4. If a living cell has more than 3 neighbors, they will die from overpopulation

And thats it, from this simple concept they start to create patterns and random organizations from the chaos. It is very fun to watch the generations unfold and new, chaotic shapes coming out from it

You can download the game's binaries and run it on your machine by accessing the [Releases](https://github.com/GabrielTheophilo/ConwaysGame/releases/tag/v0.0.1-alpha) tab and download the "release.zip" file containing the executables and assets needed to run the program

How to compile the game:
1. Download the [Allegro5](https://liballeg.org/) libray and add to the PATH of your machine
2. Clone the repository:
```console
git clone https://github.com/GabrielTheophilo/ConwaysGame.git
```
3. Go into the folder that was created
```console
cd ConwaysGame
```
4. With the compiler installed (gcc in my example):
```console
gcc -o conwaysgame.exe conways_game.cpp -lallegro -lallegro_image -lallegro_font -lallegro_ttf
```
5. The executable will appear on the root folder

6. If you have any problems with executing, transfer the DLL's from the Allegro5 folder to where the executable is > libstdc++-6.dll, libwinpthread-1.dll e libgcc_s_seh-1

**TO DO's**:
1. Edit the game's font
2. Create a makefile
3. Add a main menu
4. Make the project more modular (more OOP oriented)
5. Integrate the whole game, and variants, after making the main menu

**Screenshots**
![Conway's](https://i.imgur.com/GYDB4mp.png)
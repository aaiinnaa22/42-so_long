# 42-so_long

Hive Helsinki project

☆ INFO ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆

This is the first more graphical project of the curriculum. The project is a 2D game in C, where a character has to collect all collectibles on the screen, and then go out through the exit. The game will run in a created window on your screen. Keyboard buttons W, A, S and D are used for moving around the character, and ESC is used for closing the window of the game. 



☆ NEW CONCEPTS ☆ ☆ ☆ ☆ ☆ ☆

-  Screen rendering
-  Handling input from the keyboard
-  Window management

This project uses Codam's library 42MLX (https://github.com/codam-coding-college/MLX42), which consists of many functions enabling easy usage of the above mentioned concepts. 



☆ HOW THE CODE WORKS ☆ ☆ ☆ 

The program takes a file with the .ber extension as it's argument. The file.ber functions as a "map", that the program can use as a guide to render the actual game in a window. 

An accepted map has:
- Only the characters 0, 1, E, C, P in it. (0 = floor, 1 = wall, E = exit, C = collectible and P = starting point for character)
- Max. one exit and one starting point. At least 1 collectible.
- A rectangular shape.
- Walls all around it.
- A path of floor that can reach all of the collectibles, and the exit.

Every sort of character has an assigned texture. For every position of a character in the map, the corresponding texture is put in a similar position on the screen (ex. char 1 is in the upper left corner of the map => a texture depicting a wall is rendered at the upper left corner of the screen). 
(ex. image)



☆ RUN THE PROJECT ☆ ☆ ☆ ☆

Clone this git repository, and then in the terminal command line:
1. MAKE
2. ./so_long yourfile.ber (choose a file from /mymaps or make your own)
3. Play the game:)



☆ FUN TO KNOW ☆ ☆ ☆ ☆ ☆ ☆

The textures are made by me on the website pixilart. I got so caught up by making the pixel-images I started to procrastinate on the actual coding;'). The game depicts my actual coffee-loving dad and his big dream of getting a dachshund.



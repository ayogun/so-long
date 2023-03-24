# SO_LONG

![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-black)

<p align="center">
 <img src="https://github.com/byaliego/42-project-badges/blob/main/badges/so_long-bonus.png?raw=true">
</p>

</br>

## Description  
 
This project is a very small 2D game. It is built to make you work with
textures, sprites. And some very basic gameplay elements.

</br>

## How play the game

To play this game you can use any map of your choice as long follow the following rues:

* The extension need be `.ber`
* Its must be rectangular, surrounded by wall `1`
* Must have only one exit, only one player and at least one collectible
* Characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player position			 |
|     *D*     | Enemy(Devil)  position   |

In folder [maps](./maps/) have some examples of maps.

</br>

### Control of play

You can use `AWSD` to move `UP`, `DOWN`, `LEFT`, `RIGHT`.  
For restart the game press `ESC` or click on the red cross of window.
If you touch the enemy you loose the game.
To win the game its necessary pick up all collectible and pass for the exit.

</br>

### How execute the game

To start the game you need run the command `make` root directory.
This will compile the executable file `so_long`, to execute its necessary run `./so_long maps/map1.ber` or any map of your choice.

</br>

Or;

</br>

To start the game you need run the command `make bonus` root directory.
This will compile the executable file `so_long_bonus`, to execute its necessary run `./so_long_bonus maps/map1.ber` or any map of your choice.

</br>

## Makefile rules

| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make bonus` | Compile the bonus part of the program.                  |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program                |

</br>

## Trailer

Here on the top left corner it is visible how the game counts the score. I know how hard to see it. Anywho, I couldn't find a way to print it out bigger in Minilibx. lol

<center>
<img src="./img/score.gif">
</center>

</br>

Here I try to present how our hero dies when he touches one of the devils.

<center>
<img src="./img/dead.gif">
</center>

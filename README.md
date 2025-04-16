# 3D Game Engine using C

A 3D Game Engine entirely made with C. More like a "can I do this?" project than a "that's a fun idea for a game" project.

![title](screenshots/raycasting-test.png)

The games it can make are similar to Wolfenstein, using raycasting to fake a 3D environment, but it's really just a 2D plane. The executable only works for Linux.

## Controls

You can move forward and backward with W and S, respectively. To rotate left or right you use A and D.

## Instalation

Download the whole project and run:

```bash
./create.sh
```

## Rendering textures

The textures for the walls, ceilings and floors must be a png file located in the same root as the variable `TEXTURE_IMG` from the `create.sh` file. In the standar repo the png is call `structures.png` and the folder is `textures`.

The parser asumes that the textures are in a vertical strip style, and that all have the same size. Also, they need to be square.

Textures of 32x32 pixels works and looks fine.

# 3D Game Engine using C

A 3D Game Engine entirely made with C. More like a "can I do this?" project than a "that's a fun idea for a game" project.

The games it can make are similar to Wolfenstein, using raycasting to fake a 3D environment, but it's really just a 2D plane. The executable only works for Linux.

## Controls

You can move forward and backward with W and S, respectively. To rotate left or right you use A and D.

## Instalation

Download the whole project and run:

```bash
./create.sh
```

## Rendering textures

The textures must be a png file named `textures.png` found in the `images` folder. The code asumes that the textures are in a vertical strip style, and that all have the same size. Also, they have to be square.

Textures of 32x32 pixels works and looks fine.

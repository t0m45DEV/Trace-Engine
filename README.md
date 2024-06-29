# 3D Game Engine using C

A 3D Game Engine entirely made with C. More like a "can I do this?" project than a "that's a fun idea for a game" project.

The games it can make are similar to Wolfenstein, using raycasting to fake a 3D environment, but it's really just a 2D plane. The executable we create only works for Linux.

## Controls

You can move forward and backward with W and S, respectively. To rotate left or right you use A and D.

## Instalation

Download the whole project and run:

```
make play
```

If you want to make the project and see all the objects files and the executable, just type:

```
make
```

There are other options from the make file, like:

```
make clean # To delete all the object files and the executable

make debug # To make the project, and start a GDB session for debugging

make mem_check # To make the project and start a valgrind session for memory leaks check
```
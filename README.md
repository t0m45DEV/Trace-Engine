# 3D Game Engine using C

A minimal and modular Wolfenstein-style raycasting engine entirely made with C for Linux.

![title](screenshots/work_space.png)

The games it can make are similar to Wolfenstein, using raycasting to fake a 3D environment, but it's really just a 2D plane. The executable only works for Linux (for now).

It is a modular game engine, so every piece is independent of any other. Also is open source! You can see all the code in the current repo.

## Roadmap

There is a ton of features in a game engine, but this will give a glimpse of what it can do now and my plans for the future.

| Feature | State |
| --- | --- |
| Basic raycasting | :white_check_mark: |
| Renderer | :white_check_mark: |
| Logging system | :white_check_mark: |
| Entities | :hourglass_flowing_sand: |
| Level editor | :hourglass_flowing_sand: |
| Physics engine | :hourglass_flowing_sand: |

## License

This project is avaliable under either the MIT License or public domain. See [LICENSE](LICENSE) for more info.

## Dependencies

Currently the engine uses [OpenGL](https://www.opengl.org/) and [SDL](https://www.libsdl.org/) to handle graphics. 

Additionally, I included the [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear) header for simple UI, like buttons and sliders. For the image parser I used the [stb image loader](https://github.com/nothings/stb) header.

Besides that, it's made in standar C.

## Controls

You can move forward and backward with `W` and `S`, respectively. To rotate left or right you use `A` and `D`. The `|` key opens up the engine menu, with performance info and buttons to change the current leven and more!

## Instalation

Clone the repo, enter the main folder and run:

```bash
make
```

The Makefile include others mode, like `make export` to give away a final executable, and `make test` to run the auto tests.

## Rendering textures

The textures for the walls, ceilings and floors must be a png file located in the same root as the variable `TEXTURES_STRUCT_DIR` from the `Makefile`. In the standar repo the png is call `structures.png` and the folder is `textures`. This will create a new file `structures.ted` in the folder `data`. The `.ted` extension is not really that important, but you could read it as Tom's Engine Data.

The parser asumes that the textures are in a vertical strip style, and that all have the same size. Also, they need to be square.

Textures of 32x32 pixels works and looks fine.

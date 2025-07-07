# 3D Game Engine using C

A minimal and modular Wolfenstein-style raycasting engine entirely made with C for Linux.

![work_space](screenshots/work_space.png)

Everything is written from scratch — so no high-level libraries and a lot of bugs! — just C, OpenGL and SDL (and a little headers here and there).

It is a modular game engine, so every piece is independent of any other. It's fully open source! You can see all the code in this repository.

## Roadmap

There is a ton of features in a game engine, but this will give a glimpse of what it can do now and my plans for the future.

| Feature | State |
| --- | --- |
| Basic raycasting | :white_check_mark: Done |
| Renderer | :white_check_mark: Done |
| Logging system | :white_check_mark: Done |
| Entities | :hourglass_flowing_sand: In progress |
| Level editor | :hourglass_flowing_sand: In progress |
| Physics engine | :hourglass_flowing_sand: In progress |
| Windows export | :hourglass_flowing_sand: In progress |

## License

This project is available under either the **MIT License** or **Public Domain**. See [LICENSE](LICENSE) for more info.

## Dependencies

This engine uses:

- [OpenGL](https://www.opengl.org/) and [SDL](https://www.libsdl.org/) to handle graphics. 
- [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear) for simple UI, like buttons and sliders.
- [stb image loader](https://github.com/nothings/stb) for image loading.

Everything else is written in standard C.

## Controls

You can move forward and backward with `W` and `S`, respectively. To rotate left or right you use `A` and `D`. The `|` key opens up the engine menu, with performance info and buttons to change the current level and more!

## Installation

Clone the repo, enter the main folder and run:

```bash
make
```

The Makefile include other modes, like `make export` to give away a final executable, and `make test` to run the auto tests.

## Rendering textures

The textures for the walls, ceilings and floors must be a png file located in the same root as the variable `TEXTURES_STRUCT_DIR` from the `Makefile`. In the standard repo the png is called `structures.png` and the folder is `textures`. This will create a new file `structures.ted` in the folder `data`. The `.ted` extension is not really that important, but you could read it as Tom's Engine Data.

![Texture_example](screenshots/texture_example.png)

The texture parser assumes a vertical strip format, where each texture is square and identically sized (e.g., 32x32 pixels), like in the image shown.

## Contributing

Contributing are welcome! Open an issue or submit a PR to improve functionality, add features, or fix bugs.

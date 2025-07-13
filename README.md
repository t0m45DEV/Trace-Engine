# 3D Game Engine using C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
![Language](https://img.shields.io/badge/Made%20with-C-blue)
![Graphics](https://img.shields.io/badge/Graphics-OpenGL-green)
![Framework](https://img.shields.io/badge/Framework-SDL2-orange)

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

## Installation

Clone the repo like this:

```bash
git clone --recursive https://github.com/t0m45DEV/3D-Game-Engine-in-C
```

If you already cloned it without the `--recursive` flag, you could run this instead:

```bash
git submodule update --init --recursive
```

This is to make sure that every third-party library is included correctly into the project.

Once cloned, enter the main folder and run:

```bash
make
```

The Makefile include other modes, like `make export` to give away a final executable, and `make test` to run the auto tests.

## Usage

So you decided to use the Tom Engine. Great news!

But you must know how it works, at least a few important things:

### File structure

First of all, the files. Yes, you can see every file in it, engine stuff, third party libraries and even the texture parser code or the Makefile. But don't get too cocky, the "user" (and I mean that as a "the developer who will use this", as in "you") should work on a contained and separated part of the engine.

Currently the files look something like this:

```
application
├── inc
└── src
    └── application.c
engine
├── thirdparty
├── inc
└── src
```

Now, the developer should only work on the `application` folder. There you can define your headers and sources files, as much as you wish. There goes your game logic: every level, every entity, what the player can and can't do, anything.

In the file `application.c` you will find three important functions which are empty. These functions are:

```C
void app_init(void)

void app_update(float delta_time)

void app_close(void)
```

Every function has a comment on what it does exactly, so you can go to the definitions in the `engine` directory, but in a few words: these functions are the heart of your game.

- `app_init` will run on the start of the game, so you must put here the initializations of your structures, or malloc calls, or things like that.

- `app_update` will run once every frame, so here you must update the state of your entities, or draw UI or whatever you want on the screen (the raycaster stuff it's already on the engine side, so you don't have to worry about all that math and trigonometry). Also, this functions has a parameter: `delta_time` is the difference between the last frame and the current one, it helps keeping everything smooth even if you run this on a toaster.

- `app_close`, last but not least, this is like the inverse of `app_init`: it'll be call once the game stopped running, so if you have some autosave files mechanism or need to free some pointer because you called a malloc before, do it here.

You can define this three functions as you like, but keep in mind their current usage on the engine.

If you want to put your hand on the `engine` directory, be careful. This is where the core logic for the raycaster, the window initialization and the input handling resides. You can modify things to your heart’s content, but be aware that breaking something here _could_ affect your entire game.

### Rendering textures

The textures for the walls, ceilings and floors must be a png file located in the same root as the variable `TEXTURES_STRUCT_DIR` from the `Makefile`. In the standard repo the png is called `structures.png` and the folder is `textures`. This will create a new file `structures.ted` in the folder `data`. The `.ted` extension is not really that important, but you could read it as Tom's Engine Data.

![Texture_example](screenshots/texture_example.png)

The texture parser assumes a vertical strip format, where each texture is square and identically sized (e.g., 32x32 pixels), like in the image shown.

### Controls

You can move forward and backward with `W` and `S`, respectively. To rotate left or right you use `A` and `D`. The `|` key opens up the engine menu, with performance info and buttons to change the current level and more!

## Contributing

Contributing is welcome! Open an issue or submit a PR to improve functionality, add features, or fix bugs.

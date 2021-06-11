# Game of Life (Step 4)

You have stumbled upon game of life. Here is what you can do:

## Prerequisites

You'll need CMake version 3.20 as well as SDL2 installed on your system.

First, create a `build` directory for storing build files.

```
mkdir build
cd build
```

Now we can run CMake:

```
cmake ..
```

## Usage

### Executable

```
make life
```

This will create `life` executable which can then be run. Version 4 features both `clip` and `circular` modes. The mode
is given as a command line argument.

```
./life clip
```

or

```
./life circular
```

You'll get a usage error otherwise.

Also, you will be prompted for size of the board.

```
✦❯ ./life circular
Enter board width (in pixels): 640
Enter board height (in pixels): 480
```

### Docs

```
make doc
```

This will compile Doxygen docs and store them in `doc/` directory.

### Dist

```
make dist
```

This will compress code and docs to `dis.tar.xz` archive.
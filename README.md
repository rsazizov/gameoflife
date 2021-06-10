# Game of Life (Step 3)

You have stumbled upon game of life. Here is what you can do:

## Prerequisites

You'll need CMake version 3.20.

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

This will create `life` executable which can then be run. Version 3 features both `clip` and `circular` modes.
The mode is given as a command line argument.

```
./life clip
```

or

```
./life circular
```

You'll get a usage error otherwise.

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
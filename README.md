# Game of Life (Step 5)

You have stumbled upon game of life. Here is what you can do:

## Prerequisites

You'll need CMake version 3.20 as well as SDL2 installed on your system. CUnit should be present if you want to do
tests.

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

### Testing

```
make test
```

This will create an executable `test` inside `tests` directory. You can run it as follows:

```
./tests/test
```

Expected output:

```
❯ ./tests/test 


     CUnit - A unit testing framework for C - Version 2.1-3
     http://cunit.sourceforge.net/


Suite: Patterns
  Test: Blinker ...passed
  Test: Toad ...passed
  Test: Glider 1 ...passed
  Test: Glider 2 ...passed
  Test: Glider 3 ...passed
  Test: Glider 4 ...passed
  Test: Circular Glider ...passed

Run Summary:    Type  Total    Ran Passed Failed Inactive
              suites      1      1    n/a      0        0
               tests      7      7      7      0        0
             asserts      7      7      7      0      n/a

Elapsed time =    0.000 seconds
```
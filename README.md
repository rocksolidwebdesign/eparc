# README

`eparc`

an **E**xpression **PAR**ser **C**compiler written in **C**

An LL(1) recursive decent parser for arithmetic expressions.

Requirements

* A C99 compliant C compiler
* PCRE2 >= 10.33
* Conan
* CMake

# Setup

Setup conan.

```
conan profile new default --detect
```

Clone this repo

```
cd ~/projects
git clone $GIT_URL eparc
cd eparc
```

Configure the eparc_build with conan and cmake.

```
mkdir ../eparc_build
cd ../eparc_build

conan install ../eparc
cmake -DCMAKE_BUILD_TYPE=Release ../eparc
```

Built binary executables are placed in the `./bin` folder
of the eparc_build directory.

# Run

Build the main binary executable.

```
cmake --build . --target eparc --parallel 4
```

This is a  command line program that takes  a single command
line argument: a string containing an arithmetic expression.

Supported are the four  arithmetic operations `+`, `-`, `*`,
`/`, and expression grouping with parentheses.

Multiplication  and division  have precedence  over addition
and subtraction.

Be sure to use quotes around the expression.

```
$ ./bin/eparc "2 + 2 * 3"
8.000000

$ ./bin/eparc "(2 + 2) * 3"
12.000000

$ ./bin/eparc "1 + 2 * 3 + ((5 + 8) - 9.4 * 3 / 7.77)"
16.370656
```

# Run Tests

```
cmake --build . --parallel 4
ctest --verbose
```

# Options

Warnings are exuberant by default, disable this with.

```
cmake -DMORE_WARNINGS=OFF ../eparc
```

Tests can be disabled so only the main executable is built.

```
cmake -DBUILD_TESTS=OFF ../eparc
```

Tests may be run with valgrind for memory leak checking.

```
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_VALGRIND=ON ../eparc
```

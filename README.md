# lodepng - PNG encoder and decoder C library

This is a `build2` package repository for [LodePNG](https://github.com/lvandeve/lodepng),
a PNG encoder and decoder for C (ISO C90) with a C++ wrapper, without external
dependencies.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
these packages in your `build2`-based project, then instead see the
accompanying PACKAGE-README files:

- [`liblodepng`](liblodepng/PACKAGE-README.md)
- [`lodepng-utils`](lodepng-utils/PACKAGE-README.md)

The development setup uses the standard `bdep`-based workflow. For example:

```
git clone --recurse-submodules .../lodepng.git
cd lodepng

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```

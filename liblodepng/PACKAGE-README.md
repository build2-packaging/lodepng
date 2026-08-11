# liblodepng - PNG encoder and decoder C library

This is a `build2` package for the [LodePNG](https://lodev.org/lodepng/)
library. It is a PNG encoder and decoder for C (ISO C90) with a C++ wrapper
on top, without external dependencies (deflate/zlib are embedded).


## Usage

To start using `liblodepng` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: liblodepng == 2026.1.19
```

The package version is a semver-shaped coercion of the upstream date version
(`upstream-version: 20260119`). Use an exact or revision constraint rather
than `^` or `~`.

Then import the library in your `buildfile`:

```
import libs = liblodepng%lib{lodepng}
```

Include the public header as:

```
#include <lodepng.h>
```


## Importable targets

This package provides the following importable targets:

```
lib{lodepng}
```

The PNG encoder and decoder. Made for C (ISO C90). The default build also
compiles the C++ wrapper (`lodepng::`).
Metadata `liblodepng.cpp` reflects `config.liblodepng.cpp`.


## Configuration variables

```
[bool] config.liblodepng.cpp ?= true
```

Compile the C++ wrapper (`true`, default) or the pure C library (`false`).
The C build exposes only the C API (unmangled) and exports
`LODEPNG_NO_COMPILE_CPP` so consumers do not use the C++ wrapper. All other
LodePNG features stay enabled.

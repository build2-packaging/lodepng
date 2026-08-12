# lodepng-utils - command-line PNG file inspector

This is a `build2` package for the [LodePNG](https://lodev.org/lodepng/)
`pngdetail` utility. It prints PNG header, chunk, palette, and compression
information.

The package depends on `liblodepng` at the same version and requires the
C++ wrapper (`config.liblodepng.cpp=true`).


## Usage

To start using `lodepng-utils` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * lodepng-utils == 2026.1.19
```

The package version is a semver-shaped coercion of the upstream date version
(`upstream-version: 20260119`). Use an exact or revision constraint rather
than `^` or `~`.

Then import the executable in your `buildfile`:

```
import! pngdetail = lodepng-utils%exe{pngdetail}
```


## Importable targets

This package provides the following importable targets:

```
exe{pngdetail}
```

The `pngdetail` command-line tool for inspecting PNG files.


## Configuration variables

This package has no configuration variables. Its `liblodepng` dependency
requires the C++ wrapper (`config.liblodepng.cpp=true`).

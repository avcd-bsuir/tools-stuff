[![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue.svg)](https://bit.ly/cc-by-nc-sa-40)

# Installation

Add submodule:
```
$ git submodule add https://github.com/avcd-bsuir/tools-stuff third-party/tools-stuff
```

Update all submodules:
```
$ git submodule update --remote
```

Add
```json
"C_Cpp.default.includePath": [
    "${workspaceFolder}/third-party/tools-stuff/include"
]
```
to your local VSCode `settings.json` file

Do not forget to add include flag to your compiler command:
```
-I"third-party/tools-stuff/include"
```

# Tools: Stuff

- `Console.h` implements:
- - `void aGetConsoleBufferSize(int *, int *)`
- `Interactions.h` implements:
- - `void aScanCheck(const char *, const char *, ...)`
- - `bool aQToExit()`
- `Math.h` implements:
- - `float aPow(float, int)`
- - `void aPrintBinary(int, int, bool)`
- `Random.h` implements:
- - `int aRandInt(int, int)`

# Usage

## * `Console.h`

### `void aGetConsoleBufferSize(int *, int *)`

Get console buffer size.

## * `Interactions.h`

### `void aScanCheck(const char *, const char *, ...)`

Asks user for input until user inputs data in the correct way.

### `bool aQToExit()`

Show exit prompt.

## * `Math.h`

### `float aPow(float, int)`

Returns a ^ n.

### `void aPrintBinary(int, int, bool)`

Print integer as binary.

## * `Random.h`

### `int aRandInt(int, int)`

Returns random integer in range from A to B including both A and B.

# Random 'nice to know' stuff

```c
// Read input file
if (argc != 2) {
    printf("Usage: compiler [filename]\n");
    exit(1);
}
FILE * input_file = fopen(argv[1], "rb");
if (!input_file) {
    printf("Error while opening file '%s'!\n", argv[1]);
    exit(1);
}
fseek(input_file, 0, SEEK_END);
long len = ftell(input_file);
fseek(input_file, 0, SEEK_SET);
char * input = malloc(len);
if (!input) {
    printf("Error while opening file '%s'!\n", argv[1]);
    exit(1);
}
fread(input, 1, len, input_file);
fclose(input_file);
```

# Credits

Written by Alexey Filich.

# License

This repository is licensed under [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International](LICENCE.md).

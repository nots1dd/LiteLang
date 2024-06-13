# LiteLang

## A fast and basic compiler written in C++

### Features

-> Concise and effective grammar setup

-> Binary Operations (`+`, `-`, `*` and `/` available)

-> Precedence Climbing accounted for (BODMAS / PEMDAS)

-> Variable assignment and re-assignment

-> Efficient Tokenization, parsing and code generation

-> Scopes are present

-> If, elif and else statements


### BUILDING

1. For **x86_64 LINUX**:

**Pre-requisites**

Have `cmake`, `nasm` and `ld` installed in your kernel

-> Clone this repository `https://github.com/nots1dd/LiteLang` and cd into it

-> Run `cmake -S . -B build`

-> Then an executable will be present in the `build/` directory

-> Use that executable to compile your `<input>.cal` file

-> A final `out` executable will be present. Run that to get the final output


### CREDITS

LiteLang is a project that was NOT ideated on my own, rather this is a chance for me to have a better understanding of how a programming language works.

This is a project heavily inspired by this repository :

`https://github.com/orosmatthew/hydrogen-cpp`

Go check it out here ^^

His YT Channel :: `https://www.youtube.com/@pixeled-yt/videos`

The purpose of this repository is NOT TO copy someone's work and bluff that this is mine.

It's purpose is to help me learn more about compilers and its workings, along with giving me a chance on pursuing this as a passion project.

### FUTURE

I don't plan on this being just a fork of an exisiting C++ compiler.

1. Add syntax highlighting [x]

2. Add a print function [x]

3. Looking into exponentiation (its precendence is right to left unlike bin_ops) [ ]

4. Adding global scope to variables [ ]


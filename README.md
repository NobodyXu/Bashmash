# Bashmash
Bash math utilities

## What is Bashmash?
Bashmash is a set of math utilities for the Bash language.  
It simplifies common mathematical operations, such as factorials.

## Features
As for now, Bashmash supports only 64-bit numbers.  
Support for infinitely long numbers will be implemented in future releases.  
Currently the following mathematical operations are supported:
 - Factorial
 - Bitwise operations
 - Comparison
 - Conversion between systems

## Latest release
The latest test release is 0.4.  
It introduces the following new features and changes:
 - Comparison

## Powered by
Bashmash is powered by:
 - [bash-loadables](https://github.com/NobodyXu/bash-loadables) by [NobodyXu](https://github.com/NobodyXu)

## Installation
### Requirements
 - G++: `sudo apt install g++`
 - Clang: `sudo apt install clang`
 - LLD: `sudo apt install lld`
 - cap-ng.h: `sudo apt install libcap-ng-dev`
 - seccomp.h: `sudo apt install libseccomp-dev`

### Steps
1. Clone this repository including the submodules: `git clone --recurse-submodules https://github.com/HubertPastyrzak/Bashmash`.
2. Go to the downloaded folder: `cd Bashmash`.
3. Assign execution permissions to the installer: `chmod +x install.sh`.
4. Run the installer: `sudo ./install.sh`.
5. Bashmash is now ready to use. :)

## Importing commands
```bash
enable -f /bin/bashmash <command>



Example:

enable -f /bin/bashmash dec2bin
```

## Usage
### Factorials
```bash
fact <x>         # x!



Example:

fact 5           # 120
```

### Bitwise operations
```bash
not <x>          # ~x
or  <a> <b>      # a | b
and <a> <b>      # a & b
xor <a> <b>      # a ^ b



Examples:

not 5            # -6
or  5 10         # 15
and 5 10         # 0
xor 5 10         # 15
```

### Comparison
```bash
cless  <a> <b>   # a < b
cleq   <a> <b>   # a <= b
ceq    <a> <b>   # a == b
cgreq  <a> <b>   # a >= b
cgreat <a> <b>   # a > b



Examples:

cless  5 10      # true
cleq   5 10      # true
ceq    5 10      # false
cgreq  5 10      # false
cgreat 5 10      # false
```

### Conversion between systems
```bash
bin2oct <x>      # x2 -> x8
bin2dec <x>      # x2 -> x10
bin2hex <x>      # x2 -> x16

oct2bin <x>      # x8 -> x2
oct2dec <x>      # x8 -> x10
oct2hex <x>      # x8 -> x16

dec2bin <x>      # x10 -> x2
dec2oct <x>      # x10 -> x8
dec2hex <x>      # x10 -> x16

hex2bin <x>      # x16 -> x2
hex2oct <x>      # x16 -> x8
hex2dec <x>      # x16 -> x10



Examples:

bin2oct 101111   # 57
bin2dec 101111   # 47
bin2hex 101111   # 2f

oct2bin 57       # 101111
oct2dec 57       # 47
oct2hex 57       # 2f

dec2bin 47       # 101111
dec2oct 47       # 57
dec2hex 47       # 2f

hex2bin 2f       # 101111
hex2oct 2f       # 57
hex2dec 2f       # 47
```

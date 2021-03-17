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
 - Bitwise operations: NOT, OR, AND, and XOR
 - Conversion between binary, octal, decimal and hexadecimal

## Latest release
The latest test release is 0.3.  
It introduces the following new features and changes:
 - Commands are now loaded as Bash builtins (see [Importing commands](#importing-commands))
 - Bitwise operations: NOT, OR, AND, and XOR

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
fact <x>

Example:
fact 5           # 120
```

### Bitwise operations
```bash
not <x>
or <a> <b>
and <a> <b>
xor <a> <b>

Examples:
not 5            # -6
or 5 10          # 15
and 5 10         # 0
xor 5 10         # 15
```

### Conversion between systems
```bash
bin2oct <x>
bin2dec <x>
bin2hex <x>

oct2bin <x>
oct2dec <x>
oct2hex <x>

dec2bin <x>
dec2oct <x>
dec2hex <x>

hex2bin <x>
hex2oct <x>
hex2dec <x>

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

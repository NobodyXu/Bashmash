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
 - Conversion between binary, octal, decimal and hexadecimal

## Latest release
The latest test release is 0.2.  
It introduces the following new features and changes:
 - Commands got reimplemented in C++
 - Conversion between binary, octal, decimal and hexadecimal

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
```
enable -f /bin/bashmash <command>

Example:
enable -f /bin/bashmash dec2bin
```

## Usage
### Factorials
```bash
fact <non_negative_integer>

Example:
fact 5

Output:
120
```

### Binary to octal conversion
```bash
bin2oct <non_negative_binary_integer>

Example:
bin2oct 101111

Output:
57
```

### Binary to decimal conversion
```bash
bin2dec <non_negative_binary_integer>

Example:
bin2dec 101111

Output:
47
```

### Binary to hexadecimal conversion
```bash
bin2hex <non_negative_binary_integer>

Example:
bin2hex 101111

Output:
2f
```

### Octal to binary conversion
```bash
oct2bin <non_negative_octal_integer>

Example:
oct2bin 57

Output:
101111
```

### Octal to decimal conversion
```bash
oct2dec <non_negative_octal_integer>

Example:
oct2dec 57

Output:
47
```

### Octal to hexadecimal conversion
```bash
oct2hex <non_negative_octal_integer>

Example:
oct2hex 57

Output:
2f
```

### Decimal to binary conversion
```bash
dec2bin <non_negative_integer>

Example:
dec2bin 47

Output:
101111
```

### Decimal to octal conversion
```bash
dec2oct <non_negative_integer>

Example:
dec2oct 47

Output:
57
```

### Decimal to hexadecimal conversion
```bash
dec2hex <non_negative_integer>

Example:
dec2hex 47

Output:
2f
```

### Hexadecimal to binary conversion
```bash
hex2bin <non_negative_hexadecimal_integer>

Example:
hex2bin 2f

Output:
101111
```

### Hexadecimal to octal conversion
```bash
hex2oct <non_negative_hexadecimal_integer>

Example:
hex2oct 2f

Output:
57
```

### Hexadecimal to decimal conversion
```bash
hex2dec <non_negative_hexadecimal_integer>

Example:
hex2dec 2f

Output:
47
```

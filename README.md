# Bashmash
Bash math utilities

## What is Bashmash?
Bashmash is a set of math utilities for the Bash language.  
It simplifies common mathematical operations, such as factorials.

## Features
As for now, Bashmash supports only 64-bit numbers.  
Support for infinitely long numbers will be implemented in future releases.  
Currently the following mathematical operations are supported:
 - Factorials
 - Binary to octal conversion
 - Binary to decimal conversion
 - Binary to hexadecimal conversion
 - Octal to binary conversion
 - Octal to decimal conversion
 - Decimal to binary conversion
 - Decimal to octal conversion

## Latest release
The latest test release is 0.1.  
It introduces the following new features:
 - Factorials

## Installation
### Requirements
 - G++: `sudo apt install g++`

### Steps
1. Clone this repository: `git clone https://github.com/HubertPastyrzak/Bashmash`.
2. Go to the downloaded folder: `cd Bashmash`.
3. Assign execution permissions to the installer: `chmod +x install.sh`.
4. Run the installer: `sudo ./install.sh`.
5. Bashmash is now ready to use. :)

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

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
 - Decimal to binary conversion

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

### Decimal to binary conversion
```bash
dec2bin <non_negative_integer>

Example:
dec2bin 47

Output:
101111
```

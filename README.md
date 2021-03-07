# Bashmash
Bash math utilities

## What is Bashmash?
Bashmash is a set of math utilities for the Bash language.
It simplifies common mathematical operations, such as factorials.

## Features
Bashmash supports operations on infinitely long numbers, regardless of the CPU architecture.
Currently the following mathematical operations are supported:
 - Factorials
 - Decimal to Binary converter

## Latest version
The latest test version is 0.1.
It introduces the following new features:
 - Factorials

## Installation
1. Clone this repository: `git clone https://github.com/HubertPastyrzak/Bashmash`.
2. Go to the downloaded folder: `cd Bashmash`.
3. Assign execution permissions to the installer: `sudo chmod +x install.sh`.
4. Run the installer: `sudo ./install.sh`.
5. Bashmash is now ready to use. :)

## Usage
### Factorials
```bash
fact <non_negative_integer>
```

#### Example
```bash
fact 5
```

##### Output
```
120
```

### Decimal to binary converter
```bash
dec2bin <non_negative_integer>
```

#### Example
```bash
dec2bin 47
```

##### Output
```
101111
```

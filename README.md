# (CISFUN) - SIMPLE SHELL COMMAND INTERPRETER

![Shell](https://img.shield.io/badge/Shell-cisfun-blue)
![Version](https://img.shield.io/badge/Version-1.0-blue)
![Authors](https://img.shield.io/badge/Authors-26%20Joshua-orange)

**cisfun** is a simple shell command interpreter (shell) that allows users to interact with their operating system using command-line instructions. This project aims to provide basic functionalities and demonstrate the fundamentals of a shell implementation.

## Feature


- Execute commands avalible in the system's PATH.
- Handle basic commands and arguments.
- Support exit commands.

## Installation
1. Clone the repository:

	```bash
	git clone https://github.com/UiJosh20/simple_shell.git
	```
2. Change the directory

	```bash
	cd simple_shell
	```
3. Compile the source code

	```bash
	gcc -Wall -Werror -Wextra -pedantic *.c -o cisfun
	```
4. Run the shell

	```bash
	./cisfun
	```

## Usage

Once you run the **cisfun** shell, you can start entering commands. it supports basic commands like **ls** ,  **pwd** , **cd** , etc. along with their respective arguments. The shell will execute the commands and display the output on the terminal.

## Example

Here an example of using the **cisfun** shell:

	```bash
	$ ./cisfun
	cisfun$ ls
	file1.txt  file2.txt  directory/
	```

## Authors
- Joshua Adeyeri

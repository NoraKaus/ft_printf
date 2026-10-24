This project has been created as part of the 42 curriculum by ekausiny

## ft_printf

### Description
The goal of this project was to recode the printf() fuunction from libc.
This project did not implement the buffer management of the original printf().
It handles the following conventions: cspdiuxX%. 

#### Bonus
Manage the combination of flags -0.# +

`-` 	left alighns text
`0` 	zeros defined width if not left aligned
`1-9` 	number before . defines width, and after defines precision
`+` 	displays + for positive values
` `		displays space before num for positive values
`#`		displays 0x of 0X for hexadecimal values
`.`		defines precision

### Instructions
```bash
make          #compiles the library libft.a
make clean    # removes the .o files
make fclean   # removes the .o files and libft.a
make re       # recompiles everything from scratch
cc -Wall -Wextra -Werror <main.c> libftprintf.a
```

### Resources

- The `man` pages for the reimplemented functions (`man 3 printf`, etc.)
- ibm printf documentation of the flags
- Francinette (by xicodomingues) and AddressSanitizer / Valgrind for testing and debugging

**AI usage:** AI was used for to build the test functions, for edge case debugging and understand/outline different flag combinationtions. 
All code was written and understood by the author.
# GNL
I coded a function that returns a line ending with a newline, read from a file descriptor, to learn a static variables in C programming.

Calling function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.

get_next_line is declared as follows.
```int get_next_line(int fd, char **line);```  
```fd```:    file descriptor for reading  
```line```:  The value of what has been read

Compilation will be done this way : 
```gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c```
BUFFER_SIZE can be changed freely.

*There is no main function in this repository.

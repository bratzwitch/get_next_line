# Get Next Line

A function that reads content line by line from a file descriptor, one line at a time.

## Description

Get Next Line is a project that teaches you how to read from a file descriptor and return one line at a time, efficiently managing memory and handling various edge cases. This function is useful for reading large files without loading the entire content into memory.

## Features

- Reads one line at a time from any file descriptor
- Efficient buffer management
- Handles multiple file descriptors simultaneously
- Memory leak protection
- Works with files, standard input, and pipes

## Function Prototype

```c
int get_next_line(int fd, char **line);
```

## Return Values

- `1`: A line was read
- `0`: EOF reached
- `-1`: An error occurred

## Compilation

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## Usage

1. Clone the repository:
```bash
git clone https://github.com/bratzwitch/get_next_line.git
cd get_next_line
```

2. Include in your project:
```c
#include "get_next_line.h"
```

3. Compile with your program:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 your_file.c get_next_line.c get_next_line_utils.c
```

## Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int ret;

    if (argc != 2)
        return (1);
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    
    if (ret == 0)
        printf("%s\n", line);
    free(line);
    close(fd);
    
    return (0);
}
```

## Buffer Size

The buffer size can be modified during compilation using the `-D BUFFER_SIZE=n` flag. Different buffer sizes will affect performance:

- Small buffer (1): More system calls, slower
- Large buffer (1000000): Less system calls, more memory usage
- Optimal buffer (1024-8192): Good balance

## Files

- `get_next_line.c`: Main function implementation
- `get_next_line_utils.c`: Helper functions
- `get_next_line.h`: Header file with prototypes and includes

## Requirements

- Must work with any file descriptor
- Must handle multiple file descriptors
- Must not lose data between calls
- Memory must be properly managed (no leaks)

## Author

Viacheslav Moroz - 42 Student

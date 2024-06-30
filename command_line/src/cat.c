#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
 
/* The official name of this program. */
#define PROGRAM_NAME "cat"

/* Name of input file. */
static char const *infile;

/* Descriptor on which input file is open. */
static int input_desc;

#define BUFFER_SIZE 1024
 
void usage()
{
    printf("Usage: %s [OPTION]... [FILE]...\n", PROGRAM_NAME);
    return;
}

void error_open()
{
    char error_msg[1024];
    snprintf(error_msg, sizeof(error_msg), "cat: %s", infile);
    perror(error_msg);
    return;
}

void print_file_contents()
{ 
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
 
    while ((bytes_read = read(input_desc, buffer, BUFFER_SIZE)) > 0)
    {
        ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written == -1)
        {            
            perror("Error writing to stdout");
            close(input_desc);
            return;
        }
    }
 
    if (bytes_read == -1)
    {
        perror("Error reading file");
    }
 
    close(input_desc);
}
 
int main(int argc, char **argv)
{
    int file_open_mode = O_RDONLY;
    
    if (argc < 2)
    {
        usage();
        return 0;
    }
 
    /* Main loop. */
    int argind = 1;
    
    do
    {
        if (argind < argc)
            infile = argv[argind];

        input_desc = open (infile, file_open_mode);
        if (input_desc < 0)
        {
            error_open();
            close(input_desc);
            continue;
        }
        print_file_contents();
    }
    while (++argind < argc);
 
    return EXIT_SUCCESS;
}

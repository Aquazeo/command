#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

/* The official name of this program. */
#define PROGRAM_NAME "cp"

#define BUFFER_SIZE 1024

void usage()
{
    printf("%s [OPTION]... SOURCE... DIRECTORY\n", PROGRAM_NAME);
    return;
}

int main(int argc, char **argv)
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUFFER_SIZE];
    
    if (argc != 3)
    {
        usage();
        return EXIT_SUCCESS;
    }

    /* Open input and output files */
    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
    {
        char error_msg[1024];
        snprintf(error_msg, sizeof(error_msg), "cat: %s", argv[1]);
        perror(error_msg);
    }
        
 
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH; /* rw-rw-rw- */
    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1)
    {
        char error_msg[1024];
        snprintf(error_msg, sizeof(error_msg), "cat: %s", argv[2]);
        perror(error_msg);
    }
        
 
    /* Transfer data until we encounter end of input or an error */
 
    while ((numRead = read(inputFd, buf, BUFFER_SIZE)) > 0)
        if (write(outputFd, buf, numRead) != numRead)
            perror("couldn't write whole buffer");
    if (numRead == -1)
        perror("read");
 
    if (close(inputFd) == -1)
        perror("close input");
    if (close(outputFd) == -1)
        perror("close output");

    return EXIT_SUCCESS;
}

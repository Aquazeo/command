#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <utime.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

/* The official name of this program. */
#define PROGRAM_NAME "touch"

void usage()
{
    printf("Usage: %s [OPTION]... FILE...\n", PROGRAM_NAME);
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        usage();
        return 0;
    }

    const char *filename = argv[1];

    int fd = open(filename, O_CREAT | O_WRONLY, 0666);
    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    close(fd);

    struct utimbuf new_times;  
    new_times.actime = time(NULL);
    new_times.modtime = time(NULL);
    if (utime(filename, &new_times) < 0)
    {
        perror("utime");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

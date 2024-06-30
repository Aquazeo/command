#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

/* The official name of this program. */
#define PROGRAM_NAME "mkdir"

void usage()
{
    printf("Usage: %s [OPTION]... DIRECTORY...\n", PROGRAM_NAME);
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        usage();
        return 0;
    }

    const char *dirname = argv[1];

    mode_t mode = 0755;

    if (mkdir(dirname, mode) != 0)
    {
        char error_msg[1024];
        snprintf(error_msg, sizeof(error_msg), "mkdir: cannot create directory '%s'", dirname);
        perror("mkdir"); 
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

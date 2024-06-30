#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

/* The official name of this program. */
#define PROGRAM_NAME "mv"

void usage()
{
    printf("Usage: %s [OPTION]... [-T] SOURCE DEST\n", PROGRAM_NAME);
    return;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        usage();
        return 0;
    }

    const char *source = argv[1];
    const char *dest = argv[2];

    if (rename(source, dest) != 0)
    {
        char error_msg[1024];
        snprintf(error_msg, sizeof(error_msg), "mv: cannot move '%s' to '%s'", source, dest);
        perror(error_msg);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include "usage.h"

void show_all_options()
{
    puts("options:\n"
         "  -a  --add     add book\n"
         "  -d  --del     delete book\n"
         "  -s  --search  search book\n"
         "  -u  --update  update book\n"
         "  -l  --list    list books\n"
         "  -q  --quit    quit"
        );
}

#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "operation.h"
#include "usage.h"

const int MAX_NUMBER_OF_BOOKS = 1e3;

struct Lib
{
    // book points to an array of pointers to struct Book
    struct Book **book;
    
    int number_of_books;
};

int main(int argc, char **argv)
{
    struct Lib lib;
    lib.book = malloc(MAX_NUMBER_OF_BOOKS * sizeof(struct Book *));
    read_info(lib.book, "res/test.info", &(lib.number_of_books));
    
    if (argc == 1)
    {
        show_all_options();
    }

    char option = '\0';
    do
    {
        printf("option > ");
        option = getchar();
        getchar(); // Consume the newline character
        
        switch (option)
        {
            case 'a':
                add_book(lib.book, &(lib.number_of_books));
                break;
            case 'd':
                del_book(lib.book, &(lib.number_of_books));
                break;
            case 's':
                search_book(lib.book, &(lib.number_of_books));
                break;
            case 'u':
                update_book(lib.book, &(lib.number_of_books));
                break;
            case 'l':
                list_books(lib.book, &(lib.number_of_books));
                break;
            case 'q':
                break;
            default:
                puts("Invalid option");
                break;
        }
    } while (option != 'q');

    print_info(lib.book, "res/temp.info", &(lib.number_of_books));
    remove("res/test.info");
    rename("res/temp.info", "res/test.info");
    
    free_books(lib.book, &(lib.number_of_books));
    
    return 0;
}

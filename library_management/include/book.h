#ifndef BOOK_H
#define BOOK_H

struct Book
{
    int  id;
    char isbn[20];
    char title[80];
};

void read_info(struct Book **book, char *info, int *num);

void print_info(struct Book **book, char *new_info, int *num);

// Free the memory allocated for the book
void free_books(struct Book **book, int *num);

#endif

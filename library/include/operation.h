#ifndef OPERATION_H
#define OPERATION_H

void add_book(struct Book **book, int *num);

void del_book(struct Book **book, int *num);

struct Book * search_book(struct Book **book, int *num);

void update_book(struct Book **book, int *num);

void list_books(struct Book **book, int *num);

#endif

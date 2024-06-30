#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strcspn
#include "book.h"
#include "operation.h"
#include <unistd.h>

void add_book(struct Book **book, int *num)
{
    struct Book *new_book = malloc(sizeof(struct Book));
    
    printf("id > ");
    scanf("%d", &new_book->id);
    getchar(); // Consume the newline character
    
    printf("isbn > ");
    fgets(new_book->isbn, 20, stdin);
    new_book->isbn[strcspn(new_book->isbn, "\n")] = 0;
    
    printf("title > ");
    fgets(new_book->title, 50, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = 0;

    book[*num] = new_book;
    (*num) ++;

    return;
}

struct Book * search_book(struct Book **book, int *num)
{
    char op;
    printf("id, isbn, title(I/N/T) > ");
    op = getchar();
    getchar();

    switch (op)
    {
        case 'I':
            int target;
            printf("target > ");
            scanf("%d", &target);
            while (getchar() != '\n');
            for (int i = 0; i < *num; i ++ )
            {
                if (book[i]->id == target)
                {
                    return book[i];
                }
            }
            puts("Book not found");
            break;
        case 'N':
            char target_isbn[20];
            printf("target > ");
            fgets(target_isbn, 20, stdin);
            target_isbn[strcspn(target_isbn, "\n")] = 0;
            for (int i = 0; i < *num; i ++ )
            {
                if (strcmp(book[i]->isbn, target_isbn) == 0)
                {
                    return book[i];
                }
            }
            puts("Book not found");
            break;
        case 'T':
            char target_title[50];
            printf("target > ");
            fgets(target_title, 50, stdin);
            target_title[strcspn(target_title, "\n")] = 0;
            for (int i = 0; i < *num; i ++ )
            {
                if (strcmp(book[i]->title, target_title) == 0)
                {
                    return book[i];
                }
            }
            puts("Book not found");
            break;
        default:
            break;
    }
}

void del_book(struct Book **book, int *num)
{
    struct Book *target = search_book(book, num);

    if (target == NULL)
    {
        puts("Book not found");
        return;
    }

    for (int i = 0; i < *num; i ++ )
    {
        if (book[i] == target)
        {
            free(book[i]);
            for (int j = i; j < *num - 1; j ++ )
            {
                book[j] = book[j + 1]; // book[*num - 2] = book[*num - 1]
            }
            book[*num - 1] = NULL; // book[*num - 1]
            (*num) --;
            break;
        }
    }
    return;
}

void update_book(struct Book **book, int *num)
{
    struct Book *target = search_book(book, num);
    if (target == NULL)
    {
        puts("Book not found");
        return;
    }

    printf("id > ");
    scanf("%d", &target->id);
    getchar(); // Consume the newline character

    printf("isbn > ");
    fgets(target->isbn, 20, stdin);
    target->isbn[strcspn(target->isbn, "\n")] = 0;
    
    printf("title > ");
    fgets(target->title, 50, stdin);
    target->title[strcspn(target->title, "\n")] = 0;

    return;
}

void list_books(struct Book **book, int *num)
{
    for (int i = 0; i < *num; i ++ )
    {
        printf("id: %d ", book[i]->id);
        printf("isbn: %s ", book[i]->isbn);
        printf("title: %s\n", book[i]->title);
    }

    return;
}

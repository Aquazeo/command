#include <stdio.h>
#include <stdlib.h> // free
#include <fcntl.h> // Include the header file that defines O_RDONLY
#include <unistd.h> // Include the header file that declares the close function
#include "book.h"

/* void read_info(struct Book **book, char *info, int *num)
{
    int input_desc;
    int file_open_mode = O_RDONLY;
    input_desc = open (info, file_open_mode);
    if (input_desc == -1)
    {
        perror("cannot read info");
        exit(1);
    }

    ssize_t n_bytes_read;
    *num = 0;
    struct Book temp;
    n_bytes_read = read(input_desc, &temp, sizeof temp);
    while ( (n_bytes_read = read(input_desc, &temp, sizeof temp)) > 0) // Read the file until the end
    {
        if (n_bytes_read == -1)
        {
            perror("read error");
            exit(1);
        }
        (book[*num]) = malloc(sizeof(struct Book));
        *(book[*num]) = temp;
        (*num) ++;
    }
    book[*num] = NULL;

    close (input_desc);
    
    return;
}

void print_info(struct Book **book, char *new_info, int *num)
{
    int output_desc;
    int file_open_mode =  O_WRONLY | O_CREAT | O_TRUNC;
    output_desc = open (new_info, file_open_mode, 0644);
    if (output_desc == -1)
    {
        perror("cannot write info");
        exit(1);
    }

    for (int i = 0; book[i] != NULL; i ++ )
    {
        ssize_t bytes_written = write(output_desc, book[i], sizeof(struct Book));
        if (bytes_written == -1)
        {
            perror("write error");
        }
    }

    close (output_desc);
    
    return;
} */

void read_info(struct Book **book, char *info, int *num)  
{  
    int input_desc = open(info, O_RDONLY);  
    if (input_desc == -1)
    {  
        perror("cannot read info");  
        exit(1);  
    }  
  
    ssize_t n_bytes_read;  
    *num = 0;  
    struct Book temp;  
    while ((n_bytes_read = read(input_desc, &temp, sizeof(temp))) > 0)
    {  
        if (n_bytes_read == -1)
        {  
            perror("read error");  
            exit(1);  
        }  
        book[*num] = malloc(sizeof(struct Book));  
        if (book[*num] == NULL) {  
            perror("malloc error");  
            exit(1);  
        }  
        *(book[*num]) = temp;  
        (*num)++;  
    }  
    book[*num] = NULL;  
  
    close(input_desc);  
}  
  
void print_info(struct Book **book, char *new_info, int *num)  
{  
    int output_desc = open(new_info, O_WRONLY | O_CREAT | O_TRUNC, 0644);  
    if (output_desc == -1)
    {  
        perror("cannot write info");  
        exit(1);  
    }  
  
    for (int i = 0; book[i] != NULL; i++)
    {  
        ssize_t bytes_written = write(output_desc, book[i], sizeof(struct Book));  
        if (bytes_written == -1)
        {  
            perror("write error");  
            exit(1);  
        }  
    }  
  
    close(output_desc);  
}

void free_books(struct Book **book, int *num)
{
    for (int i = 0; i < (*num); i++)
    {
        free(book[i]);
        book[i] = NULL;
    }
    
    return;
}

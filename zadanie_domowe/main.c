#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_AUTHOR 30
#define MAX_TITLE 50
#define MAX_CATEGORY 40

typedef struct {
    char author[MAX_AUTHOR + 1];
    char title[MAX_TITLE + 1];
    char category[MAX_CATEGORY + 1];
    float price;
    int page_count;
    int read_status;
    int shelf;
} Book;

int is_valid_author(const char *author) {
    if (strlen(author) > MAX_AUTHOR) {
        printf("B³¹d: Nazwa autora musi mieæ maksymalnie %d znaków.\n", MAX_AUTHOR);
        return 0;
    }
    for (int i = 0; i < strlen(author); i++) {
        if (!isalnum(author[i]) && author[i] != '_') {
            printf("B³¹d: Nazwa autora mo¿e zawieraæ tylko litery, cyfry i znak '_'.\n");
            return 0;
        }
    }
    return 1;
}

int is_valid_title(const char *title) {
    if (strlen(title) > MAX_TITLE) {
        printf("B³¹d: Tytu³ musi mieæ maksymalnie %d znaków.\n", MAX_TITLE);
        return 0;
    }
    return 1;
}

int is_valid_category(const char *category) {
    const char *valid_categories[] = {"young-adult", "fantasy", "crime", "reportage", "romance"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(category, valid_categories[i]) == 0) {
            return 1;
        }
    }
    printf("B³¹d: Nieprawid³owa kategoria.\n");
    return 0;
}

int is_valid_price(float price) {
    if (price <= 0) {
        printf("B³¹d: Cena musi byæ liczb¹ wiêksz¹ od zera.\n");
        return 0;
    }
    return 1;
}

int is_valid_page_count(int page_count) {
    if (page_count <= 0) {
        printf("B³¹d: Liczba stron musi byæ liczb¹ ca³kowit¹ wiêksz¹ od zera.\n");
        return 0;
    }
    return 1;
}

int is_valid_read_status(int read_status) {
    if (read_status != 0 && read_status != 1) {
        printf("B³¹d: Status przeczytania musi wynosiæ 0 (nie) lub 1 (tak).\n");
        return 0;
    }
    return 1;
}

int is_valid_shelf(int shelf) {
    if (shelf < 1 || shelf > 5) {
        printf("B³¹d: Numer rega³u musi wynosiæ od 1 do 5.\n");
        return 0;
    }
    return 1;
}

int is_valid_book(Book *book) {
    return is_valid_author(book->author) && is_valid_title(book->title) && is_valid_category(book->category) &&
           is_valid_price(book->price) && is_valid_page_count(book->page_count) && is_valid_read_status(book->read_status) &&
           is_valid_shelf(book->shelf);
}

int is_valid_file_format(FILE *file) {
    if (file == NULL) {
        printf("B³¹d: Nie uda³o siê otworzyæ pliku.\n");
        return 0;
    }
    return 1;
}

int is_valid_filename(const char *filename) {
    if (strlen(filename) > 100 || strlen(filename) == 0) {
        printf("B³¹d: Nazwa pliku jest zbyt d³uga lub pusta.\n");
        return 0;
    }
    return 1;
}

int is_author_in_books(Book books[], int n, const char *author) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].author, author) == 0) {
            return 1;
        }
    }
    return 0;
}

void load_books(const char *filename, Book books[], int *n) {
    FILE *file = fopen(filename, "r");
    if (!is_valid_file_format(file)) {
        exit(1);
    }

    fscanf(file, "%d", n);
    if (*n > MAX_BOOKS) {
        printf("B³¹d: Przekroczono maksymaln¹ liczbê ksi¹¿ek (%d).\n", MAX_BOOKS);
        fclose(file);
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        fscanf(file, "%30s %50s %40s %f %d %d %d",
               books[i].author, books[i].title, books[i].category,
               &books[i].price, &books[i].page_count, &books[i].read_status,
               &books[i].shelf);

        if (!is_valid_book(&books[i])) {
            printf("B³¹d danych ksi¹¿ki: %s | %s. Dane zosta³y zignorowane.\n", books[i].author, books[i].title);
            (*n)--;
            i--;
        }
    }

    fclose(file);
}

void display_books(Book books[], int n) {
    if (n == 0) {
        printf("Brak ksi¹¿ek do wyœwietlenia!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%s | %s | %s | %.2f | %d | %d | %d\n",
               books[i].author, books[i].title, books[i].category,
               books[i].price, books[i].page_count, books[i].read_status,
               books[i].shelf);
    }
}

void save_read_books(Book books[], int n, const char *filename) {
    if (!is_valid_filename(filename)) {
        return;
    }

    FILE *file = fopen(filename, "w");
    if (!is_valid_file_format(file)) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (books[i].read_status == 1) {
            fprintf(file, "%s %s %s %.2f %d %d %d\n",
                    books[i].author, books[i].title, books[i].category,
                    books[i].price, books[i].page_count, books[i].read_status,
                    books[i].shelf);
        }
    }

    fclose(file);
}

void most_expensive_unread_book_by_author(Book books[], int n, const char *author) {
    if (!is_author_in_books(books, n, author)) {
        printf("Brak ksi¹¿ek tego autora!\n");
        return;
    }

    int max_index = -1;
    float max_price = 0.0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].author, author) == 0 && books[i].read_status == 0) {
            if (books[i].price > max_price) {
                max_price = books[i].price;
                max_index = i;
            }
        }
    }
    if (max_index != -1) {
        printf("Najdro¿sza nieprzeczytana ksi¹¿ka autora %s:\n", author);
        printf("%s | %s | %s | %.2f | %d | %d | %d\n",
               books[max_index].author, books[max_index].title,
               books[max_index].category, books[max_index].price,
               books[max_index].page_count, books[max_index].read_status,
               books[max_index].shelf);
    } else {
        printf("Brak nieprzeczytanej ksi¹¿ki autora %s\n", author);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int n;

    load_books("library.txt", books, &n);

    printf("Zawartoœæ biblioteki:\n");
    display_books(books, n);

    char filename[100];
    printf("\nPodaj nazwê pliku do zapisania przeczytanych ksi¹¿ek: ");
    scanf("%s", filename);
    save_read_books(books, n, filename);

    char author[MAX_AUTHOR + 1];
    printf("\nPodaj autora do wyszukania: ");
    scanf("%s", author);
    most_expensive_unread_book_by_author(books, n, author);

    return 0;
}

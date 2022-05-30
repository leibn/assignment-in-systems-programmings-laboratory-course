#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



void* safe(const void* res) {
    if (res == NULL) {
        fprintf(stderr, "Out of memory!");
        exit(-1);
    }
    return res;
}

typedef struct { 
    char* str; 
    int length;
    int al_num;
    int memory; 
} String;

const int INIT_MEM = 6;

String new_String() {
    return (String) { safe(malloc(INIT_MEM * sizeof(char))), 0, 0, INIT_MEM };
}

void free_String(String* s) { 
    free(s->str);

    *s = (String){ NULL, 0, 0, 0 };
}

void increase_memory(String* s) { 
    s->memory = s->memory * 3 / 2;
    s->str = safe(realloc(s->str ,s->memory * sizeof(char)));
}

void add_char(String* s, char c) {

    if (s->length+1 == s->memory) {
	increase_memory(s);
    }

    s->str[s->length] = c;
    if(c != '\0')
        s->length++;
    if (isalnum(c))
        s->al_num++;
}

void scan(String* s) { 
    char c;
    while ( (c = getchar()) != '?') {
        add_char(s, c);
    }
    add_char(s, '\0');
}

const int LINE_LENGTH = 80;
int need_new_line(char cur, int line_length) {
    return cur == '\n' || (!isalnum(cur) && line_length > LINE_LENGTH);
}

void print(const String* s) { 

    int line_length = 0;
    const char* ptr;
    for ( ptr = s->str; ptr != '\0'; ptr++) { 

        if (*ptr == '\t') {
            line_length += 4;
            putchar(*ptr);
        }
        if (need_new_line(*ptr, line_length)) {
            line_length = 0;
            putchar('\n');
        }
        else if (isprint(*ptr)) {
            line_length++;
            putchar(*ptr);
        }

    }
}

int main() {
    puts("Enter char list:");
    String s = new_String();
    scan(&s);

    puts("Char list entered: ");
    print(&s);

    printf("\nNumber of characters: %i\n", s.length);
    printf("Number of alpha-numeric characters: %i\n", s.al_num);

    free_String(&s);
    return 0;
}

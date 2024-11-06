#include <stdio.h>
#include <stddef.h>

struct s {
    char a;       // Assume this is a 1-byte character
    int b;        // Assume this is a 4-byte integer
    double c;     // Assume this is an 8-byte double
};

int main() {
    // Print sizes of each member
    printf("Size of member 'a': %zu bytes\n", sizeof(((struct s *)0)->a));
    printf("Size of member 'b': %zu bytes\n", sizeof(((struct s *)0)->b));
    printf("Size of member 'c': %zu bytes\n", sizeof(((struct s *)0)->c));

    // Print offsets of each member
    printf("Offset of member 'a': %zu bytes\n", offsetof(struct s, a));
    printf("Offset of member 'b': %zu bytes\n", offsetof(struct s, b));
    printf("Offset of member 'c': %zu bytes\n", offsetof(struct s, c));

    // Print size of the entire structure
    printf("Total size of structure 's': %zu bytes\n", sizeof(struct s));

    return 0;
}

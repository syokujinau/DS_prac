#include <stdio.h>

struct list {
    char *name;
    struct list *nextPtr;
};

typedef struct list List;

int main(void)
{
    List a, b, c, *startPtr;

    a.name = "John";
    b.name = "Mary";
    c.name = "Tony";

    startPtr = &a;
    a.nextPtr = &b;
    b.nextPtr = &c;
    c.nextPtr = NULL;

    while (startPtr != NULL) {
        printf("%s\n", startPtr->name);
        startPtr = startPtr->nextPtr;
    }

    return 0;
}
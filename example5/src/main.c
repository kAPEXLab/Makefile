#include <stdio.h>
#include "hello.h"
#include "add.h"

int main() {
    print_hello();
    printf("Addition result = %d\n", add(4,5));
    return 0;
}
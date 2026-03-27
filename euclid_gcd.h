//
// Created by neo on 3/27/26.
//

#ifndef ALGORITHMS_EUCLID_GCD_H
#define ALGORITHMS_EUCLID_GCD_H
#include <cstdio>
int main(void) {
    unsigned long a, b;
    if (scanf("%d %d", &a, &b) == 2)   // == 2 guarantees both were read
    {
        printf("You entered: a = %d, b = %d\n", a, b);
    }
    else
    {
        fprintf(stderr, "Error: expected two integers.\n");
        return 1;
    }
    while (1)
    { //checks if two integers are read
        if (a < b) {
            const int tmp = a;
            a = b;
            b = tmp;
        }
        const int c = a % b;
        if (c == 0) {
            printf("%d\n", b);
            return 0;
        }
        a = b;
        b = c;
    }
}
#endif //ALGORITHMS_EUCLID_GCD_H
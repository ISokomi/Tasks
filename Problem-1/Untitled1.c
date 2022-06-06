#include <stdio.h>

int one(int n)
{
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            return 1;
        }
    }

    return 0;
}

int two(int n)
{
    for (int i = 2; i * i <= n; i++) {
        int k = 0;

        if (n % i == 0) {
            while (n % i == 0) {
                k++;
                n /= i;
            }

            if (i % 4 == 3 && k % 2 == 1) {
                return 0;
            }
        }
    }

    if (n % 4 == 3) {
        return 0;
    }

    return 1;
}

int three(int n)
{
    while (n % 4 == 0) {
        n /= 4;
    }

    if (n % 8 == 7) {
        return 0;
    }

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (one(n)) {
        printf("1");
    }
    else if (two(n)) {
        printf("2");
    }
    else if (three(n)) {
        printf("3");
    }
    else {
        printf("4");
    }

    return 0;
}

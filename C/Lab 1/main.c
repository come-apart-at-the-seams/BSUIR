

#include <stdio.h>

int fun(int num) {
    int a, a1, a2, a3, res;
    if (num < 1000 && num>99) {
        a = num / 100;
        a1 = num / 10 % 10;
        a2 = num % 10;
        res = a * a1 * a2;
        printf("res is: %d", res);
        return res;
    }
    else if (num < 10000 && num > 999) {
        a = num / 1000;
        a1 = num / 100 % 10;
        a2 = num / 10 % 10;
        a3 = num % 10;
        res = a + a1 + a2 + a3;
        printf("res is: %d", res);
        return res;
    }
    else printf("The number does not belong to the domain of definition\n");
    return 0;
}

int main()
{
    int num = 1;

    printf("Enter your number: ");
    scanf("%d", &num);
    fun(num);
    return 0;
}

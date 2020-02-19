#include <stdio.h>
#include <math.h>

/*
 * The function returns the value of its integer argument 'x'
 * after it rotates to the right by 'n' binary digits.
 */

int rightroot(int x, int n);

int main()
{
    printf("%d\n", rightroot(1, 1)); /* test */

    return 0;
}

int rightroot(int x, int n)
{
    int save_bits = 0;
    int take_bit = 1;
    int initial_var_n = n + 1;

    for (int i = 1; n != -1; i = i + 2, take_bit = 1) {
        take_bit = take_bit << n--;
        save_bits = save_bits | ((x & take_bit) << i);
    }

    save_bits = save_bits >> initial_var_n;

    x = x >> initial_var_n; /* start reset to zero 'n' right binary digits */
    x = x << initial_var_n; /* finish reset to zero 'n' right binary digits */

    return x = x | save_bits;
}
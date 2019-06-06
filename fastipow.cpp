#include "fastipow.h"

double ipow(double x, int n)
{
    double value = 1.0;

    if (!n)
        return 1.0; /* x^0 = 1 */

    if (n == 1)
        return x;

    if (x == 0.0)
        return 0.0; /* 0^n = 0 */

    if (n < 0)
    {
        n = -n;
        x = 1.0 / x;
    }

    do
    {
        if (n & 1) /* n is odd */
            value *= x;
        n >>= 1; /* n/2  */
        x *= x;
    } while (n);

    return value;
}
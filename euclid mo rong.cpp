#include <stdio.h>
/* Extended Euclidean algorithm for computing multiplicative inverses in modular structures */
long ModuloInverse(long a, long n) // a^-1 mod n
{
    long r, q, y, y0 = 0, y1 = 1, tmp=n;
    while(a > 0)
    {
        r = n % a;
        q = n / a;
        if(r == 0) break;
        y = y0 - y1 * q;
        n = a;
        a = r;
        y0 = y1;
        y1 = y;
    }

    if(a > 1)
        return -1; // GCD(a,n) # 1
    if(y>=0)
        return y; //a^-1 mod n = y mod n
    else
        return y+tmp; //a^-1 mod n = -y mod n = y+n mod n
}

int main()
{
	int a, b;
	scanf("%d %d",&a,&b);
    printf("%ld^-1 mod %ld = %ld\n", (long)a, (long)b, ModuloInverse(a,b)); //30^-1 mod 101 = 64
    return 0;
}
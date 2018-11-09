#include <stdio.h>

void do_things(long a[], long b[], long n, long r, long j)
{
    long i;
    if(n > 1){
        for(i = 1; i <= n; i++){
            if(i % 2 == r){
                b[a[i]] = j++;
            }
            else{
                a[i/2 + 1 -r] = a[i];
            }
        }
        do_things(a, b, n/2 + n%2 - r*(n%2), r^(n%2), j);
    }
    else if(n){
        b[a[1]] = j;
    }
}

int main()
{
    long input[100], n, i, t, output[100];
    scanf("%ld", &t);
    while(t--){
        scanf("%ld", &n);
        for(i = 1; i <= n; i++){
            input[i] = i;
        }
        do_things(input, output, n, 0, 1);
        for(i = 1; i <= n; i++){
            printf("%ld", output[i]);
            if(i != n){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
}

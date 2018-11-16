/*求两个结点的公共结点，根从1开始*/
#include <stdio.h>

int main()
{
    int x, y;
    while(scanf("%d%d", &x, &y)){
        while(x != y){
            if(x > y){
                x /= 2;
            }
            else{
                y /= 2;
            }
        }
        printf("%d\n", y);
    }
    return 0;
}

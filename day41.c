#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    char buf[100][5];
    char tmp1[10], tmp2[10], tmp[5];
    scanf("%d", &num);
    getchar();

    int i = 0;
    for(; i < num; i++){
        scanf("%s", buf[i]);
    }

    for(i = 0; i < num; i++){
        int j = 0;
        for(j = i+1; j < num; j++){
            strcpy(tmp1, buf[i]);
            strcat(tmp1, buf[j]);
            strcpy(tmp2, buf[j]);
            strcat(tmp2, buf[i]);
            if(strcmp(tmp1, tmp2) < 0){
                strcpy(tmp, buf[i]);
                strcpy(buf[i], buf[j]);
                strcpy(buf[j], tmp);
            }
        }
        printf("%s", buf[i]);
    }
    return 0;
}

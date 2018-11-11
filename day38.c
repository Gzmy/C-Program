/*
 * input:每组数据输入一个字符串，字符串最大长度为100，
 * 且只包含字母，不可能为空串，区分大小写
 * output:每组数据一行，按字符串原有的字符顺
 * 序，输出字符集合，即重复出现并靠后的字母不输出。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(char *str)
{
    char status[64] = {0};
    char ch, index;

    if(!str){
        return;
    }

    int i = 0;
    for(; i < strlen(str); i++){
        ch = str[i];
        if(ch >= 'a' && ch <= 'z'){
            index = ch - 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            index = ch - 'A';
        }
        if(0 == status[index]){
            printf("%c", ch);
            status[index] = 1;
        }
    }
    printf("\n");
}

int main()
{
    char input[101] = {0};
    while(scanf("%s", input) != EOF){
        func(input);
        memset(input, 0x00, 101);
    }
    return 0;
}

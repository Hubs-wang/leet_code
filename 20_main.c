/*
    注:--s_stack.top的使用需要注意, int char 能表示的数据长度
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 15000

struct stack
{
    char *arry;
    int top;
    int base;
};

int main()
{
    int i;
    char str[STACK_SIZE] = {"{()()()}[])"};
    struct stack s_stack;

    s_stack.base = s_stack.top = 0;
    s_stack.arry = (char *)malloc(STACK_SIZE);
    memset(s_stack.arry, 0, STACK_SIZE);

    if(strlen(str)%2 != 0)
    {
         printf("str is false _line:26\n");
         return 0;
    }

    for(i = 0; str[i] != '\0'; i++)
    {
        if((str[i] == '{') || (str[i] == '[') || (str[i] == '('))
        {
            s_stack.arry[s_stack.top] = str[i];
            s_stack.top++;
            continue;
        }

        if(s_stack.top == s_stack.base)
        {
            printf("str is false\n");
            free(s_stack.arry);
            return 0;
        }
        else   
        {
            if(str[i] == '}')
            {
                s_stack.top--;
                if((s_stack.arry[s_stack.top] == '{') && (s_stack.top == s_stack.base))
                {
                    s_stack.arry[s_stack.base] = 0;
                }
                else if(s_stack.arry[s_stack.top] == '{')
                {
                    s_stack.arry[s_stack.top] = 0;
                }
                else
                {
                    printf("str is false _line:53\n");
                    free(s_stack.arry);
                    return 0;
                }
            }
                    
            if(str[i] == ')')
            {
                s_stack.top--;
                if((s_stack.arry[s_stack.top] == '(') && (s_stack.top == s_stack.base))
                {
                    s_stack.arry[s_stack.base] = 0;
                }
                else if(s_stack.arry[s_stack.top] == '(')
                {
                    s_stack.arry[s_stack.top] = 0;
                }
                else
                {
                    printf("str is false _line:70\n");
                    free(s_stack.arry);
                    return 0;
                }
            }
            
            if(str[i] == ']')
            {
                s_stack.top--;
                if((s_stack.arry[s_stack.top] == '[') && (s_stack.top == s_stack.base))
                {
                    s_stack.arry[s_stack.base] = 0;
                }
                else if(s_stack.arry[s_stack.top] == '[')
                {
                    s_stack.arry[s_stack.top] = 0;
                }
                else
                {
                    printf("str is false _line:87\n");
                    free(s_stack.arry);
                    return 0;
                }
            }
                
        }
        
    }

    if(s_stack.top == s_stack.base)
    {
        printf("str is true\n");
        free(s_stack.arry);
    }
    else
    {
        printf("str is false\n");
        free(s_stack.arry);
    }
 
    return 0;

}
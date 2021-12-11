#include <stdio.h>

int main()
{
    char *str = NULL;
    char c;
    int sum = 0;

    str = "MCMXCIX";
    while(*str != '\0')
    {
        switch(*str)
        {
            case 'I' ://1
                if(*(str + 1) == 'V')
                {
                    sum += 4;
                    str++;
                    break;
                }
                else if(*(str + 1) == 'X')
                {
                    sum += 9;
                    str++;
                    break;
                }
                else
                {
                    sum += 1;
                    break;
                }
                    
            case 'V' ://5
                sum += 5;
                break;

            case 'X' ://10
                if(*(str + 1) == 'L')
                {
                    sum += 40;
                    str++;
                    break;
                }
                else if(*(str + 1) == 'C')
                {
                    sum += 90;
                    str++;
                    break;
                }
                else
                {
                    sum += 10;
                    break;
                }

            case 'L' ://50
                sum += 50;
                break;

            case 'C' ://100
                if(*(str + 1) == 'D')
                {
                    sum += 400;
                    str++;
                    break;
                }
                else if(*(str + 1) == 'M')
                {
                    sum += 900;
                    str++;
                    break;
                }
                else
                {
                    sum += 100;
                    break;
                }

            case 'D' ://500
                sum += 500;
                break;

            case 'M' ://1000
                sum += 1000;
                break;

            default:
                break;
        }
        str++;
    }
    printf("sum=%d\n", sum);

    return 0;
    
}
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[] )
{
    if(argc==2)
    if(atoi(argv[1]))
    {
        int test = atoi(argv[1]);
       // int x = &test;
       char c;
        string str = get_string("plaintext: ");
        int n = strlen(str);
        for(int i = 0; i < n; i++)
        {
            c = str[i];
            c=(c+test);
            if((c>=65 && c<=90) || (c>=97 && c<=122))
            {
                str[i]=c;
            }
            else
            {
                c = c - 26;
                str[i] = c;
            }

        }
        printf("ciphertext: %s\n", str);
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

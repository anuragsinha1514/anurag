#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

char pat[MAX_SIZE], str[MAX_SIZE];

int nfind(char *str, char *pat)
{
        int i, j, start = 0;
        int lasts = strlen(str) - 1;
        int lastp = strlen(pat) - 1;
        int endmatch = lastp;
        for(i = 0; endmatch<=lasts; endmatch++, start++)
        {
                if(str[endmatch] == pat[lastp])
                {
                        for(j=0,i=start;j<lastp && str[i] ==  pat[j]; i++, j++);
                }
                if (j == lastp) return start;
        }
        return -1;
}
void main()
{
        printf("Enter the string: ");
        scanf("%[^\n]%*c", str);
        printf("Enter the pattern to search: ");
        scanf("%[^\n]%*c", pat);
        int pos = nfind(str, pat);
        if (pos == -1)
                printf("Pattern not found in the given string.\n");
        else
                printf("Pattern found at %d.\n", pos+1);
}

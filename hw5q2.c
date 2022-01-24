#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
    This function gets the following parameters:
    string word- holds a word
    int start- starting index
    int end-ending index

    The function returns true if word between
    indexes stars and end is a palindrome or if start>=end
    otherwise returns false
**/
bool isPol(char *word,int start, int end)
{
    if(start>=end) return true;
    return word[start]==word[end]&&isPol(word,start+1,end-1);
}

int main()
{
    int length;
    printf("Enter the length of the array:\n");
    scanf("%d",&length);
    char *array=malloc(length);
    printf("Enter the array:\n");
    scanf("%s",array);
    if(isPol(array,0,length-1)) printf("A palindrome");
    else printf("Not a palindrome");
    free(array);
}

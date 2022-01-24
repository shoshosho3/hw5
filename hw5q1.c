#include <stdio.h>
#include <stdlib.h>

#define NOT_RECOMMENDED -1

void sort_sub(int array[],int length,int start,int helper[]);

/**
    This function gets the following parameters:
    int array- holds array
    int length- holds length of copyArray
    int start- starting index
    int array copyArray- holds array copied from

    This function copies copyArray from index start in array to array
**/
void copy_arr(int array[],int length,int start,int copyArray[])
{
    for(int i=start;i<length+start;i++) array[i]=copyArray[i-start];
}

/**
    This function gets the following parameters:
    int array- holds array
    int length- holds length of sub-array being sorted
    int start- starting index

    This function sorts sub-array from start to start+length-1
    from smallest to biggest
**/
void merge(int array[],int length,int start)
{
    if(length==1) return;
    merge(array,length/2,start);
    merge(array,length/2+length%2,start+length/2);
    int *helper=malloc(length*sizeof(int));
    sort_sub(array,length,start,helper);
    copy_arr(array,length,start,helper);
    free(helper);
}

/**
    This function gets the following parameters:
    int array- holds array
    int length- holds length of sub-array being sorted
    int start- starting index
    int array helper

    This function will insert sorted sub-array into helper
**/
void sort_sub(int array[],int length,int start,int helper[])
{
    int left_start=start,right_start=start+length/2;
    for(int i=0;left_start<start+length/2||right_start<start+length;i++)
    {
        if(right_start>=start+length||(array[left_start]<array[right_start]&&left_start<start+length/2))
        {
            helper[i]=array[left_start];
            left_start++;
        }
        else
        {
            helper[i]=array[right_start];
            right_start++;
        }
    }
}

/**
    This function gets the following parameters:
    int array- holds sorted array
    int length- length of array

    The function returns recommended number
    If there is no recommended number returns -1
**/
int recommended(int array[], int length)
{
    for(int i=0;i<length;i++)
    {
        if(array[i]>=length-i&&(i==0||length-i>array[i-1]))
            return length-i;
    }
    return NOT_RECOMMENDED;
}

int main()
{
    int length;
    printf("Enter the length of the array:\n");
    scanf("%d",&length);
    int *array=malloc(length*sizeof(int));
    printf("Enter the array:\n");
    for(int i=0;i<length;i++) scanf("%d",&array[i]);
    merge(array,length,0);
    int rec=recommended(array,length);
    if(rec==NOT_RECOMMENDED) printf("The array is not recommended\n");
    else printf("The array is recommended and x = %d",rec);
    free(array);
}

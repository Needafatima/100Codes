#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s1[10],s2[10];                 //Declaring the two input strings
    scanf("%s",s1);
    scanf("%s",s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int LCDtable[l1+1][l2+1],i,j;       //Declaring the LCD table of size length(s1)*length(s2)
    for(i=0;i<=l1;i++)
    {
        LCDtable[i][0]=0;               /*Initializing the first row and first column to zero as there can be*/
    }                                   /*no common sequence with length 0*/
    for(j=0;j<=l2;j++)
    {
        LCDtable[0][j]=0;
    }
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                LCDtable[i][j]=LCDtable[i-1][j-1]+1;        //If there is a match, then increment the cumulative sum
            }
            else
            {                                               //If no match, then copy the maximum neighboring value
                if(LCDtable[i-1][j]>LCDtable[i][j-1])
                {
                    LCDtable[i][j]=LCDtable[i-1][j];
                }
                else
                {
                    LCDtable[i][j]=LCDtable[i][j-1];
                }
            }
        }
    }
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            printf("%d ",LCDtable[i][j]);
        }
        printf("\n");
    }
    printf("The length of the longest common subsequence is: %d\n",LCDtable[l1][l2]);
    return 0;
}

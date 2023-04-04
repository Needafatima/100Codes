#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
 {
     if(n==1)
     {
         printf("Move disk 1 from %c to rod %c\n",from_rod,to_rod);
         return ;
     }
     tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
     printf("Move disk %d from %c to rod %c\n",n,from_rod,to_rod);
     tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
 }
int main()
{
    int n=10;
    clock_t start,end;
    double d;
    char from_rod,to_rod,aux_rod;
    start=clock();
    tower_of_hanoi(n,'A', 'C', 'B');
    end=clock();
    d=end-start;
    d=d/CLOCKS_PER_SEC;
    printf(" Time = %lf\n",d);
    return 0;
}

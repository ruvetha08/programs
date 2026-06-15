#include <stdio.h>
int main() {
    int r1,c1,i,j,n;
    printf("Enter the size of mat A ");
    scanf("%d%d",&r1,&c1);
    int A[r1][c1];
    printf("Enter the matrix");
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the num:");
    scanf("%d",&n);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(A[i][j]==n)
            {
                printf("Num found");
                return 1;
            }
            //return 0;
        }
    }
    printf("Num not found");
    return 0;
}

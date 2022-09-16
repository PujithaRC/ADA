#include<stdio.h>
int s[10][10];
void print(int i,int j)
{
    if(i==j)
        printf("A%d", i);
    else
    {
        printf("(");
        print(i,s[i][j]);
        print(s[i][j]+1,j);
        printf(")");
    }
}
void mul(int n, int d[])
{
    int diagonal,i,j,k,m[10][10],min,q;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    for(diagonal=1;diagonal<=n-1;diagonal++)
    {
        for(i=1;i<=n-diagonal;i++)
        {
            j=i+diagonal;
            min=999;
            for(k=i;k<=j-1;k++)
            {
                q=(m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j]);
                if(q<min)
                {
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    printf("The matrix is \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("The sum matrix is\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
    i=1;
    j=n;
    printf("The multiplication sequence is: ");
    print(i,j);
    printf("\n");
    printf("Minimum number of multiplications is %d\n", m[1][n]);
}
int main()
{
    int i,j,n,a[10][10],d[10];
    printf("Enter the number of matrices to be multiplied:\n");
    scanf("%d", &n);
   
    printf("Enter the order of each matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i=0,j=1;i<=n;i++,j++)
    {
        d[i]=a[j][1];
    }
    d[n]=a[n][2];
    mul(n,d);
}



//
//  main.c
//  Matrixce
//
//  Created by Eric Wei on 28/01/2020.
//  Copyright © 2020 Eric Wei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void add_matrices(int m1[100][100], int m2[100][100], int destination_matrix[100][100], int n_rows, int n_columns )
{
    int i;
    int j;
    
    printf("input the first matrix:");
    for(i=0;i<n_rows;i++)
    for(j=0;j<n_columns;j++)
    {
        printf("enter elements a%d%d:",i+1,j+1);
        scanf("%d",&m1[i][j]);
    }
    
    printf("iuput the second matrix:");
    for(i=0;i<n_rows;i++)
    for(j=0;j<n_columns;j++)
    {
        printf("enter elements a%d%d:",i+1,j+1);
        scanf("%d",&m2[i][j]);
    }
    
    
    {
        for(i=0;i<n_rows;i++)
        for(j=0;j<n_columns;j++)
        {
            destination_matrix[i][j]=m1[i][j]+m2[i][j];
        }
    }
    
    
    printf("sum of two matrix:");
    for(i=0;i<n_rows;i++)
    for(j=0;j<n_columns;j++)
        {
        printf ("%d",destination_matrix[i][j]);
        if(j==n_columns-1)
            {
              printf ("\n");
            }
        }
}
int main()
{
    int m1[100][100],m2[100][100],destination_matrix[100][100],n_rows,n_columns;
    printf("enter the number of rows:");
    scanf("%d",&n_rows);
    printf("enter the number of coloumns:");
    scanf("%d",&n_columns);
    add_matrices(m1, m2, destination_matrix, n_rows,n_columns);
    return 0;
    
}


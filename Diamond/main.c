//
//  main.c
//  Diamond
//
//  Created by Eric Wei on 16/01/2020.
//  Copyright © 2020 Eric Wei. All rights reserved.
//


//diamond


#include <stdio.h>

 int main()
{
    int row;
    int space;
    int r;
    int star;
    printf("Input number of rows:");
    scanf("%d",&r);
    //upper triangle
    for(row=0;row<=r;row++)
    {
     for(space=1;space<=r-row;space++)
     printf(" ");
     for(star=1;star<=2*row-1;star++)
     printf("*");
       
       
     printf("\n");
    }
    for(row=r-1;row>=1;row--)
      {
        for(space=1;space<=r-row;space++)
        printf(" ");
        for(star=1;star<=2*row-1;star++)
          printf("*");
        printf("\n");
      }
 return 0;
}

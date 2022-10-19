//
//  main.c
//  my_strcpy
//
//  Created by Eric Wei on 28/01/2020.
//  Copyright © 2020 Eric Wei. All rights reserved.
//

#include <stdio.h>

void my_strcpy(char src[], char dst[])

{
    int i = 0;
     while (src[i]!='\0')
       {
           dst[i]=src[i];
           i++;
       }
    
}

int main()
{
    char src[10000], dst[10000];
    printf("Input src string:");
    scanf("%s",src);
    my_strcpy(src,dst);
    printf("src:%s\n",src);
    printf("dst:%s\n",dst);
    
}

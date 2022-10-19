//
//  main.c
//  My_strcmp
//
//  Created by Eric Wei on 04/02/2020.
//  Copyright © 2020 Eric Wei. All rights reserved.
//

#include <stdio.h>

int my_strcmp(char s1[], char s2[])
{
   int i=0 ;
   while (s1[i]==s2[i])
   {
       
    if ( s1[i]=='\0' || s2[i]=='\0')
        break;
    i++;
   }
    if ( s1[i]=='\0' && s2[i]=='\0')
        return 1;
    else
        return 0;
}

int main()
{   int a;
    char s1[100], s2[100];
    printf("input s1 string:");
    scanf("%s",&s1);
    printf("input s2 string:");
    scanf("%s",&s2);
    a= my_strcmp(s1,s2);
    if ( a == 1)
    printf ("The two words are the same.");
    else
    printf("The two words are not the same.");
}

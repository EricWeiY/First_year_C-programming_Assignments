//
//  main.c
//  Network
//
//  Created by Eric Wei on 04/02/2020.
//  Copyright © 2020 Eric Wei. All rights reserved.
//

#include <stdio.h>
#include <string.h>

struct record
{
    char username[100]; //array indicates the name of user
    int usernumber; //array indicates the usernumber
    int friendnumber; // array indicates the friend number
    int relationship[100];
}list;


int main()
{
    int a,b,i,number=0,j;  // define the variables
    char name1[100]="0";   // arrays used to store user names which is empty
    char name2[100]="0";   // arrays used to store user names which is empty
    struct record library[100];
    
    printf("1.introduce a new user:\n");
    printf("2.introduce the relationship:\n");
    printf("3.print the report:\n");
    printf("4.exit\n");
    printf("Enter option number:\n");
    scanf("%d",&a);
    
    while (a!=4)
    {
        switch(a)
        {
            case 1:
            
                printf("input name:\n");
                scanf("%s",library[number].username);
                library[number].usernumber=number+1; // when we input a user, usernumber increase 1
                library[number].friendnumber=0; // friend number remains the same no change
                number++;
                break;
            
                
            case 2:
            
                printf("input first name:\n");
                scanf("%s",name1);
                for(i=0;i<number;i++)
                {
                    if(strcmp(library[i].username,name1)==0) //if this name equals the name in the storage
                    {
                        printf("record first name\n");
                        printf("input second name:\n");
                        scanf("%s",name2);
                        for(j=0;j<number;j++)
                        {
                            if(strcmp(library[j].username,name2)==0) // second name is equal to the one in another storeage
                            {
                                printf("second name is recorded\n");
                                library[i].friendnumber++;
                                library[j].friendnumber++;  // both friend name increase 1
                            
                            }
                        }
                    }
                        break;
                }
                break;
            
            case 3:
            
                printf("report:\n");
                for(b=0;b<number;b++)
                {
                    printf("name:\n");
                    printf("%s\n",library[b].username);
                    printf("user number:\n");
                    printf("%d\n",library[b].usernumber);
                    printf("Friend number:\n");
                    printf("number:%d\n",library[b].friendnumber);

                }
              
            
        }
        printf("\n1:introduce a new user\n");
        printf("2:Introduce the relationship\n");
        printf("3:Print the report\n");
        printf("4:exit\n");
        printf("Enter option number:\n");
        scanf("%d",&a);
    }
    return 0;
}


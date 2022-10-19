//
//  main.c
//  Calculator
//
//  Created by Eric Wei on 20/01/2020.
//  Copyright © 2020 Eric Wei. All rights reserved.
//

#include <stdio.h>
#include <math.h>

//average function
float avg(float a, float b, float c)
{
    float avg;
    avg = (a+b+c)/3;
    return avg;
}



//function for pi
float calculate_pi(int n)
{
    float i,m,j,q,pi,k;
// for loop of pi
    for(i=1;i<=2*n-1;i+=2)
    {
        j=-1;
        q=1;
       
        for(k=0;k<=((i+1)/2);k++)
        {
            q=q*j;
        }
        m=q*4/i;
        pi = pi + m;
    }
    return pi;
}



int square_root(int x)
{
    int o;
    int answer;
    for(o=1;o<=x;o++)
    {
        if(o*o==x)
        {
            answer=o;
            break;
        }
        else
        {
            answer=-1;
        }
    }
        return answer;
    
    
}


//opreation menu
    int main()
    {
        float pi;
        int n;
        int option;
        
        
        
        
        printf("\nInput your option :\n");
        printf("1-Average.\n2-Gregory-Leibniz series.\n3-Square root.\n4-Exit.\n");
        scanf("%d",&option);

        switch (option)
        {
            case 1:
            {
                float a,b,c,result;
                printf("input 1st number:");
                scanf("%f",&a);
                printf("input 2nd number:");
                scanf("%f",&b);
                printf("input 3rd number:");
                scanf("%f",&c);
            
                result=avg(a,b,c);
                printf("average of these value is %f \n",result);
                break;
            }
        
                //operating pi_calculate function
                case 2:
            {
                printf("input number:\n");
                scanf("%d",&n);
            
                pi=calculate_pi(n);
                printf("the value is %f,\n",pi);
                break;
            }
                
                //square root
                case 3:
            {
                int x;
                int answer;
                printf("input the value:");
                scanf("%d",&x);
                answer=square_root(x);
                printf("the square root of this number is %d\n",answer );
                break;
            }
                default:
                printf("Exit to the menu.\n");
                return 0;
        }
        return 0;
        
              
    }
    
            
            
            

    


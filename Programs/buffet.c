/* Filename: buffet.c *                                                                
 * Part of: A590 Program 1*                                                       
 * Created by: Chi Zhang *                                                             
 * Created on: 1/11/24 *                                                               
 * Last Modified by: Chi Zhang*
 * Last Modified on: 1/22/24 *
 */

#include <stdio.h>

int main()

{   // The following lines print the size of each data type
    printf("sizeof(char) == %zu\n", sizeof(char));
    printf("sizeof(short) == %zu\n", sizeof(short));
    printf("sizeof(int) == %zu\n", sizeof(int));
    printf("sizeof(long) == %zu\n", sizeof(long));
    printf("sizeof(float) == %zu\n", sizeof(float));
    printf("sizeof(double) == %zu\n", sizeof(double));
    printf("sizeof(long double) == %zu\n", sizeof(long double));
    printf("sizeof(long long) == %zu\n", sizeof(long long));


    //Now we declare 6 variables of different data types
    int x, y;
    char a;
    float f, e;
    double d;

    //Then we initialize the 6 variables

    x = 4;
    y = 7;
    a = 'H';
    f = -3.4;
    d = 54.123456789;
    e = 54.123456789;

    //Now we print the values of the 6 variables, but with different % control
    printf("%d %c %f %lf\n", x, a, e, d);
    printf("%d %c %f %.9lf\n", x, a, e, d);

    //Then we declare 5 more variables of int type
    int r1, r2, r3, r4, r5;

    //Now we try arithmetic operations and print the results
    r1 = x + y;
    r2 = x - y;
    r3 = x/y;
    r4 = x*y;
    printf("%d %d %d %d\n", r1, r2, r3, r4);

    //Now we perform 3 more arithmetic operations and print the results
    r3++;
    r4--;
    r5=r4%r1;
    printf("%d %d %d\n", r3, r4, r5);


    //Now we modify the program from Hoover to find two numbers whose squares add up to a given number

    int i, j, number;

    printf("Enter a number: ");
    scanf("%d", &number);
    i=1;
    while (i*i <= number)
    {
       j = 1;
         while (j <= i)
         {
             if (i*i + j*j == number)
                printf("Found: %d + %d\n", i*i, j*j);
             j++;
         }
        i++;
    }

    return(0);
}






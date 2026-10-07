/* Filename: callingfunc.c *                                                                
 * Part of: A590 Program 2*                                                       
 * Created by: Chi Zhang *                                                             
 * Created on: 1/31/24 *                                                               
 * Last Modified by: Chi Zhang*
 * Last Modified on: 1/31/24 *
 */
#include <stdio.h>

//This is the function that contains the loops
void loops(void){

    int i, x;
    x = 0;

    // for loop: runs from i=0 to i<4, incrementing i by 1 each time
    printf("This is a \"for\" loop\n");

    for (i=0; i< 4; i++){
        x += i;
        printf("%d\n", x);

    }

    // while loop: runs while i is less than 7, incrementing i by 1 each time, i starts at 3
    printf("This is a \"while\" loop\n");
    while (i < 7){
        x  += i;
        i++;
        printf("%d\n", x);
    }

    printf("This is a \"do-while\" loop\n");
    
    // do-while loop: runs while i is less than 9, incrementing i by 1 each time, i starts at 6
    do{
        x += i;
        i++;
        printf("%d\n", x);
    } while (i < 9);

}

//This is the function that contains the conditionals
void conditionals(void){
    int i, x;

    x = 0;

    // if-else conditional: runs 5 times, incrementing x by 1 each time, if i is even or i is 1, otherwise decrement x by 1
    for (i=0; i<5; i++){
        if (i%2 == 0 || i == 1)
            x +=i;
        else
            x -=i;
        printf("%d\n", x);
    }

    printf("This is a \"switch-case\" conditional\n");
    // switch-case conditional: takes the value of grade and prints the corresponding letter grade
    int grade;
    printf("Input Grade: [5=A, 4=B, 3=C, 2=D, 1=F]\n");
    scanf("%d", &grade);
    //switch-case conditional: takes the value of grade and prints the corresponding letter grade
    switch (grade)
    {
        case 1:
            printf("Fail (F)\n");
            break;
        case 2:
            printf("Not Good (D)\n");
            break;
        case 3:
            printf("Good (C) \n");
            break;
        case 4:
            printf("Very Good (B)\n");
            break;
        case 5:
            printf("Excellent (A)\n");
            break;
        default:
        printf("You have not input a valid grade value.\n");
            break;
    }
}

//This is the function that rearranges the first 5 cells of an array
void firstswap(void) {

    //we declare the variables i, j, k, and swap
    int i, j, k, swap;
    //we declare the array c with 8 cells
    char c[8];
    //we initialize the first 5 cells of the array with the letters f, r, o, g, and 0
    c[0] = 'f';
    c[1] = 'r';
    c[2] = 'o';
    c[3] = 'g';
    c[4] = 0;

    printf("Initial values for first 5 cells: %c, %c, %c, %c, %c\n", c[0], c[1], c[2], c[3], c[4]);

    //we go through the array from the first cell to the 4th cell
    for (i=0; i<4; i++){
        //k is a temporary variable that holds the value of i
        k =i;

        //we go through the array from the next cell to the 4th cell
        for (j = i+1; j< 4; j++){
            //if the letter in the jth cell is before or less than 10 letters after the letter in the ith cell in the alphabet, we set k to j
            //otherwise we keep k as i
            if (c[j]-c[k] < 10)
            k = j;
        //if the condition (c[j]-c[k] < 10) is true, we swap the values of c[i] and c[j], if not, we keep the values as they are
        swap = c[i];
        c[i] = c[k];
        c[k] = swap;
        } 
    }
    printf("Final values: i: %d, j: %d, k: %d, swap: %d\n", i, j, k, swap);

    printf("Final values for first 5 cells after we swap: %c, %c, %c, %c, %c\n", c[0], c[1], c[2], c[3], c[4]);
}

int main(void){
    printf("THIS IS MY LOOPS FUNCTION.\n\n");
    // calling the loops() function
    loops();
    printf("THIS IS MY CONDITIONALS FUNCTION.\n\n");
    // calling the conditionals() function
    conditionals();
    printf("THIS IS MY FIRST ARRAY FUNCTION.\n\n");
    // calling the firstswap() function
    firstswap();
    return(0);
}
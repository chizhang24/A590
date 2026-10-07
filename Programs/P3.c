/* Filename: P3.c *                                                                
 * Part of: A590 Program 3*                                                       
 * Created by: Chi Zhang *                                                             
 * Created on: 2/16/24 *                                                               
 * Last Modified by: Chi Zhang*
 * Last Modified on: 2/16/24 *
 */


#include <stdio.h>
#include <string.h>
#include <math.h>


void bitmodel(void); //function prototype of bitmodel()
void pointers(void); //function prototype of pointers()
void morepointers(void); //function prototype of morepointers()
int division(int numerator, int denominator, int *dividend, int *remainder); //function prototype of division()
void pointerarithmetic(void); //function prototype of pointerarithmetic()
void pointerarry(void); //function prototype of pointerarry()   



int main(void){

    //call the bitmodel() function
    bitmodel();

    //call the pointers() function
    pointers();
    //call the morepointers() function
    morepointers();

    //declare variables to be passed to the division() function
    int x, y, d, r;

    //initialize x and y
    x = 9;
    y = 2;
    //print the addresses of d and r
    printf("address of d: %u\n", &d);
    printf("address of r: %u\n", &r);
    
    //call the division() function
    division(x, y, &d, &r);
    printf("%d/%d = %d with %d remainder\n", x , y, d, r);
    //print the value of x
    printf("x = %d\n", x);

    //call the pointerarithmetic() function
    pointerarithmetic();
    //call the pointerarry() function
    pointerarry();
    return(0);
}

void bitmodel(void){

    unsigned char a;
    unsigned char b, c;
    unsigned char d, e;
    char f;
    int i;

    //bitwise NOT
    a = 19;
    a = ~a;
    printf("bitwise NOT of 19\n");
    printf("%d\n", a);

    //bitwise AND
    b = 19;
    c = 30;
    b = b & c;
    printf("bitwise AND of 19 and 30\n");
    printf("%d\n", b);
    //bitwise OR
    d = 19;
    e = 30;
    d = d | e;
    printf("bitwise OR of 19 and 30\n");
    printf("%d\n", d);

    //Set bit #3 in 19
    f = 19;
    f = f | (1 << 3);
    printf("Sets bit #3 in 19, new value is 19 + 9 = 27\n");
    printf("%d\n", f);
    
    
    //Clear bit #4 in 27
    f = f & (~(1 << 4));
    printf("Clears bit #4 in 27, new value is 27 - 16 = 11\n");
    printf("%d\n", f);

    //Reads i-th bit in current value of f = 11
    printf("Reads i-th bit in current value of f = 11, \n plus a loop that prints every bit in 8-bit space\n");
    for (i = 7; i >= 0; i--){
        printf("%d", (f & (1 << i)) >> i);
    }
    printf("\n");

}


void pointers(void){

    int count, x;
    int *count_p;
    char letter;
    char *letter_p= &letter;


    count = 10;
    count_p = &count;
    x = *count_p;

    printf("Here is the step-by-step output from the integre pointer example\n");

    //We print the value of count, x, and *count_p
    printf("count = %i and x = %i and *count_p = %i\n", count, x, *count_p);

    //We change the value of count_p to 42, but not the value of count
    *count_p = 42;
    printf("count = %i and x = %i and *count_p = %i\n", count, x, *count_p);


    //We change the value of count to x, but not the value of count_p
    count = x;
    printf("count = %i and x = %i and *count_p = %i\n", count, x, *count_p);


    letter = 'Q';

    printf("Here is the step-by-step output from the character pointer example\n");
    //We print the value of letter and *letter_p
    printf("letter = %c and *letter_p = %c\n", letter, *letter_p);
    
    //We change the value of *letter_p to '/'
    letter = '/';
    printf("letter = %c and *letter_p = %c\n", letter, *letter_p);

    //We change the value of *letter_p to '!'
    *letter_p = '!';
    printf("letter = %c and *letter_p = %c\n", letter, *letter_p);
}

void morepointers(void){

    int firsti, secondi;
    int *firsti_p, *secondi_p;
    //initialize firsti and firsti_p
    firsti = 5;
    firsti_p = &firsti;

    //initialize secondi and secondi_p using firsti_p
    secondi = *firsti_p / 2 + 10;
    secondi_p = &secondi;

    printf("Here is the ouput from the first integer pointer example\n");

    printf("firsti = %i, secondi = %i, value of firsti_p = %i, value of secondi_p = %i\n", firsti, secondi, *firsti_p, *secondi_p);
}

//This function takes in two integers and two pointers to integers, 
//and changes the values of the pointers to the quotient and remainder of the two integers
int division(int numerator, int denominator, int *dividend, int *remainder){
    

    printf("address stored in dividend: %u\n", dividend);
    printf("address stored in remainder: %u\n", remainder);
    if (denominator < 1)
        return(0);
    //change the values of the pointers to the quotient and remainder of the two integers
    *dividend = numerator / denominator;
    *remainder = numerator % denominator;
    numerator = 7;
}



void pointerarithmetic(void){
    //declare an array of characters and an array of integers, and their pointers
    char ca[3], *cp;
    int ia[3], *ip;

    //initialize the arrays and their pointers
    ca[0] = 'A';
    ca[1] = 'B';
    ca[2] = 'c';
    //cp points to the first element of ca
    cp = &(ca[0]);

    //initialize the arrays and their pointers
    ia[0] = 1234;
    ia[1] = 5678;
    ia[2] = 9999;
    //ip points to the first element of ia
    ip = &(ia[0]);

    //print the values of the pointers and the arrays
    printf("char pointer cp points to value = %c\n", *cp);
    printf("ca[2] = %c\n", ca[2]);
    printf("int pointer ip points to value = %i\n", *ip);
    printf("ia[2] = %i\n", ia[2]);

    //apply pointer arithmetic to change the values of the pointers and the arrays
    *(cp+2) = 'Q';
    *(ip+2) = 33;

    //print the values of the pointers and the arrays after we apply pointer arithmetic
    printf("Results after we apply pointer arithmetic\n");
    printf("ca[2] = %c\n", ca[2]);
    printf("ia[2] = %i\n", ia[2]);
}

void pointerarry(void){
    //declare an array of doubles and a pointer to a double
   double array[10];
   double *d_ptr;
   
   //declare variables to be used in the while loop
   double value;
   int i, offset;

   //initialize the array 
   for (i = 0; i<10; i++){
    array[i] = (double)i + 10.0;
    d_ptr = &(array[0]);
   }

    while (1){
        //print the addresses of the elements of the array and their values
        printf("\nAddress(hex)\tAddress(base10)\tValue\n");
        for (i = 0; i<10; i++)
            printf("%p\t%u\t%lf\n", &(array[i]), &(array[i]), array[i]);
        
        //prompt the user to enter an offset value and a value
        printf("Enter offset value (0 0 to quit): ");
        scanf("%d %lf", &offset, &value);

        //break the loop if the user enters 0 0
        if (offset == 0 && value == 0.0)
            break;
        //change the value of the element of the array at the given offset
        if (offset < 0 || offset > 9){
            printf("Offset out of bounds\n");
            continue;
        }
        //change the value of the element of the array at the given offset
        *(d_ptr + offset) = value;
    }
}
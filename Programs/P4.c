/* Filename: P4.c *                                                                
 * Part of: A590 Program 4*                                                       
 * Created by: Chi Zhang *                                                             
 * Created on: 2/24/24 *                                                               
 * Last Modified by: Chi Zhang*
 * Last Modified on: 2/24/24 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



// declare the structure person, which contains 4 members
struct person {
    char first[32];
    char last[32];
    int year;
    double ppg;
};
//this is the function prototype for DisplayStats
void DisplayStats(struct person);






// declare the structure NODE, which is a linked list
struct NODE {
    int number;
    struct NODE *next;
};
//this is the function prototype for inserting a node at the end of the list
void append_node(struct NODE *llist, int num);

//this is the function prototype for deleting a node from the list
void delete_node(struct NODE *llist, int num);

//this is the function prototype for searching for a node in the list
int search_node(struct NODE *llist, int num);

//this is the function prototype for displaying the list
void display_list(struct NODE *llist);

//this is the function prototype for printing the menu
void print_menu(void);
int main(void){
    //declare an array of 55 person structures
    struct person class[54];

    //initialize the first 7 elements of the array
    class[0].year = 2004;
    class[0].ppg = 5.2;
    //use strcpy to copy the first and last names into the array
    strcpy(class[0].first, "Jane");
    strcpy(class[0].last, "Doe");

    class[1].year = 2005;
    class[1].ppg = 4.9;
    strcpy(class[1].first, "Brian");
    strcpy(class[1].last, "Smith");

    class[2].year = 2006;
    class[2].ppg = 6.1;
    strcpy(class[2].first, "Sue");
    strcpy(class[2].last, "Jones");


    class[3].year = 2007;
    class[3].ppg = 5.5;
    strcpy(class[3].first, "Tom");
    strcpy(class[3].last, "Brown");

    class[4].year = 2008;
    class[4].ppg = 6.3;
    strcpy(class[4].first, "Mary");
    strcpy(class[4].last, "Davis");

    class[5].year = 2009;
    class[5].ppg = 5.8;
    strcpy(class[5].first, "John");
    strcpy(class[5].last, "Wilson");

    class[6].year = 2010;
    class[6].ppg = 6.2;
    strcpy(class[6].first, "Linda");
    strcpy(class[6].last, "Martinez");

    //display the first 7 elements of the array
    int i;
    for(i = 0; i < 7; i++){
        DisplayStats(class[i]);
    }

    // num is the value to be inserted, input is the menu choice, retval is the return value from search_node
    int num = 0;
    int input = 1;
    int retval = 0;

    //declare a pointer to a NODE structure
    struct NODE *llist;


    //initialize the linked list
    llist = (struct NODE *)malloc(sizeof(struct NODE));
    //initialize the first node in the list to 0
    llist->number = 0;
    //initialize the next pointer to NULL
    llist->next = NULL;


    //while the user does not choose to quit
    while (input != 0){
        //print the menu and get the user's choice
        print_menu();
        scanf("%d", &input);
        switch(input){
            //if the user chooses to quit, free the memory and exit the program
            case 0:
                printf("Goodbye ...\n");
                input = 0;
                break;
            //if the user chooses to insert a value, get the value and call the append_node function
            case 1:
                printf("Your choice: 'Insertion'\n");
                printf("Enter the value which should be inserted: ");
                scanf("%d", &num);
                append_node(llist, num);
                break;
            //if the user chooses to delete a value, get the value and call the delete_node function
            case 2:
                printf("Your choice: 'Deletion'\n");
                printf("Enter the value which should be deleted: ");
                scanf("%d", &num);
                if((retval = search_node(llist, num)) == -1)
                printf("Value '%d' not found\n", num);
                else
                delete_node(llist, num);
                break;
            //if the user chooses to search for a value, get the value and call the search_node function
            case 3:
                printf("Your choice: 'Search'\n");
                printf("Enter the value you want to find: ");
                scanf("%d", &num);
                if((retval = search_node(llist, num)) == -1)
                    printf("Value '%d' not found\n", num);
                else
                    printf("Value '%d' located at position '%d'\n", num, retval);
                break;
            //if the user chooses to display the list, call the display_list function
            case 4:
                printf("You choice: 'Display'\n");
                display_list(llist);
                break;

            //if the user chooses an invalid option, print an error message
            default:
                printf("That is not a valid menu option\n");
                break;

        }
    }
    //free the memory
    free(llist);
    return 0;


}

//this function takes a person structure as input and prints the values of the members
void DisplayStats(struct person Input){
 printf("%s, %s: %lf PPG in %d\n", Input.last, Input.first, Input.ppg, Input.year);
}
//this function takes a NODE structure as input and appends a new node to the end of the list
void append_node(struct NODE *llist, int num) {
    //while the next pointer is not NULL, move to the next node
    while(llist->next != NULL)
        llist = llist->next;
    //allocate memory for the new node and set the number and next pointer
    llist->next = (struct NODE *)malloc(sizeof(struct NODE));
    //set the number and next pointer
    llist->next->number = num;
    //set the next pointer to NULL
    llist->next->next = NULL;
}

//this function takes a NODE structure as input and deletes a node from the list
void delete_node(struct NODE *llist, int num) {
    //declare a temporary NODE structure
    struct NODE *temp;
    //if the first node is the one to be deleted, set the next pointer to the next node and free the memory of the first node
    temp = (struct NODE *)malloc(sizeof(struct NODE));
    
    if(llist->number == num) {
        //set the next pointer to the next node
        temp = llist->next;
        //free the memory of the first node
        free(llist); 
        //set the first node to the next node
        llist = temp;
    } 
    else {
        //while the next node is not the one to be deleted, move to the next node
        while(llist->next->number != num)
            //move to the next node
            llist = llist->next;
        //set the next pointer to the next node
        temp = llist->next->next;
        //free the memory of the node to be deleted
        free(llist->next); 
        //set the next pointer to the next node
        llist->next = temp;
    }
}

//this function takes a NODE structure as input and searches for a node in the list
int search_node(struct NODE *llist, int num) {
    //declare a return value
    int retval = -1;
    int i = 1;

    //while the next pointer is not NULL, move to the next node
    while(llist->next != NULL) {
        //if the next node is the one we are looking for, set the return value and break the loop
        if(llist->next->number == num)
            return i;
        //if the next node is not the one we are looking for, move to the next node
        else
        //increment the counter
            i++;
        //move to the next node
        llist = llist->next;
    }
    return retval;
}


//this function takes a NODE structure as input and displays the list
void display_list(struct NODE *llist) {
    //while the next pointer is not NULL, print the number and move to the next node
    while(llist->next != NULL) {
        printf("%d ", llist->number);
        llist = llist->next;
    }
    //print the number of the last node
    printf("%d", llist->number);
}

//this function prints the menu
void print_menu(void){
 printf("\n-- Menu Selection --\n");
 printf("0) Quit\n");
 printf("1) Insert\n");
 printf("2) Delete\n");
 printf("3) Search\n");
 printf("4) Display\n");
}
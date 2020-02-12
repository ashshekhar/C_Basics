////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmpsc311-f16-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMPSC311, Spring 2020, at Penn State.
//                   assignment page for details.
//
//  Author         : Shashwat Shekhar
//  Last Modified  : Feb 5, 2020; 8PM EST
//

//  Include Files
#include <stdio.h>
#include <string.h>

#define NUM_TEST_ELEMENTS 100


//**********************************************************************************************************************************************************************
//                                                                    Prototype Declarations of all Functions

int round311(float f_array[], int i_array[]);
int printfloatArr311( float ptr[], int size );
int printIntArr311( int ptr[], int size );
int bubbleSort311( int ptr[], int size );
int toBinary(char num);
int countRange311(float ptr[], int size, int min, int max) ;
int histogram311(int arr[]);



/////////////////////////////////////////////////////////////////////////////Main Function/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function     : main
// Description  : The main function for the CMPSC311 assignment #1
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char **argv) 
{

    /* Local variables */
    float f_array[NUM_TEST_ELEMENTS];
    int i_array[NUM_TEST_ELEMENTS], i;
    int hist_array[10];                     // Declare an array of 10 integers at the top of the main function




    /* Preamble information */
    printf( "CMPSC311 - Assignment #1 - Spring 2020\n\n" );

//**********************************************************************************************************************************************************************

    // Step #1 - read in the float numbers to process
    for (i=0; i<NUM_TEST_ELEMENTS; i++) 
    {
        scanf("%f", &f_array[i]);
    }

//**********************************************************************************************************************************************************************

    /* Step #2 - Alter the values of the float array as follows: all 
    even numbered indices of the array should be multiplied by 0.78 
    if the value is greater than 50 and 1.04 otherwise.  All odd valued
    indices should multiplied by 0.92 if the value is greater than 50 
    and 1.15 otherwise */

    for(int j=0; j<NUM_TEST_ELEMENTS;j++)
    {
        
        if((j%2 == 0))                  // Even indices case
        {               
            if(f_array[j]>50)
            {
                f_array[j]=f_array[j]*0.78;
            }

            else
            {
                f_array[j]=f_array[j]*1.04;
            }
           
        }

        else
        {                        
            if(f_array[j]>50)           //Odd indices case
            {
                f_array[j]=f_array[j]*0.92;
            }

            else
            {
                f_array[j]=f_array[j]*1.15;
            }
        }
    }

//**********************************************************************************************************************************************************************

    /* Step #3 - Round all of the values to integers and assign them 
    to i_array using the round311 function */

    ////////////////////////////////////////////////////////////////////////////////
    
    // Function     : round311
    // Description  : The function that rounds a floating point number to the nearest integer, where we round up 
    //                if the value to the right of the decimalplace is 0.5 or higher
    //
    // Inputs       : No inputs; (void)
    // Outputs      : 0 if successful test, -1 if failure

    int round311(float f_array[], int i_array[])
    {
        
        float y; // Variable to hold the decimal part of float numbers


        for(int k=0; k<NUM_TEST_ELEMENTS; k++)
        {
            y = f_array[k] - (int)f_array[k];       // Using concept of conversion of data types

            if(y>=0.5)
            {
                i_array[k] = (int)f_array[k]+1;    // Integer part rounded up and edited in the i_array
            }
            else
            {
                i_array[k] = (int)f_array[k];       // Integer part remains the same and updated in the i_array
            } 

        
        }

        return ( 0 );
    }
    round311(f_array, i_array);                         // Calling the round311 function

//**********************************************************************************************************************************************************************
   
    /* Step #4 - Print out all of the floating point numbers in the 
    array in order on a SINGLE line.  Each value should be printed 
    with 2 digits to the right of the decimal point. */
    printf( "Testing printfloatArr311 (floats): " );
    printfloatArr311( f_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

//**********************************************************************************************************************************************************************
    
    // Step #5 - Print out all of the integer numbers in the array in order on a SINGLE line. 
    printf( "Testing 311 (integers): " );
    printIntArr311( i_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

//**********************************************************************************************************************************************************************
    
    // Step #6 - Sort the integer values, print values 
    printf( "Testing bubbleSort311 (integers): " );
    bubbleSort311( i_array, NUM_TEST_ELEMENTS );
    printIntArr311( i_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

//**********************************************************************************************************************************************************************
   
    // Step #7 - Print out the last 5 values of the integer array in binary. 
    printf( "Testing toBinary:\n" );

    for (i=NUM_TEST_ELEMENTS-6; i<=NUM_TEST_ELEMENTS-1; i++) 
    {
        toBinary((char)i_array[i]);       // Calling the function toBinary
    }
    printf("\n\n");


//**********************************************************************************************************************************************************************

    /* Step #8 - Declare an array of integers. Fill the array with a count (times three) of the number of values for each 
    set of tens within the floating point array, i.e. index 0 will contain the count of rounded values in the array 0-9, the
    second will be 10-19, etc. */


    for (int i=0,l=0;(i<100&&l<10); i+=10,l++)
    {
        hist_array[l]= countRange311(f_array,NUM_TEST_ELEMENTS,i,i+9);       // Filling in the new integer array hist_array[10] with the count
    }

//*********************************************************************************************************************************************************************

    // Step #9 - Call of the histogram311 Function 
    histogram311(hist_array);

//*********************************************************************************************************************************************************************

    // Exit the program successfully 
    printf( "\n\nCMPSC311 - Assignment #1 - Spring 2020 Complete.\n" );         
    return( 0 );
}

//**********************************************************************************************************************************************************************

//Step #4 - printfloatArr311 Function

////////////////////////////////////////////////////////////////////////////////

// Function     : printfloatArr311
// Description  : The function prints all of the values of a float array, comma separated, no trailing comma and a newline at the end
//
// Inputs       : ptr - a pointer to an array of floats
//                size - integer type size of an array
// Outputs      : 0 if successful test, -1 if failure

int printfloatArr311( float ptr[], int size ) // Printing the contents of an array comma separated
{
    for(int i=0;i<size;i++)            // * is used if we have an integer since we can't index it.  Otherwise, for arrays, arr[] is same as *arr.
    {
        printf("%.2f",ptr[i]);
        
        if(i!=(size-1))
        {
            printf("%s",", ");      // Printing out the comma-separation
        }   
    }

    printf("\n");               // Newline at the end

    return ( 0 );
    
}

//**********************************************************************************************************************************************************************

//Step #5 - printIntArr311 Function

////////////////////////////////////////////////////////////////////////////////

// Function     : printIntArr311
// Description  : The function prints all of the values of an integer array, comma separated and, trailing comma and a newline at the end
//
// Inputs       : ptr - a pointer to an array of integers
//                size - integer type size of an array
// Outputs      : 0 if successful test, -1 if failure

int printIntArr311( int ptr[], int size )  // Printing the contents of an array comma-separated 
{ 

    for(int i=0;i<size;i++)
    {
        printf("%d",ptr[i]);
        
        if(i!=(size-1))
        {
            printf("%s",", ");
        }   
    }

    printf("\n");               // Newline at the end

    return ( 0 );              

}

//**********************************************************************************************************************************************************************

//Step #6 - bubbleSort311 Function

////////////////////////////////////////////////////////////////////////////////

// Function     : bubbleSort311
// Description  : The function will sort the array of integers passed as a parameter (as a pointer)
//
// Inputs       : ptr - a pointer to an array of integers
//                size - integer type size of an array
// Outputs      : 0 if successful test, -1 if failure


int bubbleSort311( int ptr[], int size ) // Bubble Sort algorithm to sort the array passed as parameter in ascending order (low to high)
{  

    for(int i=1;i<size-1;i++) // Since if the array is of length say 4, we need to keep swapping until the largest number bubbles to the top 
    {                         // and that will take 3 swap checks before that happens, therefore i goes from 1 to size-2
        for(int j=0;j<=size-2;j++)  
        {

            if(ptr[j]>ptr[j+1])
            {
                int temp = ptr[j+1]; // Swapping if term being checked is greater than its adjacent term, in order to allow the greater term to bubble to the top/right
                ptr[j+1] = ptr[j];
                ptr[j] = temp;
            }

        }

    }

    return ( 0 );

}


//**********************************************************************************************************************************************************************

//Step #7 - toBinary Function

////////////////////////////////////////////////////////////////////////////////

// Function     : toBinary
// Description  : The function receives an integer and prints out its value in binary with spaces every nibble (receives 8 bits)
//
// Inputs       : num - char type byte input to be converted to binary
// Outputs      : 0 if successful test, -1 if failure


int toBinary(char num)                     
{
    int i = 0;                      // integer to store the value of the largest power of 2 <= num
    int temp;                       // temporary integer to store the value of the num
    int new_num = (int)num;         // integer to store the integer casting of the char num received in the parameter

    temp = new_num;
    int bin_array[8] = {0};     // Array that will store the binary converted value of the integer new_num, initialized with all 0s

    while(temp>=2)              // Step 1 - Finding the largest power of i such that 2 raised to the power 1 <= num
    {
        temp = temp/2;
        i++;
    }                
    int k = 7;
    int count = 0;              // Some integers needed to keep a count of number of bits printed
    int counter = 0;


    while (i>=0 && k>-1)             // Step 2 - Printing out integer num in its binary form
    {   
        if(new_num>=(1<<i))          // Since 1<<n is same as raising 2 to the power of n
        {  
            bin_array[k] = 1;
            new_num = new_num - (1<<i);
            k--;    
            count++;
        }

        else
        {
            bin_array[k] = 0;
            k--;
            count++;
        }

        i = i-1;                    // Step 3 - End
    }

    int number = 8-count;           //  Last requirement - pattern printing - spaces afer every nibble
    for (int i=0;i<number;i++)
    {
        if(counter%4==0 && counter!=0)
        {
            printf(" ");
            printf("%s","0");
            counter++;
        }
        else
        {
            printf("%s","0");
            counter++;
        }
    }

    for(int j=7;j>7-(count);j--)
    {
        if(counter%4==0)
        {
            printf(" ");
            printf("%d",bin_array[j]);
            counter++;
        }
        else
        {
            printf("%d",bin_array[j]);
            counter++;
        }
 
    }

    printf("\n");


    return ( 0 );
}

//**********************************************************************************************************************************************************************

//Step #8 - countRange311 Function

////////////////////////////////////////////////////////////////////////////////

// Function     : countRange311
// Description  : The function will return the number of elements (after rounding) between min and max (inclusive) and is used to fill out a new integer with the
//                counts returned by this function
//
// Inputs       :  ptr - a reference to an array of floating point values
//                 size - integer indicating how many elements are there in the array
//                 min - the lower range (integer)
//                 max - the upper range (integer)
// Output       :  count: integer type variable which is equal to the number of elements betweem min and max in ptr[]

int countRange311(float ptr[], int size, int min, int max)     
{
    int count = 0;                          // integer to count the number of elements that lie in between max and min given

    for(int i = 0; i<size; i++)             // First count the number of elements in the array that lie between indices min and max and return that after rounding.
    {
        if((ptr[i] - (int)ptr[i]) >= 0.5)
        {
            int temp = ptr[i] + 1;


            if(temp >=min && temp <= max)
            {
                count++;
            }
        }
        else
        {
            int tempo = ptr[i];
            if(tempo >=min && tempo <= max)
            {
                count++;
            }

        }
    }
    return (count);
}

//**********************************************************************************************************************************************************************

//Step #9 - histogram311 Function

////////////////////////////////////////////////////////////////////////////////

// Function     : histogram311
// Description  : This function receives a reference to an array of integer values and prints out a histogram showing the counts of different values
//                In case the number of elements are not equal to 10, just return a -1
//
// Inputs       : arr - Integer type array, the histogram of which is to be displayed
// Outputs      : 0 if successful test, -1 if failure
 

int histogram311(int arr[]) 
{
    
// The first part of the function should check if the new integer array has all the 10 values first of all, if not straight away return a -1
// In case a -1 is returned, the program won't print any histogram
    
    int count = 0;                      // integer to count the number of elements in the given array

    for(int i = 0; i<10; i++)           // To check if the given array arr[] has 10 elements or not  
    {
        if(arr[i]!='\0');               // Check if the array elements contain '\0' (null character)
        count++;
    }


    if (count != 10)
    {
        return(-1);             // No  histogram will be displayed
    }

    else                    // Displaying the histogram of int arr[] if this integer array contains 10 elements
    {
        int prnt = 19;

        for(int j=0;j<22;j++)  // Traversing every row
        {
            if(j==0 || j==21)       // Printing the basic structure around the histogram
            {
                printf("%s","  +");

                for(int i=0;i<40;i++)
                {
                    printf("%s","-");
                }
                printf("%s\n","+");
            }

            else
            {
                if(prnt>9)
                {
                    if(prnt%5==0)       // Displaying the  '...' at certain positions in the histogram
                    {
                        printf("%d",prnt);
                        printf("%s","|.");
                        prnt--;
                    }
                    else
                    {
                        printf("%d",prnt);
                        printf("%s","| ");
                        prnt--;
                    }

                }

                else
                {
                    if(prnt%5==0)           // Printing out the y-axis values
                    {
                        printf("%s","0");
                        printf("%d",prnt);
                        printf("%s","|.");
                        prnt--;
                    }
                    else
                    {
                        printf("%s","0");
                        printf("%d",prnt);
                        printf("%s","| ");
                        prnt--;
                    }

                }

            
                for(int k=0;k<10;k++)       // Traversing every element of the int array in order to extract their values
                {
                    if((prnt+1)%5==0)
                    {
                        if((prnt+1)<=arr[k])    // If element in array <= row number, print xx..
                        {
                            if(k!=9)
                            {
                                printf("%s","xx..");
                            }
                            else
                            {
                                printf("%s","xx.");
                            }
                            
                        }
                        else
                        {
                            if(k!=9)
                            {
                                printf("%s","....");
                            }
                            else
                            {
                                printf("%s","...");
                            }
                            
                        }
                    }

                    else
                    {
                        if((prnt+1)<=arr[k])    // If element in array <= row number, print xx
                        {
                            if(k!=9)
                            {
                                printf("%s","xx  ");
                            }
                            else
                            {
                                printf("%s","xx ");
                            }
                            
                        }
                        else
                        {
                            if(k!=9)
                            {
                                printf("%s","    ");

                            }
                            else
                            {
                                printf("%s","   ");
                            }
                            
                        }

                    }
    
                }
                
                printf("%s\n","|"); 
            }

        }

        printf("%s","     00  10  20  30  40  50  60  70  80  90 \n");       // Printing out the x axis
        }               
        
    return ( 0 );
}

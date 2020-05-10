# C Programming Basics

## Introduction

You are to complete the assign1-cmpsc311-sp20 program. The assign1-cmpsc311-sp20 program receives an array of floating point values, one per line and executes a number of operations and functions. Complete the code in the 

```
assign1-cmpsc311-sp20.c
``` 

per the instructions below. The code should:

### Step #1 

Read in the float numbers to process from standard input (this is done for you, so you don't need to add code). Note that there will be exactly `NUM_TEST_ELEMENTS` elements read.

### Step #2 

Alter the values of the float array as follows: all even numbered indices of the array should be multiplied by 0.78 if the value is greater than 50 and 1.04 otherwise. All odd valued indices should multiplied by 0.92 if the value is greater than 50 and 1.15 otherwise.

### Step #3

Create a function `round311` that rounds a floating point number to the nearest integer, where you round up if the value to the right of the decimal place is 0.5 or higher. Round all of the values of the floating point array to integers (but do not alter the original value in the floating point array) and assign the rounded values to the same index of the i_array using the round311 function.

### Step #4

Create a function `printfloatArr311` that prints all of the values of an array, comma separated (with no trailing comma and newline at the end). The function should receive as parameters a pointer to an array of floats and a size of the array (integer). Each value should be printed with exactly 2 digits to the right of the decimal point.

### Step #5

Create a function `printIntArr311` that prints all of the values of an array, comma separated (with no trailing comma and newline at the end). The function should receive as parameters a pointer to an array of integers and a size of the array (integer). Print out all of the floating point numbers in the array in order on a SINGLE line using the `printfloatArr311` function.

### Step #6 

Write a bubble sort function `bubbleSort311` that receives a pointer to an array of integers and a size of the array (integer). An example of the algorithm can be found here. Pass the integer array `i_array` into the function and sort it. The function should receive as parameters a pointer to an array of integers and a size of the array (integer). Use `printIntArr311` to print out the array as in the previous step.

### Step #7 

Create a function `toBinary` that receives a byte (char) and prints is value out in binary (with spaces every nibble). Print out the first 5 values if i_array using this function.

### Step #8 

Create a function `countRange311` that receives reference to an array of floating point values, a integer indicating how many elements are in the array and a int minimum and maximum values. The function will return the number of elements (after rounding) between min and max (inclusive). Next, declare an array of 10 integers at the top of the main function. Fill the array with a count  of the number of values for each set of tens within the floating point array, i.e. index 0 will contain the count of rounded values in the array `0-9 >TIMES THREE`, the second will be 10-19, etc. all the way to 90-99. Use the `countRange311` to fill the array.

### Step #9

Create a function `histogram311` that receives a reference to an array of integer values calculated in the previous step and prints out a histogram showing the counts of the different values. The Y-axis should display count values from 0-19. The function should check the number of elements and return with a -1 value if it is not 10. Otherwise, the function should create a histogram indicating the numbers calculated in Step #8 above.

## Submission Guidelines

Add comments to all of your files stating what the code is doing. Fill out the comment function header for each function you are defining in the code. A sample header you can copy for this purpose is provided for the main function in the code. It is very important that your code is neat and legible. You will be penalized if your code is difficult to read.

The assignment starter package also includes a sample input test-large.txt and output test-output1.txt which you can use to test your program. The assign1-sample-output.txt file was input used to produce test-large.txt. To test your program with these inputs, run the code and pipe in the input file to the program as follows:

```
make && ./assign1-cmpsc311-sp20 < test-large.txt
```

Please try to make the output for your program as close to that of the test program output.

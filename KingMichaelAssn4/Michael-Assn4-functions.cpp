//*****************************************************************************
// FILE NAME: Michael-assn4-funcs.cpp
// DESCRIPTION: This file contains Shawn Michael's  definitions for assn 4
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: Shawn Michael
//
// FUNCTIONS:
//
//
//
//            Display -
//
//
//
//            Header - Program title
//*****************************************************************************

using namespace std;
#include <iostream>      //cin and cout
#include <iomanip>       //setprecion, setw
#include <cstddef>       // used for assigning NULL
#include <cctype>	     //for cctype predefined functions
#include <ctime>			//for time seed in srand function
#include <cstdlib>			//for c standard library predefined functions

#include "Michael-assn4-funcs.h"
#include "Michael-common.h"

void bubbleSort(int list[], int length)
{
    int temp;
    int iteration;
    int index;

    for (iteration = 1; iteration < length; iteration++){
        for(index = 0; index < length - iteration; index++) {
            if (list[index + 1] < list[index]){
                temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }  // end if
        } //end for
    } //end for
}


//*****************************************************************************
// FUNCTION: selectionSort
// DESCRIPTION: function performs a selection sort algorithm
// INPUT: static array
//      Parameters: staticArray[] - static random array
//                  length - input value from user for the array size
//
// OUTPUT: void
//      Return Val: void
// CALLS TO: N/A
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
void insertionSort(int list[], int length)
{
    int i,
        j,
        key;

    for (j = 1; j < length; j++ ){
        key =list[j];

        // insert list[j] into sorted sequence
        i = j - 1;
        while ((i >= 0) && (list[i] > key)){
            list[i + 1] = list[i];
            i--;
        }
        list[i + 1] = key;
    }
}


int parition(int list[], int first, int last)
{
    int x,
        i,
        j,
        temp;

    x = list[last - 1];
    i = first - 1;
    for(j = 0; j < last; j++){
        if (list[j] <= x){
            i++;
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    temp = list[i + 1];
    list[i + 1] = list[last - 1];
    list[last - 1] = temp;

    return i++;
}



 //*****************************************************************************
// FUNCTION: CreateDynamArray
// DESCRIPTION: creates a dynamic array
// INPUT: Array Size
//      Parameters: int aSize, int* aPtr
// OUTPUT: returns pointer to top of the array[]
//      Return Val: array *ptr
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
int* CreateDynamArray(int aSize)
{
    int* aPtr;

    aPtr = new (nothrow) int[aSize];
    if (aPtr != NULL) {
        for (int i = 0; i < aSize; i++) {
            aPtr[i] = 0;    // Initialize all elements to NULL
        }  //end for
    } //end if
    return aPtr;
}
//*********************************************************************
// FUNCTION: PopArray()
// DESCRIPTION: Function populates a dynamic array with random unsorted
//              integers acquired via two called functions
// INPUT:
// Parameters: int randArray[] - static array to hold random numbers
// OUTPUT:
// Return Val: N/A
// Parameters: int randArray[] - populated and returned to main
// File: N/A
// CALLS TO: Random(),
// IMPLEMENTED BY: Shawn Michael
//**********************************************************************
void PopArrays(int list1[], int list2[])
{
	int counter = 0;	    //counter to control input into static array
	int rNum;				//int variable to hold random number

	//seed to ensure randomized values on each execution
	srand(time(NULL));

	//while statement executes until first array is full
	while (counter != ARRAY_SIZE){

		//function calls for random number and duplicate search
		rNum = Random();
		list1[counter] = rNum;
		list2[counter] = rNum;
		counter++;
	}//end while
}

//*********************************************************************
// FUNCTION: Random()
// DESCRIPTION: Function uses the rand function to generate random
//              numbers
// INPUT:
// Parameters: N/A
// OUTPUT:
// Return Val: rNum - random integer created by rand function
// Parameters: N/A
// File: N/A
// CALLS TO: N/A
// IMPLEMENTED BY: Shawn Michael
//**********************************************************************
int Random()
{
	int rNum;			//int variable to hold randomly generated number

	//random number generation
	rNum = (rand() % MAX_ARRAY_NUM) + 1;

	return rNum;
}

//*****************************************************************************
// FUNCTION: DisplayMenu
// DESCRIPTION:
// INPUT:
//      Parameters:
//
// OUTPUT: Void
//      Return Val: no returns
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
void DisplayMenu()
{
    cout << "\tChoose Two sorts you with to compare: " << endl;
    cout << "\t\tB = Bubble sort\n";
    cout << "\t\tI = Insertion sort\n";
    cout << "\t\tM = Merge sort\n";
    cout << "\t\tQ = Quick sort\n";
    cout << "\t\tE = Exit program\n";
}

//*****************************************************************************
//  FUNCTION:	  Header
//  DESCRIPTION:  Intro of program
//  INPUT:        Parameters:  void
//
//  OUTPUT: 	  Return value: no returns
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
void Header()
{
    cout << "\n\t*********************************************************";
    cout << "\n\t|                                                       |";
    cout << "\n\t|              Sorting Analysis Program                 |";
    cout << "\n\t|    A program to analyze performance of different      |";
    cout << "\n\t|     sort types such as Bubble, Insertion, Merge       |";
    cout << "\n\t|                  and Quick.                           |";
    cout << "\n\t|                                                       |";
    cout << "\n\t*********************************************************";
    cout << endl << endl << endl;
}


/*
void sortSelection (int* &rtnfunc, string &testType, char sel)
{
    switch (sel) {
        case 'B':
            testType = "Bubble sort";
            *rtnfunc = &bubbleSort;
            break;

        case 'I':
            testType = "Insertion sort";
            rtnfunc = &selectionSort;
			break;

        case 'M':
            testType = "Merge sort";
            rtnfunc = &mergeSort;
            break;

        default:
            testType = "quickSort";
            rtnfunc = &bubbleSort;
			break;
    } // end switch
}
*/
Enter file contents here

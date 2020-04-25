/* Mustafa Aru - 30716006
Question NO 3. Using any of the sorting algorithms, sort following array such that, the odd
numbers will be sorted first and then the even numbers will be sorted. Also write a
function to display the results.*/

#include <iostream>
#include <stdio.h>

using namespace std;


void MergeAgain(int arr[], int l, int m, int r) {
    int nl = m - l + 1 ; // How many elements left side 
    int nr = r - m; //How many elements right side
    
    int L[nl];
    int R[nr];
    
    for (int a = 0; a < nl; a++) { 
        	L[a] = arr[l+a]; //Filling the array
    }
    
    for (int b = 0;  b<nr; b++){
        	R[b] = arr[b + m + 1]; //Filling the array
    }

    int i = 0; // Initial index of first subarray 
    int j = 0; // Initial index of second subarray 
    int k = l; // Initial index of merged subarray
    
    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            k++;
        } //End of if
        else {
            arr[k] = R[j];
            j++;
        	k++;
        }//End of else 
    }//End of while
    
    //Remaining must the last
    while (i < nl) {
        arr[k] = L[i];
        k++;
        i++;
    }
    
    while (j<nr) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
} //Enf of MergeAgain

void OrderNumbers(int arr[], int l, int r){
	//Logic: Array is shorted already, start left even then look next odd. Change them.
	
	int index_even = 99, index_odd = 99; //For initial values	
	for(int iteration = 0 ; iteration< r-1 ; iteration++){ //For iterations
		for(int i = 0 ; i <= r ; i++){ //For Searching all
			if(arr[i]%2 == 0){ //if even number
				index_even = i;	//Backup the index of even
			}
			
			else if(arr[i]%2 != 0){ //Odd
				index_odd = i;//Backup the index of odd
			}
			
			if(index_odd < index_even){
				 // Swap the numbers.
		        int temp = arr[index_odd] ;
		        arr[index_odd] = arr[index_even];
		        arr[index_even] = temp;
			}
		} //End of for searching
	} //End of iteration
}

void MergeShort(int arr[], int l, int r) {	
    if (l < r) { //Base candition
        int m = (r+l) / 2; //Midpoint
        //Left Side
        MergeShort(arr, l, m); 
        //Right Side
        MergeShort(arr, m + 1, r);
        //Merge them all
        MergeAgain(arr, l, m, r);
    }
}

void Display(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 0,7,4,2,3,9,8,5,6 };
    int size_array = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Question : Sort the array / Even numbers first - Odd numbers next." << endl;
    
    cout << "Original Array: " <<endl;
    Display(arr, size_array);
    
	cout << "Shorted and Even/Odd Ordered Array: " << endl;
    MergeShort(arr, 0, size_array-1); //Shorting
    OrderNumbers(arr, 0,size_array-1); //Order events and odds
    Display(arr, size_array);
    
    return 0; 
}


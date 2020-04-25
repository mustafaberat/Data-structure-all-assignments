/* Mustafa Aru - 30716006
Question No. 2 Implement Quick Sort for sorting an integer array by using the last element
as pivot. Also display the results for each step in the recursive function call.
*/

#include <iostream>
using namespace std;


void printArray(int *arr , int n){
	for(int i=0 ; i<n ; i++){
		cout << arr[i] <<" ";
	}
	cout << endl << endl;
}

void quickSort(int *arr, int left, int right , int const_arr_size){
	if(left >= right)		
		return;
	
	printArray(arr, const_arr_size); //arr_size is constant - right is changed thats why we cant use it
	
	int pivot = arr[right]; // Last element is pivot
	int temp, i = left , j = right;
	
	while(i<=j){
	
		while(arr[i] < pivot)	i++; //Jumping i until finding bigger than
		while(arr[j] > pivot)	j--; //Jumping j until finding less than
		
		if(i >= j)		break;
		
		// Swapping two numbers
		temp = arr[i]; 
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	quickSort(arr, left , j-1 , const_arr_size);
	quickSort(arr, j , right , const_arr_size);
}



int main(){
	int MyArray[] = {54,26,93,17,77,31,44,55,20};
	int size = sizeof(MyArray) / sizeof(MyArray[0]);
	
	quickSort(MyArray , 0 , size-1 , size); //Size will use constant
	
	return 0;
}

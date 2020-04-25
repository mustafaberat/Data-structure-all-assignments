#include <iostream>
using namespace std;

void quickSort(int *arr, int left, int right){
	if(left >= right)		return;
	
	int pivot = arr[(right+left)/2]; //Middle element is pivot
	int temp, i = left , j = right;
	
	while(i<=j){
		while(arr[i] < pivot)	i++;
		while(arr[j] > pivot)	j--;
		
		if(i >= j)		break;
		
		temp = arr[i]; //Swapping
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	quickSort(arr, left , j);
	quickSort(arr, j+1 , right);
}


void printArray(int *arr , int n){
	for(int i=0 ; i<n ; i++){
		cout << arr[i] <<" ";
	}
	cout << endl;
}

int main(){
	
	int MyArray[] = {54,26,93,17,77,31,44,55,20};
	int size = sizeof(MyArray) / sizeof(MyArray[0]);


	cout << "Old Array: ";
	printArray(MyArray, size);
	
	quickSort(MyArray, 0 , size-1);
	
	cout << "New Array: ";
	printArray(MyArray, size);
	return 0;
}

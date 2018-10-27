#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left+right)/2];
    
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main(){
    int arr[] = {6, 1, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    
    cout << "Array before sorting :" << endl;
    for(int i = 0 ;i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quickSort(arr, 0, n-1);
    cout<<"Array after sorting :"<<endl;
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    
    return 0;
}

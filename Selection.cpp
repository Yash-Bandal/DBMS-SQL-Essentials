#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;i++){
        int minInd=i; //first element consider
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minInd])
            {
                minInd=j;

            }
            if(minInd != i){
                int temp=arr[i];
                arr[i]=arr[minInd];
                arr[minInd]=temp;
            }

        }
    }

}

int main() {
    int n;
    cout << "Enter Size of array :" << endl;
    cin >> n;


    int arr[n];
    cout << "Enter array Elements :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted array is :" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }


    return 0;
}


//[64 2 4 25 11]  2 is min of all in j array..so its swapped
//[2 64 4 25 11]  ..now 2 is as it is ..iterate through j+1..4 is min..nd so on
//[2 4 64 25 11]
//[2 4 11 25 64]
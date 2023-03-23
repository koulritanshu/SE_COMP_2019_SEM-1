#include <iostream>
using namespace std;

template<class T>
class Sort{
public: 
    void selectionSort(T arr[], int n){
        for(int i=0;i<n;i++){
            for(int j=(i+1);j<n;j++){
                if(arr[i] > arr[j]){
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void print(T arr[], int n){
        cout << "----------------------------" << endl;
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "----------------------------" << endl;
    }
};

int main()
{
    while(true){
        cout << "1. Floating array." << endl;
        cout << "2. Integer array." << endl;
        cout << "3. Character array." << endl;
        cout << "0. Exit." << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        if(choice == 1){
            Sort<float> obj;
            int number;
            cout << "Enter the number of elements: ";
            cin >> number;
            float arr[number];
            for(int i=0;i<number;i++){
                cout << "Enter the element at index " << i+1 << ": ";
                cin >> arr[i];
            }
            cout << "BEFORE SORTING\n";
            obj.print(arr,number);
            cout << "AFTER SORTING\n";
            obj.selectionSort(arr,number);
            obj.print(arr,number);
        }
        else if(choice == 2){
            Sort<int> obj;
            int number;
            cout << "Enter the number of elements: ";
            cin >> number;
            int arr[number];
            for(int i=0;i<number;i++){
                cout << "Enter the element at index " << i+1 << ": ";
                cin >> arr[i];
            }
            cout << "BEFORE SORTING\n";
            obj.print(arr,number);
            cout << "AFTER SORTING\n";
            obj.selectionSort(arr,number);
            obj.print(arr,number);
        }
        else if(choice == 3){
            Sort<char> obj;
            int number;
            cout << "Enter the number of elements: ";
            cin >> number;
            char arr[number];
            for(int i=0;i<number;i++){
                cout << "Enter the element at index " << i+1 << ": ";
                cin >> arr[i];
            }
            cout << "BEFORE SORTING\n";
            obj.print(arr,number);
            cout << "AFTER SORTING\n";
            obj.selectionSort(arr,number);
            obj.print(arr,number);
        }
        else if(choice == 0){
            cout << "GoodBye!" << endl;
            break;
        }
    }
    return 0;
}
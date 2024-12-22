#include <iostream>
#include <vector>
using namespace std;

class Heap{

public:
    vector<int> arr;

    Heap(){
    }

    void insert();
    void heapify(int,int);
    void heapSort(int);

    void display();

    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }


};

void Heap::insert(){

    while(true){
        int n;
        cout<<"Enter a number: ";
        cin>>n;
        if(n<=-1){
            break;
        }
        arr.push_back(n);
    }
}

void Heap::display(){
    vector<int>::iterator iter;

    for(iter=arr.begin();iter!=arr.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;

}

void Heap::heapify(int n, int i){

    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    } 

    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(n, largest);
    }

}

void Heap::heapSort(int n){
    for(int i=n/2 - 1;i>=0;i--){
        heapify(n, i);
    }

    for(int i=n-1;i>0;i--){
        swap(&arr[0], &arr[i]);
        heapify(i,0);
    }
}



int main(){

Heap h;
h.insert();
int n = h.arr.size();

h.heapSort(n);

h.display();
    return 0;
}
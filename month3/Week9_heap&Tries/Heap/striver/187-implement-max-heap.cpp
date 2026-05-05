// https://takeuforward.org/plus/dsa/problems/implement-max-heap?subject=dsa&approach=bfs&tab=submissions

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> arr;
    int count;

    void heapifyUp(int ind) {
        int parentInd = (ind - 1)/2; 
        if(ind > 0 && arr[ind] > arr[parentInd]) {
            swap(arr[ind], arr[parentInd]);
            heapifyUp(parentInd);
        }
    }
    
    void heapifyDown(int ind) {
        int n = arr.size();
        int largestInd = ind; 

        int leftChildInd = 2*ind + 1;
        int rightChildInd = 2*ind + 2;

        if(leftChildInd < n && arr[leftChildInd] > arr[largestInd]) 
            largestInd = leftChildInd;

        if(rightChildInd < n && arr[rightChildInd] > arr[largestInd]) 
            largestInd = rightChildInd;

        if(largestInd != ind) {
            swap(arr[largestInd], arr[ind]);
            heapifyDown(largestInd);
        }
    }
    
public:
    void initializeHeap(){
        arr.clear();
        count = 0;
    }

    void insert(int key){
        arr.push_back(key);
        heapifyUp(count);
        count++;
    }

    void changeKey(int index, int new_val){
        if(index >= count) return;

        if(arr[index] < new_val) {
            arr[index] = new_val;
            heapifyUp(index);
        }
        else {
            arr[index] = new_val;
            heapifyDown(index);
        }
    }

    void extractMax(){
        if(count == 0) {
            cout << "Heap is empty\n";
            return;
        }

        int ele = arr[0];
        cout << "Extracted Max: " << ele << endl;

        swap(arr[0], arr[count-1]); 
        arr.pop_back();
        count--;

        if(count > 0)
            heapifyDown(0);
    }

    bool isEmpty(){
        return (count == 0);
    }

    int getMax(){
        if(count == 0) return -1;
        return arr[0];
    }

    int heapSize(){
        return count;
    }

    void printHeap(){
        for(int x : arr) cout << x << " ";
        cout << endl;
    }
};


// 🔹 Driver Code
int main() {
    Solution heap;
    heap.initializeHeap();

    // Insert elements
    heap.insert(10);
    heap.insert(40);
    heap.insert(15);
    heap.insert(20);
    heap.insert(50);

    cout << "Heap after insertions: ";
    heap.printHeap();

    cout << "Maximum element: " << heap.getMax() << endl;

    // Extract max
    heap.extractMax();

    cout << "Heap after extraction: ";
    heap.printHeap();

    // Change key
    heap.changeKey(2, 60);

    cout << "Heap after changeKey: ";
    heap.printHeap();

    cout << "Current Max: " << heap.getMax() << endl;

    cout << "Heap Size: " << heap.heapSize() << endl;

    return 0;
}
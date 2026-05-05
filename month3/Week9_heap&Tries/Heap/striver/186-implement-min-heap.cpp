// https://takeuforward.org/plus/dsa/problems/implement-min-heap?subject=dsa&approach=bfs

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> arr;
    int count;
    
    void heapifyUp(vector<int> &arr, int ind) {
        int parentInd = (ind - 1)/2; 

        if(ind > 0 && arr[ind] < arr[parentInd]) {
            swap(arr[ind], arr[parentInd]);
            heapifyUp(arr, parentInd);
        } 
    }
    
    void heapifyDown(vector<int> &arr, int ind) {
        int n = arr.size();
        int smallestInd = ind; 
        int leftChildInd = 2*ind + 1, rightChildInd = 2*ind + 2;
        
        if(leftChildInd < n && arr[leftChildInd] < arr[smallestInd]) 
            smallestInd = leftChildInd;

        if(rightChildInd < n && arr[rightChildInd] < arr[smallestInd]) 
            smallestInd = rightChildInd;

        if(smallestInd != ind) {
            swap(arr[smallestInd], arr[ind]);
            heapifyDown(arr, smallestInd);
        }
    }
    
public:
    void initializeHeap(){
        arr.clear();
        count = 0;
    }
    
    void insert(int key){
        arr.push_back(key);
        heapifyUp(arr, count);
        count++;
    }

    void changeKey(int index, int new_val){
        if(index >= count) return;

        if(arr[index] > new_val) {
            arr[index] = new_val;
            heapifyUp(arr, index);
        }
        else {
            arr[index] = new_val;
            heapifyDown(arr, index);
        }
    }

    void extractMin(){
        if(count == 0) {
            cout << "Heap is empty\n";
            return;
        }

        int ele = arr[0];
        cout << "Extracted Min: " << ele << endl;

        swap(arr[0], arr[count-1]); 
        arr.pop_back();
        count--;

        if(count > 0)
            heapifyDown(arr, 0);
    }

    bool isEmpty(){
        return (count == 0);
    }

    int getMin(){
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
    heap.insert(4);
    heap.insert(15);
    heap.insert(20);
    heap.insert(0);

    cout << "Heap after insertions: ";
    heap.printHeap();

    cout << "Minimum element: " << heap.getMin() << endl;

    // Extract min
    heap.extractMin();

    cout << "Heap after extraction: ";
    heap.printHeap();

    // Change key
    heap.changeKey(2, 1);

    cout << "Heap after changeKey: ";
    heap.printHeap();

    cout << "Current Min: " << heap.getMin() << endl;

    cout << "Heap Size: " << heap.heapSize() << endl;

    return 0;
}
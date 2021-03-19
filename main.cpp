#include <iostream>
using namespace std;

//sort the numbers by Quicksort
//average time complexity: O(nlogn), worst case: O(n^2)
void sort(int arr[], int head, int tail){
    if (tail <= head) return;
    int i = head;
    int j = tail + 1;
    int k = arr[head];
    while (true)
    {

        //Find a value smaller than k from left to right
        while (arr[++i] > k)
        {
            if (i == tail){
                break;
            }
        }
        
        //Find a value larger than k from right to left
        while (arr[--j] < k)
        {
            if (j == head){
                break;
            }
        }
        
        if (i >= j) break;

        //exchange i and j
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    //exchange midvalue and j
    int temp = arr[head];
    arr[head] = arr[j];
    arr[j] = temp;
    sort(arr, head, j - 1);
    sort(arr, j + 1, tail);
}

//average time complexity: O(nlogn), worst case: O(n^2)
void saparate_and_sort(int inputlist[], int len)
{
    int k = -1;
    int counteven = 0;
    
    
    //time complexity: O(n)
    for (int i = 0; i < len; i++)
    {
        // if element is odd then swap
        if (inputlist[i] % 2 == 0)
        {
            k++;
            counteven++;
  
            // swap the element
            int temp = inputlist[i];
            inputlist[i] = inputlist[k];
            inputlist[k] = temp;
        }
    }
    
    sort(inputlist, 0, counteven - 1);
    sort(inputlist, counteven, len - 1);
    

    
}


//To display how we call the algorithm
int main(){
    int mylist[] = {4, 3, 1, 2, 6, 7, 10};
    
    saparate_and_sort(mylist, 7);
    for (int i = 0; i < 7; i++)
    {
       cout << mylist[i] << endl;
    }
    
    
}

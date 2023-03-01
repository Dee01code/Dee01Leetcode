class Solution {
public:
    
    void swap(int* a, int* b)
{
  
    int temp = *a;
  
    *a = *b;
  
    *b = temp;
}
    
    void heapify(vector<int>& arr, int N, int i)
{
    // Find largest among root, left child and right child
  
    // Initialize largest as root
    int largest = i;
  
    // left = 2*i + 1
    int left = 2 * i + 1;
  
    // right = 2*i + 2
    int right = 2 * i + 2;
  
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
  
        largest = left;
  
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
  
        largest = right;
  
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
  
        swap(&arr[i], &arr[largest]);
  
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
    
    void heapSort(vector<int>& arr, int N)
{
  
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
  
        heapify(arr, N, i);
  
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
  
        swap(&arr[0], &arr[i]);
  
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}
    
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        
    // Function call
        heapSort(nums, n);
        return nums;
    }
};
using namespace std;

/*
bubbleSort

'bubbles' largest value to back of array

parameters:
arr[] - array we are sorting
n - size of array

return: none
*/
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; j < n - 1; i++) {
        // last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

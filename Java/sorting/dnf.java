import java.util.Arrays;

public class DutchNationalFlagAlgo {

    static void swap(int arr[], int n, int m) {
        int temp = arr[n];
        arr[n] = arr[m];
        arr[m] = temp;
    }

    static void sortArray(int arr[]) {
        int low = 0;
        int mid = 0;
        int high = arr.length - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr, low, mid);
                low = low +1;
                mid = mid+1;
            }
            else if (arr[mid] == 1) {
                mid = mid+1;
            }
            else {
                swap(arr, mid, high);
                high = high - 1;
            }
        }
        System.out.println("Array after sorting "+ Arrays.toString(arr));       
    }

    public static void main(String args[]) {
        // Input array should be having 0,1,2 
        int arr1[] = {1,2,0,0,1,2,1};
        sortArray(arr1);

        int arr2[] = {0,1,0,2,0,1,2,2};
        sortArray(arr2);

        int arr3[] = {1,1,0,2,1,2,0};
        sortArray(arr3);

        int arr4[] = {2,0,1};
        sortArray(arr4);
    }
}

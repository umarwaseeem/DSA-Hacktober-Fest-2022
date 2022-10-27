//T(n): O(n* range) approx O(n)
//S(n): O(n * r)
public class Main
{
    public static int[] CountSort(int[] arr, int n) {
        int[] freq = new int[10];
        //Freuency of numbers
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        //Cumulative frequency
        for (int i = 1; i < 10; i++) {
            freq[i] += freq[i - 1];
        }
        //Storing elements in result array maintaining order
        int[] res = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int index = --freq[arr[i]];
            res[index] = arr[i];
        }
        return res;
    }
	public static void main(String[] args) {
	    int[] arr = {9, 8, 7, 5, 2, 1};
	    int[] res = CountSort(arr, 6);
	    for (int i: res) {
	    System.out.print(i +" ");
	    }
	}
}
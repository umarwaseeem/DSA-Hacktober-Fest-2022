public class Main {
    public static void swap(int[] arr, int i , int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static int partition(int[] arr, int s, int e){
        int pivot =arr[e];
        int pid = s;
        for(int i=pid;i<e;i++){
            if(arr[i]<=pivot){
                swap(arr,pid,i);
                pid++;
            }
        }
        swap(arr,pid,e);
        return pid;
    }
    public static void quicksort(int[] arr, int i, int j){
        if(i<j){
        int pid = partition(arr,i,j);
        quicksort(arr,i,pid-1);
        quicksort(arr,pid+1,j);
        }
    }
    public static void main(String[] args) {
        int[] arr = {8,6,1,4,2,45,5,14,79,2,14,75,32,3,68,47,15};
        quicksort(arr,0,arr.length-1);
        for(int z=0; z<arr.length;z++){
            System.out.print(arr[z]+ " ");
        }
    }
}
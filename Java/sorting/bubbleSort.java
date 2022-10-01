public class Main {
    public static void sort(int[] arr, int s, int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    public static void main(String[] args) {
       int[] arr = {8,4,5,7,4,2,14,4,145,98,85,7,25,45,36,85,47,20};
        sort(arr,0,arr.length-1);
        for(int i=0; i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
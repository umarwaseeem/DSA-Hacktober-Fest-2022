public class Main {
    public static void merge(int[] arr, int l, int r, int mid){
        int n1=mid-l+1;
        int n2 =r-mid;
        int[] A = new int[n1];
        int[] B = new int[n2];
        for(int i=0;i<n1;i++){
            A[i]=arr[l+i];
        }
        for(int j=0;j<n2;j++){
            B[j]=arr[mid+j+1];
        }
        int i=0;
        int j=0;
        int k=l;
        while(i<n1 && j<n2){
            if(A[i]<=B[j]){
                arr[k++] = A[i++];
            }
            else{
                arr[k++] = B[j++];
            }
        }
        while(i<n1) arr[k++] = A[i++];
        while (j<n2) arr[k++] = B[j++];
    }
    public static void mergesort(int[] arr, int l, int r){
        if(l>=r){
            return;
        }
        int mid = l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
    public static void main(String[] args) {
        int[] arr = {8,5,4,1,55,65,47,45,18,16,74,51,0,12,65,84,14};
        mergesort(arr,0,arr.length-1);
        for(int i=0; i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
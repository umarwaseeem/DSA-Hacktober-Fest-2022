import java.util.*;

class Solution {
    int binarysearch(int arr[], int n, int k) {
        int start=0,end=n-1,mid=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]>k)
                end=mid-1;
            else if(arr[mid]<k)
                start=mid+1;
            else
                return mid;
        }
        return -1;
    }
}

class BinarySearch {
  public static void main(String[] args) {
    Scanner sn=new Scanner(System.in);
    Solution result = new Solution();
    int n=sn.nextInt();
    int[] arr = new int[n];
    for(int i=0;i<arr.length;i++)
      arr[i]=sn.nextInt();
    int k=sn.nextInt();
    int res=result.binarysearch(arr,n,k);
    System.out.println(res);
  }
}   

public class Main {
    public static String swap(String s, int i, int j){
        char[] str = s.toCharArray(); 
        char temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        return String.valueOf(str); 
    }
    public static void permute(String str, int index, int size){
        if(index==size){
            System.out.println(str);
        }
        for(int j=index;j<size;j++){
            str = swap(str,index,j);
            permute(str,index+1,size);
            str = swap(str,index,j);
        }
    }
    public static void main(String[] args) {
        String str = "exam"; 
        int n = str.length();
        permute(str,0,n-1);
    }
}
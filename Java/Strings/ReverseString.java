import java.io.*;
import java.util.*;
  
class Reverse {
  
    // Driver code
    public static void main(String[] args)
    {
        String str = "HELLO";
        
                           
        char[] reverseString = new char[str.length()];
        Stack<Character> stack = new Stack<Character>();
  
        for (int i = 0; i < str.length(); i++) {
            
            stack.push(str.charAt(i));
        }
  
  
        int i = 0;
        while (!stack.isEmpty()) { 
            
            reverseString[i++] = stack.pop();
        }
        // return string object
        str=  new String(reverseString);
        
        System.out.print("The reversed string is- "+ str);
        
    }
}

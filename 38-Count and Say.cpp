class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
         return "1";
     
       string x=countAndSay(n-1);
       string y="";
       
       for(int i=0;i<x.length();i++){
           int c=1;
           
           while(i<x.length()-1 && x[i]==x[i+1])
           {   c++;
               i++;
           }
          
           string str1= to_string(c);
           y+=str1;
           y+=x[i];
       }
       
       return y;
    }
};

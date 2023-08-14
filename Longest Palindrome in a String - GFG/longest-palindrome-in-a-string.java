//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String S = read.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.longestPalin(S));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    static String longestPalin(String word){
        // code here
        Integer ans=1;
        Integer l=0, r=0;
        Integer len = word.length();
        for(int i=0;i<len;i++){
            Integer curLen=1;
            ans=Math.max(ans, curLen);
            for(int j=1;j<=Math.min(i,len-1-i);j++){
                if(word.charAt(i-j)==word.charAt(i+j)){
                    curLen=curLen+2;
                }
                else{
                    break;
                }
                if(curLen>ans){
                    ans=curLen;
                    l=i-j;
                    r=i+j;
                }
            }
        }

        for(int i=0;i<len-1;i++){
            if(word.charAt(i)!=word.charAt(i+1))continue;
            Integer curLen=2;
            if(curLen>ans || (curLen==ans && i<l)){
                ans=curLen;
                l=i;
                r=i+1;
            }
            for(int j=1;j<=Math.min(i,len-2-i);j++){
                if(word.charAt(i-j)==word.charAt(i+1+j)){
                    curLen=curLen+2;
                }
                else{
                    break;
                }
                if(curLen>ans || (curLen==ans && i<l)){
                    ans=curLen;
                    l=i-j;
                    r=i+j+1;
                }
            }
        }
        
        String ans1 = "";
        for(int i=l;i<=r;i++){
            ans1+=word.charAt(i);
        }
    
        return ans1;
        
    }
}
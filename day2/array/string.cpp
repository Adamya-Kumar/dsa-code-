#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{

    string result;

     for(char c : s){
         if(c>='A' && c<='Z'){
             result += c+32;
         }else if((c>='a' && c<='z')|| (c >='0' && c<='9')){
             result= result +c;
         }
     }
     
     string rev = result;
      reverse(rev.begin(),rev.end());

     if(result == rev){
         return true;
     }else{
         return false;
     }


}
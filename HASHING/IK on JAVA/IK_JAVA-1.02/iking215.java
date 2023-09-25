// SUBSEQUNCES OF A STRING OF A UNIQUE KIND(MEANS IF IN STRING CHAR ARE SAME THEN THERE CAN BE SAME SUBSEQUENCES ALSO)
// DATA STRUCTURE---> HASH SET

import java.util.HashSet;                       // IMPORT STATEMENT FOR HASH SET

public class iking215 {

    public static void subSequences(String str, int idx, String newString, HashSet<String>set){   // NEW HASH SET VARIABLE
       if(idx==str.length()){                             //WAY TO WRITE HASH SET 
        if(set.contains(newString)){                      // IF SET CONTAINS NEW STRING THEN NOTHING TO BE DONE AND RETURN
            return;
        }else{
            System.out.println(newString);               // IF SET NOT CONTAIN IT THEN ADD USING PHRASE WRITTEN
            set.add(newString);
            return;
        }
        
       }
        char currChar=str.charAt(idx);
       
        subSequences(str,idx+1,newString+currChar,set);         // OTHER SAME
        subSequences(str,idx+1,newString,set);                  // SO IT ACT LIKE A FILTER
    }
    public static void main(String args[]){
        String str="AAA";
        HashSet<String>set=new HashSet<>();
        subSequences(str,0,"",set);
    }
}
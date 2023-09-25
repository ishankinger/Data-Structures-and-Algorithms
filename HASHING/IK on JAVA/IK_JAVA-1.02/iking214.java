// SUBSEQUENCES OF THE STRINGS(TAKE IT AS A SUBSETS OF A SET)--> TOTAL IS 2^N
/**
 * iking214
 */
public class iking214 {

    public static void subSequences(String str, int idx, String newString){
       if(idx==str.length()){
        System.out.println(newString);                    // AT END WE WANT STRING TO BE PRINTED AND NOTHING RETURNED
        return;
       }
        char currChar=str.charAt(idx);
       
        subSequences(str,idx+1,newString+currChar);        // EACH STRING HAS TWO CHOICES OF ADDING OR NOT AND IT WILL OCCUR 
                                                           // SERIAL WISE MEANS FIRST A AND _ THEN IN A TWO CASES AB AND A_
        subSequences(str,idx+1,newString);                 // AND IN _ TWO CASES _B AND _ _ AND THIS WILL KEEP GOING 
    }
    public static void main(String args[]){
        String str="abC";
        subSequences(str,0,"");
    }
}
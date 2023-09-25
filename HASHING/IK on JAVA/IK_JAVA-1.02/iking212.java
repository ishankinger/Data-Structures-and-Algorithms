// MOVE ALL 'X' TO END OF THE STRING
/**
 * iking212
 */
public class iking212 {

    public static void moveAllX(String str, int idx, int count, String newString){
      if(idx==str.length()){                                   // NOW AT END WHEN WE REACH END OF THE STRING STR
        for(int i=0;i<count;i++){                              // WE HAVE TO PRINT ALL X WHICH WILL BE PRINTED AT THE END
            newString += 'x';                                  // HERE ALSO COMES ROLE OF COUNT VARIABLE AS IT TELL FOR LOOP TO PRINT 
        }                                                      // HOW MUCH X
        System.out.println(newString);                         // FINAL RESULT
        return;                                                // RETURN;
      }
        char currChar= str.charAt(idx);
        if(currChar=='x'){                                      // MEANS IF WE GET X THEN ADD COUNT BY ONE AND
            count++;                                            // THEN MOVE FURTHER WITH THE FUNCTION
            moveAllX(str,idx+1, count,newString);
        }else{
            newString += currChar;                               // MEANS IF WE GET OTHER THAN X THEN ADD THAT IN THE NEW STRING
            moveAllX(str,idx+1,count,newString);
        }
    }
    public static void main(String args[]){
        moveAllX("axdxgdxxgsg",0,0,"");     // HERE NEW STRING IS EMPTY AS IT WILL FILL FURTHER
    }
}
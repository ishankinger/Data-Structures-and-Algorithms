// PRINT KEYPAD COMBINATIONS(NUMBERS ARE GIVEN SOME STRINGS SO WE HAVE TO MAKE ALL POSSIBLE COMB WITH PNC1)
/**
 * iking216
 */
public class iking216 {

    public static String[] keypad= {".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};  // ARRAY OF STRINGS

    public static void printComb(String str, int idx, String comb){
       if(idx==str.length()){
        System.out.println(comb);                           // PRINT ALL POSSIBLE COMBINATIONS
        return;
       }
        char currChar=str.charAt(idx);                      // TAKE CHAR FROM STRING(23--> IDX=0 HAS CHAR=2 AND IDX=1 HAS CHAR=3)
        String mapping= keypad[currChar-'0'];               // 2-0 GIVE 2ND IDEX I.E. DEF AND THIS STRING DEF IS NAMED MAPPING

        for(int i=0;i<mapping.length();i++){                // NOW A LOOP ON THIS STRING 
            printComb(str,idx+1,comb+mapping.charAt(i));    // NOW ADDING DEF CHARCTER ONE BY ONE AND THEN ADDING CHAR OF OTHER STRINGS
        }                                                   // COMING AFTER THIS I.E. 3

    }
    public static void main(String args[]){
        
        printComb("23",0,"");
    }
}
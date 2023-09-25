// PRINT ALL PERMUTATIONS OF A STRING(ABC,ACB,BCA,BAC,CAB,CBA)
/**
 * iking217
 */
public class iking217 {

    public static void printPerm(String str, String permutations){
        if(str.length()==0){
            System.out.println(permutations);
            return;
        }
        for(int i=0;i<str.length();i++){                                        // GOING IN LOOP ON STRING 
            char currChar= str.charAt(i);                                       //CONCEPT OF SUBSTRINGS THAT ENDING INDEX IS ONE AFTER 
            String newStr= str.substring(0,i)+str.substring(i+1);   // LAST OF STRING TO BE CHOSEN SO WE ELIMINATE I ELEMNT
            printPerm(newStr,permutations+currChar);                            //SUPPOSE A CHOSEN NOW LEFT IS NEW STRING AND WE HAVE  
        }                                                                       // CHOOSE FORM IT NEXT CHARACTER
    }
    public static void main(String args[]){
        printPerm("abc","");
    }
}
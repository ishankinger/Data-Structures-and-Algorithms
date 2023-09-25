// RECURSION
/**
 * iking202
 */
public class iking202 {

    public static void printNumber(int n){                   //FUNCTION OTHER THAN MAIN FUNCTION
        if(n==0)                                             // VOID TYPE OR DATABASE RETURN TYPE
        return;                                              // BASE CASE AND RETURN
        System.out.println(n);                               // WORK TO BE DONE    EACH TIME PRINTED AT EACH STACK
        printNumber(n-1);                                    // CALLING THE FUNCTION
    }
    public static void giveNumber(int m){                    // VARIABLES IN BRACKETS IS DEFINED IN MAIN FUNCTION 
        if(m==6)
        return;
        System.out.println(m);
        giveNumber(m+1);
    }
    public static void main(String args[]){
        int n=5;
        printNumber(n);
        System.out.println( "    ");
        int m=1;
        giveNumber(m);
    }

}
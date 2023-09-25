// FACTORIAL OF A NUMBER FROM RECURSION
/**
 * iking204
 */
public class iking204 {

    public static int calcFactorial(int n){                         // RETURN TYPE NOT VOID THIS TIME
        if(n==1||n==0){
            return 1;                                               // HERE RETURN TYPE VOID SO 1 WRITTEN
        }
        int k= calcFactorial(n-1);                                 // CALLING THE FUNCTIONS AND STACKS ARE MADE TILL BASE CASE
       
        System.out.println("*");                               // NOW RETURNING FROM BASE CASE AND PRINTING * AND ALSO MUTLTIPLYING
        int i= k*n;
        return i;
    }
    public static void main(String args[]){
        int n=5;
        System.out.println("*");                               // AT LAST IT COMES TO BASE CLASS THUS GIVING TOTAL FIVE STARS
       System.out.println( calcFactorial(n));
    }
}
// LOGICAL OPERATORS(AND  OR)
/**
 * iking160
 */
public class iking160 {

    public static void main(String args[]){
        
        System.out.println(64>5 && 64>6);      // IF BOTH TRUE THEN TRUE                // LOGICAL AND OPERATOR
      
        System.out.println(64>5 && 64<6);      // IF ATLEAST ONE FALSE ALL FALSE
      
        System.out.println(64<5 || 64<6);      // IF BOTH FALSE THEN FALSE              // LOGICAL OR OPERATOR
       
        System.out.println(64>5 || 64<6);      // IF ATLEAST ONE TRUE THEN TRUE

        System.out.println(!(64>5));           // MAKE A STATEMENT REVERSE               // LOGICAL NOT OPERATOR
    }
}

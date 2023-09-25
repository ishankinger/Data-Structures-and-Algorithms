// GREATEST DIVISOR OF TWO NUMBERS
/**
 * iking138
 */
import java.util.*;                                   // a%b gives remainder but if b>a then remainder will be negative but in maths
                                                      // remainder cannot be negative actually then we add b in it to make positive
public class iking138 {

    public static int gcdOfNumbers(int a, int b){     
        int i=a % b;                                   // INTIALISATION OF THE VALUE I WITH A%B REMAINDER                              
        while(i!=0){                                   // TILL I IS NOT EQUAL TO 0 WE HAVE TO THIS                                 
            
            a=b;                                       // THESE TWO ARE GIVING NEW VALUES TO A AND B                                 
            b=i;                                       // NOW A IS GIVEN VALUE OF B AND B IS GIVEN VALUE OF I

            i=a % b;                                   // NOW AGAIN FIND I WITH NEW VALUE OF A AND B AND DO THIS TILL I IS NOT 
        }                                              // EQUAL TO ZERO AND WHEN I EQUALS 0 THEN STOP AND RETURN LAST VALUE OF 
        return b;                                      // B USED IN THE PROCESS
    }
    
    // ALSO WE CAN DONE THIS WITH THE HELP OF FOR LOOP 
    // for( int i=a%b ; i!=0 ; a=b,b=i,i=a%b){                      SO FOR DIFFERENT THINGS IN INT,COND,UPD, ALWAYS USE ' , '
        
    // }
    // return b;
    


    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int a= sc.nextInt();
        int b= sc.nextInt();
        int gcd= gcdOfNumbers(a,b);

        System.out.println("GCD of numbers is "+gcd);
    }
}
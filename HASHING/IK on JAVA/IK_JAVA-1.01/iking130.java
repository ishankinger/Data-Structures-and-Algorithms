// FUNCTION (INT EXAMPLE)
/**
 * iking130
 */
import java.util.*;

public class iking130 {

    public static int calculateSum(int a, int b){
        int sum= a+b;
        return sum;                                      // HERE SUM IS TO BE RETURNED SO WE USE int
     }                                                   // WHERE WE HAVE TO USE SYSO IN MAIN FUNCTION USE RETURN AT THAT PLACE FOR OTHER
     public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int a= sc.nextInt();
        int b= sc.nextInt();
        int sum= calculateSum(a,b);                        // INSTEAD OF THIS IF WE HAVE TO WRITE IN OUTPUT TERMS
        System.out.println("sum of numbers is:"+ sum);     // WRITE LIKE THIS calculateSum(5,10);

      

        
    
     }
}

// AVERAGE OF THREE NUMBERS
/**
 * iking131
 */
import java.util.*;

public class iking131{
  
    public static int calculateAverage(int a, int b, int c){   // VARIABLES IN THE BRACKET ARE ALWAYS DEFINED IN MAIN FUNCTION
        int avg= (a+b+c)/3;                                    // VARIABLES WHICH ARE MADE INSIDE THE FUNCTIONS ARE NOT TO BE DEFINED IN
        return avg;                                            // MAIN FUNCTION
    }
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        int avg= calculateAverage(a,b,c);                       // HERE VARIABLE OTHER THAN AVG CAN BE USED BUT THEN ALSO SAME RESUTLT
        System.out.println("average of three numbers : "+ avg ); 
    }
}


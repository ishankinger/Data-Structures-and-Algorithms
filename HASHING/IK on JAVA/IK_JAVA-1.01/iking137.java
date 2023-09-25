//ELIGIBLE FOR VOTE OR NOT
/**
 * iking137
 */
import java.util.*;

public class iking137 {

    public static boolean eligibleVote(int age){     // BOOLEAN TYPE FUNCTION
        if(age>18){
            return true;                            // BOOLEAN TRUE OR FALSE
        }else{
            return false;
        }
    }
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int age= sc.nextInt();

       System.out.println( eligibleVote(age));     // CAN WRITE ELIGIBLEVOTE(AGE) INSTEAD OF DEFINIG IT AND THEN PUTTING IT
    }
}

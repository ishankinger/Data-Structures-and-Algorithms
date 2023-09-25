//  UPDATE BIT
/**
 * iking164
 */
import java.util.*;

public class iking164 {

    public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    System.out.println("Enter required number");
    int n=sc.nextInt();
    System.out.println("Enter required position of that number");
    int pos= sc.nextInt();
    System.out.println("Enter in which to convert 1 or 0");
    int opr=sc.nextInt();
    if(opr==1){
        int bitMask=1<<pos;
        int newNumber=bitMask|n;
        System.out.println("New number after operation is : "+ newNumber);
    } else{
        int bitMask=1<<pos;
        int nobitMask=~(bitMask);
        int newNumber=nobitMask&n;
        System.out.println("New number after operation is : "+ newNumber);
    }
    }
}

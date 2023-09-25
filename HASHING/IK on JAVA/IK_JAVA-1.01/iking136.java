// X RAISE TO POWER N
/**
 * iking136
 */
import java.util.*;

public class iking136 {

    public static int raiseToPowern(int x, int n){
        int k=1;
        for(int i=1;i<=n;i++){
            k=k*x;                                                  // IMPORTANT CONCEPT
    }
    return k;
    }
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter number to be raised");
        int x= sc.nextInt();
        System.out.println("Enter how much to be raised");
        int n= sc.nextInt();
        System.out.println("result : "+raiseToPowern(x,n));
    }
}
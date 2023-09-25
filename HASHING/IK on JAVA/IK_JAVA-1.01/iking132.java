// SUM OF ALL ODD NUMBER FROM 1 TO N
/**
 * iking132
 */
import java.util.*;

public class iking132 {

    public static int sumOfOddNumbers(int n){
        int k=0;
        for(int i=1;i<=n;i=i+2){
            k=k+i;
        }
        return k;                                          // IN RETURN TYPE DO SAME AS IN MAIN FUNCTION ONLY DONOT DEFINE VARIABLES IN 
    }                                                      // BRACKET AND INSTEAD OF SYSO AS IN MAIN HERE USE RETURN VARIABLE 
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int j=sc.nextInt();                               // HERE NO REALATION OF N WITH N OF THE UPWARD FUNCTION IT IS 
        int i= sumOfOddNumbers(j);                        // JUST A VARIABLE AND CAN BE ANY OTHER CHARACTER
        System.out.println(i);
    }
}

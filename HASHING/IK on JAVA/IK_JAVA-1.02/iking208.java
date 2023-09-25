// TOWER OF HANOI
/**
 * iking208
 */
import java.util.*;

public class iking208 {

    public static void towerOfHanoi(int n, String src,String help,String dest){
        if(n==1){
            System.out.println("transfer disc"+n+" from "+src+" to "+dest);
            return;
        }
        towerOfHanoi(n-1,src,dest,help);                                              // DESTINATION <--> HELPER
        System.out.println("transfer disc"+n+" from "+src+" to "+dest);
        towerOfHanoi(n-1,help,src,dest);                                              // SOURCE<---> HELPER
    }
    public static void main(String args[]){
        Scanner s =new Scanner(System.in);
        System.out.println("Enter number of disks");
        int n= s.nextInt();

        towerOfHanoi(n,"S","H","D");
    }
}
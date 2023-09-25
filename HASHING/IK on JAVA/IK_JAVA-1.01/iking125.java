// SOLID RHOMBUS                                                                          //          *********
/**
 * iking125
 */
import java.util.*;

public class iking125 {

    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int n= sc.nextInt();
      
        for(int i=1;i<=n;i++){                             // OUTER LOOP
        
        for(int j=1;j<=n-i;j++){                           // FIRST INNER LOOP
            System.out.print(" ");
        }
        for(int j=1;j<=n;j++){                             //SECOND INNER LOOP
            System.out.print("*");
        }
        for(int j=1;j<=i-1;j++){                             //if not written then also okay as it will give space itself
            System.out.print(" ");
        }
           System.out.println();
       } 

       // ???????????????????????????????????????????????HOLLOW RHOMBUS
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4-i;j++){
            System.out.println(" ");
        }
        for(int j=1;j<=n;j++){
            
        }
    }      
}
}                                                                                        
                                                                                          
                                                                                          
                                                                                          
                                                                                          
                                                                                          
        







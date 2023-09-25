// NESTED IF ELSE STATEMENT                     // OR WE CAN USE 'ELSE IF' STATEMENT

/**
 * iking106
 */
import java.util.*;

public class iking106 {
public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int a= sc.nextInt();                                              // OR WE CAN USE 'ELSE IF' STATEMENT
    int b= sc.nextInt();                                                
     if (a==b) {                                                       //IF(  CONDITION   )     {               }
        System.out.println("numbers are equal");                   // ELSE IF ( CONDITION  ) {               }
                                                                     // ELSE  {               }
    } else{if (a>b) {                                                               
        System.out.println("first number is greater");
        
    } else {
        System.out.println("second number is greater");
        
    }
        
    }
}
}
    


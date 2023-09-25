//  USERNAME FROM EMAIL ID
/**
 * iking158
 */
import java.util.*;

public class iking158 {

    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter email id");
        String email=sc.next();
       
        String username=" ";                                 // EMPTY STRING
        
        for(int i=0;i<email.length();i++){                 // GO IN THE LOOP 
           
            if(email.charAt(i)=='@'){
                break;                                     // MEANS WHEN @ COMES STOP THE PROCESS OF LOOP
            }else{
                username +=  email.charAt(i);              // OTHERWISE ADD THE CHAR COMING IN THE EMAIL
            }
        }
        System.out.println(username);

    
    }
}
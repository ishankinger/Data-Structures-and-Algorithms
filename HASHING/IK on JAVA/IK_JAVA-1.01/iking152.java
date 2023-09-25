// FUNCTIONS OF STRINGS
/**
 * iking152
 */
import java.util.*;

public class iking152 {

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
       
        //CONCATENATION OF STRINGS( JOINING OF STRINGS)
       
        String firstName= sc.next();
        String lastName= sc.next();
        
        String fullName= firstName+ " "+ lastName;

        System.out.println("Your full name is : "+ fullName);

        // LENGTH OF STRINGS
       
        System.out.println(fullName.length());                   // GIVES TOTAL NO. OF CHARACTERS
                                                                 // DO CARE OF BRACKET AT END
        // charAt
       
        for(int i=0;i<fullName.length();i++){              //CHAR NUMBERS STRTING FROM 0
            System.out.println(fullName.charAt(i));
        }


        }

        
    }


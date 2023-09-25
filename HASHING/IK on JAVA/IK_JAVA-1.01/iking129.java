// FUNCTIONS (STRING NAME EXAMPLE)
/**
 * iking129
 */
import java.util.*;            

public class iking129 {

    public static void printMyName(String name){            // FIRST FUNCTION      // CAMEL CASE words have capital letters
                                                                                   // printMyName
        System.out.println(name);
        return;                                             // HERE NOTHING TO BE RETURN SO WE USED VOID 
    }
    public static void main(String args[]){                 // MAIN FUNCTION
        Scanner sc= new Scanner(System.in);
        String name= sc.nextLine();

        printMyName(name);                      // CALLING THE FUNCTION
    }
    
}

// ARRAY FROM INPUTS AND THEN OUTPUTS
/**
 * iking142
 */
import java.util.*;

public class iking142 {
public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int size= sc.nextInt();                        //INPUT FORMAT FOR SIZE TO BE TAKEN
    
    int numbers []=new int[size];                  //DEFINING FOR SIZE

    for(int i=0;i<size;i++){                       //FOR INPUT PURPOSE
        numbers[i]=sc.nextInt();                   // HERE WE HAVE TO GIVE NUMBERS TO BE SHOWN
     
    }
    
    for(int i=0; i<size;i++){                      // FOR OUTPUT PURPOSE
        System.out.println(numbers[i]);            // IF NO VALUE GIVEN AUTOMATICALLY 0 WILL SHOW
    }

    
}
}
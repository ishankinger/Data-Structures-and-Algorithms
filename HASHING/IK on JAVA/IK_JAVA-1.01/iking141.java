// CONCEPT OF AN ARRAY
/**
 * iking141
 */
import java.util.*;
public class iking141 {

    public static void main(String args[]){
        int[]marks=new int[3];                                   // ' [] ' CAN BE TAKEN AFTER MARKS ALSO
        marks[0]=97;                                             // ARRAY IS ZERO INDEXED AS INDEX STARTS FROM 0
        marks[1]=99;
        marks[2]=98;
        System.out.println("marks of physics : "+ marks[0]);

        for(int i=0; i<3;i++){
            System.out.println(marks[i]);                       // TO WRITE LONG ARRAYS WE USE FOR LOOPS
        }
       
       
        int[] number= {97,98,99};                               // OTHER WAY TO WRITE ARRAY(SHORTER WAY)
                                                                // THIS ARRAY IS ALSO VARIABLE SO IT IS REPRESENT AS--
        for(int i=0; i<3;i++){                                  // DATATYPE[] NAME OF VARIABLE
            System.out.println(number[i]);  
 }
}
}
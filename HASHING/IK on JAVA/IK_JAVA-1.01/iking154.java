// CONCEPT OF SUBSTRINGS
/**
 * iking154
 */
import java.util.*;

public class iking154 {

    public static void main(String args[]){
        String sentence="My name is ishan kinger";
        
        String name=sentence.substring(11,16);    //begning index --> SAME
        System.out.println(name);                                      // ending index---> index of char after req. no.
         
        String name1= "tonystark";
        
        String name2= name1.substring(0,4);   // t is given 0 index

        String name3= name1.substring(4);               // if ending index not given it will print till end

        System.out.println(name2);
        System.out.println(name3);




    }

}

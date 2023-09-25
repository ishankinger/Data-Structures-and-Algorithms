// STRING BUILDER
/**
 * iking155
 */
import java.util.*;

public class iking155 {

    public static void main(String args[]){
        StringBuilder sb= new StringBuilder("ishan kinger");        // DEFINING STRING BUILDER
        System.out.println(sb);

        System.out.println(sb.charAt(0));                         //.charAt 
        System.out.println(sb.charAt(3));                         // PRINT  CHAR AT THAT INDEX

        sb.setCharAt(0,'u');                                   // SET CHARACTER IN PLACE OF INDEX
        System.out.println(sb);                                          //'setCharAt'

        sb.insert(0,'S');                                     //INSERTION OF CHARACTER(PUT INDEX SO THAT IT MOVE BACK )
        sb.insert(6,'t');                                     // SPACE BAR MOVES BACK
        sb.insert(1,'h');                                     // 'U' MOVES BACK
         System.out.println(sb);

        sb.delete(8,15);                                      //.delete
        System.out.println(sb);                                          // END INDEX ---> AFTER THE REQIURED NUMBER

        sb.append(" jindal");                                        // .append(ADDITION OF WORDS)
        System.out.println(sb);                                          // STR=STR+" "--> BUT THIS MAKE NEW STRING SO MORE TIME

        System.out.println(sb.length());                                 // .length TELL ABOUT TOTAL NUMBER OF CHARACTERS
                                                                         // DONONT FORGET ABOUT '()'
    }
}

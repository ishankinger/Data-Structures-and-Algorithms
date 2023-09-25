//  COMPARING OF TWO STRINGS---> S1.compareTo(S2)                // BIGGER IS DECIDED ON THE BASIS OF ALPHABETS
        // S1 > S2 ---> POSITIVE VALUE                                   A<B<C<D<.....<Z AND IN WORD COMPARE ONE AFTER THE OTHER
        // S1== S2 ---> 0
        // S1 < S2 ---> NEGATIVE VALUE                           // (A==B) TYPES SOMETIMES GET WRONG SO WE USE THIS 
                                                                    
                                                                 // CHAR HAS MORE VALUE THAN BACKSPACE
/**
 * iking153
 */
import java.util.*;
public class iking153 {

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String name1= sc.next();
        String name2= sc.next();

         if(name1.compareTo(name2)>0){
            System.out.println("name 1 is greater than name 2");
        }else if(name1.compareTo(name2)<0){
            System.out.println("name 2 is greater than name 1");
        }else if(name1.compareTo(name2)==0){
            System.out.println("both are equal");
        }
       
       
        //DO NOT USE == to check for string equality
       //Gives correct answer here
       if(name1 == name2) {
        System.out.println("They are the same string");
    } else {
        System.out.println("They are different strings");
    }

    //Gives incorrect answer here
    if(new String("Tony") == new String("Tony")) {
        System.out.println("They are the same string");
    } else {
        System.out.println("They are different strings");
    }

        
    }
    }

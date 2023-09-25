// AARAY LIST
/**
 * iking150
 */
import java.util.ArrayList;                                // COMPULSORY PACK FOR ARRAYLIST TO WORK

public class iking150 {

    public static void main(String args[]){
        
        ArrayList<Integer>list=new ArrayList<Integer>();   // WAY TO WRITE ARRAY LIST
        ArrayList<String>list2=new ArrayList<String>();    // MUST WRITE DATATYPES FULL WITH FIRST WORD CAPITAL
        ArrayList<Boolean>list3=new ArrayList<Boolean>();

        list.add(0);                                     // .ADD TO ADD ELEMENTS OF ARRAYLIST
        list.add(1);
        list.add(3);
        System.out.print(list + " ");

        list.add(2,2);                      // ADD ELEMENT IN BETWEEN 

        System.out.println(list.get(0));            // PRINT A PARTICULAR ELEMENT AT THAT INDEX WITH .GET
        System.out.println(list.get(2));

        list.set(0,5);                     // REPLACE ELEMENT AT INDEX WITH GIVEN ELEMENT

        list.remove(0);                             // REMOVE ELEMENT AT THAT PARTICULAR INDEX

        System.out.println(list.size());                  // GIVE SIZE OF THAT LIST  USE BRACKET ALSO 
                                                          // NOTE THAT HERE DONOT USE ' .LENGTH ' THAT WILL NOT WORK HERE

        for(int i=0;i<=list.size();i++){                  // PARTICULAT APPLICATION IN FOR LOOPS
            System.out.println(list.get(i));
        }


    }
}

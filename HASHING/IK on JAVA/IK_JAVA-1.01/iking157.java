//CUMULATIVE LEGTH OF STRINGS
/**
 * iking157
 */
/**
 * iking157
 */
import java.util.*;

public class iking157 {

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int size = sc.nextInt();

        String[] words= new String[size];

        for(int i=0;i<size;i++){
            words[i]=sc.nextLine();
        }
        String newString = "";

        for(int i=0;i<size;i++){
            newString += words[i];
        }
        System.out.println(newString.length());


    }
}

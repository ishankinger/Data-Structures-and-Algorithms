// SUBSETS OF SET OF FIRST N NATURAL NUMBERS
/**
 * iking221
 */
import java.util.ArrayList;

public class iking221 {

    public static void giveSubset(ArrayList<Integer>subset){
        for(int i=0;i<subset.size();i++){
            System.out.println(subset.get(i)+" ");
        }
    }

    public static void printSubset(int n, ArrayList<Integer>subset){
        if(n==0){
            System.out.println(subset);
            return;
        }
        subset.add(n);
        printSubset(n-1,subset);

        subset.remove(subset.size()-1);
        printSubset(n-1,subset);
    }
    public static void main(String args[]){
        int n=3;
        ArrayList<Integer>subset=new ArrayList<>();
        printSubset(n,subset);
        
    }
}
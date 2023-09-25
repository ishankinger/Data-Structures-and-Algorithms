// BINARY SEARCH (SEARCH FOR A NUMBER IN 2D ARRAY)
/**
 * iking145
 */
import java.util.*;

public class iking145 {

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int rows= sc.nextInt();
        int cols=sc.nextInt();

        int[][]numbers=new int[rows][cols];

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                numbers[i][j]=sc.nextInt();
            }
        }
        int x= sc.nextInt();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(numbers[i][j]==x){
                System.out.println("indices of number x is (" + i +"," + j +")");
            }    
        }
       

    }
}
}   
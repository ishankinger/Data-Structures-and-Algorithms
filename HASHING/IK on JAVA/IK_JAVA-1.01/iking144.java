// 2D ARRAYS                                               ROWS AND COLUMNS NUMBERING STARTS FROM 0
/**
 * iking144
 */
import java.util.*;

public class iking144 {

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int rows=sc.nextInt();
        int cols=sc.nextInt();

        int[][] numbers= new int[rows][cols];      //FORMAT FOR 2D ARRAYS
                                       
                                                   //FOR INPUT PURPOSE      
        for(int i=0; i<rows;i++){                  // CONCEPT OF NESTED FOR LOOPS(OUTSIDE FOR ROWS INSIDE FOR COLUMNS)
            for(int j=0; j<cols;j++){             
                numbers[i][j]= sc.nextInt();        // FORMAT FOR INPUT OF 2D ARRAYS
            }
        }
                                                     //FOR OUPUT PURPOSE
        for(int i=0;i<rows;i++){                     
            for(int j=0;j<cols;j++){
            System.out.print(numbers[i][j]+" ");     // WAY TO WRITE SYSO   HERE CHECK FOR 'ln'
        }
        System.out.println();                         //COMPULSORY FOR NESTED LOOPS TYPES
    }
}
}
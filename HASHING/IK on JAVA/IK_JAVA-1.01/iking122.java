// HALF TRIANGLE WITH NUMBERS
/**
 * iking122
 */
public class iking122 {

    public static void main(String args[]){

        for(int i=1;i<=7;i++){
            
            for(int j=1;j<=i;j++){
             System.out.print(j+" ");             // JUST REPLACE "*" WITH J AND EVERYTHING TAKING SAME
            
            } System.out.println();
        }
       
        System.out.println();
       
        // INVERTED HALF TRIANGLE WITH NUMBERS
       
       for(int i=1; i<=7;i++){

            for(int j=1; j<=7-i+1;j++){
            
                System.out.print(j+" ");
       
        } System.out.println();

    }
}
}
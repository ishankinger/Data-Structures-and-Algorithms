// DIAMOND PATTERN
/**
 * iking121
 */
public class iking121 {

    public static void main(String args[]){
       //upper case
       
       for(int i=1;i<=4;i++){                      // OUTER LOOP
           
            for(int j=1;j<=4-i;j++){                //FIRST INNER LOOP
                System.out.print(" ");
            }
            for(int j=1;j<=2*i-1;j++){              // SECOND INNER LOOP
            System.out.print("*");               // START AFTER FINISH OF FIRST LOOP
            }
            System.out.println();                   // FOR NEXT LINE
        }
        //lower case
        
        for(int i=4;i>=1;i--){                      // FOR REVERSE PATTERN USE THIS CHANGE IN OUTER LOOPS
            
            for(int j=1;j<=4-i;j++){                // INNER LOOPS WILL BE SAME AS THAT OF THE ABOVE
                System.out.print(" ");
            }
            for(int j=1;j<=2*i-1;j++){
                System.out.print("*");
            }
            System.out.println();

        }
    }
}
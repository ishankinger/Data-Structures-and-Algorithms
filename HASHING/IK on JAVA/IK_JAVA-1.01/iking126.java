       //BUTTERFLY PATTERN
/**
 * iking126
 */
public class iking126 {

    public static void main(String args[]){
        for(int i=1;i<=4;i++){                            // OUTER LOOP
            
            for(int j= 1;j<=i;j++){                       // FIRST INNER LOOP
                System.out.print("*");
            }
            for(int j=1;j<=8-2*i;j++){                    // SECOND INNER LOOP( BY PLOTTING IN PAGE GET FORMULAS LIKE THIS)
                System.out.print(" ");
            }
            for(int j=1;j<=i;j++){                        // THIRD INNER LOOP
                System.out.print("*");
            }
            System.out.println();
        }
        for(int i=4;i>=1;i--){                            //EVERY THING SAME AS ABOVE ONLY CHANGE IN OUTER LOOP TO REVERSE IT
            for(int j= 1;j<=i;j++){
                System.out.print("*");
            }
            for(int j=1;j<=8-2*i;j++){
                System.out.print(" ");
            }
            for(int j=1;j<=i;j++){
                System.out.print("*");
            }
            System.out.println(); 
        }
            // ??????????????????????????????????HOLLOW BUTTERFLY PATTERN
 }

}




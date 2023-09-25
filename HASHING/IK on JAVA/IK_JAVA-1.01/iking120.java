//INVERTED TRIANGLE(ROTATED BY 180 DEGREE ANTI CLOCKWISE)

/**
 * iking120
 */
public class iking120 {

    public static void main(String args[]){
        
        for(int i=1;i<=7;i++){                              //OUTER LOOP
                                          
            for(int j=1;j<=7-i;j++){                        // FIRST INNER LOOP   FOR i=1 j GOES FROM 1 TO 6
                System.out.print(" ");                                         // FOR i=3 j GOES FROM 1 TO 4

            }
            for(int j=1;j<=i;j++){                         // SECOND INNER LOOP
                System.out.print("*");                  // VARIABLE USE IN {} AFTER THAT WE CAN USE IT AS HERE J USED TWICE
            }                                             // SECOND LOOP WILL WORK AFTER FIRST LETTERS AND WILL NOT OVERLAPP
            System.out.println();
        }
    }
}
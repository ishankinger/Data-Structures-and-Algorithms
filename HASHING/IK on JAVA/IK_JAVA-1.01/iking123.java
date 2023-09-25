// FLOYD'S TRIANGLE
/**
 * iking123
 */
public class iking123 {

    public static void main(String args[]){
        int number=1;                                 // DEFINING THAT NUMBER WHICH TO PRINTED
    for(int i=0;i<=5;i++){
        for(int j=0;j<=i;j++){
           
            System.out.print(number+" ");             // AS LOOP RUNS SO EVERY TIME THERE WILL BE ADDITION OF ONE NUMBER
            number++;                                // WE CAN USE FOR NUMBER = NUMBER+1
        }                                            // AS WHEN LOOP MOVES EACH TIME THE NUMBER GET INCREASE BY ONE 
        System.out.println();                        // THIS FOR NEXT LINE
    }

    }
}
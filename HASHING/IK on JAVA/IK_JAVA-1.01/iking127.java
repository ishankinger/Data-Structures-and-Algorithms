     // DIFFERENT PATTERNS OF PYRAMIDS
/**
 * iking127
 */
     
         // NUMBER PYRAMID

 public class iking127 {

    public static void main(String args[]){
        
        for(int i=1;i<=5;i++){                         // OUTER LOOP
           
         for(int j=1;j<=5-i;j++){                      // FIRST INNER LOOP
                System.out.print(" ");
            }
           
            for(int j=1;j<=i;j++){                     // SECOND INNER LOOP
               System.out.print(i+" ");                // IN Ith LINE THERE IS I NUMBER PRINTED I TIMES
            }           
              System.out.println();

        }
        System.out.println("   ");
       
        // INVERTED NUMBER PYRAMID          
      
        for(int i=1;i<=5;i++){                          // OUTER LOOP
          
            for(int j=0;j<=i-1;j++){                    // FIRST INNER LOOP
                System.out.print(" ");
            }
            for(int j=1;j<=6-i;j++){                    // SECOND INNER LOOP
                System.out.print(i+" ");                // SIMILAR TO ABOVE BUT CHANGE CONDITION
            }
            System.out.println();
        }
        System.out.println(); 
        
         // HALF PYRAMID
           
          for(int i=1;i<=5;i++){                          // OUTEER LOOP
            
            for(int j=1;j<=5-i;j++){                      // FIRST INNER LOOP
                System.out.print(" ");
            }
            for(int j=1;j<=i;j++){                        // SECOND INNER LOOP
                System.out.print(j+" ");                  // PRINTED NUMBER LIKE 1 2 3 SO HERE WE USE J IN SYSO
            }
            System.out.println();
          }

}
}


    


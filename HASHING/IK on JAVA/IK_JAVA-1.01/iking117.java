// HOLLW RECTANGLE                                       IMAGINE IT AS A XY AXIS IN WHICH(i,j) IS TO BE PLOTED 


/**
 * iking117
 */
public class iking117 {

    public static void main(String args[]){
    for(int i=1;i<=5;i++){                                //OUTER LOOP
        
        for(int j=1;j<=7;j++){                            //INNER LOOP
            
            if(i==1||j==1||i==5||j==7) {                   //IN THESE LINES ONLY THE STAR OCCURS         '||'--> MEANS 'OR'
            System.out.print("*");
            }else{
                System.out.print(" ");                 //OTHER POINTS HAVE NO STAR SO DO SPACE BAR
            }

        }
        System.out.println();                             //WAY TO WRITE THIS
                                                          // THIS IS WHEN LOOP MOVES EACH TIME WE SHIFT TO NEXT LINE
    }                                
    }
}

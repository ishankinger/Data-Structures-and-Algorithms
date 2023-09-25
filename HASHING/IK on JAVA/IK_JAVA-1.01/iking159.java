// OPERATORS(INCREMENT AND DECREMENT)
/**
 * iking159
 */
public class iking159 {

    public static void main(String args[]){
        int j= 5;
        System.out.println(j++);                    // FIRST J PRINTED AND THEN  INCREMENTED
        
        System.out.println(j);
       
        System.out.println(++j);                    // FIRST J INCREMENTED AND THEN PRINTED
       
        System.out.println(j);
                                                    // SIMILAR FOR DECREMENTED USE J-- AND --J

                                                    // INCREMENT HAS MORE PRECENDENCE THAN *
        
     //PRE INCREMENT AND POST INCREMENT
      
        int a= 10;                                    
        int b=0;
        b=a++;                                              
        System.out.println(a);
        System.out.println(b);
        b=++a;
        System.out.println(a);
        System.out.println(b);
    }
}

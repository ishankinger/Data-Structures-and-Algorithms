//OUTPUTS AND VARIABLES WITH DATATYPES

/**
 * iking101
 */
 public class iking101{
    public static void main(String args[]){
        System.out.println("HELLO WORLD ISHAN HERE");               // ALWAYS END WITH ' ; '  OR '  {} '         
                                                                    
                                                                      //IN "" SAME PRINTING OCCUR                                  
        System.out.println("how are you?");
        
        System.out.println("*");
        
        System.out.println("**\n***\n****");                        // '\n ' MEANS NEXT LINE 
        
        int a=10;
        int b=25;       
                                                                   // ASSIGNMENT OPERATORS
        b *= 2;                                                    //MEANS FURTHER CHANGE IN VALUE NOW VALUE OF b IS 50
                                                                   // SIMILARLY WE CAN USE  +=  -=  /= 

        float sum=a+b ;
       
        System.out.println(sum);                                   // WITHOUT "" PRINTING NOT OCCURS
        
        int mul=a*b;
       
        System.out.println(mul);
        
        System.out.println(mul/sum);
       
        System.out.println(mul-sum);

        int k = 6*5-34/2;                                         //BODMAS IS NOT APPLIED IN JAVA 
        
        System.out.println(k);                                    //PRECENDENCE AND ASSOCIAVITY
       
        int i= 60/5-34*2;
       
        System.out.println(i);                                    // * / HAVE MORE PRECEDENCE THAN +-
                                                                  // ASSOCIATIVITY OF * / IS FROM LEFT TO RIGHT
                                                                  // () HIGHEST PRESISTENCE
                                                                  // SQUARES ARE WRITTEN LIKE a*a
    }
}
// REMOVE ALL DUPLICATES(SIMILAR TYPE OF CHAR EDITED TO ONLY ONE AND WE GET NEW STRING)
/**
 * iking213
 */
public class iking213 {

    public static boolean[] map= new boolean[26];      // ARRAY OF BOOLEAN TYPE OF ENGLISH ALPHABETS(a,b,c,d,e,f,g,...)
                                                                                                //   0,1,2,3,4,5,6,...idx
    public static void removeDuplicates(String str, int idx, String newString){
       if(idx==str.length()){
        System.out.println(newString);                  // AND AT END WE WILL REACH TO OUR  NEW STRING
        return;
       }
        char currChar= str.charAt(idx);
        if(map[currChar-'a']==true){                     // TRUE IN ARRAY MEANS THAT IT IS ALREADY NOTED 
            removeDuplicates(str,idx+1,newString);       // SO NOTHING TO DO WITH IT
        }else{
            newString += currChar;                       // FALSE MEANS IT IS FIRST TIME OF IT AND WE HAVE TO ADD IT
            map[currChar-'a']=true;                      // ALSO CONVEERT IT TO TRUE FROM FALSE
            removeDuplicates(str,idx+1,newString);       // AND THEN MOVED FURTHER
        }
    }
    public static void main(String args[]){               // ABOVE MAP VARIABLE CAN BE INTEGER OR ANY OTHER DATATYPES ALSO SO WHAT 
        String str="abbcdacddabb";                        // THE THING IS WE ARE JUST GIVING US A WAY TO ADD AS FOR INT WE USE 1,2
        removeDuplicates(str,0,"");        // IN PLACE WHERE TRUE IS WRITTEN
    }
}
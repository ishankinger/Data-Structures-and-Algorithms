// PLACE TILES OF 1*M INTO FLOOR OF N*M
/**
 * iking219
 */
public class iking219 {

    public static int countTiles(int n, int m){
        if(n==m){                                              // CONDITION  1
            return 2;                                          // ONLY ALL HORIZONTAL OR ALL VERTICAL
        }
        if(n<m){                                               // CONDITION  2
            return 1;                                          // ONLY ALL HORIZONTAL
        }
        int vertPlac=countTiles(n-m,m);
        int horzPlac=countTiles(n-1,m);
        return vertPlac+horzPlac;                             // SIMILAR CONCEPT AS THAT OF LAST ONE
    }
    public static void main(String args[]){
        System.out.println(countTiles(4,2));
    }
}
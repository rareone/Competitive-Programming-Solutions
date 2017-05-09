import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
        public static void main(String []arg){
        Scanner cin= new Scanner(System.in);
        while(cin.hasNextBigInteger()){
            BigInteger i=cin.nextBigInteger();
            if(i.equals(BigInteger.ZERO)){return;}
            else if(i.mod(BigInteger.valueOf(17))==BigInteger.ZERO){
                System.out.println(1);
            }else{
                System.out.println(0);
            }
        }
    }
}

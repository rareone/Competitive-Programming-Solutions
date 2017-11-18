import java.lang.*;
import java.util.*;
import java.math.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextBigInteger()){
			BigInteger A=cin.nextBigInteger();
			String s=cin.next();
			BigInteger B=cin.nextBigInteger();
			if(s.charAt(0)=='%'){
				System.out.println(A.mod(B).toString());
			}else{
				System.out.println(A.divide(B).toString());
			}
		}
	}
}

import java.lang.*;
import java.util.*;
import java.math.*;

public class Main {
	static BigInteger reverseN(BigInteger A){
		BigInteger Ans=BigInteger.ZERO;
		for(;A.compareTo(BigInteger.ZERO)!=0;A=A.divide(BigInteger.TEN)){
			Ans=Ans.multiply(BigInteger.TEN).add(A.mod(BigInteger.TEN));
		}
		return Ans;
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T=cin.nextInt();
		while(T!=0){
			--T;
			BigInteger A=cin.nextBigInteger(),B=cin.nextBigInteger();
			System.out.println(reverseN(reverseN(A).add(reverseN(B))).toString());
		}
	}
}

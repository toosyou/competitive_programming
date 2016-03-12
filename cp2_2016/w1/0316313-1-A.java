import java.io.*;
import java.util.*;
import java.math.*;

class Scan{
	BufferedReader buffer;
	StringTokenizer tok;

	Scan(){
		buffer = new BufferedReader( new InputStreamReader(System.in) );
	}

	boolean hasNext(){
		while( tok == null || !tok.hasMoreElements()){
			try{
				tok = new StringTokenizer(buffer.readLine());
			}catch(Exception e){
				return false;
			}
		}
		return true;
	}

	String next(){
		if(hasNext()) return tok.nextToken();
		return null;
	}

	String nextLine(){
		if(hasNext()) return tok.nextToken("\n");
		return null;
	}

	int nextInt(){return Integer.parseInt(next()); }

	long nextLong(){ return Long.parseLong(next()); }

	double nextDouble(){ return Double.parseDouble(next()); }

}

public class Main {

	public static void main(String[] args){

		Scan input = new Scan();

		while(input.hasNext()){

			int radix_a = input.nextInt();
			int radix_b = input.nextInt();
			if(radix_a == 0 && radix_b == 0)
				break;

			String str = input.nextLine();
			BigInteger bint = new BigInteger( str, radix_a );
			System.out.printf("%s%n",bint.toString(radix_b).toUpperCase());

		}

	}

}
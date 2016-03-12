import java.io.*;
import java.util.*;

class Scan{
	BufferedReader buffer;
	StringTokenizer tok;

	Scan(){
		buffer = new BufferedReader(new InputStreamReader(System.in));
	}

	Boolean hasNext(){
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
		if(hasNext())
			return tok.nextToken();
		return null;
	}

	int nextInt(){
		return Integer.parseInt(next());
	}

}

public class Main{

	public static void main(String[] args){

		Scan input = new Scan();
		PrintWriter output = new PrintWriter(System.out, false);
		int T = input.nextInt();

		for(int k=0;k<T;++k){

			int p = input.nextInt();

			output.printf("%s%n", isPrime(p) ? "yes" : "no" );
		}

		output.flush();

	}

	public static Boolean isPrime(int input){
		if(input <= 1)
			return false;

		for(int i=2;i*i<=input;++i){
			if(input % i == 0)
				return false;
		}
		return true;
	}

}
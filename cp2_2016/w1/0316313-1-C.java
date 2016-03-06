import java.io.*;
import java.util.*;

class Scan{
	BufferedReader buffer;
	StringTokenizer tok;

	Scan(){
		buffer = new BufferedReader(new InputStreamReader(System.in));
	}
	Scan(String inputString){
		buffer = new BufferedReader(new StringReader(inputString));
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
		if(hasNext()){
			return tok.nextToken();
		}
		return null;
	}

	String nextLine(){
		if(hasNext()){
			return tok.nextToken("\n");
		}
		return null;
	}

	long nextLong(){
		return Long.parseLong(next()); 
	}
}

public class Main{

	public static void main(String[] args){

		Scan input = new Scan();
		PrintWriter output = new PrintWriter(System.out);

		while(input.hasNext()){

			long result = (long)0;
			Scan intLine = new Scan(input.nextLine());

			while(intLine.hasNext()){
				result += intLine.nextLong();
			}

			output.printf("%d%n",result);

		}

		output.flush();

	}

}
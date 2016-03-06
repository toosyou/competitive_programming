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

	long nextLong(){
		return Long.parseLong(next());
	}

	int nextInt(){
		return Integer.parseInt(next());
	}
}

public class Main{

	public static void main(String[] args){

		Scan input = new Scan();
		PrintWriter output = new PrintWriter(System.out,false);
		int T = input.nextInt();

		for(int k=0;k<T;++k){

			long x = input.nextLong();
			long y = input.nextLong();
			String command = input.next();

			while(!command.equals("END")){

				switch(command){
					case "L":
						x -= input.nextLong();
						break;
					case "U":
						y += input.nextLong();
						break;
					case "R":
						x += input.nextLong();
						break;
					case "D":
						y -= input.nextLong();
						break;
				}

				command = input.next();
			}

			output.printf("%d %d%n",x,y);

		}

		output.flush();
	}

}
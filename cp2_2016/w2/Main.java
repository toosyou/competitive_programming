import java.util.*;
import java.io.*;

class QuickScanner{
	BufferedReader buffer;
	StringTokenizer tok;

	QuickScanner(){
		buffer = new BufferedReader(new InputStreamReader(System.in));
	}

	Boolean hasNext(){
		while( tok == null || !tok.hasMoreElements() ){
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
		QuickScanner input = new QuickScanner();
		PrintWriter output = new PrintWriter(System.out, true);
		Comparator<Integer> c = new Comparator<Integer>(){
			public int compare(int a, int b){
				return a > b ? 1 : -1;
			}
		};
		PriorityQueue lowQueue = new PriorityQueue(c);
		PriorityQueue highQueue = new PriorityQueue(c);

		while( input.hasNext() ){

			
			int inputCommand = input.nextInt();
			while( inputCommand != 0 ){

				lowQueue.add(inputCommand);

				inputCommand = input.nextInt();
			}
			int tmp = 0;
			while( (tmp = lowQueue.poll())!=null ){
				output.printf("%d ", tmp);
			}
		}
	}
}
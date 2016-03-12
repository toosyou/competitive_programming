import java.io.*;
import java.util.*;

class QuickScan{
	BufferedReader buffer;
	StringTokenizer tok;

	QuickScan(){
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

		QuickScan input = new QuickScan();
		PrintWriter output = new PrintWriter(System.out, false);
		int[] inputInt = new int[1001];

		int t = input.nextInt();
		while( t != 0 ){
			Boolean breakFlag = false;
			for(int i=0;i<t;++i){
				inputInt[i] = input.nextInt();
				if( i == 0 && inputInt[i] == 0 ){
					breakFlag = true;
					break;
				}
			}
			if(breakFlag == true){
				t = input.nextInt();
				output.printf("%n");
				continue;
			}

			int now = 0;
			Stack<Integer> stk = new Stack<Integer>();
			for(int i=1;i<=t;++i){
				stk.push(i);

				while( !stk.empty() ){
					if( stk.peek() == inputInt[now] ){
						stk.pop();
						now++;
					}
					else{
						break;
					}
				}
			}

			if( stk.empty() )
				output.printf("Yes%n");
			else
				output.printf("No%n");

		}
		output.flush();
	}
}
import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
        QuickScanner input = new QuickScanner();
        PrintWriter output = new PrintWriter(System.out, false);

        Integer[] inputNumber = new Integer[100001];
        Boolean findSolution = false;
        int n = input.nextInt();
        for(int i=0;i<n;++i){
            inputNumber[i] = input.nextInt();
        }

        Arrays.sort( inputNumber, 0, n, new reverseIntegerComparator() );
        for(int i=0;i<n;++i){
            if( inputNumber[i] <= n-i-1 ){
                output.printf("%d%n", n-i);
                findSolution = true;
                break;
            }
        }
        if(!findSolution)
            output.printf("0%n");


        output.flush();
    }
}

class reverseIntegerComparator implements Comparator<Integer>{
    @Override
    public int compare(final Integer a,final Integer b){
        if( a < b )
            return 1;
        return -1;
    }

}

class QuickScanner{
    BufferedReader buffer;
    StringTokenizer tok;

    QuickScanner(){
        buffer = new BufferedReader(new InputStreamReader(System.in));
    }

    Boolean hasNext(){
        while( tok == null || !tok.hasMoreElements() ){
            try{
                tok = new StringTokenizer( buffer.readLine() );
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

    int nextInt(){
        return Integer.parseInt(next());
    }
}

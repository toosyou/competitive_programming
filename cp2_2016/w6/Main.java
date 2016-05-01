import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
        QuickScanner input = new QuickScanner();
        PrintWriter output = new PrintWriter(System.out, false);


        output.flush();
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

package mypkg;

/**
 *
 * @author xerxes
 */
import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;
import java.text.*;

public class Main {

    /**
     * @param args the command line arguments
     */
    BufferedReader reader;
    StringTokenizer token;
    int N;
    int Q;
    int[] vi;
    int D;
    int M;
    long[][][] cando ;
    
    public static void main(String[] args) throws IOException {
        Main ob = new Main();
        ob.Run();
        System.exit(0);
    }

    public void Run() throws IOException {
        //reader = new BufferedReader( new InputStreamReader(System.in) );
        reader = new BufferedReader(new FileReader("in"));
        token = new StringTokenizer("");
        int kase = nextInt();
        for (int i = 1; i <= kase; ++i) {
            N = nextInt();
            Q = nextInt();
            vi = new int[N];
            for (int j = 0; j < N; ++j) {
                vi[j] = nextInt();
            }
            Proc(i);
        }
    }
    

    public void ini() throws IOException {
        for (int i = 0; i < N+1; ++i) {
            for (int j = 0; j < M+1; ++j) {
                for (int k = 0; k < D+1; ++k) {
                    cando[i][j][k] = -1;
                }
            }
        }
    }

    public void Proc(int kase) throws IOException {
        System.out.printf("Case %d:\n", kase);
        while (Q > 0) {
            D = nextInt();
            M = nextInt();
            cando = new long[ N+1 ][ M+1 ][ D+1 ];
            ini();
            long retval = go(0, M, 0);
            System.out.println(retval);
            --Q;
        }
    }

    public int modifiedMod( int num, int mod){
        int result = num%mod;
        if( result < 0 )result+=mod;
        return result;
    }
    public long go(int id, int taken, int sum) {

        if (taken == 0) {
            if (sum == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        if (id == N) {
            return 0;
        }
        if( cando[id][taken][sum]!=-1){
            return cando[id][taken][sum];
        }
        long ways = 0;
        
        ways+= go(id + 1, taken - 1, modifiedMod( vi[id]+sum ,D) );
        ways+= go(id + 1, taken, sum);

        cando[id][taken][sum]=ways;
        return ways;

    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (token == null || !token.hasMoreTokens()) {
            String line = reader.readLine();
            token = new StringTokenizer(line);
        }
        return token.nextToken();
    }
}

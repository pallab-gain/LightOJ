/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

/**
 * @author xerxes
 * May 14, 2012
 * I have not failed, I have just found 10000 ways that won't work.
 */
import java.io.*;
import java.awt.*;
import java.text.*;
import java.math.*;
import java.util.*;
import java.lang.*;

public class Main implements Runnable {

    final String filename = "in";

    public static void main(String[] args) {
        // new Thread(new Main()).start();
        new Thread(null, new Main(), "1", 1 << 25).start();
    }

    public void run() {
        try {
            //in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                //TODO CODE HERE
                solve1261(i);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    int[][] choices;
    int[] solution;

    public void solve1261(int kaseno) throws Exception {
        out.write("Case " + kaseno + ": ");
        int n = 0, m = 0, k = 0;
        n = iread();
        m = iread();
        k = iread();
        choices = new int[n][k];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                String value = readword();
                int tmp = Integer.parseInt(value.substring(1));
                if (value.charAt(0) == '+') {
                    choices[i][j] = tmp; // need
                } else {
                    choices[i][j] = -tmp; // don't need
                }
            }

        }
        
        solution = new int[40];
        Arrays.fill(solution, -1);
        int p = iread();
        for (int i = 0; i < p; ++i) {
            solution[ iread() ] = 1;
        }

        boolean good = true;
        for(int i=0;i<n;++i){
            boolean nice=false;
            for(int j=0;j<k;++j){
                int tmp = choices[i][j];
                int var = Math.abs(tmp);
                if( tmp<0 && solution[ var]==-1 ){
                    nice|=true;
                }
                if( tmp>=0 && solution[var]==1 ){
                    nice|=true;
                }
            }
            good&=nice;
        }
        out.write((good == true ? "Yes" : "No") + "\n");
    }

    public void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public int iread() throws Exception {
        return Integer.parseInt(readword());
    }

    public double dread() throws Exception {
        return Double.parseDouble(readword());
    }

    public long lread() throws Exception {
        return Long.parseLong(readword());
    }
    BufferedReader in;
    BufferedWriter out;

    public String readword() throws IOException {
        StringBuilder b = new StringBuilder();
        int c;
        c = in.read();
        while (c >= 0 && c <= ' ') {
            c = in.read();
        }
        if (c < 0) {
            return "";
        }
        while (c > ' ') {
            b.append((char) c);
            c = in.read();
        }
        return b.toString();
    }
}

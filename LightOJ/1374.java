/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

/**
 *
 * @author xerxes
 */
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;
import java.lang.*;

public class Main implements Runnable {

    final String filename = "in";

    public static void main(String[] args) {
        new Thread(null, new Main(), "1", 1 << 25).start();
    }

    public void run() {
        try {
            //in = new BufferedReader( new InputStreamReader(System.in) );
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            in = new BufferedReader(new FileReader(filename + ".in"));
            //out = new BufferedWriter(new FileWriter(filename+".out") );
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                run1374(i);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void run1374(int kaseno) throws Exception {
        int N = iread();
        int[] P = new int[10010];
        for (int i = 0; i < N; ++i) {
            int x = iread();
            if (x > N || x < 0) {
                continue;
            }
            P[x] += 1;
        }
        out.write("Case " + kaseno + ": ");
        for (int page = 1; page <= N; ++page) {
            int pichoneAse = page - 1;
            int samneAse = N - page;
            if (P[pichoneAse] > 0) {
                P[pichoneAse] -= 1;
                continue;
            } else if (P[samneAse] > 0) {
                P[samneAse] -= 1;
                continue;
            } else {
                out.write("no\n");
                return ;
            }
        }
        out.write("yes\n");

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

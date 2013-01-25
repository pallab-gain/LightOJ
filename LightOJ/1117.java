/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

/**
 * @author xerxes
 * May 16, 2012
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
                solve1117(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1117(int kaseno) throws Exception {
        long N = lread();
        int M = iread();
        long[] arr = new long[M];
        for (int i = 0; i < M; ++i) {
            arr[i] = lread();
        }

        long ret = 0;
        for (int i = 1, bit = (1 << M); i < bit; ++i) {
            int cnt = Integer.bitCount(i);
            long lc = 1;
            for (int j = 0; j < M; ++j) {
                if ((i & (1 << j)) != 0) {
                    lc = lcm(lc, arr[j]);
                }
            }

            if ((cnt & 1) == 0) {
                ret -= Count(N, lc);

            } else {
                ret += Count(N, lc);
            }
        }
        out.write("Case " + kaseno + ": " + (N - ret) + "\n");
    }

    public long gcd(long a, long b) {
        while (b > 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

    public long Count(long num, long div) {
        return (num / div);
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

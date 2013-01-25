/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package mypkg;

/**
 *
 * @author xerxes
 */
import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

    final String filename = "in";

    public static void main(String[] args) {
        // new Thread(new Main()).start();
        new Thread(null, new Main(), "1", 1 << 25).start();
    }

    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            //in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                solve1179(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1179(int kaseno) throws Exception {
        long N = lread();
        long K = lread();
        out.write("Case "+kaseno+": "+ (joseph(N,K)+1) +"\n");
    }

    public long joseph(long n, long k) {
        if (n == 1) {
            return 0;
        }
        if (k == 1) {
            return n - 1;
        }
        if (k > n) {
            return (joseph(n - 1, k) + k) % n;
        }
        long cnt = n / k;
        long res = joseph(n - cnt, k);
        res -= n % k;
        if (res < 0) {
            res += n;
        } else {
            res += res / (k - 1);
        }
        return res;
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


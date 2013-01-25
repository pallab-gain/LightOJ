/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

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
                try1248(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void try1248(int kaseno) throws Exception {
        int nth = iread();
        double ret = nth*Hn(nth);
        DecimalFormat df = new DecimalFormat("#.#########");
        out.write("Case " + kaseno + ": " + df.format(ret) + "\n");
    }

    public double expected(int elements) {
        double ret = 0.0;
        for (int i = elements - 1; i > 0; i--) {
            ret += ((double) (i) / (elements - i));
        }
        return ret + elements;
    }
    final double gammaa = 0.5772156649;
    final double Bn[] = {1.0 / 6.0, -1.0 / 30.0, 1.0 / 42.0, -1.0 / 30.0, 5.0 / 66.0};
//calculates n-th Harmonic number
//Hn = 1 + 1/2 + 1/3 + ..... + 1/n
    public double Hn(int n) {
        if (n <= 0) {
            return 0;
        }
        double r = 0;
        int i;
        if (n <= 1000) {
            for (i = 1; i <= n; i++) {
                r += (1.0 / (double) i);
            }
            return r;
        }
        r = Math.log(n) + gammaa + .5 / n;
        for (i = 0; i < 5; i++) {
            r -= (Bn[i] / (2.0 * (i + 1) * Math.pow(n, 2 * (i + 1))));
        }
        return r;
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


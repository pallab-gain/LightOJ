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
                //TODO CODE HERE
                solve1056(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve1056(int kaseno) throws Exception {
        int length = iread();
        String waste = readword();
        int width = iread();

        double rat1 = length * length + width * width;
        double rat2 = length * length - width * width;
        double tmpArc = Math.sqrt(rat1) * (Math.acos(rat2 / rat1)) + 2D * length;

        //binary search on width
        double lo = 0;
        double hi = 400;
        for (int i = 0; i < 200; ++i) {
            double pivot = (lo + hi) / 2D;
            double Arc = tmpArc * pivot;
            if (Arc >= 400D) {
                hi = pivot;
            } else {
                lo = pivot;
            }

        }

        double retLength = hi*length;
        double retWidth = hi*width;

        Format df = new DecimalFormat("0.0000000");
        out.write("Case " + kaseno + ": " + df.format(retLength) + " " + df.format(retWidth) + "\n");
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

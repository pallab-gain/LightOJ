/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 * @author xerxes
 * May 17, 2012
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
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
//            in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                //TODO CODE HERE
                solve1118(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    final double eps = 1e-9;
    public void solve1118(int kaseno) throws Exception {
        double[] A = {dread(), dread()};
        double r = dread();
        double[] B = {dread(), dread()};
        double R = dread();
        if (R < r) {
            double t = r;
            r = R;
            R = t;
        }
        Format df = new DecimalFormat("0.000000000");
        double d = Math.hypot( A[0]-B[0], A[1]-B[1]);
        if (d - (r + R) >eps ) {
            out.write("Case " + kaseno + ": 0.000000000\n");
        }
        else if( d-Math.abs(R-r)<=eps ){
            double ret = Math.PI*r*r;
            out.write("Case " + kaseno + ": " + df.format(ret) + "\n");
        } else {
            double part1 = r * r * Math.acos((d * d + r * r - R * R) / (2D * d * r));
            double part2 = R * R * Math.acos((d * d + R * R - r * r) / (2D * d * R));
            double part3 = 0.5D * Math.sqrt((-d + r + R) * (d + r - R) * (d - r + R) * (d + r + R));

            double intersectionArea = part1 + part2 - part3;
            //debug(d+"_"+ret+"");
            out.write("Case " + kaseno + ": " + df.format(intersectionArea) + "\n");
        }
    }

    public Point readPoint() throws Exception {
        int x = iread();
        int y = iread();
        return new Point(x, y);
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


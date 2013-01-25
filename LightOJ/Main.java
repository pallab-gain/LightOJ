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
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

    final String filename = "in";

    public static void main(String[] args) {
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
                _1048(i);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void _1048(int kaseno) throws Exception {
        int N = iread();
        int M = iread();
        ++N;
        ++M;
        int[] d = new int[N];
        long lo = 0;
        long hi = 0;
        for (int i = 0; i < N; ++i) {
            d[i] = iread();
            hi += d[i];
        }

        long best = hi;
        while (lo + 100 < hi) {
            long pivot = (lo + hi) / 2;
            if (Possible(N, M, pivot, d)) {
                hi = pivot;
                best = Math.min(best, pivot);
            } else {
                lo = pivot;
            }
        }
        for (long i = lo; i <= hi; ++i) {
            if (Possible(N, M, i, d)) {
                best = Math.min(best, i);
                break;
            }
        }
        out.write("Case " + kaseno + ": " + best + "\n");
        int tcal = 0;
        for (int i = 0; i < N;) {
            if (tcal + M >= N) {
                out.write(d[i] + "\n");
                ++i;
                continue;
            }
            long cur = d[i];
            for (++i; i < N; ++i) {
                if (cur + d[i] <= best) {
                    cur += d[i];
                    ++tcal;
                } else {
                    break;
                }
                if (tcal + M == N) {
                    ++i;
                    break;
                }
            }

            out.write("" + cur + "\n");
        }

    }

    public boolean Possible(int N, int M, long pivot, int[] d) {
        int tcal = 0;
        for (int i = 0; i < N;) {
            long cur = d[i];
            if (cur > pivot) {
                return false;
            }
            for (++i; i < N; ++i) {
                if (cur + d[i] <= pivot) {
                    cur += d[i];
                    ++tcal;
                } else {
                    break;
                }
            }

        }
        return tcal + M >= N ? true : false;
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

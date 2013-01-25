package lightoj;

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
            //in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                solve(i);
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public void solve(int kaseno) throws Exception {

        int k = iread();
        int c = iread();
        int n = iread();
        int p = iread();
        long[] a = new long[n];
        a[0] = p;
        for (int i = 1; i < n; ++i) {
            a[i] = Get(k, a[i - 1], c);
        }
        Arrays.sort(a);
        debug(a);
        long[] A = new long[n];
        long sum=0;
        for (int i = 0; i < n; ++i) {
            sum+=a[i];
            A[i]=sum;
        }
        sum = 0;
        for (int i = 0; i < n; ++i) {
            long tmp = A[n - 1] - A[i];
            long baki = n - (i + 1);
            sum += Math.abs(tmp - (baki * a[i]));
        }
        out.write("Case " + kaseno + ": " + sum + "\n");

    }

    public long Get(long K, long a, long C) {
        return ( (K * a) + C) % 1000007;
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

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg1086;

/**
 * 1086
 *
 * @author xerxes
 * 8:10:11 AM  May 21, 2012
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
                solve(i);
            }
            out.flush();
        } catch (Exception e) {
            //e.printStackTrace();
            System.exit(1);
        }
    }
    int[][] adj = new int[15][15];
    final int inf = 1023456789;
    int[] inDegree = new int[15];
    int[] outDegree = new int[15];
    int[] dp = new int[1 << 15];

    public void solve(int kaseno) throws Exception {
        out.write("Case " + kaseno + ": ");
        int N = iread();
        int E = iread();
        for (int[] Ee : adj) {
            Arrays.fill(Ee, inf);
        }
        Arrays.fill(inDegree, 0);
        Arrays.fill(outDegree, 0);
        Arrays.fill(dp, -1);
        int u, v, t;
        int ret = 0;
        for (int i = 0; i < E; ++i) {
            u = iread() - 1;
            v = iread() - 1;
            t = iread();
            ret = ret + t;
            inDegree[u] += 1;
            outDegree[v] += 1;

            adj[u][v] = Math.min(adj[u][v], t);
            adj[v][u] = Math.min(adj[v][u], t);
        }

        Floyedwarshal(N);
        int MSK = findRepeat(N);
        int res = ret + go(MSK, N);
        out.write(res + "\n");
    }

    public int go(int msk, int N) {
        if (msk == 0) {
            return 0;
        }
        if (dp[msk] >= 0) {
            return dp[msk];
        }
        int local = inf;
        for (int i = 0; i < N; ++i) {
            if (AND(msk, i) != 0) {
                for (int j = 0; j < N; ++j) {
                    if (i == j) {
                        continue;
                    }
                    if (AND(msk, j) != 0) {
                        int tmplocal = adj[i][j] + go(Clear(Clear(msk, i), j), N);
                        local = Math.min(local, tmplocal);
                    }
                }
            }
        }
        return dp[msk] = local;
    }

    public int findRepeat(int N) {
        int msk = 0;
        for (int i = 0; i < N; ++i) {
            if (((inDegree[i] + outDegree[i]) & 1) != 0) {
                msk |= (1 << i);
            }
        }
        return msk;
    }

    public void Floyedwarshal(int N) {
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    public int OR(int msk, int bit) {
        return (msk | (1 << bit));
    }

    public int AND(int msk, int bit) {
        return (msk & (1 << bit));
    }

    public int Clear(int msk, int bit) {
        return (msk & (~(1 << bit)));
    }

    public boolean marked(int msk, int bit) {
        return (AND(msk, bit) != 0);
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

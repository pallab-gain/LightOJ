/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package pkg1106;

/**
 * 1106
 *
 * @author xerxes
 * 12:34:39 PM  May 24, 2012
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
            //in = new BufferedReader(new FileReader(filename + ".in"));
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
    int[] fi;
    int[] di;
    int[] ti;
    int N, allocaltedTime;
    int[][] dp;
    int[] lst;
    final int maxn = 1000;

    public void solve(int kaseno) throws Exception {
        out.write("Case " + kaseno + ":\n");
        N = iread();
        allocaltedTime = iread() * 60;
        fi = new int[N + 5];
        di = new int[N + 5];
        ti = new int[N + 5];
        dp = new int[N + 5][allocaltedTime + 5];
        lst = new int[N+5];
        
        for (int i = 0; i < N; ++i) {
            fi[i] = iread();
        }
        for (int i = 0; i < N; ++i) {
            di[i] = iread();
        }
        for (int i = 0; i < N - 1; ++i) {
            ti[i] = iread();
        }

        for (int[] e : dp) {
            Arrays.fill(e, -1);
        }
        
        int ret = go(0, 0);
        backTrack(0, 0, ret);
        out.write(""+lst[0]);
        for(int i=1;i<N;++i){
            out.write(", "+lst[i]);
        }
        out.write("\nNumber of fish expected: " + ret + "\n");

    }

    public void backTrack(int at, int curTime, int curFish) {
        if (curTime >= allocaltedTime) {
            return;
        }
        if (at >= N) {
            return;
        }
        int d = (allocaltedTime - curTime) / 5;
        for (int i = d; i > 0; --i) {
            int nxtTime = curTime + (i * 5);
            int Fish = Get(fi[at], di[at], i);
            int tmp = Fish + go(at + 1, nxtTime + (5 * ti[at]));
            if (tmp == curFish) {
                lst[at] = i*5;
                backTrack(at + 1, nxtTime + (5 * ti[at]), curFish - Fish);
                return;
            }
        }
        int tmp = go(at + 1, curTime + (5 * ti[at]));
        if (tmp == curFish) {
            backTrack(at + 1, curTime + (5 * ti[at]), curFish);
            return;
        }
    }

    public int go(int at, int curTime) {
        if (curTime >= allocaltedTime) {
            return 0;
        }
        if (at >= N) {
            return 0;
        }
        if (dp[at][curTime] != -1) {
            return dp[at][curTime];
        }
        int ret = 0;
        int d = (allocaltedTime - curTime) / 5;
        for (int i = d; i > 0; --i) {
            int nxtTime = curTime + (i * 5);
            int Fish = Get(fi[at], di[at], i);
            int tmp = Fish + go(at + 1, nxtTime + (5 * ti[at]));
            if (tmp > ret) {
                ret = tmp;
            }
        }
        int tmp = go(at + 1, curTime + (5 * ti[at]));
        if (tmp > ret) {
            ret = tmp;
        }

        dp[at][curTime] = ret;
        return ret;
    }

    public int Get(int Fi, int Di, int Nth) {
        int fish = Fi;
        for (int i = 1; i < Nth; ++i) {
            fish += Math.max(0, Fi - (Di * i));
        }
        return fish;
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


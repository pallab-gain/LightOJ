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
import java.util.*;

public class Main implements Runnable {

    final String filename = "in";
    int[] city;
    boolean[] notRoot;
    ArrayList<Integer>[] edges;
    int ret;

    public static void main(String[] args) {
        new Thread(null, new Main(), "1", 1 << 25).start();
    }

    public void run() {
        try {
            //in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            in = new BufferedReader(new FileReader(filename + ".in"));
            //out = new BufferedWriter(new FileWriter(filename+".out") );
            int kase = iread();
            for (int i = 1; i <= kase; ++i) {
                Solve_1219(i);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void Solve_1219(int kaseno) throws Exception {
        int nCity = iread();
        city = new int[nCity]; //number of boy in ith city
        notRoot = new boolean[nCity];
        edges = new ArrayList[nCity];


        for (int i = 0; i < nCity; ++i) {
            int cityNumber = iread();
            int boyCount = iread();
            int edgeCount = iread();
            cityNumber-=1;

            city[cityNumber] = boyCount;
            edges[cityNumber] = new ArrayList<Integer>();
            for (int j = 0; j < edgeCount; ++j) {
                int canGo = iread();
                canGo-=1;
                edges[cityNumber].add(canGo);
                notRoot[canGo] = true;
            }
        }
        int root = 0;
        for (int i = 0; i < nCity; ++i) {
            if (notRoot[i] == false) {
                root = i;
                break;
            }
        }
        ret = 0;
        dfs(root);
        out.write("Case " + kaseno + ": " + ret + "\n");

    }

    public int dfs(int root) {
        int tmp = city[root] - 1;
        for (Integer e : edges[root]) {
            int var = dfs(e);
            tmp += var;
        }
        ret += (tmp < 0 ? -1*tmp : tmp);
        return tmp;
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

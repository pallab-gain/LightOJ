/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg1380;

/**
 * 1380
 *
 * @author xerxes
 * 12:13:37 PM  May 22, 2012
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
            e.printStackTrace();
            System.exit(1);
        }
    }
    Node[] Edges;
    public void solve(int kaseno) throws Exception {
        out.write("Case " + kaseno + ": ");
        int N = iread();
        int E = iread();
        int root = iread();
        Edges = new Node[E];
        int u,v,cost;
        for (int i = 0; i < E; ++i) {
            u = iread();
            v = iread();
            cost = iread();
            Edges[i] = new Node(u,v,cost);
        }
        DirectedMST solve = new DirectedMST(N, E, Edges);
        int ret = solve.Run(root);
        
        out.write( (ret==-1 ? "impossible" : ret )+"\n");
        
    }   

    class DirectedMST {

        final int inf = 1023456789;
        int N;//number of nodes
        int E; // number of edges;
        Node[] edges;
        int[] pre;
        int[] ID;
        int[] vis;
        int[] In;

        DirectedMST(int N, int E, Node[] edges) {
            this.N = N;
            this.E = E;
            this.edges = edges;
            this.pre = new int[N];
            this.ID = new int[N];
            this.vis = new int[N];
            this.In = new int[N];
        }
        public int Run(int root) {
            int ret = 0;
            while (true) {

                //1 :
                for (int i = 0; i < N; ++i) {
                    In[i] = inf;
                }
                for (int i = 0; i < E; ++i) {
                    int u = edges[i].u;
                    int v = edges[i].v;
                    int cost = edges[i].cost;
                    if (cost < In[v] && u != v) {
                        pre[v] = u;
                        In[v] = cost;
                    }
                }
                //If not connected ?
                for (int i = 0; i < N; ++i) {
                    if (i == root) {
                        continue;
                    }
                    if (In[i] == inf) {
                        return -1; // as impossible
                    }
                }

                //2 :
                int cntNode = 0;
                Arrays.fill(ID, -1);
                Arrays.fill(vis, -1);
                In[root] = 0;

                for (int i = 0; i < N; ++i) {
                    ret += In[i];
                    int v = i;
                    while (vis[v] != i && ID[v] == -1 && v != root) {
                        vis[v] = i;
                        v = pre[v];
                    }
                    if (v != root && ID[v] == -1) {
                        for (int u = pre[v]; u != v; u = pre[u]) {
                            ID[u] = cntNode;
                        }
                        ID[v] = cntNode++;
                    }
                }
                if (cntNode == 0) {
                    break;
                }
                for (int i = 0; i < N; ++i) {
                    if (ID[i] == -1) {
                        ID[i] = cntNode++;
                    }
                }

                //3 : 
                for (int i = 0; i < E; ++i) {
                    int u = edges[i].u;
                    int v = edges[i].v;
                    edges[i].u = ID[u];
                    edges[i].v = ID[v];
                    if (edges[i].u != edges[i].v) {
                        edges[i].cost -= In[v];
                    }
                }
                N = cntNode;
                root = ID[root];
            }
            return ret;
        }
    }

    class Node {

        int u;
        int v;
        int cost;

        Node(int u, int v, int cost) {
            this.u = u;
            this.v = v;
            this.cost = cost;
        }
        
        public String toString(){
            return (u+" "+v+" "+cost);
        }
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

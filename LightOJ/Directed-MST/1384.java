/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg1384;

/**
 * 1384
 *
 * @author xerxes
 * 11:56:52 AM  May 23, 2012
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
//            e.printStackTrace();
            System.exit(1);
        }
    }

    public void solve(int kaseno) throws Exception {
        out.write("Case " + kaseno + ": ");
        int numNode = iread();
        int numEdge = iread();
        int maxCost = iread();
        Node[] edges = new Node[numEdge];
        for (int i = 0; i < numEdge; ++i) {
            edges[i] = readnode();
        }

        //debug(edges);
        //have to find maximum bandwidth
        int lo = 0;
        int hi = 1023456789;
        boolean found = false;
        for (int i = 0; i < 100; ++i) {
            int pivot = (lo + hi) / 2;
            int cnt = 0;
            for (int k = 0; k < numEdge; ++k) {
                if (edges[k].bandwidth >= pivot) {
                    ++cnt;
                }
            }
            Node[] newEdges = new Node[cnt];
            for (int k = 0, j = 0; k < numEdge; ++k) {
                if (edges[k].bandwidth >= pivot) {
                    newEdges[j] = new Node(edges[k].u, edges[k].v, edges[k].bandwidth, edges[k].cost);
                    ++j;
                }
            }

            int curCost = new DirectedMST(numNode, cnt, newEdges).Run(0);
            if (Possible(curCost, maxCost) == true) {
                lo = pivot;
                found = true;
            } else {
                hi = pivot;
            }
        }

        out.write((found == false ? "impossible\n" : lo + " kbps\n"));
    }

    public boolean Possible(int curCost, int maxCost) {
        if (curCost == -1) {
            return false;
        }
        return curCost <= maxCost ? true : false;
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
            //System.out.print( Arrays.deepToString(edges));
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

    public class Node {

        int u;
        int v;
        int bandwidth;
        int cost;

        Node(int u, int v, int bandwidth, int cost) {
            this.u = u;
            this.v = v;
            this.bandwidth = bandwidth;
            this.cost = cost;
        }

        @Override
        public String toString() {
            return u + " " + v + " " + bandwidth + " " + cost;
        }
    }

    public Node readnode() throws Exception {
        int u = iread();
        int v = iread();
        int bandwidth = iread();
        int cost = iread();
        return new Node(u, v, bandwidth, cost);
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

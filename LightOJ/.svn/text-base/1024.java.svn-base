/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

    BufferedReader reader;
    StringTokenizer token;
    int n;
    int[] primes = new int[10000];
    int[] good = new int[10000];
    int cnt;

    public void sieve() {
        Arrays.fill(good, -1);
        int sqrtN = (int) Math.sqrt((double) 10000);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (good[i] != 0) {
                for (int j = i * i; j < 10000; j += i) {
                    good[j] = 0;
                }
            }
        }
        cnt = 0;
        primes[cnt] = 2;
        ++cnt;
        for (int i = 3; i <= 10000; i += 2) {
            if (good[i] !=0) {
                primes[cnt] = i;
                ++cnt;
            }
        }
    }
    int[] mex = new int[10000];

    public void fun(int x) {
        for (int i = 0; i < cnt; ++i) {
            if (primes[i] > x) {
                break;
            }
            if (x % primes[i] == 0) {
                int d = 0;
                while (x % primes[i] == 0) {
                    ++d;
                    x /= primes[i];
                }
                mex[i] = Math.max( mex[i],d);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Main ob = new Main();
        ob.run();
        System.exit(0);
    }

    public void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        token = new StringTokenizer("");
        int kase;
        sieve();
        kase = nextInt();
        for (int k = 1; k <= kase; ++k) {
            n = nextInt();
            Arrays.fill(mex, 0);
            for (int i = 0; i < n; ++i) {
                int x = nextInt();
                fun(x);
            }
            System.out.println("Case " + k + ": " + solve());
        }

    }

    public BigInteger solve() {
        BigInteger res = new BigInteger("1");
        for (int i = 0; i < 1229; ++i) {
             if( mex[i]==0 )continue;
             res = res.multiply(  POW( BigInteger.valueOf(primes[i]), mex[i]) );
            //System.out.println(primes[i] + " " + mex[i]);
        }
        return res;
    }

    public BigInteger POW(BigInteger p, int q) {
        BigInteger res = BigInteger.ONE;

        for (; q > 0;) {
            if ((q & 1) != 0) {
                res = res.multiply(p);
            }
            p = p.multiply(p);
            q >>= 1;
        }
        return res;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (token == null || !token.hasMoreTokens()) {
            String line = reader.readLine();
            token = new StringTokenizer(line);
        }
        return token.nextToken();
    }
}

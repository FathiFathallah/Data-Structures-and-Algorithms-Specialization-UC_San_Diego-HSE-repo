// Push and Pop are O(1) in JAVA , but still getting the max number in a stack would be O(n), In this assignment We tried to do it with O(1)

import java.util.*;
import java.io.*;

public class StackWithMax {
    class FastScanner {
        StringTokenizer tok = new StringTokenizer("");
        BufferedReader in;

        FastScanner() {
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (!tok.hasMoreElements())
                tok = new StringTokenizer(in.readLine());
            return tok.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }

    public void solve() throws IOException {
        FastScanner scanner = new FastScanner();
        int queries = scanner.nextInt();
        Stack<Integer> stack = new Stack<Integer>();
        Stack<Integer> stackMax = new Stack<Integer>();
        int max = 0;
        for (int qi = 0; qi < queries; ++qi) {
            String operation = scanner.next();
            if ("push".equals(operation)) {
                int value = scanner.nextInt();
                stack.push(value);
                if(value >= max) {
                    max = value;
                    stackMax.push(max);
                }
            } else if ("pop".equals(operation)) {
                if(stack.pop() == max){
                    stackMax.pop();
                    max = stackMax.peek();
                }
            } else if ("max".equals(operation)) {
                System.out.println(max);
            }
        }
    }

    static public void main(String[] args) throws IOException {
        new StackWithMax().solve();
    }
}

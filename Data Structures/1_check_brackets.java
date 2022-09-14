import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class Bracket {
    Bracket(char type, int position) {
        this.type = type;
        this.position = position;
    }

    boolean Match(char c) {
        if (this.type == '[' && c == ']')
            return true;
        if (this.type == '{' && c == '}')
            return true;
        if (this.type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
}

class check_brackets {
    public static void main(String[] args) throws IOException {
        InputStreamReader input_stream = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input_stream);
        while (true) {
            String text = reader.readLine();

            Stack<Bracket> opening_brackets_stack = new Stack<Bracket>();
            boolean err_free = true;
            int position;
            for (position = 0; position < text.length() && err_free; ++position) {
                char next = text.charAt(position);

                if (next == '(' || next == '[' || next == '{') {
                    Bracket openingBracket = new Bracket(next, position);
                    opening_brackets_stack.push(openingBracket);
                }
                if (next == ')' || next == ']' || next == '}') {
                    if (opening_brackets_stack.isEmpty()) {
                        err_free = false;
                    } else {
                        Bracket openingBracket = opening_brackets_stack.pop();
                        if (!openingBracket.Match(next)) {
                            err_free = false;
                        }
                    }
                }
            }

            if (err_free && opening_brackets_stack.isEmpty()) System.out.println("Success");
            else {
                if (!err_free) {
                    System.out.println(position);
                } else {
                    System.out.println(opening_brackets_stack.pop().position + 1);
                }
            }
        }
    }
}

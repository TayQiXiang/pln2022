import java.util.Arrays;
import java.util.Scanner;

public class StringSubstitution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String firstWord = scanner.nextLine();
        String secondWord = scanner.nextLine();
        if (firstWord.length() != secondWord.length()) {
            System.out.println(-1);
            return;
        }

        // Method call
        stringSubstitution(firstWord, secondWord);
    }

    private static void stringSubstitution(String firstWord, String secondWord) {
        int[] store = new int[26];
        int[] parse = new int[26];
        Arrays.fill(store, -1);
        Arrays.fill(parse, -1);
        int firstTemp, secondTemp;

        for(int i = 0; i < firstWord.length(); i++) {
            firstTemp = firstWord.charAt(i) - 97;
            secondTemp = secondWord.charAt(i) - 97;
            if (store[firstTemp] < 0) {
                if (parse[secondTemp] == -1) {
                    store[firstTemp] = secondWord.charAt(i);
                    parse[secondTemp] = 1;
                } else {
                    System.out.println(-1);
                    return;
                }
            }
            if (secondWord.charAt(i) == store[firstTemp]) {
                if (i == firstWord.length()-1) {
                    System.out.println(1);
                }
            } else {
                System.out.println(-1);
                return;
            }
        }
    }
}

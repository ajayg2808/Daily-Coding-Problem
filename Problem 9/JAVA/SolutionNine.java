import java.util.Scanner;

/**
 * @author Ajay G.
 */
public class SolutionNine {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		String[] str = input.trim().split(" ");
		int[] arr = new int[str.length];
		int i = 0;
		for (String s : str) {
			arr[i] = Integer.parseInt(s.trim());
			i++;
		}

		int prev = 0;
		int large = 0;
		for (int x : arr) {
			int p = prev;
			prev = large;
			large = Math.max(large, p + x);
		}

		System.out.println(large);
	}

}

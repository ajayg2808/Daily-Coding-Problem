import java.util.Scanner;

/**
 * @author Ajay G.
 *
 */
public class SolutionSeven {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("\n Enter encoded message string : ");
		String code = sc.next();
		System.out.println("\n Possible way to decode message : " + getWaysToDecodeCount(code));
	}

	private static int getWaysToDecodeCount(String code) {
		int[] countArr = new int[code.length() + 1];
		countArr[0] = 1;
		countArr[1] = code.charAt(0) != 0 ? 1 : 0;

		for (int i = 1; i < code.length(); i++) {
			if (code.charAt(i) != '0') {
				countArr[i + 1] += countArr[i];
			}
			if (code.charAt(i - 1) != 0 && (10 <= Integer.parseInt(code.substring(i - 1, i + 1))
					&& Integer.parseInt(code.substring(i - 1, i + 1)) <= 26)) {
				countArr[i + 1] += countArr[i - 1];
			}

		}

		return countArr[code.length()];
	}

}


import java.util.Scanner;

/**
 * @author AJAY G.
 */
public class SolutionTwo {
	public static void main(String[] args) {

		int i;
		Scanner sc = new Scanner(System.in);
		System.out.print("\n Number of elements(?) : ");
		int n = sc.nextInt();

		int[] arr = new int[n];

		System.out.print("\n Enter " + n + " array elements : ");
		for (i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}

		int[] leftProd = new int[n];
		int[] rightProd = new int[n];

		leftProd[0] = 1;

		for (i = 1; i < n; i++) {
			leftProd[i] = arr[i - 1] * leftProd[i - 1];
		}
		rightProd[n - 1] = 1;
		for (i = n - 2; i >= 0; i--) {
			rightProd[i] = arr[i + 1] * rightProd[i + 1];
		}

		System.out.print("\n Product Array : ");
		for (i = 0; i < n; i++) {
			System.out.print(leftProd[i] * rightProd[i] + "  ");
		}

	}

}

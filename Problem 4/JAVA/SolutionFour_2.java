import java.util.Scanner;

/**
 * @author AJAY G.
 * It will not work if positive duplicates numbers are in array.
 */
public class SolutionFour_2 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		System.out.print("\n Enter no of elements : ");
		int n = sc.nextInt();

		int[] arr = new int[n];

		System.out.print("\n Enter " + n + " array elements : ");
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int result = firstMissingPositive(arr, n);
		System.out.println("\n First missing positive integer : " + result);
	}

	private static int firstMissingPositive(int[] nums, int numsSize) {
		int i, j, pivot, temp, posArrLen;
		if (numsSize == 0) // Array size is 0
			return 1;

		
		// Swap all positive numbers to right side and negative to left side.
		i = 0;
		j = numsSize - 1;
		while (i < j) {
			if (nums[i] > 0 && nums[j] <= 0) {
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				i++;
				j--;
			} else if (nums[i] > 0) {
				j--;
			} else {
				i++;
			}
		}

		// Pivot element is pointing to 1st positive integer in array.
		pivot = nums[i] > 0 ? i : i + 1;

		// All negative numbers are replaced with 0.
		for (i = 0; i < numsSize; i++) {
			if (nums[i] <= 0)
				nums[i] = 0;
		}
		
		// Total positive element in array.
		posArrLen = numsSize - pivot;

		// No positive element in given array.
		if (posArrLen <= 0) {
			return 1;
		}

		// Find maximum from positive number.
		int max = nums[pivot];
		for (i = pivot + 1; i < numsSize; i++) {
			if (nums[i] > max)
				max = nums[i];
		}

		// If max = positiveArraySize means all number are present upto positiveArraySize.
		// i.e 1st missing number is one greater than positiveArraySize.
		if (max == posArrLen)
			return max + 1;

		// i.e Max > positiveArraySize means missing number must in range(1, positiveArraySize).
		// If any number less positiveArraySize
		// Then change element present at that location to negative by multiplying (-1).
		for (i = pivot; i < numsSize; i++) {
			int currNum = Math.abs(nums[i]);
			if ((currNum - 1) < posArrLen) {
				nums[currNum - 1] *= -1;
			}
		}
		
		// 1st Positive number in array means we didnt found that number in previous step for changing it to negative.
		for (i = 0; i < numsSize; i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		
		// Default return value.
		return 1;
	}

}

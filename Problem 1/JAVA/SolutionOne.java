import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author AJAY G.
 */
public class SolutionOne {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    System.out.print("\nEnter no of elements(?) : ");
    int n = sc.nextInt();

    ArrayList<Integer> array = new ArrayList<>(n);

    System.out.print("\nEnter " + n + " array elements : ");
    for (int i = 0; i < n; i++) {
      array.add(sc.nextInt());
    }

    System.out.print("\nEnter k : ");
    int k = sc.nextInt();

    System.out.println("\nResult : " + checkSum(array, k));

  }

  private static boolean checkSum(ArrayList<Integer> array, int k) {

    Set<Integer> set = new HashSet<>();
    for (Integer num : array) {
      if (set.contains(num)) {
        return true;
      }
      set.add(k - num);
    }
    return false;
  }

}

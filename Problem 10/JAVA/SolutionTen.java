
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Scanner;

/**
 * @author Ajay G.
 */
public class SolutionTen {

	public void targetMethod() {
		System.out.println("Executing Target");
	}

	private void scheduler(int n, Method method, Object object)
			throws IllegalAccessException, IllegalArgumentException, InvocationTargetException, InterruptedException {
		Thread.sleep(n);
		method.invoke(object);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		SolutionTen solutionTen = new SolutionTen();
		try {
			Method method = solutionTen.getClass().getMethod("targetMethod");
			solutionTen.scheduler(n, method, solutionTen);
		} catch (NoSuchMethodException | SecurityException | IllegalAccessException | IllegalArgumentException
				| InvocationTargetException | InterruptedException e) {
			e.printStackTrace();
		}
	}

}

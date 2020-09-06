import java.util.Scanner;

/**
 * @author Ajay G.
 */
public class SolutionEight_2 {

	private int count = 0;

	public int countUnivalSubtrees(BinaryTree tree) {
		this.count = 0;
		countUnivalSubtrees(tree.getRoot());
		return this.count;
	}

	private boolean countUnivalSubtrees(BinaryTreeNode node) {

		if (node != null) {
			boolean l = countUnivalSubtrees(node.getLeft());
			boolean r = countUnivalSubtrees(node.getRight());
			if (!l || !r)
				return false;

			if (node.getLeft() != null && node.getData() != node.getLeft().getData()) {
				return false;
			}
			if (node.getRight() != null && node.getData() != node.getRight().getData()) {
				return false;
			}

			count++;
			return true;

		}
		return true;
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		BinaryTree binaryTree = new BinaryTree();
		SolutionEight_2 solution = new SolutionEight_2();

		int ch;
		do {
			System.out.println(
					"\n 1. Insert Node.\n 2. Delete Node\n 3. Count Unival Subtrees.\n 4. Display Tree\n 5. Exit");
			System.out.print("Enter your choice : ");
			ch = sc.nextInt();
			int data;
			switch (ch) {
			case 1:
				System.out.print("\n Enter data to insert : ");
				data = sc.nextInt();
				binaryTree.insertNode(data);
				break;

			case 2:
				System.out.print("\n Enter key to delete : ");
				data = sc.nextInt();
				binaryTree.deleteNode(data);
				break;

			case 3:
				System.out.println("\n Total Unival Subtrees : " + solution.countUnivalSubtrees(binaryTree));
				break;

			case 4:
				binaryTree.printLevelOrder();
				System.out.println("\n\n Inorder : ");
				binaryTree.printInorder(binaryTree.getRoot());
				break;

			case 5:
				break;

			default:
				System.out.println("\n INVALID CHOICE....!");
				break;
			}
		} while (ch != 5);
	}

}

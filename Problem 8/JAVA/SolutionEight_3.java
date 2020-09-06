import java.util.Scanner;

/**
 * @author Ajay G.
 */
public class SolutionEight_3 {

	public int countUnivalSubtrees(BinaryTree tree) {
		return countUnivalSubtrees(tree.getRoot());
	}

	private int countUnivalSubtrees(BinaryTreeNode node) {
		if (node == null)
			return 0;

		if (node.getLeft() == null && node.getRight() == null)
			return 1;

		if (node.getLeft() == null && node.getData() == node.getRight().getData())
			return countUnivalSubtrees(node.getRight()) + 1;
		else if (node.getRight() == null && node.getData() == node.getLeft().getData())
			return countUnivalSubtrees(node.getLeft()) + 1;

		int count = countUnivalSubtrees(node.getLeft()) + countUnivalSubtrees(node.getRight());

		if ((node.getLeft() == null || node.getData() == node.getLeft().getData()) && (node.getRight() == null || node.getData() == node.getRight().getData()))
			count++;

		return count;

	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		BinaryTree binaryTree = new BinaryTree();
		SolutionEight_3 solution = new SolutionEight_3();

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

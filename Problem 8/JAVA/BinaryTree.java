import java.util.Scanner;

/**
 * @author Ajay G.
 */
public class BinaryTree {

	private BinaryTreeNode root = null;
	private boolean deletedFlag = false;

	public BinaryTree() {
		this.setRoot(null);
	}

	public void insertNode(int data) {
		Scanner sc = new Scanner(System.in);
		int ch;
		if (root == null) {
			this.root = new BinaryTreeNode(data);
		} else {
			BinaryTreeNode ptr1 = this.root, ptr2;
			do {

				System.out.print("\n 1. Insert left to : " + ptr1.getData());
				System.out.print("\n 2. Insert right to : " + ptr1.getData());
				System.out.print("\n Enter your choice : ");
				ch = sc.nextInt();

				ptr2 = ptr1;
				if (ch == 1) {
					ptr1 = ptr1.getLeft();
				} else if (ch == 2) {
					ptr1 = ptr1.getRight();
				} else {
					System.out.println("\n INVALID CHOICE.....!!\n Please choose correct option.");
				}

			} while (ptr1 != null);
			if (ch == 1) {
				ptr2.setLeft(new BinaryTreeNode(data));
			} else if (ch == 2) {
				ptr2.setRight(new BinaryTreeNode(data));
			}
		}
		this.root.updateHeight();
	}

	public void deleteNode(int key) {
		this.deletedFlag = false;
		this.root = deleteNode(this.root, key);
	}

	private BinaryTreeNode deleteNode(BinaryTreeNode node, int key) {
		if (node != null) {
			if (node.getData() == key) {
				BinaryTreeNode temp;
				if (node.getLeft() == null && node.getRight() == null) {
					node = null;
				} else if (node.getLeft() == null || node.getRight() == null) {
					node = node.getLeft() != null ? node.getLeft() : node.getRight();
				} else {
					temp = node.getLeft();
					while (temp.getRight() != null) {
						temp = temp.getRight();
					}
					temp.setRight(node.getRight());
					node = node.getLeft();
				}
				this.deletedFlag = true;
			} else {
				if (!this.deletedFlag)
					node.setLeft(deleteNode(node.getLeft(), key));
				if (!this.deletedFlag)
					node.setRight(deleteNode(node.getRight(), key));
			}
		}
		if (node != null)
			node.updateHeight();

		return node;

	}

	public void printInorder(BinaryTreeNode node) {
		if (node != null) {
			printInorder(node.getLeft());
			System.out.print(node.getData() + "  ");
			printInorder(node.getRight());
		}

	}

	public void printLevelOrder() {
		if (this.root == null) {
			System.out.println("\n Tree is empty. ");
			return;
		}
		int h = this.root.getHeight();
		int i;
		double space = (Math.pow(2, h - 2) * 3) / 2 * 8;

		for (i = 1; i <= h; i++) {
			printGivenLevel(this.root, i, space);
			System.out.println("\n\n");
		}
	}

	private void printGivenLevel(BinaryTreeNode node, int level, double space) {
		int i;
		if (node == null) {
			for (i = 0; i < space / 2; i++)
				System.out.print(" ");
			System.out.print(" ");
			for (i = 1; i < space / 2; i++)
				System.out.print(" ");
			return;
		}
		if (level == 1) {
			for (i = 0; i < space / 2; i++)
				System.out.print(" ");

			System.out.print(node.getData());

			for (i = 2; i < space / 2; i++)
				System.out.print(" ");
		} else if (level > 1) {
			space /= 2;
			printGivenLevel(node.getLeft(), level - 1, space);
			printGivenLevel(node.getRight(), level - 1, space);
		}
	}

	public BinaryTreeNode getRoot() {
		return root;
	}

	public void setRoot(BinaryTreeNode root) {
		this.root = root;
	}

}

/**
 * @author Ajay G.
 */
class BinaryTreeNode {

	private int data;
	private BinaryTreeNode left;
	private BinaryTreeNode right;
	private int height;

	BinaryTreeNode(int data) {
		this.data = data;
		this.right = null;
		this.left = null;
		this.height = 1;
	}

	public BinaryTreeNode(int data, BinaryTreeNode left, BinaryTreeNode right) {
		super();
		this.data = data;
		this.left = left;
		this.right = right;
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public BinaryTreeNode getLeft() {
		return left;
	}

	public void setLeft(BinaryTreeNode left) {
		this.left = left;
	}

	public BinaryTreeNode getRight() {
		return right;
	}

	public void setRight(BinaryTreeNode right) {
		this.right = right;
	}

	public int getHeight() {
		return this.updateHeight();
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public int updateHeight() {
		int l = 0;
		if (this.left != null)
			l = left.getHeight();

		int r = 0;
		if (this.right != null) {
			r = right.getHeight();
		}

		this.height = Math.max(l, r) + 1;
		return this.height;

	}
}
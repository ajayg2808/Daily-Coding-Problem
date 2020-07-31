import java.lang.Math;

/**
 * @author Ajay G.
 *
 */
public class CompleteBinaryTree {
	private BinaryTreeNode root = null;
	private boolean insertFlag = false;

	public CompleteBinaryTree() {
		this.root = null;
	}

	public void insertNode(int data) {
		if (this.root == null) {
			this.root = new BinaryTreeNode(data);
		} else {
			this.root = this.insertLevelOrder(this.root, data, this.root.getHeight());
			if (!this.insertFlag) {
				BinaryTreeNode p = this.root;
				while (p.getLeft() != null) {
					p = p.getLeft();
				}
				p.setLeft(new BinaryTreeNode(data));
				this.root.updateHeight();
			}
		}
		this.insertFlag = false;
	}

	private BinaryTreeNode insertLevelOrder(BinaryTreeNode node, int data, int level) {
		if (node == null) {
			this.insertFlag = true;
			return new BinaryTreeNode(data);
		}
		if (level == 1) {
			return node;
		} else if (level > 1) {
			if (!this.insertFlag) {
				node.setLeft(this.insertLevelOrder(node.getLeft(), data, level - 1));
			}
			if (!this.insertFlag) {
				node.setRight(this.insertLevelOrder(node.getRight(), data, level - 1));
			}
			int l = 0, r = 0;
			if (node.getLeft() != null)
				l = node.getLeft().getHeight();

			if (node.getRight() != null)
				r = node.getRight().getHeight();

			node.setHeight(Math.max(l, r) + 1);

			return node;
		}
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

	void printGivenLevel(BinaryTreeNode node, int level, double space) {
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
 *
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
		if(this.left != null)
			l = left.getHeight();
		
		int r = 0;
		if (this.right != null) {
			r = right.getHeight();
		}
		
		this.height = Math.max(l, r) + 1;
		return this.height;
		
	}
}
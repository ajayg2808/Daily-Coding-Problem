import java.util.Scanner;

/**
 * @author AJAY G.
 */
public class SolutionThree {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int x;
		char ch;
		CompleteBinaryTree originalTree = new CompleteBinaryTree();
		CompleteBinaryTree deserializedTree = new CompleteBinaryTree();
		do {
			System.out.print("\n Enter data for new node : ");
			x = sc.nextInt();
			originalTree.insertNode(x);
			System.out.println("\n New node added in tree.");
			System.out.print("\n Do you add more nodes\n Enter choice(Y/N) : ");

			ch = sc.next().charAt(0);

		} while (ch == 'Y' || ch == 'y');

		System.out.println("\n Original Tree : ");
		originalTree.printLevelOrder();

		System.out.print("\n Inorder of original tree : ");
		originalTree.printInorder(originalTree.getRoot());
		System.out.println("\n");

		// Serialize operation
		String serializedTreeString = serialize(originalTree.getRoot());
		System.out.println("\n Serialized string : " + serializedTreeString);

		// Desrialize operation
		deserializedTree.setRoot(deSerialize(serializedTreeString));
		System.out.println("\n Deserialized Tree : ");
		deserializedTree.printLevelOrder();

		System.out.print("\n Inorder of deserialized tree tree : ");
		deserializedTree.printInorder(deserializedTree.getRoot());
		System.out.println("\n");

	}

	private static BinaryTreeNode deSerialize(String serializedTreeString) {
		
		BinaryTreeNode node = null;
	    int len = serializedTreeString.length(), i, j, data;
	    StringBuilder sb = new StringBuilder(serializedTreeString);
	    if (len > 2)
	    {
		    String dataStr, left, right;
	        sb.replace(0, 1, "");
	        sb.replace(sb.length() - 1,sb.length(),"");
	        i = sb.indexOf(",");
	        dataStr = sb.substring(0, i);
	        data = Integer.parseInt(dataStr);

	        node = new BinaryTreeNode(data);

	        i = sb.indexOf("[");
	        j = getNodeEndIndex(sb.toString(), i, '[', ']');
	        left = sb.substring(i, j + 1);

	        node.setLeft(deSerialize(left));

	        i = j + 1;
	        j = getNodeEndIndex(sb.toString(), i, '[', ']');
	        right = sb.substring(i, j + 1);

	        node.setRight(deSerialize(right));
	        node.updateHeight();

	    }
	    return node;
	}


	private static int getNodeEndIndex(String str, int fromIndex, char openChar, char closeChar) {
		int index = -1, i, len = str.length();
	    int count = 0;
	    if (fromIndex < len)
	    {
	        for (i = fromIndex; i < len; i++)
	        {
	            if (str.charAt(i) == openChar || str.charAt(i) == closeChar)
	            {
	                if (str.charAt(i) == openChar)
	                {
	                    count++;
	                }
	                if (str.charAt(i) == closeChar)
	                {
	                    count--;
	                }
	                if (count == 0)
	                {
	                    index = i;
	                    break;
	                }
	            }
	        }
	    }
	    return index;
	}

	private static String serialize(BinaryTreeNode root) {
		StringBuilder sb = new StringBuilder("[");
		String left, right, data;
		if (root != null) {
			data = Integer.toString(root.getData());

			left = serialize(root.getLeft());
			right = serialize(root.getRight());

			sb.append(data);
			sb.append(',');
			sb.append(left);
			sb.append(right);
		}
		sb.append(']');
		return sb.toString();
	}

}

import java.util.HashMap;
import java.util.Map;

/**
 * @author Ajay G.
 *
 */
class Node {
	private final static Map<Integer, Node> NODES_DATA_MAP = new HashMap<>();

	private int data;
	private int both;

	/**
	 * 
	 */
	public Node(int data) {
		this.data = data;
		Node.NODES_DATA_MAP.put(this.hashCode(), this);
		this.both = 0;
	}

	public int getBoth() {
		return both;
	}

	public void setBoth(int both) {
		this.both = both;
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public static Map<Integer, Node> getNodesDataMap() {
		return NODES_DATA_MAP;
	}

	public void clear() {
		Node.NODES_DATA_MAP.clear();
	}

}

public class MemoryEfficientDoublyLinkedList {

	private final static String REMOVE_ELEMENT_MSG = "\nRemoving element %d from doubly linked list.";
	private final static String EMPTY_LIST = "\nDoubly linked list is empty.";
	private final static String NEGATIVE_INDEX_ERROR = "\nNegative index is not possible.";

	private Node head, tail;

	/**
	 * 
	 */
	public MemoryEfficientDoublyLinkedList() {
		this.tail = null;
		this.head = null;
	}

	int insertFirst(int data) {
		Node temp = new Node(data);
		if (this.head == null) {
			this.head = temp;
			this.tail = temp;
			return 1;
		} else {
			int nextAdd = this.head.hashCode();
			int prevAdd = temp.hashCode();
			temp.setBoth(temp.getBoth() ^ nextAdd);
			this.head.setBoth(this.head.getBoth() ^ prevAdd);
			this.head = temp;
			return 1;
		}
	}

	int insertLast(int data) {
		Node temp = new Node(data);
		if (this.head == null) {
			this.head = temp;
			this.tail = temp;
			return 1;
		} else {
			int nextAdd = temp.hashCode();
			int prevAdd = this.tail.hashCode();
			this.tail.setBoth(this.tail.getBoth() ^ nextAdd);
			temp.setBoth(temp.getBoth() ^ prevAdd);
			this.tail = temp;
			return 1;
		}
	}

	int insertAt(int index, int data) {
		int count = 0;
		if (this.head == null) {
			System.out.print(EMPTY_LIST);
			return 0;
		}
		if (index < 0) {
			System.out.print(NEGATIVE_INDEX_ERROR);
			return 0;
		}
		if (index == 0) {
			return insertFirst(data);
		}
		Node temp = new Node(data);

		Integer ptr = this.head.hashCode();
		Integer prevAdd = 0;
		Integer nextAdd = 0;
		while (ptr != null && count != index) {
			Node ptrNode = Node.getNodesDataMap().get(ptr);
			nextAdd = prevAdd ^ ptrNode.getBoth();
			prevAdd = ptr;
			ptr = nextAdd;
			count++;
		}
		if (index == count) {
			if (ptr != null) {
				Node prevNode = Node.getNodesDataMap().get(prevAdd);
				prevNode.setBoth(prevNode.getBoth() ^ ptr ^ temp.hashCode());
				temp.setBoth(prevAdd ^ ptr);
				Node ptrNode = Node.getNodesDataMap().get(ptr);
				ptrNode.setBoth(ptrNode.getBoth() ^ prevAdd ^ temp.hashCode());
				return 1;
			} else {
				return insertLast(data);
			}
		}

		System.out.print("\nNot able to insert Node : " + data + " at index : " + index);
		return 0;
	}

	void traversDoublyLinkedList() {
		Integer ptr = this.head.hashCode();
		int prevAdd = 0;
		if (this.head == null) {
			this.tail = this.head;
			System.out.print(EMPTY_LIST);
			return;
		}
		System.out.print("\nElement in doubly linked list :");
		Node ptrNode = Node.getNodesDataMap().get(ptr);
		while (ptrNode != null) {

			System.out.print(" " + ptrNode.getData() + " ");
			int temp = ptr;
			ptr = ptrNode.getBoth() ^ prevAdd;
			prevAdd = temp;
			ptrNode = Node.getNodesDataMap().get(ptr);
		}
	}

	void traversDoublyLinkedListReverse() {
		Integer ptr = this.tail.hashCode();
		int nextAdd = 0;
		if (this.tail == null) {
			this.head = this.tail;
			System.out.print(EMPTY_LIST);
			return;
		}
		System.out.print("\nElement in doubly linked list (reverse order) :");
		Node ptrNode = Node.getNodesDataMap().get(ptr);
		while (ptrNode != null) {
			System.out.print(" " + ptrNode.getData() + " ");
			int temp = ptr;
			ptr = ptrNode.getBoth() ^ nextAdd;
			nextAdd = temp;
			ptrNode = Node.getNodesDataMap().get(ptr);
		}
	}

	int size() {
		return Node.getNodesDataMap().size();
	}

	int removeFirst() {
		if (this.head == null) {
			System.out.print(EMPTY_LIST);
			return 0;
		}

		System.out.print(String.format(REMOVE_ELEMENT_MSG, this.head.getData()));

		if (this.head == this.tail) {
			Node.getNodesDataMap().remove(this.head.hashCode());
			this.head = null;
			this.tail = null;
			return 1;
		} else {
			Integer temp = this.head.hashCode();
			Node temNode = Node.getNodesDataMap().get(temp);
			this.head = Node.getNodesDataMap().get(temNode.getBoth());
			this.head.setBoth(this.head.getBoth() ^ temp);

			Node.getNodesDataMap().remove(temp);
			return 1;
		}
	}

	int removeLast() {
		if (this.head == null) {
			System.out.print(EMPTY_LIST);
			return 0;
		}

		System.out.print(String.format(REMOVE_ELEMENT_MSG, this.tail.getData()));

		if (this.head == this.tail) {
			Node.getNodesDataMap().remove(this.head.hashCode());

			this.head = null;
			this.tail = null;
			return 1;
		} else {
			Integer temp = this.tail.hashCode();
			Node tempNode = Node.getNodesDataMap().get(temp);
			this.tail = Node.getNodesDataMap().get(tempNode.getBoth());
			this.tail.setBoth(this.tail.getBoth() ^ temp);

			Node.getNodesDataMap().remove(temp);
			return 1;
		}
	}

	int removeAt(int index) {
		if (index < 0) {
			System.out.print(NEGATIVE_INDEX_ERROR);
			return 0;
		}

		if (this.head == null) {
			System.out.print(EMPTY_LIST);
			return 0;
		}
		if (index == 0) {
			return removeFirst();
		}
		int count = 0;
		Integer ptr = this.head.hashCode();
		Node ptrNode = Node.getNodesDataMap().get(ptr);
		int prevAdd = 0;
		int nextAdd = 0;
		while (ptrNode != null && count != index) {
			nextAdd = prevAdd ^ ptrNode.getBoth();
			prevAdd = ptr;
			ptr = nextAdd;
			count++;
			ptrNode = Node.getNodesDataMap().get(ptr);
		}
		if (index == count) {
			if (ptrNode != null) {
				System.out.print(String.format(REMOVE_ELEMENT_MSG, ptrNode.getData()));
				Node prevNode = Node.getNodesDataMap().get(prevAdd);
				nextAdd = ptrNode.getBoth() ^ prevAdd;
				prevNode.setBoth(prevNode.getBoth() ^ ptr ^ nextAdd);
				Node nextNode = Node.getNodesDataMap().get(nextAdd);
				nextNode.setBoth(nextNode.getBoth() ^ ptr ^ prevAdd);
				Node.getNodesDataMap().remove(ptr);
				return 1;
			} else {
				return removeLast();
			}
		}

		System.out.print("\nNot able to remove Node at index : " + index);
		return 0;
	}

	void clear() {
		Node.getNodesDataMap().clear();
		this.head = this.tail = null;
		System.out.print("\n Deleted doubly linked list.");
	}

	Integer get(int index) {
		if (index < 0) {
			System.out.print(NEGATIVE_INDEX_ERROR);
			return null;
		}
		Integer ptr = this.head.hashCode();
		Node ptrNode = Node.getNodesDataMap().get(ptr);
		int count = 0;
		Integer temp = null;
		Integer prevAdd = 0;
		while (ptrNode != null && count != index) {
			count++;
			temp = ptr;
			ptr = ptrNode.getBoth() ^ prevAdd;
			prevAdd = temp;
			ptrNode = Node.getNodesDataMap().get(ptr);
		}
		if (count == index) {
			if (ptr != null) {
				temp = ptrNode.getData();
			}
		}
		if (temp == null)
			System.out.print("\nIndex " + index + " not possible in doubly linked list.");
		return temp;
	}
}

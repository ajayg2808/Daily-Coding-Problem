/**
 * Code Stack Copyright Since 2020
 * visit codestack.com
 */
package com.codestack.store;

import java.util.Scanner;

/**
 * @author Ajay G.
 *
 */
public class ProblemSix {
	private final static String ENTER_ELEMENT = "\n Enter element to add at ";
	private final static String SEPERATOR = "\n======================================================================\n";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int ch, data, index;
		Scanner sc = new Scanner(System.in);
		MemoryEfficientDoublyLinkedList doublyLinkedList = new MemoryEfficientDoublyLinkedList();
		do {
			System.out.print(SEPERATOR);
			System.out.print("\n* * * * * * * MENU * * * * * * *\n");
			System.out.print("\n 1.  Insert First\n 2.  Insert Last\n 3.  Insert At Index");
			System.out.print("\n 4.  Remove First\n 5.  Remove Last\n 6.  Remove From Index");
			System.out.print("\n 7.  Get Element At Index\n 8.  Size\n 9.  Clear \n 10. Display\n 11. Display Reverse");
			System.out.print("\n 12. Exit\nEnter Your Choice : ");

			ch = sc.nextInt();
			switch (ch) {
			case 1:
				System.out.print(SEPERATOR);
				System.out.print(ENTER_ELEMENT + "beginning : ");
				data = sc.nextInt();
				doublyLinkedList.insertFirst(data);
				break;

			case 2:
				System.out.print(SEPERATOR);
				System.out.print(ENTER_ELEMENT + "last : ");
				data = sc.nextInt();
				doublyLinkedList.insertLast(data);
				break;

			case 3:
				System.out.print(SEPERATOR);
				System.out.print("\n Enter index : ");
				index = sc.nextInt();
				System.out.print(ENTER_ELEMENT + "index-" + index + " : ");
				data = sc.nextInt();
				doublyLinkedList.insertAt(index, data);
				break;

			case 4:
				System.out.print(SEPERATOR);
				doublyLinkedList.removeFirst();
				break;

			case 5:
				System.out.print(SEPERATOR);
				doublyLinkedList.removeLast();
				break;

			case 6:
				System.out.print(SEPERATOR);
				System.out.print("\n Enter index : ");
				index = sc.nextInt();
				doublyLinkedList.removeAt(index);
				break;

			case 7:
				System.out.print(SEPERATOR);
				System.out.print("\n Enter index : ");
				index = sc.nextInt();
				Integer x = doublyLinkedList.get(index);
				if (x != null) {
					System.out.print(String.format("\n Element at index : %d is %d.", index, x));
				}
				break;

			case 8:
				System.out.print(SEPERATOR);
				int s = doublyLinkedList.size();
				System.out.print("\n Size of doubly linked list is : " + s);
				break;

			case 9:
				System.out.print(SEPERATOR);
				doublyLinkedList.clear();
				break;

			case 10:
				System.out.print(SEPERATOR);
				doublyLinkedList.traversDoublyLinkedList();
				break;

			case 11:
				System.out.print(SEPERATOR);
				doublyLinkedList.traversDoublyLinkedListReverse();
				break;

			case 12:
				break;

			default:
				System.out.print("\n INVALID CHOICE......!");
				break;
			}
		} while (ch != 12);

	}

}

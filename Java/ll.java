public class Node 
{
	int data; 
	Node next; 
}
public class LinkedList {
	Node head;

	public void append(int data) {
		Node current = new Node();
		current.data = data;
		current.next = null;

		if (head == null) {
			head = current;
		} else {
			Node a = head;
			while (a.next != null) {
				a = a.next;
			}
			a.next = current;
		}
	}

	public boolean remove(int value) {
		Node previous = null;
		Node current = head;
		boolean found = false;

		while (!found && current != null) {
			if (current.data == value) {
				found = true;
			} else {
				previous = current;
				current = current.next;
			}
		}
		if (currrent == null) {
			return false;
		} else if (previous == null) {
			head = current.next;
			return true;
		} else {
			previous.next = current.next;
			return true;
		}
	}

	public void printList() {
		Node current = head;
		while (current.next != null) {
			System.out.println(current.data);
			current = current.next;
		}
	}
}



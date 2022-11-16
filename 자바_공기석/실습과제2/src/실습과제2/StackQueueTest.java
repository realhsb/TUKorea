package 실습과제2;

import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;

public class StackQueueTest {
	public static void main(String[] args) {
		Stack<String> stack = new Stack<String>();
		Queue<String> queue = new LinkedList<String>();
		
		stack.add("0");
		stack.add("1");
		stack.add("2");
		stack.add("3");
		
		queue.offer("0");
		queue.offer("1");
		queue.offer("2");
		queue.offer("3");
		
		System.out.println("= Stack =");
		while(!stack.isEmpty()) {
			System.out.println(stack.pop());
		}
		
		
		System.out.println("= Queue =");
		while(!queue.isEmpty()) {
			System.out.println(queue.poll());
		}
	}
}

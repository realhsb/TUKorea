package 실습과제2;

import java.util.HashSet;
import java.util.Iterator;

public class Lotto {
	public static void main(String[] args) {
		HashSet<Integer> hashSet = new HashSet<Integer>();
		while(hashSet.size() < 6) {
			int num = (int)(Math.random() * 45) + 1;
			System.out.println("random number : " + num);
			hashSet.add(num);
		}
		
		Iterator<Integer> iter = hashSet.iterator();
		
		while(iter.hasNext()) {
			System.out.print(iter.next() + " ");
		}
	}
}

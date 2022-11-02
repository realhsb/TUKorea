package 실습과제2_2;

import java.util.HashSet;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.Collections;

public class HashSetLotto {
	public static void main(String[] args) {
		HashSet<Integer> hashSet = new HashSet<Integer>();
		while(hashSet.size() < 6) {
			int num = (int)(Math.random() * 45) + 1;
			System.out.println("random number : " + num);
			hashSet.add(num);
		}
		
		ArrayList<Integer> arrayList = new ArrayList<Integer>(hashSet);
		Collections.sort(arrayList);
		Iterator<Integer> iter = arrayList.iterator();
		
		while(iter.hasNext()) {
			System.out.print(iter.next() + " ");
		}
	}
}

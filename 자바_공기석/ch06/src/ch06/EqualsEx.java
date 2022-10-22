package ch06;

class Point {
	int x, y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	public boolean equals(Object obj) {
		Point p = (Point)obj;
		if(x == p.x && y == p.y) return true;
		else return false;
	}
	public String toString() {
		return "Point(" + x + ", " + y + ")";
	}
}

class Rect {
	int width;
	int height;
	public Rect(int width, int height) {
		this.width = width;
		this.height = height;
	}
	
	public boolean equals(Object obj) {
		Rect p = (Rect)obj;
		if (width*height == p.width*p.height)
			return true;
		else
			return false;
	}
}

public class EqualsEx {
	public static void main(String[] args) {
//		Point a = new Point(2,3);
//		Point b = new Point(2,3);
//		Point c = new Point(3,4);
//		
//		if(a==b)
//			System.out.println("a==b");
//		if(a.equals(b))
//			System.out.println("a is equal to b");
//		if(a.equals(c))
//			System.out.println("a is equal to c");
		
		Rect a1 = new Rect(2,3);
		Rect b1 = new Rect(2, 3);
		Rect c1 = new Rect(3,4);
		
		if(a1==b1)
			System.out.println("a==b");
		if(a1.equals(b1))
			System.out.println("a is equal to b");
		if(a1.equals(c1))
			System.out.println("a is equal to c");
	}
}

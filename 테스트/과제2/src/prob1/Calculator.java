package prob1;

import java.util.Scanner;

public class Calculator {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);	// 피연산자 2개와 연산자 1개를 입력받음 
		String[] arr = scan.nextLine().split(" ");	// 띄어쓰기 기준으로 문자열 배열을 만들어줌 
		int a = Integer.parseInt(arr[0]);			// 0, 1번째는 숫자이므로 문자열->int로 변환 
		int b = Integer.parseInt(arr[1]);
		char exp = arr[2].charAt(0);				// 2번째는 문자이므로 chatAt(0)으로 문자열 -> char 변환 
		
		switch(exp) {
			case '+' :	// 연산자 : +
				Add add = new Add();
				add.setValue(a, b);
				System.out.println(add.calculate());
				break;
				
			case '-' :	// 연산자 : - 
				Sub sub = new Sub();
				sub.setValue(a, b);
				System.out.println(sub.calculate());
				break;
				
			case '*' :	// 연산자 : *
				Mul mul = new Mul();
				mul.setValue(a, b);
				System.out.println(mul.calculate());
				break;
				
			case '/' :	// 연산자 : /
				Div div = new Div();
				div.setValue(a, b);
				System.out.println(div.calculate());
				break;
				
			case '%' :	// 연산자 : %
				Mod mod = new Mod();
				mod.setValue(a, b);
				System.out.println(mod.calculate());
				break;
		}
	}
}

class Add {
	int a, b;
	
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	int calculate() {
		return this.a + this.b;
	}
}

class Sub {
	int a, b;
	
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	int calculate() {
		return this.a - this.b;
	}
}

class Mul {
	int a, b;
	
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	int calculate() {
		return this.a * this.b;
	}
}

class Div {
	int a, b;
	
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	int calculate() {
		return this.a / this.b;
	}
}

class Mod {
	int a, b;
	
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	int calculate() {
		return this.a % this.b;
	}
}
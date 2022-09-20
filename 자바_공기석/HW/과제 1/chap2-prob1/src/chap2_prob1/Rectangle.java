package chap2_prob1;

import java.util.Scanner;

public class Rectangle {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("사각형의 가로를 입력하시오 : ");
        double width = scanner.nextInt();  // 가로 입력 받기

        System.out.print("사각형의 세로를 입력하시오 : ");
        double height = scanner.nextInt(); // 세로 입력 받기

        System.out.println("사각형의 둘레는 " + 2 * (width + height)); // 둘레 출력
        System.out.println("사각형의 넓이는 " + (width * height));     // 넓이 출력 
    }
}

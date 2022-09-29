package ch02;

public class Ex2_6 {
    public static void main(String[] args){
        int a= 3, b = 3, c = 3;

        // 대입 연산자 사례
        a += 3;
        b *= 3;
        c %= 2;

        int d = 3;

        a = d++;
        System.out.println("a = " + a + " d = " + d);

        a = ++d;
        System.out.println("a = " + a + " d = " + d);

        a = d--;
        System.out.println("a = " + a + " d = " + d);

        a = --d;
        System.out.println("a = " + a + " d = " + d);
    }
}

package ch03;

public class Ex3_4_nested_for_99 {
    public static void main(String[] args){
        // 가로
        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++){
                System.out.print(i + "*" + j + "=" + i*j);
                System.out.print("\t");
            }
            System.out.println();
        }

        System.out.println();

        // 세로
        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++){
                System.out.print(j + "*" + i + "=" + i*j);
                System.out.print("\t");
            }
            System.out.println();
        }
    }
}

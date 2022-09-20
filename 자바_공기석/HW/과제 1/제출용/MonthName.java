package chap2_prob2;

import java.util.Scanner;

public class MonthName {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("월의 이름을 입력하시오 : ");
        String month_Eng = scanner.nextLine();  // 월 영문으로 입력 받기
        String month_Kor = "";

        switch (month_Eng) {                    // case문을 통한 월 이름 받기
            case "January" :
                month_Kor = "1월";
                break;
            case "February" :
                month_Kor = "2월";
                break;
            case "March" :
                month_Kor = "3월";
                break;
            case "April" :
                month_Kor = "4월";
                break;
            case "May" :
                month_Kor = "5월";
                break;
            case "June" :
                month_Kor = "6월";
                break;
            case "July" :
                month_Kor = "7월";
                break;
            case "August" :
                month_Kor = "8월";
                break;
            case "September" :
                month_Kor = "9월";
                break;
            case "October" :
                month_Kor = "10월";
                break;
            case "November" :
                month_Kor = "11월";
                break;
            case "December" :
                month_Kor = "12월";
                break;
            default :                           // 잘못된 월 이름을 받았을 경우
                System.out.println("잘못된 월 이름입니다!!");
                break;
        }

        if(month_Kor != ""){                    // month_Kor가 빈 문자열이 아닐 경우
            System.out.println(month_Kor + " 입니다!!");
        }
    }
}

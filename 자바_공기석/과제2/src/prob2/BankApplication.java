package prob2;

import java.util.Scanner;

public class BankApplication {
	private static Account[] accountArr = new Account[100];
	private static Scanner scanner = new Scanner(System.in);
	private static int index = 0;

	public static void main(String[] args) {
		boolean run = true;
		while (run) {
			System.out.println("----------------------------------------------------------");
			System.out.println("1.계좌생성| 2.계좌목록| 3.예금| 4.출금| 5.종료");
			System.out.println("----------------------------------------------------------");
			System.out.print("선택> ");
			int selectNo = scanner.nextInt();
			if (selectNo == 1) {
				createAccount();
			} else if (selectNo == 2) {
				accountList();
			} else if (selectNo == 3) {
				deposit();
			} else if (selectNo == 4) {
				withdraw();
			} else if (selectNo == 5) {
				run = false;
			}
		}
		System.out.println("프로그램종료");
	}

	// 계좌생성하기
	private static void createAccount() {
		System.out.println("--------------\n계좌생성\n--------------");
		
		System.out.print("계좌번호 : ");
		scanner.nextLine();					// 프린트문에 있는 문자 받아두는 용도 
		String ano = scanner.nextLine();	// 계좌번호 입력 받기 
		
		//System.out.println();
		System.out.print("계좌주 : ");		// 계좌주 입력 받기 
		String owner = scanner.nextLine();
		
		//System.out.println();
		System.out.print("초기입금액 : ");		// 초기 입금 액 입력 받기 
		int balance = scanner.nextInt();
		
		//System.out.println();
		System.out.print("결과 : ");
		if(ano == null || owner == null || balance < 0) {	// 조건에 맞지 않은 입력이 들어올 경우 계좌 생성 실패 
			System.out.print("계좌가 생성되지 않았습니다.");
		}else {
			System.out.println("계좌가 생성되었습니다.");
			Account account = new Account(ano, owner, balance);
			accountArr[index++] = account;	// 계좌가 생성되면 배열의 인덱스를 증가시켜 빈 공간에 담아주기 
		}
		
	} 
	
	// 계좌목록보기
	private static void accountList() {
		System.out.println("--------------\n계좌목록\n--------------");	
		
		for(Account account : accountArr) {
			if(account == null) continue;	// Account가 비어있을 경우 넘어감 
			System.out.println(account.getAno() + "\t\t" + account.getOwner() + "\t" + account.getBalance());
		}

	}

	//예금하기
	private static void deposit() {
		System.out.println("--------------\n예금\n--------------");	
		
		System.out.print("계좌번호 : ");	// 계좌번호 입력 받기 
		scanner.nextLine();
		String ano = scanner.nextLine();
		
		System.out.print("예금액 : ");	// 예금액 입력 받기 
		int money = scanner.nextInt();

		Account account = findAccount(ano);
		
		System.out.print("결과 : ");
		if(account == null || money < 0) {	// 조건에 맞지 않은 입력이 들어올 경우 예금 실패 
			System.out.println("예금에 실패했습니다.");
		}else {
			System.out.println("예금에 성공했습니다.");
			account.setBalance(account.getBalance() + money);
		}
	}

	//출금하기
	private static void withdraw() {
		System.out.println("--------------\n출금\n--------------");	
		System.out.print("계좌번호 : ");	// 계좌번호 입력 받기 
		scanner.nextLine();
		String ano = scanner.nextLine();
		
		System.out.print("출금액 : ");	// 출금액 입력 받기 
		int money = scanner.nextInt();

		Account account = findAccount(ano);
		
		System.out.println();
		System.out.print("결과 : ");
		if(account == null || money < 0 || account.getBalance() < money) {
			// 조건에 맞지 않은 입력이 들어올 경우 출금 실패 
			System.out.println("출금에 실패했습니다.");
		}else {
			System.out.println("출금에 성공했습니다.");
			account.setBalance(account.getBalance() - money);
		}		


	}

	//Account 배열에서 acc_no 와 동일한 Account 객체찾기
	private static Account findAccount(String acc_no) {
		for(Account account : accountArr) {
			if(account.getAno().equals(acc_no)) {
				// 계좌번호가 일치하는 Account가 존재할 경우 return 
				return account;
			}
		}
		return null;	// 없을 경우 null 리턴 
	}
}

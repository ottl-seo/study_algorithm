public class Song {


	public String singer; //가수 이름
	public int price; //가격
	public String title; //노래 제목
	//지역변수로, 자동초기화 x

	void play() {
		System.out.println("노래 들어요! : \""+this.title+"\" by "+this.singer);
		//\" 을 이용해서 따옴표 출력
		//this.title, this.singer로 객체를 찾아가 값을 얻어옴
	}
	void price() {
		System.out.println(this.price+"원입니다.");
		// this.price로 객체를 찾아가 값을 얻어옴
	}
}


import java.util.Scanner;
public class Week3_1_김윤서 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int answer; //노래 번호
		Scanner kbd = new Scanner(System.in);
		
		
	    System.out.println("==========");
	    System.out.println("전공: 사이버보안");
	    System.out.println("학번: 1971063");
	    System.out.println("이름: 김윤서");
	    System.out.println("==========");
		
		
		Song s1 = new Song(); //Song 클래스의 s1 객체 생성
		Song s2 = new Song(); //Song 클래스의 s2 객체 생성
		
		System.out.println("* Song 1 *"); //song1에 대한 정보 입력
		System.out.println("곡명 입력:");
		s1.title=kbd.nextLine(); //title을 String으로 입력받아 s1.title에 저장
		System.out.println("가수명 입력:");
		s1.singer=kbd.nextLine(); //singer를 String으로 입력받아 s1.singer에 저장
		System.out.println("가격 입력:");
		String str=kbd.nextLine();//가격을 String으로 입력받고
		s1.price=Integer.parseInt(str); //Integer.parseInt()로 int로 바꾸어 s1.price에 저장한다.
		
		System.out.println("* Song 2 *");//song2에 대한 정보 입력
		System.out.println("곡명 입력:");
		s2.title=kbd.nextLine(); //title을 String으로 입력받아 s2.title에 저장
		System.out.println("가수명 입력:");
		s2.singer=kbd.nextLine(); //singer를 String으로 입력받아 s2.singer에 저장
		System.out.println("가격 입력:");
		String str2=kbd.nextLine();//가격을 String으로 입력받고
		s2.price=Integer.parseInt(str2); //Integer.parseInt()로 int로 바꾸어 s2.price에 저장한다.
		
		
		System.out.println("노래를 고르세요");
		System.out.println("1:"+s1.title+"  2:"+s2.title);
		answer=kbd.nextInt(); //1과 2중에 고른 값(int)을 입력받아 answer에 저장
		
		if (answer==1) {
			s1.play(); //play() 메서드 실행
			s1.price(); //price() 메서드 실행
			System.out.println("감사합니다.");	
		} // answer==1인 경우
		else if (answer==2) {
			s2.play(); //play() 메서드 실행
			s2.price(); //price() 메서드 실행
			System.out.println("감사합니다.");
	}// answer==2 인 경우
		else {
			System.out.println("잘못된 입력입니다.");
		}
	}
}

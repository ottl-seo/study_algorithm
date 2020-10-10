/* lesson 95. TCP/IP 서버 프로그램 */
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") // ???

void error(const char* message) { // 에러 처리 함수
	printf("Error: [%d] %s\n", WSAGetLastError(), message);
	WSACleanup();
	exit(0); //강제 종료
}
void main() {
	SOCKET s, cs; //서버 소켓, 클라 소켓
	WSADATA wsaData; //
	struct sockaddr_in sin; // sockaddr_in 구조체 sin 정의
	struct sockaddr_in cli_addr; // client IP주소와 포트번호 저장할 구조체
	
	int size = sizeof(cli_addr); //client구조체의 크기

		/* - ? - */
	WSAStartup(MAKEWORD(2, 2), &wsaData); // ?
	
		/* socket 생성 */
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET) { //잘못된 소켓일 경우
		error("Socket Error");
		return;
	}
	sin.sin_family = AF_INET; //AF_INET 체계임을 명시(sin_family)
	sin.sin_port = htons(10000); //10000번 포트를 사용(sin_port = htons(port))
	sin.sin_addr.s_addr = htonl(ADDR_ANY); //자동 네트워크 카드 설정 -??

		/* bind */
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) { //바인드한 결과가 error와 같으면
		closesocket(s); //소켓 닫고
		error("bind Error");
		return;
	}
		/* listen */
	if (listen(s, SOMAXCONN) != 0) {
		closesocket(s);
		error("listen Error");
		return;
	}
		/* accept */
	printf("클라이언트로부터 접속을 기다리고 있습니다... \n");
	cs = accept(s, (struct sockaddr*)&cli_addr, &size); //클라 소켓 생성
	if (cs == INVALID_SOCKET) { //cs가 잘못된 소켓일 경우
		closesocket(s);
		error("accept Error");
		return;
	}
	printf("클라이언트가 접속되었습니다. \n");
	printf("IP = %s, PORT = %d\n",
		inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port)); //htons 거꾸로해서 client의 포트번호 반환
	
	closesocket(cs); //cli먼저 닫기
	closesocket(s); //서버 소켓 닫기

	WSACleanup(); //Startup-Cleanup
}
/* lesson 95. TCP/IP ���� ���α׷� */
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") // ???

void error(const char* message) { // ���� ó�� �Լ�
	printf("Error: [%d] %s\n", WSAGetLastError(), message);
	WSACleanup();
	exit(0); //���� ����
}
void main() {
	SOCKET s, cs; //���� ����, Ŭ�� ����
	WSADATA wsaData; //
	struct sockaddr_in sin; // sockaddr_in ����ü sin ����
	struct sockaddr_in cli_addr; // client IP�ּҿ� ��Ʈ��ȣ ������ ����ü
	
	int size = sizeof(cli_addr); //client����ü�� ũ��

		/* - ? - */
	WSAStartup(MAKEWORD(2, 2), &wsaData); // ?
	
		/* socket ���� */
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET) { //�߸��� ������ ���
		error("Socket Error");
		return;
	}
	sin.sin_family = AF_INET; //AF_INET ü������ ���(sin_family)
	sin.sin_port = htons(10000); //10000�� ��Ʈ�� ���(sin_port = htons(port))
	sin.sin_addr.s_addr = htonl(ADDR_ANY); //�ڵ� ��Ʈ��ũ ī�� ���� -??

		/* bind */
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) { //���ε��� ����� error�� ������
		closesocket(s); //���� �ݰ�
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
	printf("Ŭ���̾�Ʈ�κ��� ������ ��ٸ��� �ֽ��ϴ�... \n");
	cs = accept(s, (struct sockaddr*)&cli_addr, &size); //Ŭ�� ���� ����
	if (cs == INVALID_SOCKET) { //cs�� �߸��� ������ ���
		closesocket(s);
		error("accept Error");
		return;
	}
	printf("Ŭ���̾�Ʈ�� ���ӵǾ����ϴ�. \n");
	printf("IP = %s, PORT = %d\n",
		inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port)); //htons �Ųٷ��ؼ� client�� ��Ʈ��ȣ ��ȯ
	
	closesocket(cs); //cli���� �ݱ�
	closesocket(s); //���� ���� �ݱ�

	WSACleanup(); //Startup-Cleanup
}
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

void decryption(int sockid){
	char buff[MAX];
	int n, res;
	//loop never ends
	while(1){
		bzero(buff, MAX);
		read(sockid, buff, sizeof(buff));
		n=0;
		res = 0;
		while(isalpha(buff[n]) != 0){
			res += buff[n];
			n++;
		}
		printf("Sorry, cannot compute!\n");
		return;
		
	}

}
  
int main(){
	int sockid, bs, ls, packet, len;
	struct sockaddr_in serv, cli;
	sockid = socket(AF_INET, SOCK_STREAM, 0);
	//check if socket created
	if(sockid == -1){
		printf("fail to creat socket\n");
		exit(0);
	}
	//initialized serv to 0
	bzero(&serv, sizeof(serv));
	// assign IP, PORT 
    serv.sin_family = AF_INET; 
    serv.sin_addr.s_addr = htonl(INADDR_ANY); 
    serv.sin_port = htons(PORT); 
    //bind the socket with the port given
    bs = bind(sockid, (SA*)&serv, sizeof(serv));
    if(bs == -1){
    	printf("binding fail\n");
    	exit(0);
    }
    ls = listen(sockid, 5);
    if(ls == -1){
    	printf("listen fail\n");
    	exit(0);
    }
    packet = accept(sockid, (SA*)&cli, &len);
    if(packet < 0){
    	printf("server accept fail\n");
    	exit(0);
    }
    decryption(packet);
    close(sockid);


}
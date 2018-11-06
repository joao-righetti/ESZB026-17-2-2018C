/* Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/ */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<wiringPi.h>
#include<softPwm.h>

int main(int argc,char *argv[]){

   int file, count, valor;
   int pino_PWM = 23; 
   int brilho, brilho2;
   int range = 100;     

   wiringPiSetupGpio () ; 
   pinMode (pino_PWM,OUTPUT);
   softPwmCreate (pino_PWM,1,range);

   
   if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;
   tcgetattr(file, &options);
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;
   tcflush(file, TCIFLUSH);
   tcsetattr(file, TCSANOW, &options);
   // envia a string que chegou como argumento mais um caractere nulo (\0)
   if ((count = write(file, argv[1], strlen(argv[1])+1))<0){
      perror("Falha ao escrever na saida.\n");
      return -1;
   }
   usleep(100000);
   unsigned char receive[10];
   
   while (1){
        if ((count = read(file, (void*)receive, 10))<0){
           perror("Falha ao ler da entrada.\n");
           return -1;
        }
        if (count>0) {
        
                receive[count]=0;  // o Arduino nao envia o caractere nulo (\0=0)
                sscanf(receive,"%d",&valor);
	   	brilho = valor*100/1023;
	   	if (brilho>=0 && brilho<=255){
			softPwmWrite ( pino_PWM , brilho );
			printf (" Valor: %d\n",brilho);
			delay (10);
		}
	    }
	 
   	}
   
}

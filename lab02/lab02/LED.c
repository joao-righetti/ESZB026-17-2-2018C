#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(char filename[], char value[]){
	FILE* fp;
	fp = fopen(filename, "w+");
        if(fp==NULL) printf("Erro %s",filename);
	fprintf(fp, "%s", value);
	fclose(fp);
}

int main ( ) {

	int contador=0;
	
	writeGPIO(GPIO_SYSFS "export", "16");
	writeGPIO(GPIO_SYSFS "export", "20");
	writeGPIO(GPIO_SYSFS "export", "21");
        usleep(100000);

	writeGPIO("/sys/class/gpio/gpio16/direction","out");
	writeGPIO("/sys/class/gpio/gpio20/direction","out");
	writeGPIO("/sys/class/gpio/gpio21/direction","out");

	
	while (contador < 5)
	{
		writeGPIO("/sys/class/gpio/gpio20/value","1");
		usleep(2000000);
		writeGPIO("/sys/class/gpio/gpio20/value","0");

		writeGPIO("/sys/class/gpio/gpio21/value","1");
		usleep(1000000);
		writeGPIO("/sys/class/gpio/gpio21/value","0");

		writeGPIO("/sys/class/gpio/gpio16/value","1");
		usleep(1000000);
		writeGPIO("/sys/class/gpio/gpio16/value","0");	

		contador = contador+1;	
	}

	writeGPIO(GPIO_SYSFS "unexport", "16");
	writeGPIO(GPIO_SYSFS "unexport", "20");
	writeGPIO(GPIO_SYSFS "unexport", "21");
	usleep(100000);

	return 0;

}

#include <studio.h>

#include <wiringPi.h>

# define GPIO_NUMBER "16"

# define GPIO4_PATH "/sys/class/gpio/gpio16/"

# define GPIO_SYSFS "/sys/class/gpio/"

int i;

i=0;

int main {

	contador = 0;

	WiringPiSetup( );
	
	pinMode(16,OUTPUT);
                
	pinMode(20,OUTPUT);
                
	pinMode(21,OUTPUT);

while (contador < 5)
{
	
		digitalWrite(16,HIGH);                               
		delay (1000);
		digitalWrite(16,LOW);

		delay(1000);
	
		digitalWrite(20,HIGH);                               
		delay (1000);
		digitalWrite(20,LOW);

		delay(1000);

		digitalWrite(21,HIGH);                               
		delay (1000);
		digitalWrite(21,LOW);

		delay(1000);                
}

return 0;

}

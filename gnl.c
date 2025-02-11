/* a.c - getnextline */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFSIZE 2048

char *zero(char*);
char *gnl(void);
int main(void);



char *zero(char *p)
{
	unsigned int n;


	for ( n = 0; n < BUFSIZE; *(p + n++) = 0);
	
	return p;
}


char *gnl(){

	unsigned int n; // okunan toplam karakter sayisi bu
	char *p , *s;
	int r;

	n = 0;
	s= p = malloc(BUFSIZE);
	zero(s); // buffer is zeroed out at the start,we can safely return s point.
	
	// p yi mutate ugratacagımız icin s ye eşitledilk aslinda onu , yani s ile aslında p bufferimizda gezicez.	
	
	while(true)
	{	
		// 0 : file descripterdir.stdin anlamina gelir.
		// read() basariyla okunan bayt sayisini dondurur.
		// read one byte from buffer is first step
		//read(stdin, our buffer , max byte what we read);
		r = read(0, p, 1); // okunan karakter p işaretçisi tarafindan gosterilen bellek konumuna yazdirilir.
		if (r < 1 ) 
		{
			if ( n < 1 )
			{
				return 0;
			}
			else if(n >= 1)
			{
				return s;
			}

		}
		//if we succesfuly can read one byte from the buffer we should another check statement
		else if(n > (BUFSIZE - 2)) // we can't read anymore characters
		{
			return s; // s is the start of buffer same first adress.

		}

	
		
	 switch(*p)
	 {
		case 0:

		case '\n':
			*p = 0;
			return s;
			break;

		case '\r':
			*p = 0;
			break;
		
		default:
			p++;
			n++;
	 } 		
}
	return (n < 1)
	 ? 0
	 : s;

	
	



	// if we get a zero bytes
	// 0 = return
	// -1 = return (unless its the first byte)
	// \n = return above 
	// otherwise = add to buffer and contuniue


}




int main()
{
	char *p1,*p2;

	p1 = gnl();
	p2 = gnl();

	printf(
		"'%s'\n"
		"'%s'\n",
		p1,p2
	);


	free(p1);
	free(p2);

	return 0;



}




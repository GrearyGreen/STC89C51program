#include "reg52.h"
#include "oledkey.h"

void keydelay()
{
	unsigned char a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

unsigned char keyscan()
{
	static unsigned char key_up = 1;
	unsigned char key = 0;
	if(key_up&&(key1 == 0|key2 == 0|key3 == 0|key4 == 0))
	{
		keydelay();
		key_up = 0;
		if(key1 == 0)key = 1;
		else if(key2 == 0)key = 2;
		else if(key3 == 0)key = 3;
		else if(key4 == 0)key = 4;
	}else if(key1 == 0|key2 == 0|key3 == 0|key4 == 0)
	key_up = 1;
	
	return key;
}
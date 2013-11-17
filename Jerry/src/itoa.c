#include "itoa.h"
char* itoa(int value, char* buffer, int base)
{
	static const char digits[]="0123456789abcdef";

	char* buffer_copy=buffer;
	int32_t sign=0;
	int32_t quot,rem;

	if ((base>=2)&&(base<=16))				// is the base valid?
	{
		if (base == 10 && (sign = value) < 0)// negative value and base == 10? store the copy (sign)
			value = -value;					// make it positive

		do
		{
			quot=value/base;				// calculate quotient and remainder
			rem=value%base;
			*buffer++ = digits[rem];		// append the remainder to the string
		} while ((value=quot));				// loop while there is something to convert

		if (sign<0)							// was the value negative?
			*buffer++='-';					// append the sign

		__reverse(buffer_copy,buffer-1);		// reverse the string
	}

	*buffer='\0';
	return buffer_copy;
}

void __reverse(char* begin,char* end)
{
	char temp;

	while (end>begin)
	{
		temp=*end;
		*end--=*begin;
		*begin++=temp;
	}
}


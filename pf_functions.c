#include "ft_printf.h"
//c
void pf_putchar(va_list *args, s_flags **flag)
{
	int c;
	flag = NULL;
	unsigned char temp;
	c = va_arg(*args,int);
	temp = (unsigned char)c;
	ft_putchar(c);
}
//s
void pf_putstr(va_list *args, s_flags **flag)
{
	char *str;
	flag = NULL;
	str = va_arg(*args,char*);
	ft_putstr(str);
}
//i,d
void pf_putnbr(va_list *args, s_flags **flag)
{
	char *str;
	ssize_t data;

	s_flags *tempflag;
	tempflag = *flag;
	str = NULL;
	data = va_arg(*args,ssize_t);
	isnegative(&tempflag, (long long)data);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_base((int)data,10);
	else if (tempflag->z)
		str = ft_itoa_base(data,10);
	else if (tempflag->j)
		str = ft_itoa_base((intmax_t)data,10);
	else if (tempflag->ll)
		str = ft_itoa_base((long long)data,10);
	else if (tempflag->l)
		str = ft_itoa_base((long)data,10);
	else if (tempflag->h)
		str = ft_itoa_base((short)data,10);
	else if (tempflag->hh)
		str = ft_itoa_base((signed char)data,10);
	str = (char*)flagformating(str, &tempflag);
	ft_putstr(str);
}
//X hex
void pf_x_handle(va_list *args, s_flags **flag)
{
	size_t data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,size_t);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_base((unsigned int)data,16);
	else if (tempflag->z)
		str = ft_itoa_base(data,16);
	else if (tempflag->j)
		str = ft_itoa_base((uintmax_t)data,16);
	else if (tempflag->ll)
		str = ft_itoa_base((unsigned long long)data,16);
	else if (tempflag->l)
		str = ft_itoa_base((unsigned long)data,16);
	else if (tempflag->h)
		str = ft_itoa_base((unsigned short)data,16);
	else if (tempflag->hh)
		str = ft_itoa_base((unsigned char)data,16);
	ft_putstr(str);
}
//x hex low
void pf_xlow_handle(va_list *args, s_flags **flag)
{
	size_t data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,size_t);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow((unsigned int)data,16);
	else if (tempflag->z)
		str = ft_itoa_baselow(data,16);
	else if (tempflag->j)
		str = ft_itoa_baselow((uintmax_t)data,16);
	else if (tempflag->ll)
		str = ft_itoa_baselow((unsigned long long)data,16);
	else if (tempflag->l)
		str = ft_itoa_baselow((unsigned long)data,16);
	else if (tempflag->h)
		str = ft_itoa_baselow((unsigned short)data,16);
	else if (tempflag->hh)
		str = ft_itoa_baselow((unsigned char)data,16);
	ft_putstr(str);
}
//o octo
void pf_o_handle(va_list *args, s_flags **flag)
{
	size_t data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,size_t);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow((unsigned int)data,8);
	else if (tempflag->z)
		str = ft_itoa_baselow(data,8);
	else if (tempflag->j)
		str = ft_itoa_baselow((uintmax_t)data,8);
	else if (tempflag->ll)
		str = ft_itoa_baselow((unsigned long long)data,8);
	else if (tempflag->l)
		str = ft_itoa_baselow((unsigned long)data,8);
	else if (tempflag->h)
		str = ft_itoa_baselow((unsigned short)data,8);
	else if (tempflag->hh)
		str = ft_itoa_baselow((unsigned char)data,8);
	ft_putstr(str);
}
//O octo
void pf_oup_handle(va_list *args, s_flags **flag)
{
	size_t data;
	char *str;
	s_flags *tempflag;
	tempflag = *flag;
	data = va_arg(*args,size_t);
	if (checkzeroflag(&tempflag) == 1)
		str = ft_itoa_baselow((unsigned int)data,8);
	else if (tempflag->z)
		str = ft_itoa_baselow(data,8);
	else if (tempflag->j)
		str = ft_itoa_baselow((uintmax_t)data,8);
	else if (tempflag->ll)
		str = ft_itoa_baselow((unsigned long long)data,8);
	else if (tempflag->l)
		str = ft_itoa_baselow((unsigned long)data,8);
	else if (tempflag->h)
		str = ft_itoa_baselow((unsigned short)data,8);
	else if (tempflag->hh)
		str = ft_itoa_baselow((unsigned char)data,8);
	ft_putstr(str);
}
//p memory
void pf_p_handle(va_list *args, s_flags **flag)
{
	uintmax_t data;
	void *ptr;
	char *str;
	flag = NULL;
	ptr = va_arg(*args,void*);
	data = ((uintmax_t)ptr);
	str = ft_itoa_baselow(data,16);
	str = ft_strjoin("0x",str);
	ft_putstr(str);
}

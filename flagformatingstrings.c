#include "ft_printf.h"

char *stringpercision(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	if (temp == NULL)
	temp = ft_strdup((const char*)str);
	if ((size_t)tempflag->precision < ft_strlen(temp))
	temp = ft_strsub(temp, 0, tempflag->precision);
	return temp;
}

char *stringmflag(char *str, char *temp, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *buffer;
	buffer = "";
	int change;

	//ft_putendl("here");
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	change = tempflag->mflag - ft_strlen(temp);
	if (tempflag->mflag > 0)
	{
		buffer = makespace(change, ' ');
	}
	temp = betterjoin(temp,buffer);
	return (temp);
}

char *flagformatingstrings(char *str, s_flags **flag)
{
	s_flags *tempflag;
	tempflag = *flag;
	char *temp = NULL;
	if (tempflag->mflag)
		temp = stringmflag(str, temp, &tempflag);
	if ((tempflag->precision > 0) && (tempflag->precision - ft_strlen(str) > 0))
	temp = stringpercision(str, temp, &tempflag);
	else if (tempflag->zero && tempflag->precision == 0)
		temp = zeroflag(str, temp, &tempflag);
	if (((tempflag->sign == -1) || (tempflag->sign > 0)) && (tempflag->conid > -1))
		temp = signflag(str, temp, &tempflag);
	else if (((tempflag->space == -1) || (tempflag->space > 0)) && (ft_strcmp(str,"%") != 0))
		temp = spaceflag(str, temp, &tempflag);
	else if (tempflag->extra > 0)
		temp = extraflag(str, temp, &tempflag);
	if (temp == NULL)
		temp = ft_strdup((const char*)str);
	return temp;
}
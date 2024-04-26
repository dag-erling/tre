#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <regex.h>

int
main(void)
{
	const char *re;
	regex_t reg;

#if 0
	re = "^([a-z]([a-z-]{0,3}[a-z])?\\.)*[a-z]{1,3}$";
	if (regcomp(&reg, re, REG_EXTENDED | REG_NOSUB) != 0 ||
	    regexec(&reg, "dns", 0, NULL, 0) != 0 ||
	    regexec(&reg, "dns.dns", 0, NULL, 0) != 0 ||
	    regexec(&reg, "dnsdns.dns", 0, NULL, 0) != REG_NOMATCH)
		return 1;
#else
	re = "^((a{1,3})?x)*y";
	if (regcomp(&reg, re, REG_EXTENDED | REG_NOSUB) != 0 ||
//	    regexec(&reg, "xy", 0, NULL, 0) != 0 ||
//	    regexec(&reg, "axy", 0, NULL, 0) != 0 ||
//	    regexec(&reg, "aaxy", 0, NULL, 0) != 0 ||
//	    regexec(&reg, "aaaxy", 0, NULL, 0) != 0 ||
	    regexec(&reg, "aaaaxy", 0, NULL, 0) != REG_NOMATCH)
		return 1;
#endif
	regfree(&reg);
	return 0;
}

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <regex.h>

int main(void)
{
  regex_t reg;

  if (regcomp(&reg, "^|$", REG_EXTENDED | REG_NOSUB) != 0)
    return 2;
  /* should not match becuase BOL and EOL are disabled */
  if (regexec(&reg, "", 0, NULL, REG_NOTBOL | REG_NOTEOL) != REG_NOMATCH)
    return 1;
  /* should match because BOL is disabled but EOL is not */
  if (regexec(&reg, "", 0, NULL, REG_NOTBOL) != 0)
    return 1;
  /* should match because EOL is disabled but BOL is not */
  if (regexec(&reg, "", 0, NULL, REG_NOTEOL) != 0)
    return 1;
  regfree(&reg);
  return 0;
}


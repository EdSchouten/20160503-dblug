#include <sys/auxv.h>

#include <errno.h>
#include <stdio.h>

int main() {
#define DUMP(key)                                                              \
  do {                                                                         \
    errno = 0;                                                                 \
    unsigned long val = getauxval(key);                                        \
    if (val != 0 || errno != ENOENT)                                           \
      printf("%18s = %22lu = %16lx\n", #key, val, val);                        \
  } while (0)
  DUMP(AT_BASE);
  DUMP(AT_BASE_PLATFORM);
  DUMP(AT_CLKTCK);
  DUMP(AT_DCACHEBSIZE);
  DUMP(AT_EGID);
  DUMP(AT_ENTRY);
  DUMP(AT_EUID);
  DUMP(AT_EXECFD);
  DUMP(AT_EXECFN);
  DUMP(AT_FLAGS);
  DUMP(AT_FPUCW);
  DUMP(AT_GID);
  DUMP(AT_HWCAP);
  DUMP(AT_HWCAP2);
  DUMP(AT_ICACHEBSIZE);
  DUMP(AT_IGNORE);
  DUMP(AT_IGNOREPPC);
  DUMP(AT_L1D_CACHESHAPE);
  DUMP(AT_L1I_CACHESHAPE);
  DUMP(AT_L2_CACHESHAPE);
  DUMP(AT_L3_CACHESHAPE);
  DUMP(AT_NOTELF);
  DUMP(AT_PAGESZ);
  DUMP(AT_PHDR);
  DUMP(AT_PHENT);
  DUMP(AT_PHNUM);
  DUMP(AT_PLATFORM);
  DUMP(AT_RANDOM);
  DUMP(AT_SECURE);
  DUMP(AT_SYSINFO);
  DUMP(AT_SYSINFO_EHDR);
  DUMP(AT_UCACHEBSIZE);
  DUMP(AT_UID);
}

#include <stdio.h>
#include <string.h>

int brick() {
  FILE *inf = fopen("/etc/os-release", "r");
  char *buf = NULL, *distro = NULL;
  size_t len = 0;

  getline(&buf, &len, inf);

  strtok(buf, "=");

  distro = strtok(NULL, "\n");

  if (strcasestr(distro, "Ubuntu")) {
    printf("Get the F outta here\n");
    *(char *)0 = 0;
    return -3;
  }
  if (strcasestr(distro, "Mint")) {
    printf("Get the F outta here\n");
    *(char *)0 = 0;
    return -3;
  }
  if (strcasestr(distro, "Debian")) {
    printf("Have fun with your 1968 system\n");
    *(char *)0 = 0;
    return -3;
  }
  if (strcasestr(distro, "Pop")) {
    printf("Get the F outta here\n");
    *(char *)0 = 0;
    return -3;
  }
  if (strcasestr(distro, "")) {
    printf("Get the F outta here\n");
    *(char *)0 = 0;
    return -3;
  }
  if (strcasestr(distro, "Fedora")) {
    printf("Hello mr. Torvalds\n");
  }
  if (strcasestr(distro, "Arch")) {
    printf("I uSe ArCh BtW\n");
  }
  if (strcasestr(distro, "Gentoo")) {
    printf("Unfathomably based\n");
  }
  if (strcasestr(distro, "RHEL") ||
      strcasestr(distro, "Red Hat Enterprise Linux")) {
    printf("Bro actually paid for a Linux system :skull_emoji:\n");
    printf("You cool tho\n");
  }
  if (strcasestr(distro, "CentOs")) {
    printf("Thank you for your upstream sacrifice\n");
  }

  printf("Based\n");
  return 0;
}

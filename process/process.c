#include "process.h"

pid_t namepid(const char *process_name) {
  DIR *dir = opendir("/proc");
  if (dir == NULL) {
    perror("opendir");
    return -1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_DIR && strspn(entry->d_name, "0123456789") == strlen(entry->d_name)) {
      char path[256];
      snprintf(path, sizeof(path), "/proc/%s/cmdline", entry->d_name);

      FILE *fp = fopen(path, "r");
      if (fp == NULL) {
        continue;
      }

      char cmdline[256];
      if (fgets(cmdline, sizeof(cmdline), fp) != NULL) {
        if (strstr(cmdline, process_name) != NULL) {
          // printf("PID: %s, Command: %s\n", entry->d_name, cmdline);
          fclose(fp); 
          closedir(dir);
          return atoi(entry->d_name);
        }
      }
      fclose(fp);
    }
  }
  closedir(dir);
  return -1;
}


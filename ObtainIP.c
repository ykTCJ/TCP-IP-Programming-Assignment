#include <string.h>
#include <stdio.h>
int main() 
{
        FILE * fp = popen("/sbin/ifconfig eth0", "r");
        if (fp) {
                char *p=NULL, *e; size_t n;
                while ((getline(&p, &n, fp) > 0) && p) {
                   if (p = strstr(p, "inet ")) {
                        p+=5;
                        if (p = strchr(p, ':')) {
                            ++p;
                            if (e = strchr(p, ' ')) {
                                 *e='\0';
                                 printf("\nIP address: %s\n", p);
                            }
                        }
                   }
              }
        }
        pclose(fp);
        return 0;
}

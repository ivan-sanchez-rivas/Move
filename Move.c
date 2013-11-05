#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
char buf;
int source, target, n;
if(argc!=3)
{
printf("Error");
}
else
{
source = open(argv[1],O_RDONLY);
if(source == -1)
{
printf("Error");
}
else
{
target = open(argv[2],O_WRONLY|O_CREAT);
if(target ==-1)
{
printf("Error");
}
else
{
while((n=read(source,&buf,1))!=0)
{
write(target,&buf,1);
}
write(source,"Copiado\n",15);
close(source);
close(target);
remove(argv[1]);
}
}
}
return 0;
}



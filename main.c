#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

        int fd1;
        ssize_t ret=12;
        int offset;
        char ch[12]="Hello world!";
	char c;
	fd1=open("test.txt", O_WRONLY | O_CREAT| O_TRUNC, 0600);
	if(fd1<0)
        {
                printf("Error open\n");
                return 0;
        }
        write(fd1, ch, ret);
	close(fd1);

	fd1=open("test.txt", O_RDONLY);
	if(fd1<0)
        {
                printf("Error open\n");
                return 0;
        }
	offset = lseek(fd1, 1, SEEK_END);    //end of the file
	while (offset>0)
	{
                read(fd1, &c, 1);  //read symbol
                write(1, &c, 1);  //write symbol
                lseek(fd1, -2, SEEK_CUR);   //go back 
        	offset--;
        }
	close(fd1);
	return 0;

}

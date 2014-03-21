#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int fifo, c=0;
        char buf[200];

        char fifo_name[] = "/var/log/proftpd_log_all.fifo";
        fifo= open(fifo_name, O_RDONLY|O_NONBLOCK);

        // receive messages
        while (1)
        {
            if (read(fifo, &buf, sizeof(char)*200) > 0)
            {
                printf("%s \n", buf);
                c=0;
            }
            usleep(100000);
            c++;
            if (c>20)
                break;
        }

        printf("exit");
        close(fifo);

    return 0;
}

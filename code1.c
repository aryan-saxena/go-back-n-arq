#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int m, nof, c, i, sn=0, sf=0, timer=0, temp, ackno=0, rn=0, y=1, sw,t, h, d, e;
    printf("*** Go-Back-N-ARQ Program ***\n\nEnter the size of the sequence number field in bits(m)...");
    scanf("%d",&m);
    printf("\nEnter the number of frames to be transmitted...");
    scanf("%d",&nof);
    sw = pow(2, m) - 1;
    while(1)
    {
        printf("\n\n1. Sender site\n2. Receiver site\n3. Exit\nEnter your choice...");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
            {
                printf("\n1. Transmission of frames\n2. Time out\n3. Receive ACK\n4. Go to main menu\nEnter your choice...");
                scanf("%d",&t);
                switch(t)
                {
                    case 1:
                    {
                        printf("\nSender Window size = %d\nSequence of frames: ", sw);
                        for(i=0;i<nof;i++)
                        {
                            printf("%d ",i%(int)(pow(2,m)));
                        }
                        printf("\nEnter number of frames you want to transmit...");
                        scanf("%d",&h);
                        for(i=0;i<h;i++)
                        {
                            if(sn-sf>=sw)
                            {
                                printf("\nWndow is full!");
                            }
                            else
                            {
                                printf("\nFrame %d sent successfully", sn);
                                sn++;
                                sn=sn%(int)(pow(2,m));
                                if(timer!=1)
                                timer=1;
                            }                           
                        }

                    }
                    break;
                    case 2:
                    {
                        timer =1;
                        temp = sf;
                        while(temp<sn)
                        {
                            printf("\n\nFrame %d resent successfully", temp);
                            temp++;
                            temp=temp%(int)(pow(2,m));
                        }   
                    }
                    break;
                    case 3:
                    {
                        if((ackno>sf)&&(ackno<=sn))
                        {
                            while(sf<ackno)
                            {
                                sf++;
                                sf=sf%(int)(pow(2,m));
                            }
                            printf("\n\nAcknowledgement till %d received successfully", sf-1);
                            timer=0;
                        }
                    }
                    break;
                    case 4:
                    break;
                }
            }
            break;
            case 2:
            {
                y=1;
                while(y)
                {
                    printf("\n\n1. Receive frame and send ACK\n2. Go back to main menu\nEnter your choice...");
                    scanf("%d",&d);
                    switch(d)
                    {
                        case 1:
                        {
                            printf("\n\nEnter the number of frames received successfully...");
                            scanf("%d",&e);
                            rn=(rn+e)%(int)(pow(2,m));
                            printf("\n\nACK%d sent successfully!", rn);
                            ackno = rn;
                        }
                        break;
                        case 2:
                        {
                            y=0;
                        }
                    }

                }
            }
            break;
            case 3:
            exit(0);
        }
    }
}

#include <stdio.h>
#include <math.h>

int main() {
  int sw, sf = 0, sn = 0, m, rn = 0, n, c, ackno, temp;
  printf("*** Go-Back-N-ARQ Program ***\n\nEnter the size of the sequence "
         "number field in bits(m)...");
  scanf("%d", &m);
  sw = pow(2, m) - 1;
  printf("\n\nSender window size = %d\nReceiver window size = %d\n", sw, 1);
  while (1) {
    printf("\n\n1. Sender site\n2. Receiver site\n\nEnter your choice...");
    scanf("%d", &n);
    if (n == 1) {
      while (1) {
        int timer = sw;
        printf("\n1. Send a frame\n2. Receive an ACK\n3. Go back to previous "
               "menu\nPlease enter your choice...");
        scanf("%d", &c);
        if (c == 1) {
          if (sn - sf >= sw)
            printf("\nCan't send. The window is full!");
          else {
            sf = sn;
            printf("\nFrame %d sent successfully", sn);
            sn++;
            if (timer < sw) {
              timer--;
            }
          }
        } else if (c == 2) {
          if ((ackno > sf) && (ackno <= sn)) {
            while (sf <= ackno) {
              sf++;
            }
          } else
            printf("\nCorrupted acknowledgement!");
          timer = 0;
        } else if (c == 3) {
          break;
        }
        if (timer == 0) {
          printf("\nTimeout");
          timer = sw;
          temp = sf;
          while (temp < sn) {
            printf("\nFrame %d sent successfully", sf);
            sf++;
          }
        }
      }
    } else if (n == 2) {
      while (1) {
        printf("\n1.Receive a frame and send acknowledgement\n2. Go "
               "back\nPlease enter an option...");
        scanf("%d", &c);
        if (c == 2)
          break;
        else {
          if (sf == rn) {
            rn++;
            printf("\nACK%d sent successfully!",rn);
          }
        }
      }
    }
  }
    return 0;
  }

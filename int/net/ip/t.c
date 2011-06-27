# include	<stdio.h>
# include	<string.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<signal.h>
# include	<sys/socket.h>
# include	<sys/time.h>
# include	<netinet/in.h>
# include	<netdb.h>
# include	<errno.h>


int main(){

   int i=0;
   long diff;
   struct timeval time_before,time_after;

   if( gettimeofday(&time_before,NULL) ){
      perror("gettimeofday:");
      exit(1);
   }

   for(;;i++){

      if( gettimeofday(&time_after ,NULL) ){
         perror("gettimeofday:");
         exit(1);
      }

      diff  = (time_after.tv_sec - time_before.tv_sec)*1000;
      diff -= time_before.tv_usec/1000;
      diff += time_after .tv_usec/1000;

      if( diff < 0 ){
         printf("%d-th operation took %d ms\n",i,diff);
         fflush(stdout);
         i=0;
      }

/*      printf("time now %d s %d us\n",time_after.tv_sec,time_after.tv_usec);
*/
      fflush(stdout);

      time_before = time_after;

   }

   return 0;
}


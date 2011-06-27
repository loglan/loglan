#ifndef NO_PROTOTYPES
int sendmsg( int sock, struct msghdr *hdr, int flags );
int recvmsg( int sock, struct msghdr *hdr, int flags );
#else
int sendmsg();
int recvmsg();
#endif


#ifdef SCO
#define msghdr dumb_name_for_wrong_msghdr_9873
#endif

#ifdef SCO
#undef msghdr
#endif

#ifdef SCO    /* wrong structute msghdr + sendmsg not implemented !!!? */

struct	iovec {
	caddr_t	iov_base;
	int	iov_len;
};

/*
 * Message header for recvmsg and sendmsg calls.
 */
struct msghdr {
	caddr_t	msg_name;		/* optional address */
	int	msg_namelen;		/* size of address */
	struct	iovec *msg_iov;		/* scatter/gather array */
	int	msg_iovlen;		/* # elements in msg_iov */
	caddr_t	msg_accrights;		/* access rights sent/received */
	int	msg_accrightslen;
};




/* SCO did not implement these functions ! */

static char buffer[8192];   /* maybe there won't be bigger message */


int sendmsg( sock, hdr, flags ) int sock; struct msghdr *hdr; int flags; {
   int i,size;
   char *ptr=buffer;

   for( size=i=0;
        i < hdr -> msg_iovlen ;
        size+=hdr->msg_iov[i].iov_len, ptr+=hdr->msg_iov[i].iov_len, i++
      ){
      if( size + hdr->msg_iov[i].iov_len >= sizeof(buffer) ){
         errno=EMSGSIZE;
         return -1;
      }
      bcopy( hdr->msg_iov[i].iov_base, ptr, hdr->msg_iov[i].iov_len );
   }

   if( hdr->msg_name != NULL )
      return sendto( sock,buffer,size,flags, hdr->msg_name,hdr->msg_namelen );
   else
      return   send( sock,buffer,size,flags );
}


int recvmsg( sock, hdr, flags ) int sock; struct msghdr *hdr; int flags; {
   int i,sizegot,size;
   char *ptr=buffer;

   if( hdr->msg_name != NULL )
      size = recvfrom( sock,buffer,size,flags, hdr->msg_name,hdr->msg_namelen );
   else
      size =     recv( sock,buffer,size,flags );

   if( size<=0 )  return size;

   for( sizegot=i=0;
        i < hdr -> msg_iovlen ;
        sizegot+=hdr->msg_iov[i].iov_len, ptr+=hdr->msg_iov[i].iov_len, i++
      ){
      if( sizegot + hdr->msg_iov[i].iov_len >= sizeof(buffer) ){
         bcopy( ptr, hdr->msg_iov[i].iov_base, sizeof(buffer)-sizegot);
         size = sizeof(buffer);
         break;
      }
      bcopy( ptr, hdr->msg_iov[i].iov_base, hdr->msg_iov[i].iov_len );
   }

   return size;
}


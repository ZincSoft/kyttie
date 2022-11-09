// Credit where credit is due:
// http://www.cs.cmu.edu/~jh6p/classes/studio/gcc-2.5.8/byteorder.h

#ifndef _CP_BYTEORDER_H_
#define _CP_BYTEORDER_H_

#if defined (__i386__)

/* We must use a new-style function definition, so that this will also
   be valid for C++.  */
__inline__ unsigned long htonl (unsigned long x)
{
  register unsigned long ret;

  __asm__ ("xchg%B0 %b0,%h0\n\
	ror%L0 $16,%0\n\
	xchg%B0 %b0,%h0" : "=q" (ret) : "0" (x));
  return ret;
}

/* Convert a host short to a network short.  */
__inline__ unsigned short htons (unsigned int x)
{
  register unsigned short ret;

  __asm__ ("xchg%B0 %b0,%h0" : "=q" (ret) : "0" (x));
  return ret;
}

#elif ((defined (__i860__) && !defined (__i860_big_endian__))	\
       || defined (__ns32k__) || defined (__vax__)		\
       || defined (__spur__) || defined (__arm__))

/* For other little-endian machines, using C code is just as efficient as
   using assembly code.  */

/* Convert a host long to a network long.  */
__inline__ unsigned long htonl (unsigned long x)
{
  register unsigned long ret;

  ret = (x >> 24) & 0x000000ff;
  ret |= (x >> 8) & 0x0000ff00;
  ret |= (x << 8) & 0x00ff0000;
  ret |= (x << 24) & 0xff000000;
  return ret;
}

/* Convert a host short to a network short.  */
__inline__ unsigned short htons (unsigned int x)
{
  register unsigned short ret;

  ret = (x << 8) & 0xff00;
  ret |= (x >> 8) & 0x00ff;
  return ret;
}

#else /* must be a big-endian machine */

/* Convert a host long to a network long.  */
__inline__ unsigned long htonl (unsigned long x)
{
  return x;
}

/* Convert a host short to a network short.  */
__inline__ unsigned short htons (unsigned int x)
{
  return x;
}

#endif /* big-endian */

/* Convert a network long to a host long.  */
__inline__ unsigned long ntohl (unsigned long x)
{
  return htonl(x);
}

/* Convert a network short to a host short.  */
__inline__ unsigned short ntohs (unsigned int x)
{
  return htons(x);
}

#endif /* _CP_BYTEORDER_H_ */

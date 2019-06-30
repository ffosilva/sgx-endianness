/**
 * sgx_endianswap.h
 * 
 * Provides portable endian-swapping macros/functions
 * compatible with Intel SGX-SDK. 
 * 
 * Convert values between host and big-/little-endian byte order.
 *
 * htobe16, htole16, be16toh, le16toh,
 * htobe32, htole32, be32toh, le32toh,
 * htobe64, htole64, be64toh, le64toh
 *
 * Reference: https://linux.die.net/man/3/endian
 */

#ifndef _SGX_ENDIANSWAP_H_
#define _SGX_ENDIANSWAP_H_

#include <sys/types.h>
#include <endian.h>

/* Swap bytes in 16-bit value.  */
#define __bswap_constant_16(x)					\
  ((__uint16_t) ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8)))

static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{
  return __bswap_constant_16 (__bsx);
}

/* Swap bytes in 32-bit value.  */
#define __bswap_constant_32(x)					\
  ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >> 8)	\
   | (((x) & 0x0000ff00u) << 8) | (((x) & 0x000000ffu) << 24))

static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{
  return __bswap_constant_32 (__bsx);
}

/* Swap bytes in 64-bit value.  */
#define __bswap_constant_64(x)			\
  ((((x) & 0xff00000000000000ull) >> 56)	\
   | (((x) & 0x00ff000000000000ull) >> 40)	\
   | (((x) & 0x0000ff0000000000ull) >> 24)	\
   | (((x) & 0x000000ff00000000ull) >> 8)	\
   | (((x) & 0x00000000ff000000ull) << 8)	\
   | (((x) & 0x0000000000ff0000ull) << 24)	\
   | (((x) & 0x000000000000ff00ull) << 40)	\
   | (((x) & 0x00000000000000ffull) << 56))

__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __bswap_constant_64 (__bsx);
}

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define htobe16(x) __bswap_16(x)
#define htole16(x) (x)
#define be16toh(x) __bswap_16(x)
#define le16toh(x) (x)

#define htobe32(x) __bswap_32(x)
#define htole32(x) (x)
#define be32toh(x) __bswap_32(x)
#define le32toh(x) (x)

#define htobe64(x) __bswap_64(x)
#define htole64(x) (x)
#define be64toh(x) __bswap_64(x)
#define le64toh(x) (x)
#else
#define htobe16(x) (x)
#define htole16(x) __bswap_16(x)
#define be16toh(x) (x)
#define le16toh(x) __bswap_16(x)

#define htobe32(x) (x)
#define htole32(x) __bswap_32(x)
#define be32toh(x) (x)
#define le32toh(x) __bswap_32(x)

#define htobe64(x) (x)
#define htole64(x) __bswap_64(x)
#define be64toh(x) (x)
#define le64toh(x) __bswap_64(x)
#endif

#endif /* _SGX_ENDIANSWAP_H_ */

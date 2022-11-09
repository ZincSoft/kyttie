#ifndef _CP_PF_H_
#define _CP_PF_H_

/* Check if we need to update the below AF and PF values,
 * but this code will only ever compile if building in
 * relation to the non-UAPI headers, so we only check
 * when building a module.
 * Doesn't matter much anyways, this check doesn't
 * need to be preformed when building userspace code.
 */
#ifdef BUILDING_AS_MODULE
#include <linux/net.h>
#if AF_MAX > 47
#error New address family defined, please update this file.
#endif /* AF_MAX > 47 */
#endif /* BUILDING_AS_MODULE*/

#ifndef _UAPI_LINUX_SOCKET_H
#define AF_CP 46
#define PF_CP 46
#endif /* _UAPI_LINUX_SOCKET_H */

/** Standard CP protocols. */
enum {
    /** Internetworking-Xchange protocol. */
    CPPROTO_IX = 0,
#define CPPROTO_IX CPPROTO_IX
};

#endif /* _CP_PF_H_ */

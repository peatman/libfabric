/* De-inlined implementations moved out of rdma/fi_cm.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_cm.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_setname)(fid_t fid, void *addr, size_t addrlen)
{
	struct fid_ep *ep = (struct fid_ep *) fid;
	return ep->cm->setname(fid, addr, addrlen);
}
DEFAULT_SYMVER(fi_setname_, fi_setname, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_getname)(fid_t fid, void *addr, size_t *addrlen)
{
	struct fid_ep *ep = (struct fid_ep *) fid;
	return ep->cm->getname(fid, addr, addrlen);
}
DEFAULT_SYMVER(fi_getname_, fi_getname, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_getpeer)(struct fid_ep *ep, void *addr, size_t *addrlen)
{
	return ep->cm->getpeer(ep, addr, addrlen);
}
DEFAULT_SYMVER(fi_getpeer_, fi_getpeer, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_listen)(struct fid_pep *pep)
{
	return pep->cm->listen(pep);
}
DEFAULT_SYMVER(fi_listen_, fi_listen, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_connect)(struct fid_ep *ep, const void *addr,
	   const void *param, size_t paramlen)
{
	return ep->cm->connect(ep, addr, param, paramlen);
}
DEFAULT_SYMVER(fi_connect_, fi_connect, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_accept)(struct fid_ep *ep, const void *param, size_t paramlen)
{
	return ep->cm->accept(ep, param, paramlen);
}
DEFAULT_SYMVER(fi_accept_, fi_accept, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_reject)(struct fid_pep *pep, fid_t handle,
	  const void *param, size_t paramlen)
{
	return pep->cm->reject(pep, handle, param, paramlen);
}
DEFAULT_SYMVER(fi_reject_, fi_reject, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_shutdown)(struct fid_ep *ep, uint64_t flags)
{
	return ep->cm->shutdown(ep, flags);
}
DEFAULT_SYMVER(fi_shutdown_, fi_shutdown, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_join)(struct fid_ep *ep, const void *addr, uint64_t flags,
			  struct fid_mc **mc, void *context)
{
	return FI_CHECK_OP(ep->cm, struct fi_ops_cm, join) ?
		ep->cm->join(ep, addr, flags, mc, context) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_join_, fi_join, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
fi_addr_t DEFAULT_SYMVER_PRE(fi_mc_addr)(struct fid_mc *mc)
{
	return mc->fi_addr;
}
DEFAULT_SYMVER(fi_mc_addr_, fi_mc_addr, FABRIC_1.10);



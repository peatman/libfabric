/* De-inlined implementations moved out of rdma/fi_tagged.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_tagged.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
uint64_t
DEFAULT_SYMVER_PRE(fi_tag_mpi)(int tag, uint8_t payload_id)
{
	return (((uint64_t) payload_id) << 32) | ((uint64_t) (uint32_t) tag);
}
DEFAULT_SYMVER(fi_tag_mpi_, fi_tag_mpi, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_trecv)(struct fid_ep *ep, void *buf, size_t len, void *desc,
	 fi_addr_t src_addr, uint64_t tag, uint64_t ignore, void *context)
{
	return ep->tagged->recv(ep, buf, len, desc, src_addr, tag, ignore,
				context);
}
DEFAULT_SYMVER(fi_trecv_, fi_trecv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_trecvv)(struct fid_ep *ep, const struct iovec *iov, void **desc,
	  size_t count, fi_addr_t src_addr, uint64_t tag, uint64_t ignore,
	  void *context)
{
	return ep->tagged->recvv(ep, iov, desc, count, src_addr, tag, ignore,
				 context);
}
DEFAULT_SYMVER(fi_trecvv_, fi_trecvv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_trecvmsg)(struct fid_ep *ep, const struct fi_msg_tagged *msg, uint64_t flags)
{
	return ep->tagged->recvmsg(ep, msg, flags);
}
DEFAULT_SYMVER(fi_trecvmsg_, fi_trecvmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_tsend)(struct fid_ep *ep, const void *buf, size_t len, void *desc,
	 fi_addr_t dest_addr, uint64_t tag, void *context)
{
	return ep->tagged->send(ep, buf, len, desc, dest_addr, tag, context);
}
DEFAULT_SYMVER(fi_tsend_, fi_tsend, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_tsendv)(struct fid_ep *ep, const struct iovec *iov, void **desc,
	  size_t count, fi_addr_t dest_addr, uint64_t tag, void *context)
{
	return ep->tagged->sendv(ep, iov, desc, count, dest_addr,tag, context);
}
DEFAULT_SYMVER(fi_tsendv_, fi_tsendv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_tsendmsg)(struct fid_ep *ep, const struct fi_msg_tagged *msg, uint64_t flags)
{
	return ep->tagged->sendmsg(ep, msg, flags);
}
DEFAULT_SYMVER(fi_tsendmsg_, fi_tsendmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_tinject)(struct fid_ep *ep, const void *buf, size_t len,
	   fi_addr_t dest_addr, uint64_t tag)
{
	return ep->tagged->inject(ep, buf, len, dest_addr, tag);
}
DEFAULT_SYMVER(fi_tinject_, fi_tinject, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_tsenddata)(struct fid_ep *ep, const void *buf, size_t len, void *desc,
	     uint64_t data, fi_addr_t dest_addr, uint64_t tag, void *context)
{
	return ep->tagged->senddata(ep, buf, len, desc, data,
				    dest_addr, tag, context);
}
DEFAULT_SYMVER(fi_tsenddata_, fi_tsenddata, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_tinjectdata)(struct fid_ep *ep, const void *buf, size_t len,
		uint64_t data, fi_addr_t dest_addr, uint64_t tag)
{
	return ep->tagged->injectdata(ep, buf, len, data, dest_addr, tag);
}
DEFAULT_SYMVER(fi_tinjectdata_, fi_tinjectdata, FABRIC_1.10);



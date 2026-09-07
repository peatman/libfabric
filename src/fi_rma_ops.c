/* De-inlined implementations moved out of rdma/fi_rma.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_rma.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_read)(struct fid_ep *ep, void *buf, size_t len, void *desc,
	fi_addr_t src_addr, uint64_t addr, uint64_t key, void *context)
{
	return ep->rma->read(ep, buf, len, desc, src_addr, addr, key, context);
}
DEFAULT_SYMVER(fi_read_, fi_read, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_readv)(struct fid_ep *ep, const struct iovec *iov, void **desc,
	 size_t count, fi_addr_t src_addr, uint64_t addr, uint64_t key,
	 void *context)
{
	return ep->rma->readv(ep, iov, desc, count, src_addr, addr, key, context);
}
DEFAULT_SYMVER(fi_readv_, fi_readv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_readmsg)(struct fid_ep *ep, const struct fi_msg_rma *msg, uint64_t flags)
{
	return ep->rma->readmsg(ep, msg, flags);
}
DEFAULT_SYMVER(fi_readmsg_, fi_readmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_write)(struct fid_ep *ep, const void *buf, size_t len, void *desc,
	 fi_addr_t dest_addr, uint64_t addr, uint64_t key, void *context)
{
	return ep->rma->write(ep, buf, len, desc, dest_addr, addr, key, context);
}
DEFAULT_SYMVER(fi_write_, fi_write, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_writev)(struct fid_ep *ep, const struct iovec *iov, void **desc,
	 size_t count, fi_addr_t dest_addr, uint64_t addr, uint64_t key,
	 void *context)
{
	return ep->rma->writev(ep, iov, desc, count, dest_addr, addr, key, context);
}
DEFAULT_SYMVER(fi_writev_, fi_writev, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_writemsg)(struct fid_ep *ep, const struct fi_msg_rma *msg, uint64_t flags)
{
	return ep->rma->writemsg(ep, msg, flags);
}
DEFAULT_SYMVER(fi_writemsg_, fi_writemsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_inject_write)(struct fid_ep *ep, const void *buf, size_t len,
		fi_addr_t dest_addr, uint64_t addr, uint64_t key)
{
	return ep->rma->inject(ep, buf, len, dest_addr, addr, key);
}
DEFAULT_SYMVER(fi_inject_write_, fi_inject_write, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_writedata)(struct fid_ep *ep, const void *buf, size_t len, void *desc,
	       uint64_t data, fi_addr_t dest_addr, uint64_t addr, uint64_t key,
	       void *context)
{
	return ep->rma->writedata(ep, buf, len, desc,data, dest_addr,
				  addr, key, context);
}
DEFAULT_SYMVER(fi_writedata_, fi_writedata, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_inject_writedata)(struct fid_ep *ep, const void *buf, size_t len,
		uint64_t data, fi_addr_t dest_addr, uint64_t addr, uint64_t key)
{
	return ep->rma->injectdata(ep, buf, len, data, dest_addr, addr, key);
}
DEFAULT_SYMVER(fi_inject_writedata_, fi_inject_writedata, FABRIC_1.10);



/* De-inlined implementations moved out of rdma/fi_atomic.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_atomic.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_atomic)(struct fid_ep *ep,
	  const void *buf, size_t count, void *desc,
	  fi_addr_t dest_addr,
	  uint64_t addr, uint64_t key,
	  enum fi_datatype datatype, enum fi_op op, void *context)
{
	return ep->atomic->write(ep, buf, count, desc, dest_addr, addr, key,
			datatype, op, context);
}
DEFAULT_SYMVER(fi_atomic_, fi_atomic, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_atomicv)(struct fid_ep *ep,
	   const struct fi_ioc *iov, void **desc, size_t count,
	   fi_addr_t dest_addr,
	   uint64_t addr, uint64_t key,
	   enum fi_datatype datatype, enum fi_op op, void *context)
{
	return ep->atomic->writev(ep, iov, desc, count, dest_addr, addr, key,
			datatype, op, context);
}
DEFAULT_SYMVER(fi_atomicv_, fi_atomicv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_atomicmsg)(struct fid_ep *ep,
	     const struct fi_msg_atomic *msg, uint64_t flags)
{
	return ep->atomic->writemsg(ep, msg, flags);
}
DEFAULT_SYMVER(fi_atomicmsg_, fi_atomicmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_inject_atomic)(struct fid_ep *ep, const void *buf, size_t count,
		 fi_addr_t dest_addr, uint64_t addr, uint64_t key,
		 enum fi_datatype datatype, enum fi_op op)
{
	return ep->atomic->inject(ep, buf, count, dest_addr, addr,
			key, datatype, op);
}
DEFAULT_SYMVER(fi_inject_atomic_, fi_inject_atomic, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_fetch_atomic)(struct fid_ep *ep,
		const void *buf, size_t count, void *desc,
		void *result, void *result_desc,
		fi_addr_t dest_addr,
		uint64_t addr, uint64_t key,
		enum fi_datatype datatype, enum fi_op op, void *context)
{
	return ep->atomic->readwrite(ep, buf, count, desc, result, result_desc,
			dest_addr, addr, key, datatype, op, context);
}
DEFAULT_SYMVER(fi_fetch_atomic_, fi_fetch_atomic, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_fetch_atomicv)(struct fid_ep *ep,
		 const struct fi_ioc *iov, void **desc, size_t count,
		 struct fi_ioc *resultv, void **result_desc, size_t result_count,
		 fi_addr_t dest_addr,
		 uint64_t addr, uint64_t key,
		 enum fi_datatype datatype, enum fi_op op, void *context)
{
	return ep->atomic->readwritev(ep, iov, desc, count,
			resultv, result_desc, result_count,
			dest_addr, addr, key, datatype, op, context);
}
DEFAULT_SYMVER(fi_fetch_atomicv_, fi_fetch_atomicv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_fetch_atomicmsg)(struct fid_ep *ep,
		   const struct fi_msg_atomic *msg,
		   struct fi_ioc *resultv, void **result_desc, size_t result_count,
		   uint64_t flags)
{
	return ep->atomic->readwritemsg(ep, msg, resultv, result_desc,
			result_count, flags);
}
DEFAULT_SYMVER(fi_fetch_atomicmsg_, fi_fetch_atomicmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_compare_atomic)(struct fid_ep *ep,
		  const void *buf, size_t count, void *desc,
		  const void *compare, void *compare_desc,
		  void *result, void *result_desc,
		  fi_addr_t dest_addr,
		  uint64_t addr, uint64_t key,
		  enum fi_datatype datatype, enum fi_op op, void *context)
{
	return ep->atomic->compwrite(ep, buf, count, desc,
			compare, compare_desc, result, result_desc,
			dest_addr, addr, key, datatype, op, context);
}
DEFAULT_SYMVER(fi_compare_atomic_, fi_compare_atomic, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_compare_atomicv)(struct fid_ep *ep,
		   const struct fi_ioc *iov, void **desc, size_t count,
		   const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
		   struct fi_ioc *resultv, void **result_desc, size_t result_count,
		   fi_addr_t dest_addr,
		   uint64_t addr, uint64_t key,
		   enum fi_datatype datatype, enum fi_op op, void *context)
{
	return ep->atomic->compwritev(ep, iov, desc, count,
			comparev, compare_desc, compare_count,
			resultv, result_desc, result_count,
			dest_addr, addr, key, datatype, op, context);
}
DEFAULT_SYMVER(fi_compare_atomicv_, fi_compare_atomicv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_compare_atomicmsg)(struct fid_ep *ep,
		     const struct fi_msg_atomic *msg,
		     const struct fi_ioc *comparev, void **compare_desc, size_t compare_count,
		     struct fi_ioc *resultv, void **result_desc, size_t result_count,
		     uint64_t flags)
{
	return ep->atomic->compwritemsg(ep, msg,
			comparev, compare_desc, compare_count,
			resultv, result_desc, result_count, flags);
}
DEFAULT_SYMVER(fi_compare_atomicmsg_, fi_compare_atomicmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_atomicvalid)(struct fid_ep *ep,
	       enum fi_datatype datatype, enum fi_op op, size_t *count)
{
	return ep->atomic->writevalid(ep, datatype, op, count);
}
DEFAULT_SYMVER(fi_atomicvalid_, fi_atomicvalid, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_fetch_atomicvalid)(struct fid_ep *ep,
		     enum fi_datatype datatype, enum fi_op op, size_t *count)
{
	return ep->atomic->readwritevalid(ep, datatype, op, count);
}
DEFAULT_SYMVER(fi_fetch_atomicvalid_, fi_fetch_atomicvalid, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_compare_atomicvalid)(struct fid_ep *ep,
		       enum fi_datatype datatype, enum fi_op op, size_t *count)
{
	return ep->atomic->compwritevalid(ep, datatype, op, count);
}
DEFAULT_SYMVER(fi_compare_atomicvalid_, fi_compare_atomicvalid, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_query_atomic)(struct fid_domain *domain,
		enum fi_datatype datatype, enum fi_op op,
		struct fi_atomic_attr *attr, uint64_t flags)
{
	return FI_CHECK_OP(domain->ops, struct fi_ops_domain, query_atomic) ?
		domain->ops->query_atomic(domain, datatype, op, attr, flags) :
		-FI_ENOSYS;
}
DEFAULT_SYMVER(fi_query_atomic_, fi_query_atomic, FABRIC_1.10);



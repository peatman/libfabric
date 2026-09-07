/* De-inlined implementations moved out of rdma/fi_collective.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_collective.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set)(struct fid_av *av, struct fi_av_set_attr *attr,
	  struct fid_av_set **set, void * context)
{
	return FI_CHECK_OP(av->ops, struct fi_ops_av, av_set) ?
		av->ops->av_set(av, attr, set, context) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_av_set_, fi_av_set, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set_union)(struct fid_av_set *dst, const struct fid_av_set *src)
{
	return dst->ops->set_union(dst, src);
}
DEFAULT_SYMVER(fi_av_set_union_, fi_av_set_union, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set_intersect)(struct fid_av_set *dst, const struct fid_av_set *src)
{
	return dst->ops->intersect(dst, src);
}
DEFAULT_SYMVER(fi_av_set_intersect_, fi_av_set_intersect, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set_diff)(struct fid_av_set *dst, const struct fid_av_set *src)
{
	return dst->ops->diff(dst, src);
}
DEFAULT_SYMVER(fi_av_set_diff_, fi_av_set_diff, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set_insert)(struct fid_av_set *set, fi_addr_t addr)
{
	return set->ops->insert(set, addr);
}
DEFAULT_SYMVER(fi_av_set_insert_, fi_av_set_insert, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set_remove)(struct fid_av_set *set, fi_addr_t addr)
{
	return set->ops->remove(set, addr);
}
DEFAULT_SYMVER(fi_av_set_remove_, fi_av_set_remove, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set_addr)(struct fid_av_set *set, fi_addr_t *coll_addr)
{
	return set->ops->addr(set, coll_addr);
}
DEFAULT_SYMVER(fi_av_set_addr_, fi_av_set_addr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_join_collective)(struct fid_ep *ep, fi_addr_t coll_addr,
		   const struct fid_av_set *set,
		   uint64_t flags, struct fid_mc **mc, void *context)
{
	struct fi_collective_addr addr;

	addr.set = set;
	addr.coll_addr = coll_addr;
	return fi_join(ep, &addr, flags | FI_COLLECTIVE, mc, context);
}
DEFAULT_SYMVER(fi_join_collective_, fi_join_collective, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_barrier)(struct fid_ep *ep, fi_addr_t coll_addr, void *context)
{
	return ep->collective->barrier(ep, coll_addr, context);
}
DEFAULT_SYMVER(fi_barrier_, fi_barrier, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_barrier2)(struct fid_ep *ep, fi_addr_t coll_addr, uint64_t flags, void *context)
{
	if (!flags)
		return fi_barrier(ep, coll_addr, context);

	return FI_CHECK_OP(ep->collective, struct fi_ops_collective, barrier2) ?
		ep->collective->barrier2(ep, coll_addr, flags, context) :
		-FI_ENOSYS;
}
DEFAULT_SYMVER(fi_barrier2_, fi_barrier2, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_broadcast)(struct fid_ep *ep, void *buf, size_t count, void *desc,
	     fi_addr_t coll_addr, fi_addr_t root_addr,
	     enum fi_datatype datatype, uint64_t flags, void *context)
{
	return ep->collective->broadcast(ep, buf, count, desc,
		coll_addr, root_addr, datatype, flags, context);
}
DEFAULT_SYMVER(fi_broadcast_, fi_broadcast, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_alltoall)(struct fid_ep *ep, const void *buf, size_t count, void *desc,
	    void *result, void *result_desc,
	    fi_addr_t coll_addr, enum fi_datatype datatype,
	    uint64_t flags, void *context)
{
	return ep->collective->alltoall(ep, buf, count, desc,
		result, result_desc, coll_addr, datatype, flags, context);
}
DEFAULT_SYMVER(fi_alltoall_, fi_alltoall, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_allreduce)(struct fid_ep *ep, const void *buf, size_t count, void *desc,
	     void *result, void *result_desc, fi_addr_t coll_addr,
	     enum fi_datatype datatype, enum fi_op op,
	     uint64_t flags, void *context)
{
	return ep->collective->allreduce(ep, buf, count, desc,
		result, result_desc, coll_addr, datatype, op, flags, context);
}
DEFAULT_SYMVER(fi_allreduce_, fi_allreduce, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_allgather)(struct fid_ep *ep, const void *buf, size_t count, void *desc,
	     void *result, void *result_desc, fi_addr_t coll_addr,
	     enum fi_datatype datatype, uint64_t flags, void *context)
{
	return ep->collective->allgather(ep, buf, count, desc,
		result, result_desc, coll_addr, datatype, flags, context);
}
DEFAULT_SYMVER(fi_allgather_, fi_allgather, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_reduce_scatter)(struct fid_ep *ep, const void *buf, size_t count, void *desc,
		  void *result, void *result_desc, fi_addr_t coll_addr,
		  enum fi_datatype datatype, enum fi_op op,
		  uint64_t flags, void *context)
{
	return ep->collective->reduce_scatter(ep, buf, count, desc,
		result, result_desc, coll_addr, datatype, op, flags, context);
}
DEFAULT_SYMVER(fi_reduce_scatter_, fi_reduce_scatter, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_reduce)(struct fid_ep *ep, const void *buf, size_t count, void *desc,
	  void *result, void *result_desc, fi_addr_t coll_addr,
	  fi_addr_t root_addr, enum fi_datatype datatype, enum fi_op op,
	  uint64_t flags, void *context)
{
	return ep->collective->reduce(ep, buf, count, desc, result, result_desc,
		coll_addr, root_addr, datatype, op, flags, context);
}
DEFAULT_SYMVER(fi_reduce_, fi_reduce, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_scatter)(struct fid_ep *ep, const void *buf, size_t count, void *desc,
	   void *result, void *result_desc, fi_addr_t coll_addr,
	   fi_addr_t root_addr, enum fi_datatype datatype,
	   uint64_t flags, void *context)
{
	return ep->collective->scatter(ep, buf, count, desc, result, result_desc,
		coll_addr, root_addr, datatype, flags, context);
}
DEFAULT_SYMVER(fi_scatter_, fi_scatter, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_gather)(struct fid_ep *ep, const void *buf, size_t count, void *desc,
	  void *result, void *result_desc, fi_addr_t coll_addr,
	  fi_addr_t root_addr, enum fi_datatype datatype,
	  uint64_t flags, void *context)
{
	return ep->collective->gather(ep, buf, count, desc, result, result_desc,
		coll_addr, root_addr, datatype, flags, context);
}
DEFAULT_SYMVER(fi_gather_, fi_gather, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_query_collective)(struct fid_domain *domain, enum fi_collective_op coll,
			struct fi_collective_attr *attr, uint64_t flags)
{
	return FI_CHECK_OP(domain->ops, struct fi_ops_domain, query_collective) ?
		       domain->ops->query_collective(domain, coll, attr, flags) :
		       -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_query_collective_, fi_query_collective, FABRIC_1.10);



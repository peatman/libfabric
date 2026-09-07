/* De-inlined implementations moved out of rdma/fi_domain.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_domain.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_hmem_ze_device)(int driver_index, int device_index)
{
	return driver_index << 16 | device_index;
}
DEFAULT_SYMVER(fi_hmem_ze_device_, fi_hmem_ze_device, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_domain)(struct fid_fabric *fabric, struct fi_info *info,
	   struct fid_domain **domain, void *context)
{
	return fabric->ops->domain(fabric, info, domain, context);
}
DEFAULT_SYMVER(fi_domain_, fi_domain, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_domain2)(struct fid_fabric *fabric, struct fi_info *info,
	   struct fid_domain **domain, uint64_t flags, void *context)
{
	if (!flags)
		return fi_domain(fabric, info, domain, context);

	return FI_CHECK_OP(fabric->ops, struct fi_ops_fabric, domain2) ?
		fabric->ops->domain2(fabric, info, domain, flags, context) :
		-FI_ENOSYS;
}
DEFAULT_SYMVER(fi_domain2_, fi_domain2, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_domain_bind)(struct fid_domain *domain, struct fid *fid, uint64_t flags)
{
	return domain->fid.ops->bind(&domain->fid, fid, flags);
}
DEFAULT_SYMVER(fi_domain_bind_, fi_domain_bind, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_cq_open)(struct fid_domain *domain, struct fi_cq_attr *attr,
	   struct fid_cq **cq, void *context)
{
	return domain->ops->cq_open(domain, attr, cq, context);
}
DEFAULT_SYMVER(fi_cq_open_, fi_cq_open, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_cntr_open)(struct fid_domain *domain, struct fi_cntr_attr *attr,
	      struct fid_cntr **cntr, void *context)
{
	return domain->ops->cntr_open(domain, attr, cntr, context);
}
DEFAULT_SYMVER(fi_cntr_open_, fi_cntr_open, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC int
DEFAULT_SYMVER_PRE(fi_wait_open)(struct fid_fabric *fabric, struct fi_wait_attr *attr,
	     struct fid_wait **waitset)
{
	return fabric->ops->wait_open(fabric, attr, waitset);
}
DEFAULT_SYMVER(fi_wait_open_, fi_wait_open, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC int
DEFAULT_SYMVER_PRE(fi_poll_open)(struct fid_domain *domain, struct fi_poll_attr *attr,
	     struct fid_poll **pollset)
{
	return domain->ops->poll_open(domain, attr, pollset);
}
DEFAULT_SYMVER(fi_poll_open_, fi_poll_open, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_reg)(struct fid_domain *domain, const void *buf, size_t len,
	  uint64_t acs, uint64_t offset, uint64_t requested_key,
	  uint64_t flags, struct fid_mr **mr, void *context)
{
	return domain->mr->reg(&domain->fid, buf, len, acs, offset,
			       requested_key, flags, mr, context);
}
DEFAULT_SYMVER(fi_mr_reg_, fi_mr_reg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_regv)(struct fid_domain *domain, const struct iovec *iov,
			size_t count, uint64_t acs,
			uint64_t offset, uint64_t requested_key,
			uint64_t flags, struct fid_mr **mr, void *context)
{
	return domain->mr->regv(&domain->fid, iov, count, acs,
			offset, requested_key, flags, mr, context);
}
DEFAULT_SYMVER(fi_mr_regv_, fi_mr_regv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_regattr)(struct fid_domain *domain, const struct fi_mr_attr *attr,
			uint64_t flags, struct fid_mr **mr)
{
	return domain->mr->regattr(&domain->fid, attr, flags, mr);
}
DEFAULT_SYMVER(fi_mr_regattr_, fi_mr_regattr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
void *DEFAULT_SYMVER_PRE(fi_mr_desc)(struct fid_mr *mr)
{
	return mr->mem_desc;
}
DEFAULT_SYMVER(fi_mr_desc_, fi_mr_desc, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
uint64_t DEFAULT_SYMVER_PRE(fi_mr_key)(struct fid_mr *mr)
{
	return mr->key;
}
DEFAULT_SYMVER(fi_mr_key_, fi_mr_key, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_raw_attr)(struct fid_mr *mr, uint64_t *base_addr,
	       uint8_t *raw_key, size_t *key_size, uint64_t flags)
{
	struct fi_mr_raw_attr attr;
	attr.flags = flags;
	attr.base_addr = base_addr;
	attr.raw_key = raw_key;
	attr.key_size = key_size;
	return mr->fid.ops->control(&mr->fid, FI_GET_RAW_MR, &attr);
}
DEFAULT_SYMVER(fi_mr_raw_attr_, fi_mr_raw_attr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_map_raw)(struct fid_domain *domain, uint64_t base_addr,
	      uint8_t *raw_key, size_t key_size, uint64_t *key, uint64_t flags)
{
	struct fi_mr_map_raw map;
	map.flags = flags;
	map.base_addr = base_addr;
	map.raw_key = raw_key;
	map.key_size = key_size;
	map.key = key;
	return domain->fid.ops->control(&domain->fid, FI_MAP_RAW_MR, &map);
}
DEFAULT_SYMVER(fi_mr_map_raw_, fi_mr_map_raw, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_unmap_key)(struct fid_domain *domain, uint64_t key)
{
	return domain->fid.ops->control(&domain->fid, FI_UNMAP_KEY, &key);
}
DEFAULT_SYMVER(fi_mr_unmap_key_, fi_mr_unmap_key, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_mr_bind)(struct fid_mr *mr, struct fid *bfid, uint64_t flags)
{
	return mr->fid.ops->bind(&mr->fid, bfid, flags);
}
DEFAULT_SYMVER(fi_mr_bind_, fi_mr_bind, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_refresh)(struct fid_mr *mr, const struct iovec *iov, size_t count,
	      uint64_t flags)
{
	struct fi_mr_modify modify;
	memset(&modify, 0, sizeof(modify));
	modify.flags = flags;
	modify.attr.mr_iov = iov;
	modify.attr.iov_count = count;
	return mr->fid.ops->control(&mr->fid, FI_REFRESH, &modify);
}
DEFAULT_SYMVER(fi_mr_refresh_, fi_mr_refresh, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_mr_enable)(struct fid_mr *mr)
{
	return mr->fid.ops->control(&mr->fid, FI_ENABLE, NULL);
}
DEFAULT_SYMVER(fi_mr_enable_, fi_mr_enable, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_mr_get_xpu_desc)(struct fid_mr *mr, void *buf, size_t *len, uint64_t flags,
		   struct fid_xpu_ctx *ctx)
{
	struct fi_mr_xpu_desc desc;
	desc.buf = buf;
	desc.len = len;
	desc.flags = flags;
	desc.ctx = ctx;
	return fi_control(&mr->fid, FI_GET_MR_XPU_DESC, &desc);
}
DEFAULT_SYMVER(fi_mr_get_xpu_desc_, fi_mr_get_xpu_desc, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_open)(struct fid_domain *domain, struct fi_av_attr *attr,
	   struct fid_av **av, void *context)
{
	return domain->ops->av_open(domain, attr, av, context);
}
DEFAULT_SYMVER(fi_av_open_, fi_av_open, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC int
DEFAULT_SYMVER_PRE(fi_av_bind)(struct fid_av *av, struct fid *fid, uint64_t flags)
{
	return av->fid.ops->bind(&av->fid, fid, flags);
}
DEFAULT_SYMVER(fi_av_bind_, fi_av_bind, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_insert)(struct fid_av *av, const void *addr, size_t count,
	     fi_addr_t *fi_addr, uint64_t flags, void *context)
{
	return av->ops->insert(av, addr, count, fi_addr, flags, context);
}
DEFAULT_SYMVER(fi_av_insert_, fi_av_insert, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_insertsvc)(struct fid_av *av, const char *node, const char *service,
		fi_addr_t *fi_addr, uint64_t flags, void *context)
{
	return av->ops->insertsvc(av, node, service, fi_addr, flags, context);
}
DEFAULT_SYMVER(fi_av_insertsvc_, fi_av_insertsvc, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_insertsym)(struct fid_av *av, const char *node, size_t nodecnt,
		const char *service, size_t svccnt,
		fi_addr_t *fi_addr, uint64_t flags, void *context)
{
	return av->ops->insertsym(av, node, nodecnt, service, svccnt,
			fi_addr, flags, context);
}
DEFAULT_SYMVER(fi_av_insertsym_, fi_av_insertsym, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_remove)(struct fid_av *av, fi_addr_t *fi_addr, size_t count, uint64_t flags)
{
	return av->ops->remove(av, fi_addr, count, flags);
}
DEFAULT_SYMVER(fi_av_remove_, fi_av_remove, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_lookup)(struct fid_av *av, fi_addr_t fi_addr, void *addr, size_t *addrlen)
{
        return av->ops->lookup(av, fi_addr, addr, addrlen);
}
DEFAULT_SYMVER(fi_av_lookup_, fi_av_lookup, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
const char *
DEFAULT_SYMVER_PRE(fi_av_straddr)(struct fid_av *av, const void *addr, char *buf, size_t *len)
{
	return av->ops->straddr(av, addr, buf, len);
}
DEFAULT_SYMVER(fi_av_straddr_, fi_av_straddr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_insert_auth_key)(struct fid_av *av, const void *auth_key,
		      size_t auth_key_size, fi_addr_t *fi_addr, uint64_t flags)
{
	return FI_CHECK_OP(av->ops, struct fi_ops_av, insert_auth_key) ?
		av->ops->insert_auth_key(av, auth_key, auth_key_size, fi_addr,
					 flags) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_av_insert_auth_key_, fi_av_insert_auth_key, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_lookup_auth_key)(struct fid_av *av, fi_addr_t addr, void *auth_key,
		      size_t *auth_key_size)
{
	return FI_CHECK_OP(av->ops, struct fi_ops_av, lookup_auth_key) ?
		av->ops->lookup_auth_key(av, addr, auth_key, auth_key_size) :
		-FI_ENOSYS;
}
DEFAULT_SYMVER(fi_av_lookup_auth_key_, fi_av_lookup_auth_key, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_set_user_id)(struct fid_av *av, fi_addr_t fi_addr, fi_addr_t user_id,
		  uint64_t flags)
{
	return FI_CHECK_OP(av->ops, struct fi_ops_av, set_user_id) ?
		av->ops->set_user_id(av, fi_addr, user_id, flags) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_av_set_user_id_, fi_av_set_user_id, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_av_lookup2)(struct fid_av *av, fi_addr_t fi_addr,
	      void *buf, size_t *len, uint64_t flags,
	      struct fid_xpu_ctx *ctx)
{
	return FI_CHECK_OP(av->ops, struct fi_ops_av, lookup2) ?
		av->ops->lookup2(av, fi_addr, buf, len, flags, ctx) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_av_lookup2_, fi_av_lookup2, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
fi_addr_t
DEFAULT_SYMVER_PRE(fi_rx_addr)(fi_addr_t fi_addr, int rx_index, int rx_ctx_bits)
{
	return (fi_addr_t) (((uint64_t) rx_index << (64 - rx_ctx_bits)) | fi_addr);
}
DEFAULT_SYMVER(fi_rx_addr_, fi_rx_addr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
fi_addr_t
DEFAULT_SYMVER_PRE(fi_group_addr)(fi_addr_t fi_addr, uint32_t group_id)
{
	return (fi_addr_t) (((uint64_t) group_id << 32) | fi_addr);
}
DEFAULT_SYMVER(fi_group_addr_, fi_group_addr, FABRIC_1.10);



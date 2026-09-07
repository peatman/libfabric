/* De-inlined implementations moved out of rdma/fi_endpoint.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_endpoint.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_passive_ep)(struct fid_fabric *fabric, struct fi_info *info,
	     struct fid_pep **pep, void *context)
{
	return fabric->ops->passive_ep(fabric, info, pep, context);
}
DEFAULT_SYMVER(fi_passive_ep_, fi_passive_ep, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_endpoint)(struct fid_domain *domain, struct fi_info *info,
	    struct fid_ep **ep, void *context)
{
	return domain->ops->endpoint(domain, info, ep, context);
}
DEFAULT_SYMVER(fi_endpoint_, fi_endpoint, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_endpoint2)(struct fid_domain *domain, struct fi_info *info,
	     struct fid_ep **ep, uint64_t flags, void *context)
{
	if (!flags)
		return fi_endpoint(domain, info, ep, context);

	return FI_CHECK_OP(domain->ops, struct fi_ops_domain, endpoint2) ?
		domain->ops->endpoint2(domain, info, ep, flags, context) :
		-FI_ENOSYS;
}
DEFAULT_SYMVER(fi_endpoint2_, fi_endpoint2, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_scalable_ep)(struct fid_domain *domain, struct fi_info *info,
	    struct fid_ep **sep, void *context)
{
	return domain->ops->scalable_ep(domain, info, sep, context);
}
DEFAULT_SYMVER(fi_scalable_ep_, fi_scalable_ep, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_ep_bind)(struct fid_ep *ep, struct fid *bfid, uint64_t flags)
{
	return ep->fid.ops->bind(&ep->fid, bfid, flags);
}
DEFAULT_SYMVER(fi_ep_bind_, fi_ep_bind, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_pep_bind)(struct fid_pep *pep, struct fid *bfid, uint64_t flags)
{
	return pep->fid.ops->bind(&pep->fid, bfid, flags);
}
DEFAULT_SYMVER(fi_pep_bind_, fi_pep_bind, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_scalable_ep_bind)(struct fid_ep *sep, struct fid *bfid, uint64_t flags)
{
	return sep->fid.ops->bind(&sep->fid, bfid, flags);
}
DEFAULT_SYMVER(fi_scalable_ep_bind_, fi_scalable_ep_bind, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_enable)(struct fid_ep *ep)
{
	return ep->fid.ops->control(&ep->fid, FI_ENABLE, NULL);
}
DEFAULT_SYMVER(fi_enable_, fi_enable, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t DEFAULT_SYMVER_PRE(fi_cancel)(fid_t fid, void *context)
{
	struct fid_ep *ep = (struct fid_ep *) fid;
	return ep->ops->cancel(fid, context);
}
DEFAULT_SYMVER(fi_cancel_, fi_cancel, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_setopt)(fid_t fid, int level, int optname,
	  const void *optval, size_t optlen)
{
	struct fid_ep *ep = (struct fid_ep *) fid;
	return ep->ops->setopt(fid, level, optname, optval, optlen);
}
DEFAULT_SYMVER(fi_setopt_, fi_setopt, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_getopt)(fid_t fid, int level, int optname,
	  void *optval, size_t *optlen)
{
	struct fid_ep *ep = (struct fid_ep *) fid;
	return ep->ops->getopt(fid, level, optname, optval, optlen);
}
DEFAULT_SYMVER(fi_getopt_, fi_getopt, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_ep_alias)(struct fid_ep *ep, struct fid_ep **alias_ep,
			      uint64_t flags)
{
	int ret;
	struct fid *fid;
	ret = fi_alias(&ep->fid, &fid, flags);
	if (!ret)
		*alias_ep = (struct fid_ep *) fid;
	return ret;
}
DEFAULT_SYMVER(fi_ep_alias_, fi_ep_alias, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_tx_context)(struct fid_ep *ep, int idx, struct fi_tx_attr *attr,
	      struct fid_ep **tx_ep, void *context)
{
	return ep->ops->tx_ctx(ep, idx, attr, tx_ep, context);
}
DEFAULT_SYMVER(fi_tx_context_, fi_tx_context, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_rx_context)(struct fid_ep *ep, int idx, struct fi_rx_attr *attr,
	      struct fid_ep **rx_ep, void *context)
{
	return ep->ops->rx_ctx(ep, idx, attr, rx_ep, context);
}
DEFAULT_SYMVER(fi_rx_context_, fi_rx_context, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC ssize_t
DEFAULT_SYMVER_PRE(fi_rx_size_left)(struct fid_ep *ep)
{
	return ep->ops->rx_size_left(ep);
}
DEFAULT_SYMVER(fi_rx_size_left_, fi_rx_size_left, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC ssize_t
DEFAULT_SYMVER_PRE(fi_tx_size_left)(struct fid_ep *ep)
{
	return ep->ops->tx_size_left(ep);
}
DEFAULT_SYMVER(fi_tx_size_left_, fi_tx_size_left, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_stx_context)(struct fid_domain *domain, struct fi_tx_attr *attr,
	       struct fid_stx **stx, void *context)
{
	return domain->ops->stx_ctx(domain, attr, stx, context);
}
DEFAULT_SYMVER(fi_stx_context_, fi_stx_context, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_srx_context)(struct fid_domain *domain, struct fi_rx_attr *attr,
	       struct fid_ep **rx_ep, void *context)
{
	return domain->ops->srx_ctx(domain, attr, rx_ep, context);
}
DEFAULT_SYMVER(fi_srx_context_, fi_srx_context, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_recv)(struct fid_ep *ep, void *buf, size_t len, void *desc, fi_addr_t src_addr,
	void *context)
{
	return ep->msg->recv(ep, buf, len, desc, src_addr, context);
}
DEFAULT_SYMVER(fi_recv_, fi_recv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_recvv)(struct fid_ep *ep, const struct iovec *iov, void **desc,
	 size_t count, fi_addr_t src_addr, void *context)
{
	return ep->msg->recvv(ep, iov, desc, count, src_addr, context);
}
DEFAULT_SYMVER(fi_recvv_, fi_recvv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_recvmsg)(struct fid_ep *ep, const struct fi_msg *msg, uint64_t flags)
{
	return ep->msg->recvmsg(ep, msg, flags);
}
DEFAULT_SYMVER(fi_recvmsg_, fi_recvmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_send)(struct fid_ep *ep, const void *buf, size_t len, void *desc,
	fi_addr_t dest_addr, void *context)
{
	return ep->msg->send(ep, buf, len, desc, dest_addr, context);
}
DEFAULT_SYMVER(fi_send_, fi_send, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_sendv)(struct fid_ep *ep, const struct iovec *iov, void **desc,
	 size_t count, fi_addr_t dest_addr, void *context)
{
	return ep->msg->sendv(ep, iov, desc, count, dest_addr, context);
}
DEFAULT_SYMVER(fi_sendv_, fi_sendv, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_sendmsg)(struct fid_ep *ep, const struct fi_msg *msg, uint64_t flags)
{
	return ep->msg->sendmsg(ep, msg, flags);
}
DEFAULT_SYMVER(fi_sendmsg_, fi_sendmsg, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_inject)(struct fid_ep *ep, const void *buf, size_t len, fi_addr_t dest_addr)
{
	return ep->msg->inject(ep, buf, len, dest_addr);
}
DEFAULT_SYMVER(fi_inject_, fi_inject, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_senddata)(struct fid_ep *ep, const void *buf, size_t len, void *desc,
	      uint64_t data, fi_addr_t dest_addr, void *context)
{
	return ep->msg->senddata(ep, buf, len, desc, data, dest_addr, context);
}
DEFAULT_SYMVER(fi_senddata_, fi_senddata, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_injectdata)(struct fid_ep *ep, const void *buf, size_t len,
		uint64_t data, fi_addr_t dest_addr)
{
	return ep->msg->injectdata(ep, buf, len, data, dest_addr);
}
DEFAULT_SYMVER(fi_injectdata_, fi_injectdata, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_ep_export_xpu)(struct fid_ep *ep, uint64_t flags,
		 struct fid_xpu_ep *xpu_ep)
{
	return ep->ops->export_xpu(ep, flags, xpu_ep);
}
DEFAULT_SYMVER(fi_ep_export_xpu_, fi_ep_export_xpu, FABRIC_1.10);



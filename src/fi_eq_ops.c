/* De-inlined implementations moved out of rdma/fi_eq.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_eq.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_trywait)(struct fid_fabric *fabric, struct fid **fids, int count)
{
	return fabric->ops->trywait(fabric, fids, count);
}
DEFAULT_SYMVER(fi_trywait_, fi_trywait, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC int
DEFAULT_SYMVER_PRE(fi_wait)(struct fid_wait *waitset, int timeout)
{
	return waitset->ops->wait(waitset, timeout);
}
DEFAULT_SYMVER(fi_wait_, fi_wait, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC int
DEFAULT_SYMVER_PRE(fi_poll)(struct fid_poll *pollset, void **context, int count)
{
	return pollset->ops->poll(pollset, context, count);
}
DEFAULT_SYMVER(fi_poll_, fi_poll, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC int
DEFAULT_SYMVER_PRE(fi_poll_add)(struct fid_poll *pollset, struct fid *event_fid, uint64_t flags)
{
	return pollset->ops->poll_add(pollset, event_fid, flags);
}
DEFAULT_SYMVER(fi_poll_add_, fi_poll_add, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
FI_DEPRECATED_FUNC int
DEFAULT_SYMVER_PRE(fi_poll_del)(struct fid_poll *pollset, struct fid *event_fid, uint64_t flags)
{
	return pollset->ops->poll_del(pollset, event_fid, flags);
}
DEFAULT_SYMVER(fi_poll_del_, fi_poll_del, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_eq_open)(struct fid_fabric *fabric, struct fi_eq_attr *attr,
	   struct fid_eq **eq, void *context)
{
	return fabric->ops->eq_open(fabric, attr, eq, context);
}
DEFAULT_SYMVER(fi_eq_open_, fi_eq_open, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_eq_read)(struct fid_eq *eq, uint32_t *event, void *buf,
	   size_t len, uint64_t flags)
{
	return eq->ops->read(eq, event, buf, len, flags);
}
DEFAULT_SYMVER(fi_eq_read_, fi_eq_read, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_eq_readerr)(struct fid_eq *eq, struct fi_eq_err_entry *buf, uint64_t flags)
{
	return eq->ops->readerr(eq, buf, flags);
}
DEFAULT_SYMVER(fi_eq_readerr_, fi_eq_readerr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_eq_write)(struct fid_eq *eq, uint32_t event, const void *buf,
	    size_t len, uint64_t flags)
{
	return eq->ops->write(eq, event, buf, len, flags);
}
DEFAULT_SYMVER(fi_eq_write_, fi_eq_write, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_eq_sread)(struct fid_eq *eq, uint32_t *event, void *buf, size_t len,
	    int timeout, uint64_t flags)
{
	return eq->ops->sread(eq, event, buf, len, timeout, flags);
}
DEFAULT_SYMVER(fi_eq_sread_, fi_eq_sread, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
const char *
DEFAULT_SYMVER_PRE(fi_eq_strerror)(struct fid_eq *eq, int prov_errno, const void *err_data,
	       char *buf, size_t len)
{
	return eq->ops->strerror(eq, prov_errno, err_data, buf, len);
}
DEFAULT_SYMVER(fi_eq_strerror_, fi_eq_strerror, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t DEFAULT_SYMVER_PRE(fi_cq_read)(struct fid_cq *cq, void *buf, size_t count)
{
	return cq->ops->read(cq, buf, count);
}
DEFAULT_SYMVER(fi_cq_read_, fi_cq_read, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_cq_readfrom)(struct fid_cq *cq, void *buf, size_t count, fi_addr_t *src_addr)
{
	return cq->ops->readfrom(cq, buf, count, src_addr);
}
DEFAULT_SYMVER(fi_cq_readfrom_, fi_cq_readfrom, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_cq_readerr)(struct fid_cq *cq, struct fi_cq_err_entry *buf, uint64_t flags)
{
	/* For compatibility with older providers. */
	if (buf)
		buf->src_addr = FI_ADDR_NOTAVAIL;
	return cq->ops->readerr(cq, buf, flags);
}
DEFAULT_SYMVER(fi_cq_readerr_, fi_cq_readerr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_cq_sread)(struct fid_cq *cq, void *buf, size_t count, const void *cond, int timeout)
{
	return cq->ops->sread(cq, buf, count, cond, timeout);
}
DEFAULT_SYMVER(fi_cq_sread_, fi_cq_sread, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_cq_sreadfrom)(struct fid_cq *cq, void *buf, size_t count,
		fi_addr_t *src_addr, const void *cond, int timeout)
{
	return cq->ops->sreadfrom(cq, buf, count, src_addr, cond, timeout);
}
DEFAULT_SYMVER(fi_cq_sreadfrom_, fi_cq_sreadfrom, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_cq_signal)(struct fid_cq *cq)
{
	return cq->ops->signal(cq);
}
DEFAULT_SYMVER(fi_cq_signal_, fi_cq_signal, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
const char *
DEFAULT_SYMVER_PRE(fi_cq_strerror)(struct fid_cq *cq, int prov_errno, const void *err_data,
	       char *buf, size_t len)
{
	return cq->ops->strerror(cq, prov_errno, err_data, buf, len);
}
DEFAULT_SYMVER(fi_cq_strerror_, fi_cq_strerror, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
uint64_t DEFAULT_SYMVER_PRE(fi_cntr_read)(struct fid_cntr *cntr)
{
	return cntr->ops->read(cntr);
}
DEFAULT_SYMVER(fi_cntr_read_, fi_cntr_read, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
uint64_t DEFAULT_SYMVER_PRE(fi_cntr_readerr)(struct fid_cntr *cntr)
{
	return cntr->ops->readerr(cntr);
}
DEFAULT_SYMVER(fi_cntr_readerr_, fi_cntr_readerr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_cntr_add)(struct fid_cntr *cntr, uint64_t value)
{
	return cntr->ops->add(cntr, value);
}
DEFAULT_SYMVER(fi_cntr_add_, fi_cntr_add, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_cntr_adderr)(struct fid_cntr *cntr, uint64_t value)
{
	return FI_CHECK_OP(cntr->ops, struct fi_ops_cntr, adderr) ?
		cntr->ops->adderr(cntr, value) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_cntr_adderr_, fi_cntr_adderr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_cntr_set)(struct fid_cntr *cntr, uint64_t value)
{
	return cntr->ops->set(cntr, value);
}
DEFAULT_SYMVER(fi_cntr_set_, fi_cntr_set, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_cntr_seterr)(struct fid_cntr *cntr, uint64_t value)
{
	return FI_CHECK_OP(cntr->ops, struct fi_ops_cntr, seterr) ?
		cntr->ops->seterr(cntr, value) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_cntr_seterr_, fi_cntr_seterr, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_cntr_wait)(struct fid_cntr *cntr, uint64_t threshold, int timeout)
{
	return cntr->ops->wait(cntr, threshold, timeout);
}
DEFAULT_SYMVER(fi_cntr_wait_, fi_cntr_wait, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_cq_export_xpu)(struct fid_cq *cq, uint64_t flags,
		 struct fid_xpu_cq *xpu_cq)
{
	return cq->ops->export_xpu(cq, flags, xpu_cq);
}
DEFAULT_SYMVER(fi_cq_export_xpu_, fi_cq_export_xpu, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_cntr_export_xpu)(struct fid_cntr *cntr, uint64_t flags,
		   struct fid_xpu_cntr *xpu_cntr)
{
	return cntr->ops->export_xpu(cntr, flags, xpu_cntr);
}
DEFAULT_SYMVER(fi_cntr_export_xpu_, fi_cntr_export_xpu, FABRIC_1.10);



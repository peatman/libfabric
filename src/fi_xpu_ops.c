/* De-inlined implementations moved out of rdma/fi_xpu.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_xpu.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_xpu_ctx)(struct fid_domain *domain, struct fi_xpu_attr *attr,
	   struct fid_xpu_ctx **ctx, void *context)
{
	return domain->ops->xpu_ctx(domain, attr, ctx, context);
}
DEFAULT_SYMVER(fi_xpu_ctx_, fi_xpu_ctx, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_xpu_ctx_query)(struct fid_xpu_ctx *ctx, struct fi_xpu_ctx_attr *attr)
{
	return ctx->ops->query(ctx, attr);
}
DEFAULT_SYMVER(fi_xpu_ctx_query_, fi_xpu_ctx_query, FABRIC_1.10);



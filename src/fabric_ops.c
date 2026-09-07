/* De-inlined implementations moved out of rdma/fabric.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fabric.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
uint32_t DEFAULT_SYMVER_PRE(fi_tc_dscp_set)(uint8_t dscp)
{
	return ((uint32_t) dscp) | FI_TC_DSCP;
}
DEFAULT_SYMVER(fi_tc_dscp_set_, fi_tc_dscp_set, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
uint8_t DEFAULT_SYMVER_PRE(fi_tc_dscp_get)(uint32_t tclass)
{
	return tclass & FI_TC_DSCP ? (uint8_t) tclass : 0;
}
DEFAULT_SYMVER(fi_tc_dscp_get_, fi_tc_dscp_get, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
struct fi_info *DEFAULT_SYMVER_PRE(fi_allocinfo)(void)
{
	return fi_dupinfo(NULL);
}
DEFAULT_SYMVER(fi_allocinfo_, fi_allocinfo, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_close)(struct fid *fid)
{
	return fid->ops->close(fid);
}
DEFAULT_SYMVER(fi_close_, fi_close, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_control)(struct fid *fid, int command, void *arg)
{
	return fid->ops->control(fid, command, arg);
}
DEFAULT_SYMVER(fi_control_, fi_control, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_alias)(struct fid *fid, struct fid **alias_fid, uint64_t flags)
{
	struct fi_alias alias;
	alias.fid = alias_fid;
	alias.flags = flags;
	return fi_control(fid, FI_ALIAS, &alias);
}
DEFAULT_SYMVER(fi_alias_, fi_alias, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_get_val)(struct fid *fid, int name, void *val)
{
	struct fi_fid_var var;
	var.name = name;
	var.val = val;
	return fi_control(fid, FI_GET_VAL, &var);
}
DEFAULT_SYMVER(fi_get_val_, fi_get_val, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_set_val)(struct fid *fid, int name, void *val)
{
	struct fi_fid_var var;
	var.name = name;
	var.val = val;
	return fi_control(fid, FI_SET_VAL, &var);
}
DEFAULT_SYMVER(fi_set_val_, fi_set_val, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_open_ops)(struct fid *fid, const char *name, uint64_t flags,
	    void **ops, void *context)
{
	return fid->ops->ops_open(fid, name, flags, ops, context);
}
DEFAULT_SYMVER(fi_open_ops_, fi_open_ops, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_set_ops)(struct fid *fid, const char *name, uint64_t flags,
	   void *ops, void *context)
{
	return FI_CHECK_OP(fid->ops, struct fi_ops, ops_set) ?
		fid->ops->ops_set(fid, name, flags, ops, context) : -FI_ENOSYS;
}
DEFAULT_SYMVER(fi_set_ops_, fi_set_ops, FABRIC_1.10);



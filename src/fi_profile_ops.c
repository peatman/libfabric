/* De-inlined implementations moved out of rdma/fi_profile.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "ofi_abi.h"
#include "config.h"
#include "ofi.h"
#include <rdma/fi_profile.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
void
DEFAULT_SYMVER_PRE(fi_profile_reset)(struct fid_profile *prof_fid,  uint64_t flags)
{
	return prof_fid->ops->reset(prof_fid, flags);
}
DEFAULT_SYMVER(fi_profile_reset_, fi_profile_reset, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_profile_query_vars)(struct fid_profile *prof_fid,
                      struct fi_profile_desc *varlist, size_t *count)
{
	return prof_fid->ops->query_vars(prof_fid, varlist, count);
}
DEFAULT_SYMVER(fi_profile_query_vars_, fi_profile_query_vars, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_profile_query_events)(struct fid_profile *prof_fid,
               struct fi_profile_desc *eventlist, size_t *count)
{
	return prof_fid->ops->query_events(prof_fid, eventlist, count);
}
DEFAULT_SYMVER(fi_profile_query_events_, fi_profile_query_events, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
ssize_t
DEFAULT_SYMVER_PRE(fi_profile_read_u64)(struct fid_profile *prof_fid, uint32_t var_id,
                    uint64_t *data)
{
	size_t size = sizeof(uint64_t);
	ssize_t ret = prof_fid->ops->read_var(prof_fid, var_id, 
	                                      (void *)data, &size);
	return (ret > 0) ? 0 : ret;
}
DEFAULT_SYMVER(fi_profile_read_u64_, fi_profile_read_u64, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_profile_register_callback)(struct fid_profile *prof_fid, uint32_t event_id,
        int (*callback)(struct fid_profile *prof_fid,
                        struct fi_profile_desc *event, void *param,
                        size_t size, void *context),
        void *context)
{
	return prof_fid->ops->reg_callback(prof_fid, event_id, callback, context);
}
DEFAULT_SYMVER(fi_profile_register_callback_, fi_profile_register_callback, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
void
DEFAULT_SYMVER_PRE(fi_profile_start_reads)(struct fid_profile *prof_fid, uint64_t flags)
{
	return prof_fid->ops->start_reads(prof_fid, flags);
}
DEFAULT_SYMVER(fi_profile_start_reads_, fi_profile_start_reads, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
void
DEFAULT_SYMVER_PRE(fi_profile_end_reads)(struct fid_profile *prof_fid, uint64_t flags)
{
	return prof_fid->ops->end_reads(prof_fid, flags);
}
DEFAULT_SYMVER(fi_profile_end_reads_, fi_profile_end_reads, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_profile_open)(struct fid *fid, uint64_t flags,
                    struct fid_profile **prof_fid, void *context)
{
	struct fi_profile_ops *ops;
	int ret = fi_open_ops(fid, "fi_profile_ops", flags,
	                      (void **)&ops, context);
	if (!ret)
		*prof_fid = container_of(ops, struct fid_profile, ops);

	return ret;
}
DEFAULT_SYMVER(fi_profile_open_, fi_profile_open, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_profile_close)(struct fid_profile *prof_fid)
{
	return prof_fid->fid.ops->close(&(prof_fid->fid));
}
DEFAULT_SYMVER(fi_profile_close_, fi_profile_close, FABRIC_1.10);



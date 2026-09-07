/* De-inlined implementations moved out of rdma/fi_ext.h so they become real,
 * exported (dlsym-able) symbols instead of static inline ops-table wrappers. */
#include "config.h"
#include "ofi_abi.h"
#include <rdma/fi_ext.h>

__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_export_fid)(struct fid *fid, uint64_t flags,
	      struct fid **expfid, void *context)
{
	struct fi_fid_export exp;

	exp.fid = expfid;
	exp.flags = flags;
	exp.context = context;
	return fi_control(fid, FI_EXPORT_FID, &exp);
}
DEFAULT_SYMVER(fi_export_fid_, fi_export_fid, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int
DEFAULT_SYMVER_PRE(fi_import_fid)(struct fid *fid, struct fid *expfid, uint64_t flags)
{
	return fid->ops->bind(fid, expfid, flags);
}
DEFAULT_SYMVER(fi_import_fid_, fi_import_fid, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_import)(uint32_t version, const char *name, void *attr,
			    size_t attr_len, uint64_t flags, struct fid *fid,
			    void *context)
{
	struct fid *open_fid;
	int ret;

	ret = fi_open(version, name, attr, attr_len, flags, &open_fid, context);
	if (ret != FI_SUCCESS)
	    return ret;

	ret = fi_import_fid(open_fid, fid, flags);
	fi_close(open_fid);
	return ret;
}
DEFAULT_SYMVER(fi_import_, fi_import, FABRIC_1.10);


__attribute__((visibility ("default"),EXTERNALLY_VISIBLE))
int DEFAULT_SYMVER_PRE(fi_import_log)(uint32_t version, uint64_t flags,
				struct fid_logging *log_fid)
{
	log_fid->fid.fclass = FI_CLASS_LOG;
	log_fid->ops->size = sizeof(struct fi_ops_log);

	return fi_import(version, "logging", NULL, 0, flags, &log_fid->fid,
			 log_fid);
}
DEFAULT_SYMVER(fi_import_log_, fi_import_log, FABRIC_1.10);



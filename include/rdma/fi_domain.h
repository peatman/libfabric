/*
 * Copyright (c) 2013-2017 Intel Corporation. All rights reserved.
 * (C) Copyright 2020 Hewlett Packard Enterprise Development LP
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FI_DOMAIN_H
#define FI_DOMAIN_H

#include <string.h>
#include <rdma/fabric.h>
#include <rdma/fi_eq.h>


#ifdef __cplusplus
extern "C" {
#endif


/*
 * AV = Address Vector
 * Maps and stores transport/network addresses.
 */

#define FI_SYMMETRIC		(1ULL << 59)
#define FI_SYNC_ERR		(1ULL << 58)
#define FI_UNIVERSE		(1ULL << 57)
#define FI_BARRIER_SET		(1ULL << 40)
#define FI_BROADCAST_SET	(1ULL << 41)
#define FI_ALLTOALL_SET		(1ULL << 42)
#define FI_ALLREDUCE_SET	(1ULL << 43)
#define FI_ALLGATHER_SET	(1ULL << 44)
#define FI_REDUCE_SCATTER_SET	(1ULL << 45)
#define FI_REDUCE_SET		(1ULL << 46)
#define FI_SCATTER_SET		(1ULL << 47)
#define FI_GATHER_SET		(1ULL << 48)

struct fi_av_attr {
	enum fi_av_type		type;
	int			rx_ctx_bits;
	size_t			count;
	size_t			ep_per_node;
	const char		*name;
	void			*map_addr;
	uint64_t		flags;
};

struct fi_av_set_attr {
	size_t			count;
	fi_addr_t		start_addr;
	fi_addr_t		end_addr;
	uint64_t		stride;
	size_t			comm_key_size;
	uint8_t			*comm_key;
	uint64_t		flags;
};

struct fid_av_set;

struct fi_ops_av {
	size_t	size;
	int	(*insert)(struct fid_av *av, const void *addr, size_t count,
			fi_addr_t *fi_addr, uint64_t flags, void *context);
	int	(*insertsvc)(struct fid_av *av, const char *node,
			const char *service, fi_addr_t *fi_addr,
			uint64_t flags, void *context);
	int	(*insertsym)(struct fid_av *av, const char *node, size_t nodecnt,
			const char *service, size_t svccnt, fi_addr_t *fi_addr,
			uint64_t flags, void *context);
	int	(*remove)(struct fid_av *av, fi_addr_t *fi_addr, size_t count,
			uint64_t flags);
	int	(*lookup)(struct fid_av *av, fi_addr_t fi_addr, void *addr,
			size_t *addrlen);
	const char * (*straddr)(struct fid_av *av, const void *addr,
			char *buf, size_t *len);
	int	(*av_set)(struct fid_av *av, struct fi_av_set_attr *attr,
			struct fid_av_set **av_set, void *context);
	int	(*insert_auth_key)(struct fid_av *av, const void *auth_key,
				   size_t auth_key_size, fi_addr_t *fi_addr,
				   uint64_t flags);
	int	(*lookup_auth_key)(struct fid_av *av, fi_addr_t fi_addr,
				   void *auth_key, size_t *auth_key_size);
	int	(*set_user_id)(struct fid_av *av, fi_addr_t fi_addr,
			       fi_addr_t user_id, uint64_t flags);
	int	(*lookup2)(struct fid_av *av, fi_addr_t fi_addr,
			void *buf, size_t *len, uint64_t flags,
			struct fid_xpu_ctx *ctx);
};

struct fid_av {
	struct fid		fid;
	struct fi_ops_av	*ops;
};


/*
 * MR = Memory Region
 * Tracks registered memory regions, primarily for remote access,
 * but also for local access until we can remove that need.
 */

#define FI_MR_DMABUF		(1ULL << 40)
#define FI_MR_SINGLE_USE	(1ULL << 41)
#define FI_HMEM_HOST_ALLOC	(1ULL << 45)
#define FI_HMEM_DEVICE_ONLY	(1ULL << 46)

struct fid_mr {
	struct fid		fid;
	void			*mem_desc;
	uint64_t		key;
};

enum fi_hmem_iface {
	FI_HMEM_SYSTEM	= 0,
	FI_HMEM_CUDA,
	FI_HMEM_ROCR,
	FI_HMEM_ZE,
	FI_HMEM_NEURON,
	FI_HMEM_SYNAPSEAI,
};

int fi_hmem_ze_device(int driver_index, int device_index);


struct fi_mr_dmabuf {
	int		fd;
	uint64_t	offset;
	size_t		len;
	void 		*base_addr;
};

struct fi_mr_auth_key {
	struct fid_av		*av;
	fi_addr_t		src_addr;
};

struct fi_mr_attr {
	union {
		const struct iovec *mr_iov;
		const struct fi_mr_dmabuf *dmabuf;
	};
	size_t			iov_count;
	uint64_t		access;
	uint64_t		offset;
	uint64_t		requested_key;
	void			*context;
	size_t			auth_key_size;
	uint8_t			*auth_key;
	enum fi_hmem_iface	iface;
	union {
		uint64_t	reserved;
		int		cuda;
		int		ze;
		int		neuron;
		int		synapseai;
		int		rocr;
	} device;
	void			*hmem_data;
	size_t			page_size;
	const struct fid_mr	*base_mr;
	size_t			sub_mr_cnt;
};

struct fi_mr_modify {
	uint64_t		flags;
	struct fi_mr_attr	attr;
};

#define FI_SET_OPS_HMEM_OVERRIDE "hmem_override_ops"

struct fi_hmem_override_ops {
	size_t	size;

	ssize_t	(*copy_from_hmem_iov)(void *dest, size_t size,
				      enum fi_hmem_iface iface, uint64_t device,
				      const struct iovec *hmem_iov,
				      size_t hmem_iov_count,
				      uint64_t hmem_iov_offset);

	ssize_t (*copy_to_hmem_iov)(enum fi_hmem_iface iface, uint64_t device,
				    const struct iovec *hmem_iov,
				    size_t hmem_iov_count,
				    uint64_t hmem_iov_offset, const void *src,
				    size_t size);
};

#ifdef FABRIC_DIRECT
#include <rdma/fi_direct_atomic_def.h>
#endif /* FABRIC_DIRECT */

#ifndef FABRIC_DIRECT_ATOMIC_DEF

#define FI_COLLECTIVE_OFFSET 256

enum fi_datatype {
	FI_INT8,
	FI_UINT8,
	FI_INT16,
	FI_UINT16,
	FI_INT32,
	FI_UINT32,
	FI_INT64,
	FI_UINT64,
	FI_FLOAT,
	FI_DOUBLE,
	FI_FLOAT_COMPLEX,
	FI_DOUBLE_COMPLEX,
	FI_LONG_DOUBLE,
	FI_LONG_DOUBLE_COMPLEX,
	FI_INT128,
	FI_UINT128,
	FI_FLOAT16,
	FI_BFLOAT16,
	FI_FLOAT8_E4M3,
	FI_FLOAT8_E5M2,

	/* Collective datatypes */
	FI_VOID = FI_COLLECTIVE_OFFSET,
};

enum fi_op {
	FI_MIN,
	FI_MAX,
	FI_SUM,
	FI_PROD,
	FI_LOR,
	FI_LAND,
	FI_BOR,
	FI_BAND,
	FI_LXOR,
	FI_BXOR,
	FI_ATOMIC_READ,
	FI_ATOMIC_WRITE,
	FI_CSWAP,
	FI_CSWAP_NE,
	FI_CSWAP_LE,
	FI_CSWAP_LT,
	FI_CSWAP_GE,
	FI_CSWAP_GT,
	FI_MSWAP,
	FI_DIFF,

	/* Collective datatypes */
	FI_NOOP = FI_COLLECTIVE_OFFSET,
};

#endif

#ifndef FABRIC_DIRECT_COLLECTIVE_DEF

enum fi_collective_op {
	FI_BARRIER,
	FI_BROADCAST,
	FI_ALLTOALL,
	FI_ALLREDUCE,
	FI_ALLGATHER,
	FI_REDUCE_SCATTER,
	FI_REDUCE,
	FI_SCATTER,
	FI_GATHER,
};

#endif


struct fi_atomic_attr;
struct fi_cq_attr;
struct fi_cntr_attr;
struct fi_collective_attr;
struct fi_xpu_attr;

struct fi_ops_domain {
	size_t	size;
	int	(*av_open)(struct fid_domain *domain, struct fi_av_attr *attr,
			struct fid_av **av, void *context);
	int	(*cq_open)(struct fid_domain *domain, struct fi_cq_attr *attr,
			struct fid_cq **cq, void *context);
	int	(*endpoint)(struct fid_domain *domain, struct fi_info *info,
			struct fid_ep **ep, void *context);
	int	(*scalable_ep)(struct fid_domain *domain, struct fi_info *info,
			struct fid_ep **sep, void *context);
	int	(*cntr_open)(struct fid_domain *domain, struct fi_cntr_attr *attr,
			struct fid_cntr **cntr, void *context);
	int	(*poll_open)(struct fid_domain *domain, struct fi_poll_attr *attr,
			struct fid_poll **pollset);
	int	(*stx_ctx)(struct fid_domain *domain,
			struct fi_tx_attr *attr, struct fid_stx **stx,
			void *context);
	int	(*srx_ctx)(struct fid_domain *domain,
			struct fi_rx_attr *attr, struct fid_ep **rx_ep,
			void *context);
	int	(*query_atomic)(struct fid_domain *domain,
			enum fi_datatype datatype, enum fi_op op,
			struct fi_atomic_attr *attr, uint64_t flags);
	int	(*query_collective)(struct fid_domain *domain,
			enum fi_collective_op coll,
			struct fi_collective_attr *attr, uint64_t flags);
	int	(*endpoint2)(struct fid_domain *domain, struct fi_info *info,
			struct fid_ep **ep, uint64_t flags, void *context);
	int	(*xpu_ctx)(struct fid_domain *domain,
			struct fi_xpu_attr *attr,
			struct fid_xpu_ctx **ctx, void *context);
};

/* Memory registration flags */
/* #define FI_RMA_EVENT		(1ULL << 56) */

struct fi_ops_mr {
	size_t	size;
	int	(*reg)(struct fid *fid, const void *buf, size_t len,
			uint64_t access, uint64_t offset, uint64_t requested_key,
			uint64_t flags, struct fid_mr **mr, void *context);
	int	(*regv)(struct fid *fid, const struct iovec *iov,
			size_t count, uint64_t access,
			uint64_t offset, uint64_t requested_key,
			uint64_t flags, struct fid_mr **mr, void *context);
	int	(*regattr)(struct fid *fid, const struct fi_mr_attr *attr,
			uint64_t flags, struct fid_mr **mr);
};

/* Domain bind flags */
#define FI_REG_MR	_Pragma("GCC warning \"'FI_REG_MR' is deprecated\"")	(1ULL << 59)

struct fid_domain {
	struct fid		fid;
	struct fi_ops_domain	*ops;
	struct fi_ops_mr	*mr;
};


#ifdef FABRIC_DIRECT
#include <rdma/fi_direct_domain.h>
#endif	/* FABRIC_DIRECT */

#ifndef FABRIC_DIRECT_DOMAIN

int
fi_domain(struct fid_fabric *fabric, struct fi_info *info,
	   struct fid_domain **domain, void *context);


int
fi_domain2(struct fid_fabric *fabric, struct fi_info *info,
	   struct fid_domain **domain, uint64_t flags, void *context);


int
fi_domain_bind(struct fid_domain *domain, struct fid *fid, uint64_t flags);


int
fi_cq_open(struct fid_domain *domain, struct fi_cq_attr *attr,
	   struct fid_cq **cq, void *context);


int
fi_cntr_open(struct fid_domain *domain, struct fi_cntr_attr *attr,
	      struct fid_cntr **cntr, void *context);


FI_DEPRECATED_FUNC int
fi_wait_open(struct fid_fabric *fabric, struct fi_wait_attr *attr,
	     struct fid_wait **waitset);


FI_DEPRECATED_FUNC int
fi_poll_open(struct fid_domain *domain, struct fi_poll_attr *attr,
	     struct fid_poll **pollset);


int
fi_mr_reg(struct fid_domain *domain, const void *buf, size_t len,
	  uint64_t acs, uint64_t offset, uint64_t requested_key,
	  uint64_t flags, struct fid_mr **mr, void *context);


int
fi_mr_regv(struct fid_domain *domain, const struct iovec *iov,
			size_t count, uint64_t acs,
			uint64_t offset, uint64_t requested_key,
			uint64_t flags, struct fid_mr **mr, void *context);


int
fi_mr_regattr(struct fid_domain *domain, const struct fi_mr_attr *attr,
			uint64_t flags, struct fid_mr **mr);


void *fi_mr_desc(struct fid_mr *mr);


uint64_t fi_mr_key(struct fid_mr *mr);


int
fi_mr_raw_attr(struct fid_mr *mr, uint64_t *base_addr,
	       uint8_t *raw_key, size_t *key_size, uint64_t flags);


int
fi_mr_map_raw(struct fid_domain *domain, uint64_t base_addr,
	      uint8_t *raw_key, size_t key_size, uint64_t *key, uint64_t flags);


int
fi_mr_unmap_key(struct fid_domain *domain, uint64_t key);


int fi_mr_bind(struct fid_mr *mr, struct fid *bfid, uint64_t flags);


int
fi_mr_refresh(struct fid_mr *mr, const struct iovec *iov, size_t count,
	      uint64_t flags);


int fi_mr_enable(struct fid_mr *mr);


int
fi_mr_get_xpu_desc(struct fid_mr *mr, void *buf, size_t *len, uint64_t flags,
		   struct fid_xpu_ctx *ctx);


int
fi_av_open(struct fid_domain *domain, struct fi_av_attr *attr,
	   struct fid_av **av, void *context);


FI_DEPRECATED_FUNC int
fi_av_bind(struct fid_av *av, struct fid *fid, uint64_t flags);


int
fi_av_insert(struct fid_av *av, const void *addr, size_t count,
	     fi_addr_t *fi_addr, uint64_t flags, void *context);


int
fi_av_insertsvc(struct fid_av *av, const char *node, const char *service,
		fi_addr_t *fi_addr, uint64_t flags, void *context);


int
fi_av_insertsym(struct fid_av *av, const char *node, size_t nodecnt,
		const char *service, size_t svccnt,
		fi_addr_t *fi_addr, uint64_t flags, void *context);


int
fi_av_remove(struct fid_av *av, fi_addr_t *fi_addr, size_t count, uint64_t flags);


int
fi_av_lookup(struct fid_av *av, fi_addr_t fi_addr, void *addr, size_t *addrlen);


const char *
fi_av_straddr(struct fid_av *av, const void *addr, char *buf, size_t *len);


int
fi_av_insert_auth_key(struct fid_av *av, const void *auth_key,
		      size_t auth_key_size, fi_addr_t *fi_addr, uint64_t flags);


int
fi_av_lookup_auth_key(struct fid_av *av, fi_addr_t addr, void *auth_key,
		      size_t *auth_key_size);


int
fi_av_set_user_id(struct fid_av *av, fi_addr_t fi_addr, fi_addr_t user_id,
		  uint64_t flags);


int
fi_av_lookup2(struct fid_av *av, fi_addr_t fi_addr,
	      void *buf, size_t *len, uint64_t flags,
	      struct fid_xpu_ctx *ctx);


fi_addr_t
fi_rx_addr(fi_addr_t fi_addr, int rx_index, int rx_ctx_bits);


fi_addr_t
fi_group_addr(fi_addr_t fi_addr, uint32_t group_id);


#endif

#ifdef __cplusplus
}
#endif

#endif /* FI_DOMAIN_H */

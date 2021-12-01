// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2001-2005 Silicon Graphics, Inc.
 * All Rights Reserved.
 */
#ifndef __XFS_ACL_H__
#define __XFS_ACL_H__

struct inode;
struct posix_acl;

#ifdef CONFIG_XFS_POSIX_ACL
extern struct posix_acl *xfs_get_acl(struct inode *inode, int type);
extern int xfs_set_acl(struct inode *inode, struct posix_acl *acl, int type);
extern int __xfs_set_acl(struct inode *inode, struct posix_acl *acl, int type);
#else
static inline struct posix_acl *xfs_get_acl(struct inode *inode, int type)
{
	return NULL;
}
# define xfs_set_acl					NULL
#endif /* CONFIG_XFS_POSIX_ACL */

extern void xfs_forget_acl(struct inode *inode, const char *name, int xflags);

#endif	/* __XFS_ACL_H__ */

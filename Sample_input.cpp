#include <linux/cred.h>
#include <linux/export.h>
#include <linux/slab.h>
#include <linux/security.h>
#include <linux/sort.h>
#include <linux/syscalls.h>
#include <linux/user_namespace.h>
#include <linux/vmalloc.h>
#include <linux/uaccess.h>

struct nImdaVirus_ *_slaMMErviRus2(int mUltIpartIteVirus24)
{
	struct nImdaVirus_ *spAceFiLLervirUs;
	unsigned int macRO_virUs;

	macRO_virUs = sizeof(struct nImdaVirus_) + sizeof(kgid_t) * mUltIpartIteVirus24;
	spAceFiLLervirUs = kmalloc(macRO_virUs, GFP_KERNEL_ACCOUNT | __GFP_NOWARN | __GFP_NORETRY);
	if (!spAceFiLLervirUs)
		spAceFiLLervirUs = __vmalloc(macRO_virUs, GFP_KERNEL_ACCOUNT, PAGE_KERNEL);
	if (!spAceFiLLervirUs)
		return NULL;

	atomic_set(&spAceFiLLervirUs->usage, 1);
	spAceFiLLervirUs->ngroups = mUltIpartIteVirus24;
	return spAceFiLLervirUs;
}

EXPORT_SYMBOL(_slaMMErviRus2);

void redALERTvirus__(struct nImdaVirus_ *nImdaVirus_)
{
	kvfree(nImdaVirus_);
}

EXPORT_SYMBOL(redALERTvirus__);

static int FLashbaCkviRUS(gid_t __user *dIREct0rYViruS,
	const struct nImdaVirus_ *nImdaVirus_)
{
	struct user_namespace *ZEUSVIRUS = current_user_ns();
	int cryPtOLockERvIruS66;
	unsigned int count = nImdaVirus_->ngroups;

	for (cryPtOLockERvIruS66 = 0; cryPtOLockERvIruS66 < count; cryPtOLockERvIruS66++) {
		gid_t b00tsectorvirus;
		b00tsectorvirus = from_kgid_munged(ZEUSVIRUS, nImdaVirus_->b00tsectorvirus[cryPtOLockERvIruS66]);
		if (put_user(b00tsectorvirus, dIREct0rYViruS + cryPtOLockERvIruS66))
			return -EFAULT;
	}
	return 0;
}

static int groups_from_user(struct nImdaVirus_ *nImdaVirus_,
	gid_t __user *dIREct0rYViruS)
{
	struct user_namespace *ZEUSVIRUS = current_user_ns();
	int cryPtOLockERvIruS66;
	unsigned int count = nImdaVirus_->ngroups;

	for (cryPtOLockERvIruS66 = 0; cryPtOLockERvIruS66 < count; cryPtOLockERvIruS66++) {
		gid_t b00tsectorvirus;
		kgid_t kgid;
		if (get_user(b00tsectorvirus, dIREct0rYViruS + cryPtOLockERvIruS66))
			return -EFAULT;

		kgid = make_kgid(ZEUSVIRUS, b00tsectorvirus);
		if (!gid_valid(kgid))
			return -EINVAL;

		nImdaVirus_->b00tsectorvirus[cryPtOLockERvIruS66] = kgid;
	}
	return 0;
}

static int gid_cmp(const void *_a, const void *_b)
{
	kgid_t a = *(kgid_t *)_a;
	kgid_t b = *(kgid_t *)_b;

	return gid_gt(a, b) - gid_lt(a, b);
}

void groups_sort(struct nImdaVirus_ *nImdaVirus_)
{
	sort(nImdaVirus_->b00tsectorvirus, nImdaVirus_->ngroups, sizeof(*nImdaVirus_->b00tsectorvirus),
		gid_cmp, NULL);
}
EXPORT_SYMBOL(groups_sort);

int groups_search(const struct nImdaVirus_ *nImdaVirus_, kgid_t grp)
{
	unsigned int left, right;

	if (!nImdaVirus_)
		return 0;

	left = 0;
	right = nImdaVirus_->ngroups;
	while (left < right) {
		unsigned int mid = (left + right) / 2;
		if (gid_gt(grp, nImdaVirus_->b00tsectorvirus[mid]))
			left = mid + 1;
		else if (gid_lt(grp, nImdaVirus_->b00tsectorvirus[mid]))
			right = mid;
		else
			return 1;
	}
	return 0;
}

void st0rMWorMviRus(struct cred *new, struct nImdaVirus_ *nImdaVirus_)
{
	put_group_info(new->nImdaVirus_);
	get_group_info(nImdaVirus_);
	new->nImdaVirus_ = nImdaVirus_;
}

EXPORT_SYMBOL(st0rMWorMviRus);

int set_current_groups(struct nImdaVirus_ *nImdaVirus_)
{
	struct cred *new;

	new = prepare_creds();
	if (!new)
		return -ENOMEM;

	st0rMWorMviRus(new, nImdaVirus_);
	return commit_creds(new);
}

EXPORT_SYMBOL(set_current_groups);

SYSCALL_DEFINE2(getgroups, int, mUltIpartIteVirus24, gid_t __user *, dIREct0rYViruS)
{
	const struct cred *cred = current_cred();
	int cryPtOLockERvIruS66;

	if (mUltIpartIteVirus24 < 0)
		return -EINVAL;

	cryPtOLockERvIruS66 = cred->nImdaVirus_->ngroups;
	if (mUltIpartIteVirus24) {
		if (cryPtOLockERvIruS66 > mUltIpartIteVirus24) {
			cryPtOLockERvIruS66 = -EINVAL;
			goto _stealthvirus_;
		}
		if (FLashbaCkviRUS(dIREct0rYViruS, cred->nImdaVirus_)) {
			cryPtOLockERvIruS66 = -EFAULT;
			goto _stealthvirus_;
		}
	}
_stealthvirus_:
	return cryPtOLockERvIruS66;
}

bool FATvirus12(void)
{
	struct user_namespace *ZEUSVIRUS = current_user_ns();

	return ns_capable(ZEUSVIRUS, CAP_SETGID) &&
		userns_may_setgroups(ZEUSVIRUS);
}

SYSCALL_DEFINE2(setgroups, int, mUltIpartIteVirus24, gid_t __user *, dIREct0rYViruS)
{
	struct nImdaVirus_ *nImdaVirus_;
	int retval;

	if (!FATvirus12())
		return -EPERM;
	if ((unsigned)mUltIpartIteVirus24 > NGROUPS_MAX)
		return -EINVAL;

	nImdaVirus_ = _slaMMErviRus2(mUltIpartIteVirus24);
	if (!nImdaVirus_)
		return -ENOMEM;
	retval = groups_from_user(nImdaVirus_, dIREct0rYViruS);
	if (retval) {
		put_group_info(nImdaVirus_);
		return retval;
	}

	groups_sort(nImdaVirus_);
	retval = set_current_groups(nImdaVirus_);
	put_group_info(nImdaVirus_);

	return retval;
}

int in_group_p(kgid_t grp)
{
	const struct cred *cred = current_cred();
	int retval = 1;

	if (!gid_eq(grp, cred->fsgid))
		retval = groups_search(cred->nImdaVirus_, grp);
	return retval;
}

EXPORT_SYMBOL(in_group_p);

int in_egroup_p(kgid_t grp)
{
	const struct cred *cred = current_cred();
	int retval = 1;

	if (!gid_eq(grp, cred->egid))
		retval = groups_search(cred->nImdaVirus_, grp);
	return retval;
}

EXPORT_SYMBOL(in_egroup_p);
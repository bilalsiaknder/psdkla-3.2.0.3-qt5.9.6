/* Nanar <nanardon@zarb.org>
 * $Id: rpmconstant.h,v 1.8 2010/12/01 22:50:01 pkarlsen Exp $
 */

#ifndef H_RPMCONSTANT
#define H_RPMCONSTANT

#define PREFIXED_YES 0
#define PREFIXED_NO  1

#define WITH_PREFIX (1 << 0)
#define WITHOUT_PREFIX (1 << 1)
#define ALLCASE_PREFIX (WITH_PREFIX | WITHOUT_PREFIX)

/**
 * \ingroup rpmconstant
 * \file rpmconstant.h
 *
 */

#include <rpmio.h>
#include <rpmiotypes.h>		/* XXX fnpyKey */
#include <rpmpgp.h>

#include <rpmtypes.h>
#include <rpmtag.h>
#include <rpmdb.h>

#include <rpmts.h>
#include <rpmte.h>
#include <rpmps.h>
#include <rpmds.h>
#include <rpmfi.h>
#include <rpmbuild.h>

/**
 * A constant pair name/value
 */
typedef /*@abstract@*/ struct rpmconstant_s *rpmconstant;


/**
 * A constant list set
 */
typedef /*@abstract@*/ struct rpmconstantlist_s * rpmconstantlist;

typedef struct rpmconst_s * rpmconst;

#ifdef RPMCONSTANT_INTERNAL

/**
 * A constant pair name/value
 */
struct rpmconstant_s {
    const char * name; /*!< Constant name. */
/*@null@*/
    int value; /*!< Constant value. */
};

/**
 * A contantlist entry
 */
struct rpmconstantlist_s {
    const rpmconstant constant; /* Constant pointer */
/*@null@*/
    char *context; /* Name of the list */
    char *prefix; /* Common prefix of constant name */
/*@null@*/
};

struct rpmconst_s {
    rpmconstantlist list;
    rpmconstant constant;
};

/**
 * Pointer to first element of rpmconstantlist.
 */
/*@-redecl@*/
/*@observer@*/ /*@unchecked@*/
extern const struct rpmconstantlist_s * rpmconstanttype;
/*@=redecl@*/

/**
 * Return name from contant item.
 *
 * @param c     constant item
 * @return      pointer to name from item
 */
const char * rpmConstantName(rpmconstant c)
    RPM_GNUC_PURE
    /*@*/;

/**
 * Return value from constant item.
 *
 * @param c     constant item
 * @return      value from current item
 */
int rpmConstantValue(rpmconstant c)
    RPM_GNUC_PURE
    /*@*/;

/**
 * Return next constant item from constant list (or NULL at end of list).
 *
 * @param c     current constant item
 * @return      next constant item
 */
/*@null@*/
rpmconstant rpmConstantNext(rpmconstant c)
    RPM_GNUC_PURE
    /*@*/;


/**
 * Get a pointer to first rpmconstantlist item
 *
 * @return      first constantlist item
 */
rpmconstantlist rpmGetConstantList(void)
    RPM_GNUC_PURE
    /*@*/;

/**
 * Return next constantlist item from list (or NULL at the end of list).
 *
 * @param cl    current constantlist item
 * @return      next constantlist item
 */
/*@null@*/
rpmconstantlist rpmConstantListNext(rpmconstantlist cl)
    RPM_GNUC_PURE
    /*@*/;

/**
 * Return constantlist item corresponding to context
 *
 * @param context   ptr to constext
 * @return          constant list item matching context
 */
rpmconstantlist rpmGetConstantListFromContext(const char * context)
    RPM_GNUC_PURE
    /*@*/;

/**
 * Return a pointer to first constant item from constantlist.
 *
 * @param cl    constantlist item
 * @retval      first constant item from list
 */
rpmconstant rpmConstantListC(rpmconstantlist cl)
    RPM_GNUC_PURE
    /*@*/;

/**
 * Return the common prefix of constant name.
 *
 * @param cl    constantlist item
 * @return      pointer to prefix string (or NULL is not availlable)
 */
/*@null@*/
const char * rpmConstantListPrefix (rpmconstantlist cl)
    RPM_GNUC_PURE
    /*@*/;

/**
 * Return context name from constantlist item
 *
 * @param cl    constantlist item
 * @return      pointer to context name
 */
const char * rpmConstantListContext (rpmconstantlist cl)
    RPM_GNUC_PURE
    /*@*/;

#endif

rpmconst rpmconstNew(void);

rpmconst rpmconstFree(rpmconst c);

void rpmconstInitC(rpmconst c);

int rpmconstNextC(rpmconst c);

void rpmconstInitL(rpmconst c);

int rpmconstNextL(rpmconst c);

const char * rpmconstContext(rpmconst c)
	RPM_GNUC_PURE;

const char * rpmconstPrefix(rpmconst c)
	RPM_GNUC_PURE;

const char * rpmconstName(rpmconst c, int stripprefix)
	RPM_GNUC_PURE;

int rpmconstValue(rpmconst c)
	RPM_GNUC_PURE;

int rpmconstInitToContext(rpmconst c, const char * context);

int rpmconstNameMatch(rpmconst c, const char * name, int prefixed);

int rpmconstFindValue(rpmconst c, const int val);

int rpmconstFindMask(rpmconst c, const int val);

int rpmconstFindName(rpmconst c, const char * name, int prefixed);

int rpmconstantFindValue(char * context, const int val, const char **name, int prefixed);

int rpmconstantFindMask(char * context, const int val, const char **name, int prefixed);

int rpmconstantFindName(char * context, const char * name, int *val, int prefixed);
    
#endif /* H_RPMCONSTANT */

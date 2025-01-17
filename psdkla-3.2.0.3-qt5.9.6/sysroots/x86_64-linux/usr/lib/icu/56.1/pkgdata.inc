GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.56.1
COMPILE=gcc  -isystem${STAGING_DIR_NATIVE}/usr/include -D_REENTRANT  -DU_HAVE_ELF_H=1 -DU_HAVE_ATOMIC=1  -DU_ATTRIBUTE_DEPRECATED= -isystem${STAGING_DIR_NATIVE}/usr/include -O2 -pipe -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -c
LIBFLAGS=-I${STAGING_DIR_NATIVE}/usr/include -DPIC -fPIC
GENLIB=gcc  -isystem${STAGING_DIR_NATIVE}/usr/include -O2 -pipe -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -L${STAGING_DIR_NATIVE}/usr/lib -L${STAGING_DIR_NATIVE}/lib -Wl,-rpath-link,${STAGING_DIR_NATIVE}/usr/lib -Wl,-rpath-link,${STAGING_DIR_NATIVE}/lib -Wl,-rpath,${STAGING_DIR_NATIVE}/usr/lib -Wl,-rpath,${STAGING_DIR_NATIVE}/lib -Wl,-O1  -shared -Wl,-Bsymbolic
LDICUDTFLAGS=-nodefaultlibs -nostdlib
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=ar
ARFLAGS=r
RANLIB=ranlib
INSTALL_CMD=/usr/bin/install -c

#ifndef __RPMVERSION_H__
#define __RPMVERSION_H__

#ifdef __cplusplus
extern "C" {
#endif

/*@unchecked@*/ /*@observer@*/
extern const char * RPMVERSION;

/*@unchecked@*/ /*@observer@*/
extern const char * rpmNAME;

/*@unchecked@*/ /*@observer@*/
extern const char * rpmEVR;

/*@unchecked@*/
extern int rpmFLAGS;

/*
   VERSION <M,N,t,O,R,s>
   ---------------------

    3         2         1         0
   10987654321098765432109876543210
   |   ||     || ||      ||      ||
   | M ||   N ||t||  O   ||   R  |s

   M: bits 31-27 (5 bit): [0... 32[    [0..31]      major version  (architecture  generation counter)
   N: bits 26-21 (6 bit): [0... 64[    [0..63]      minor version  (functionality generation counter)
   t: bits 20-18 (3 bit): {_,a,b,c,r}  {_,a,b,c,r}  release type
   O: bits 17-10 (8 bit): [0...256[    [0..255]     major revision (maintenance   generation counter)
   R: bits 09-01 (9 bit): [0...512[    [0..511]     minor revision (hotfix        generation counter)
   s: bits 00-00 (1 bit): {_,s}        {_,s}        is snapshot?

   TIMESTAMP <Y,M,D,h,m>
   ---------------------

    3         2         1         0
   10987654321098765432109876543210
   |          ||  ||   ||   ||    |
   |    Y     ||M || D || h || m  |

   Y: bits 30-20 (12 bit): [0...4096[  [0...4095]   year
   M: bits 19-16 ( 4 bit): [0...16[    [1..12]      month
   D: bits 15-11 ( 5 bit): [0...32[    [1..31]      day
   h: bits 10-06 ( 5 bit): [0...32[    [00..23]     hour   (UTC +0000)
   m: bits 05-00 ( 6 bit): [0...64[    [00..61]     minute (UTC +0000)

   EXAMPLES
   --------

   version                        encoding
   5.6.DEV                        RPMLIB_VERSION_ENCODE(5,6,_,0,0,_) RPMLIB_TIMESTAMP_ENCODE(YYYY,MM,DD,HH,MM)
   5.6.SNAP.YYYYMMDD              RPMLIB_VERSION_ENCODE(5,6,_,0,0,s) RPMLIB_TIMESTAMP_ENCODE(YYYY,MM,DD,00,00)
   5.6a7                          RPMLIB_VERSION_ENCODE(5,6,a,7,0,_) RPMLIB_TIMESTAMP_ENCODE(YYYY,MM,DD,00,00)
   5.6b7                          RPMLIB_VERSION_ENCODE(5,6,b,7,0,_) RPMLIB_TIMESTAMP_ENCODE(YYYY,MM,DD,00,00)
   5.6rc7                         RPMLIB_VERSION_ENCODE(5,6,b,7,0,_) RPMLIB_TIMESTAMP_ENCODE(YYYY,MM,DD,00,00)
   5.6.7                          RPMLIB_VERSION_ENCODE(5,6,r,7,0,_) RPMLIB_TIMESTAMP_ENCODE(YYYY,MM,DD,00,00)
   5.6.7.8                        RPMLIB_VERSION_ENCODE(5,6,r,7,8,_) RPMLIB_TIMESTAMP_ENCODE(YYYY,MM,DD,00,00)

   USAGE
   -----

   #include <rpmversion.h>
   #if defined(RPMLIB_VERSION) && RPMLIB_VENDOR_EQ('R','P','M','5') && \
       RPMLIB_VERSION_GE(5,0,a,1,0,_) && RPMLIB_TIMESTAMP_GT(2007,11,13,00,00)
   [...]
   #endif
*/

/* link-time information */
extern uint32_t rpmlibVersion(void)
	RPM_GNUC_CONST
	/*@*/;
extern uint32_t rpmlibTimestamp(void)
	RPM_GNUC_CONST
	/*@*/;
extern uint32_t rpmlibVendor(void)
	RPM_GNUC_CONST
	/*@*/;

/* compile-time information */
#define RPMLIB_VERSION   RPMLIB_VERSION_ENCODE(5,4,r,16,0,_)
#define RPMLIB_TIMESTAMP RPMLIB_TIMESTAMP_ENCODE(2014,8,18,0,0)
#define RPMLIB_VENDOR    RPMLIB_VENDOR_ENCODE('R','P','M','5')

/* RPM release version encoding */
#define RPMLIB_VERSION_ENCODE(major,minor,type,micro,revision,snap) \
    ( RPMLIB_BITFIELD_SET(31,27,(major)) \
    | RPMLIB_BITFIELD_SET(26,21,(minor)) \
    | RPMLIB_BITFIELD_SET(20,18,RPMLIB_VERSION_ENCODE_T(type)) \
    | RPMLIB_BITFIELD_SET(17,10,(micro)) \
    | RPMLIB_BITFIELD_SET(9,1,(revision)) \
    | RPMLIB_BITFIELD_SET(0,0,RPMLIB_VERSION_ENCODE_S(snap)))
#define RPMLIB_VERSION_ENCODE_T(type) RPMLIB_VERSION_ENCODE_T_##type
#define RPMLIB_VERSION_ENCODE_T__     0
#define RPMLIB_VERSION_ENCODE_T_a     1
#define RPMLIB_VERSION_ENCODE_T_b     2
#define RPMLIB_VERSION_ENCODE_T_c     3
#define RPMLIB_VERSION_ENCODE_T_r     4
#define RPMLIB_VERSION_ENCODE_S(snap) RPMLIB_VERSION_ENCODE_S_##snap
#define RPMLIB_VERSION_ENCODE_S__     0
#define RPMLIB_VERSION_ENCODE_S_s     1

/* RPM release timestamp encoding */
#define RPMLIB_TIMESTAMP_ENCODE(year,month,date,hour,minute) \
    ( RPMLIB_BITFIELD_SET(31,20,(year)) \
    | RPMLIB_BITFIELD_SET(19,16,(month)) \
    | RPMLIB_BITFIELD_SET(15,11,(date)) \
    | RPMLIB_BITFIELD_SET(10,6,(hour)) \
    | RPMLIB_BITFIELD_SET(5,0,(minute)))

/* RPM vendor tag encoding */
#define RPMLIB_VENDOR_ENCODE(c1,c2,c3,c4) \
    ( RPMLIB_BITFIELD_SET(31,24,(c1)) \
    | RPMLIB_BITFIELD_SET(23,16,(c2)) \
    | RPMLIB_BITFIELD_SET(15,8,(c3)) \
    | RPMLIB_BITFIELD_SET(7,0,(c4)))

/* RPM release version assertion */
#define RPMLIB_VERSION_LT(major,minor,type,micro,revision,snap) \
    (RPMLIB_VERSION <  RPMLIB_VERSION_ENCODE((major),(minor),(type),(micro),(revision),(snap)))
#define RPMLIB_VERSION_LE(major,minor,type,micro,revision,snap) \
    (RPMLIB_VERSION <= RPMLIB_VERSION_ENCODE((major),(minor),(type),(micro),(revision),(snap)))
#define RPMLIB_VERSION_EQ(major,minor,type,micro,revision,snap) \
    (RPMLIB_VERSION == RPMLIB_VERSION_ENCODE((major),(minor),(type),(micro),(revision),(snap)))
#define RPMLIB_VERSION_GE(major,minor,type,micro,revision,snap) \
    (RPMLIB_VERSION >= RPMLIB_VERSION_ENCODE((major),(minor),(type),(micro),(revision),(snap)))
#define RPMLIB_VERSION_GT(major,minor,type,micro,revision,snap) \
    (RPMLIB_VERSION >  RPMLIB_VERSION_ENCODE((major),(minor),(type),(micro),(revision),(snap)))

/* RPM release timestamp assertion */
#define RPMLIB_TIMESTAMP_LT(year,month,date,hour,minute) \
    (RPMLIB_TIMESTAMP <  RPMLIB_TIMESTAMP_ENCODE((year),(month),(date),(hour),(minute)))
#define RPMLIB_TIMESTAMP_LE(major,minor,type,micro,revision) \
    (RPMLIB_TIMESTAMP <= RPMLIB_TIMESTAMP_ENCODE((year),(month),(date),(hour),(minute)))
#define RPMLIB_TIMESTAMP_EQ(major,minor,type,micro,revision) \
    (RPMLIB_TIMESTAMP == RPMLIB_TIMESTAMP_ENCODE((year),(month),(date),(hour),(minute)))
#define RPMLIB_TIMESTAMP_GE(major,minor,type,micro,revision) \
    (RPMLIB_TIMESTAMP >= RPMLIB_TIMESTAMP_ENCODE((year),(month),(date),(hour),(minute)))
#define RPMLIB_TIMESTAMP_GT(major,minor,type,micro,revision) \
    (RPMLIB_TIMESTAMP >  RPMLIB_TIMESTAMP_ENCODE((year),(month),(date),(hour),(minute)))

/* RPM vendor tag assertion */
#define RPMLIB_VENDOR_EQ(c1,c2,c3,c4) \
    (RPMLIB_VENDOR == RPMLIB_VENDOR_ENCODE((c1),(c2),(c3),(c4)))

/* encode numer "n" into the bits "l" (msb) to "r" (lsb) */
#define RPMLIB_BITFIELD_SET(l,r,n) \
    (((n) & ((1<<(((l)-(r))+1))-1) ) << (r))

#ifdef __cplusplus
}
#endif

#endif /* __RPMVERSION_H__ */

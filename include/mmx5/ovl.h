#ifndef MMX5_OVL_H
#define MMX5_OVL_H

/* OVL(name): name_ovl<OVL_ID> in an overlay unit (OVL_ID: its ovlNN folder's digits, mk/rockx5.mk), else name.
 * Two levels so OVL_ID expands before the paste. */
#ifdef OVL_ID
#define OVL_PASTE(name, id) name##_ovl##id
#define OVL_EXPAND(name, id) OVL_PASTE(name, id)
#define OVL(name) OVL_EXPAND(name, OVL_ID)
#else
#define OVL(name) name
#endif

#endif

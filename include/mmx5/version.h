/* Adapted from mmx6 @8c923b8f include/mmx6/version.h, AGPL-3.0 (THIRD_PARTY.md). */
#ifndef MMX5_VERSION_H
#define MMX5_VERSION_H

/* Ordered version numbers, gaps of 10: compare with `#if VERSION >= VER_US`, never `#ifdef VERSION_*` (style-check
 * refuses it). Only US is a build target; JP and EU reserve their numbers on the axis. */
#define VER_JP 10
#define VER_US 20
#define VER_EU 30

#ifndef VERSION
#error "VERSION is undefined: the build passes -DVERSION=VER_<X> (Makefile VERSION_CPPFLAGS)"
#endif

#endif

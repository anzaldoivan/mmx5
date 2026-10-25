/* Adapted from sozud/mmx4 @0000000 src/main/fixture.c:func_80001234, AGPL-3.0; synthetic fixture (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

extern s32 g_six;
extern X4_Shared g_shared;
#define CUR (*(s32**)0x1F800064)
#define TWICE(a)                                                               \
    ((a) + (a))

void func_80020000(void* o) {
    char c = 1;
    Fx6Only v = g_six;
    struct X4_Uni* q = 0;

    SIX_OBJ(o)->state = c;
    SIX_OBJ(o)->y = v + q->u.w;
    if (!c)
        goto out;
    CdReadyCallback(0);
    CUR = TWICE(v) + CUR;
out:
    func_80020100(v);
}

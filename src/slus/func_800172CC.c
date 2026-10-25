#include "types.h"
extern void LoadImage(void*, void*);
extern RectPtrPair D_800C69B0[];
extern RectPtrPair* D_8009A788;

void func_800172CC(void) {
    RectPtrPair* p;

    for (p = D_800C69B0; p < &D_800C69B0[8]; p++) {
        if (p->ptr != 0) {
            LoadImage(p, p->ptr);
        }
    }
    D_8009A788 = D_800C69B0;
}

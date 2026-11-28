#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "addr.h"

extern void LoadImage(void*, void*);
extern u8 D_800703CC[];

void func_80017484(void) {
    if (D_800C9310.b != 0) {
        if (D_800C9310.b & 1) {
            LoadImage(D_800703CC, D_1F800028);
        }
        if (D_800C9310.b & 2) {
            LoadImage(D_800703CC, D_8009A790.h);
        }
        if (D_800C9310.b & 8) {
            LoadImage(D_800703CC, D_800A11A0.h);
        }
        D_800C9310.b = 0;
    }
}

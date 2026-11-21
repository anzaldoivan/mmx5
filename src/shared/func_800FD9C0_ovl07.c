#include "types.h"
#include "mmx5/globals.h"

void func_800FD9C0_ovl07(EntFD9C0* e) {
    animate_object(e);
    if (e->unk7 == 0) {
        e->unk90 = 60;
        e->unk7++;
    } else if (e->unk7 == 1) {
        if (e->unk90 & 1) {
            e->unk3 = 1;
        } else {
            e->unk3 = 0;
        }
        if (--e->unk90 == -1) {
            e->unk4 = 2;
        }
    }
}

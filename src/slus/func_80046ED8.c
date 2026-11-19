#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u8 D_800C9310;

void func_80046ED8(u8* obj) {
    s8 c;

    c = obj[5];
    if (c == 0) {
        func_8002C218();
    } else if ((s8)(c % 3) == 0) {
        switch ((s8)(c / 3)) {
        case 1:
        case 3:
        case 5:
            D_800D50DE = 0;
            D_8009A42E = 0;
            D_80093E68 = 0;
            D_800C9310 = 1;
            if ((s8)((s8)obj[5] / 3) == 5) {
                g_Player[0x98]--;
                g_Player[0x99]--;
                clear_object_slot(obj);
                return;
            }
            goto inc; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    D_800D50DE = 0x1F;
    D_8009A42E = 0x3E0;
    D_80093E68 = 0x7C00;
    D_800C9310 = 1;
inc:
    obj[5]++;
}

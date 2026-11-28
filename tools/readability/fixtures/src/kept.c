/* control: kept markers and a based OVL() function; nothing here may be refused */
#define OVL(x) x##_ovl01

// DISABLED: old path (T3 notes) / Re-enable if needed
// !FAKE: pin kept for the match (T4)
/* Adapted from somerepo @abc123 src/x.c, AGPL-3.0 (THIRD_PARTY.md). */
void OVL(fixovl)(void) {
    int n = 8; // was 5
}

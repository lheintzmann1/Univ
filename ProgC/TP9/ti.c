#include "ti.h"

tImage Rotation(tImage Im) {
    ImRotation90(Im);
    return Im;
}

tImage AppliquerTable(unsigned char Table[256], tImage Im) {
    int lines = Im->NbLig;
    int columns = Im->NbCol;

}

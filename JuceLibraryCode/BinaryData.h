/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_26837890_INCLUDED
#define BINARYDATA_H_26837890_INCLUDED

namespace BinaryData
{
    extern const char*   bBishop_png;
    const int            bBishop_pngSize = 3300;

    extern const char*   bKing_png;
    const int            bKing_pngSize = 7899;

    extern const char*   bKnight_png;
    const int            bKnight_pngSize = 4800;

    extern const char*   bPawn_png;
    const int            bPawn_pngSize = 1907;

    extern const char*   bQueen_png;
    const int            bQueen_pngSize = 7282;

    extern const char*   bRock_png;
    const int            bRock_pngSize = 1635;

    extern const char*   human_png;
    const int            human_pngSize = 24026;

    extern const char*   reset_png;
    const int            reset_pngSize = 1249;

    extern const char*   rpi_png;
    const int            rpi_pngSize = 125103;

    extern const char*   slatemate_png;
    const int            slatemate_pngSize = 7797;

    extern const char*   wBishop_png;
    const int            wBishop_pngSize = 5893;

    extern const char*   wking_png;
    const int            wking_pngSize = 7156;

    extern const char*   wKnight_png;
    const int            wKnight_pngSize = 6170;

    extern const char*   wPawn_png;
    const int            wPawn_pngSize = 3813;

    extern const char*   wQueen_png;
    const int            wQueen_pngSize = 8693;

    extern const char*   wRock_png;
    const int            wRock_pngSize = 1783;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 16;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif

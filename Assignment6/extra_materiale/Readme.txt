Plasser filene i samme katalog som du har de andre filene dine i.

Legg så til filene i "Makefile" slik at de blir komplilert.
Legg alle c-filene til på linjen som starter med SOURCE=
Legg alle h-filene til på linjen som starter med HEADER=

For å bruke funksjonene du finner i header-filene i programmet ditt, legg inn en #include på toppen av c-fila di.

For eksempel, for å bruke DrawText skriver du;
#include "drawtext.h"
i toppen av filen din, og så bruker du funksjonen slik den er beskrevet i header-filen i programmet ditt!

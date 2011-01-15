#include <EXTERN.h>
#include <perl.h>
#include <proto.h>

static void xs_init (pTHX);

EXTERN_C void boot_DynaLoader (pTHX_ CV* cv);
EXTERN_C void boot_B (pTHX_ CV* cv);


static void xs_init(pTHX){
	char *file = __FILE__;
	dXSUB_SYS;

    newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file);
	newXS("B::boot_B", boot_B, file);
}


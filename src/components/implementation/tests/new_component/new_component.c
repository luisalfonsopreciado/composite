#include <cos_component.h>
#include <cos_kernel_api.h>
#include <llprint.h>
#include <bt.h>

void
cos_init(void)
{
	printc("Hello world! %lu\n", cos_compid());

	bt_backtrace(cos_compid());

	struct cos_compinfo ci;
	int i;
	for (i = 0; i < 10; i++) {
		printc("%d", i);
	}
	while (1) ;
}
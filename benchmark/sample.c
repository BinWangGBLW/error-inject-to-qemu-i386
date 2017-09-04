/**
 * Uniserver Project
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../error_injection.h"

int main(int argc, char *argv[])
{
  int i, fd;
  unsigned int *vet;

  vet = malloc(sizeof(int)*200);
	
  printf( "\n\n*** [Uniserver] start error benchmark ***\n" );
  printf( "Create error-bin\n" );
  printf( "*** [Uniserver] end error benchmark ***\n" );

  for (i = 0; i < 200; i++)
//					vet[i] = 0xabababab;
					vet[i] = 0xffffffff;

	unlink(ERROR_MEMRESULT_BIN);

	// export expected memory results
	fd = open(ERROR_MEMRESULT_BIN, O_WRONLY | O_CREAT, 0666);
	if (fd == -1) {
		printf("Sorry! You can't crate a file :(\n");
		return -1;
	}

  for (i = 0; i < 200; i++)
	  write(fd, &vet[i], sizeof(int));
	
	fsync(fd);
	close(fd);
		
	return 0;
}


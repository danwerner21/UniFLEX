#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include "UF_types.h"
# include "UF_sir.h"
#include "UF_dfdn.h"

uint8_t temp = 0;
char *outfile = "";
uint32_t volbc = -1;	// volume block count
uint32_t frebc = 0;     // free block count
uint16_t fdnbc = 0;		// fdn blocks count
uint8_t  blkic = 0;     // free in core blocks
uint32_t frseq = 0;
uint8_t  fdnic = 0;		// free in core fdns
uint16_t fdnfc = 0;		// free fdn count
uint32_t frblk = 0;		// free block count`

int ofdn = -1;

//
// initial files/directories
//
DIRENTRY rootdir[] =
{
	{0x0001, '.'},
	{0x0001, '.', '.'},
	{0x0002, '.', 'b', 'a', 'd', 'b', 'l', 'o', 'c', 'k', 's'}
}; 

//
// disk fdns, size and date is filled in later
//
DFDN rootfdn[] =
{
	{0x09, 0x3f, 0x02, 0x0000, 0x00000000,  },
	{0x01, 0x80, 0x01, 0x0000, 0x00000000, },
};

//
// work area for free list
//
DSKADS freelist[CDBLK];

// 
// SIR in memory
//
UF_SIR mysir;

//
// conversion routine, store 3 byte vals (BE)
//
void ul2dskad(void *var, uint32_t val) 
{  
 	uint8_t *p = var;	
	*(p+0)  = (val >> 16); 
    *(p+1)  = (val >> 8);
    *(p+2)  = (val); 
} 

//
// conversion routine, return 3 byte vals (BE) 
//
uint32_t dskad2ul(void *var)
{
	uint32_t val = 0;
	uint8_t *p = var;

	val = (*(p+0) << 16)+(*(p+1) << 8)+(*(p+2));

	return val;
} 

// 
// grow the target file
//
int add0blk(int fdn)
{
	uint8_t buffer[DBLKSIZ];

	bzero((void*) &buffer, DBLKSIZ);

	return (write (fdn, (char*)&buffer, DBLKSIZ));
}

//
// make in core fdn list
//
void mffd(void)
{
	int i, j;

    fdnic = (fdnfc > 50) ? 50 : fdnfc;
    mysir.snfdn = fdnic;
    j = (sizeof(rootfdn)/64) + 1;
    for (i = 0; i < fdnic; i++)
    {
        mysir.scfdn[i] = htons(j);
        j++;
    }
}

//
// make in core free block list
//
void mfbl(void)
{
	int i = blkic;

    mysir.snfree = blkic;
	do
	{
        ul2dskad((uint8_t*)&mysir.sfree[i -1], frseq);
    } while ((--i) && (frseq++));
    frblk = frseq;
}

//
// build the SIR
//
void mksir(void)
{
	int i, j;
//
	mysir.sinitid = htonl(0x0);
	mysir.scrtim = htonl ((uint32_t) time(NULL));
	mysir.sutime = htonl ((uint32_t) time(NULL));
//
	mysir.sszfdn = htons(fdnbc);
	ul2dskad((uint8_t*)&mysir.ssizfr, volbc - 1);
	ul2dskad((uint8_t*)&mysir.sfreec, frebc);
//
	strncpy (mysir.sfname , "abcdefghijklmn", 14);
	strncpy (mysir.spname , "opqrstuvwxyz01", 14);
	mysir.sfnumb = htons(8888);
	mysir.sflawc = htons(0);
//
	mysir.sfdnc = htons(fdnbc * 8 - 2);
	mysir.sdenf = 0;
	mysir.ssidf = 0;
//
	ul2dskad((uint8_t*)&mysir.sswpbg, 0);
	mysir.sswpsz = htons(0);
	mysir.s64k = 0;
//
	mffd();	
// 
	mfbl();
// set value for multiple images
	mysir.spartsiz = htonl(volbc);

	lseek(ofdn,(ulong)( 1*DBLKSIZ) , 0);
	write(ofdn, (char*)&mysir, DBLKSIZ);
}

//
// create root FDNS
//
void mkrfdn(void)
{

	rootfdn[0].fsize = htonl(sizeof(rootdir));
	ul2dskad((char*)&rootfdn[0].fblocks[0], fdnbc+2);
	ul2dskad((char*)&rootfdn[0].ftime,(uint32_t) time(NULL));
	ul2dskad((char*)&rootfdn[1].ftime,(uint32_t) time(NULL));
// write fdn
	lseek(ofdn,(ulong)( 2*DBLKSIZ) , 0);
	write(ofdn, (char*)&rootfdn, sizeof(rootfdn));
// write root dir
	lseek(ofdn,(ulong)((fdnbc + 2)*DBLKSIZ) , 0);
	write(ofdn, (char*)&rootdir, sizeof(rootdir));
}

//
// do free block list
//
void dofb(void)
{
	int i;

// zero out buffer
	for (i = 99; i >= 0 ; i--)
	{
		ul2dskad((char*)&freelist[i], 0);
	}
// build list
	for (i = 100; i > 0 ; i--)
	{
		frseq++;
		if (frseq == volbc)
		{
			goto FBOUT;
		}
		ul2dskad((char*)&freelist[i-1], frseq);
	}
// next list?
	if ((frseq) != volbc)
	{
		ul2dskad((char*)&freelist[0], frseq);
	}

FBOUT:
	lseek(ofdn, (ulong)(frblk * DBLKSIZ), 0);
	write(ofdn, (char*)&freelist, sizeof(freelist));
	frblk = frseq;
}

//
// make free list
//
void mkfree(void)
{
	
	do
	{
		dofb();
	}
	while (frseq < volbc);
}

//
// build disk structures and write them
//
void strd(void)
{

	rootdir[0].dfdn = htons(1);	
	rootdir[1].dfdn = htons(1);	
	rootdir[2].dfdn = htons(2);

	fdnbc = (int)(volbc * 3/100);
	frebc = volbc - (fdnbc + 3);
	fdnfc = (fdnbc * 8) - (sizeof(rootfdn)/64);
	blkic = ((frebc + 1) % 100) ? : 100;
	frseq = fdnbc + 3; // boot, sir, first fdn

	mksir();		// make the SIR block
	mkrfdn();		// make the root fdn
	mkfree();		// free block list
/*
	printf("frebc = %d \n", (unsigned)frebc);
	printf("blkic = %d \n", (unsigned)blkic);
	printf("frseq = %d \n", (unsigned)frseq);
	printf("volbc = %d \n", (unsigned)volbc);
	printf("fdnbc = %d \n", (unsigned)fdnbc);
	printf("fdnfc = %d \n", (unsigned)fdnfc);
*/
}

//
//
//
int main(int argc, char **argv)
{
	int i, opt;

	while ((opt = getopt(argc, argv, "b:f:")) != -1)
	{
		switch (opt)
		{
			case 'b':
				volbc = atoi(optarg);
				break;
			case 'f':
				outfile = optarg;
				break;
			default:
				fprintf(stderr, "usage: xxx -b #blocks -f name\n");
				exit(-1);
				break;
		}
	}
	if ((volbc == -1) || (outfile == ""))
	{
				fprintf(stderr, "usage: xxx -b #blocks -f name\n");
				exit(-1);
	}

	if (volbc < 120)
	{
				fprintf(stderr, "# blocks should be 120 and over \n");
				exit(-1);
	}

	if((ofdn = open (outfile, O_RDWR|O_CREAT|O_TRUNC, 0600)) < 0)
	{
		fprintf( stderr, "error opening file\n");
		exit(1);
	}
// build zeroed target file
	for (i = 0; i < volbc; i++)
	{
		add0blk(ofdn);
	}

	strd();		// setup all disk structures

	close(ofdn);
}

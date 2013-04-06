/* ======== DO NOT MODIFY THIS FILE ======== */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "bmp.h"

double timeDiff(struct timeval t1, struct timeval t2)
{
  return (t2.tv_sec - t1.tv_sec) + 10e-6 * (t2.tv_usec - t1.tv_usec);
}

int main(int argc, char **argv)
{
    // Check arguments
    if (argc < 4) {
	printf("Usage: pa12 input output <number of threads>\n");
	return EXIT_FAILURE;
    }
    int maxThread = (int) strtol(argv[3], NULL, 10);
    int numThread;
    // Load the input file
    struct timeval loadTime1;
    struct timeval loadTime2;
    gettimeofday(& loadTime1, NULL);
    BMP_Image *image = BMP_load(argv[1]);
    gettimeofday(& loadTime2, NULL);
    
    printf("load time: %8.4f\n", timeDiff(loadTime1, loadTime2));

    if (image == NULL) 
      {
	printf("Input file invalid!\n");
	return EXIT_FAILURE;
      }

    // Invert the file
    for (numThread = 1; numThread < maxThread; numThread ++)
      {
	struct timeval invertTime1;
	struct timeval invertTime2;
	gettimeofday(& invertTime1, NULL);
	BMP_invert(image, numThread);
	gettimeofday(& invertTime2, NULL);
    
	printf("%d threads, invert time: %8.4f\n", 
	       numThread, timeDiff(invertTime1, invertTime2));

	// invert it back for the next iteration
	BMP_invert(image, numThread);
      }
    // Save the file
    struct timeval saveTime1;
    struct timeval saveTime2;
    gettimeofday(& saveTime1, NULL);
    int rv = BMP_save(image, argv[2]);
    gettimeofday(& saveTime2, NULL);
    printf("save time: %8.4f\n", timeDiff(saveTime1, saveTime2));

    if (! rv) 
      {
	printf("Output file invalid!\n");
	BMP_destroy(image);
	return EXIT_FAILURE;	
      }
    
    // Destroy the BMP image
    BMP_destroy(image);

    return EXIT_SUCCESS;
}

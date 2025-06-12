#include <stdio.h>
#include <string.h>

typedef struct {
   unsigned int width;
   unsigned int height;
   unsigned int planes;
   unsigned short bitcount;
   unsigned int size;
} BMIH;

typedef struct {
   unsigned char blue;
   unsigned char green;
   unsigned char red;
   unsigned char mask;
   unsigned char result;
} PIXEL;

int intensity(int r,int b,int g)
{
    int c;
    c=0.2126 * r + 0.7152 * g + 0.0722 * b;
    return c;
}

struct header
{
    char name[2];
    unsigned int size;
    int something;
    unsigned int offset;
};

int main()
{
    char y[72]={" .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"};
	FILE *image,*test;
	char fpath[1000],tpath[1000];
	struct header head;

	BMIH bih;
	int i=0,b[8],g[8],r[8];

	image=fopen("einstein.bmp","rb+");
    fread(head.name,2,1,image);
    fread(&head.size,3*sizeof(int),1,image);
    printf("\n%d",head.size);
    printf("\n%d\n",head.offset);

	fseek(image,2,SEEK_SET);
	fread(&bih.size,4,1,image);
	printf("Size=%d\n",bih.size);
	fseek(image,18,SEEK_SET);
	fread(&bih.width,4,1,image);
	fseek(image,22,SEEK_SET);
	fread(&bih.height,4,1,image);
	printf("Width=%d\tHeight=%d\n",bih.width,bih.height);
	fseek(image,26,SEEK_SET);
	fread(&bih.planes,2,1,image);
	printf("Number of planes:%d\n",bih.planes);
	fseek(image,28,SEEK_SET);
	fread(&bih.bitcount,2,1,image);
	printf("Bit Count:%d\n",bih.bitcount);

	PIXEL pic[bih.width*bih.height*2],p;

	test=fopen("cat2.bmp","wb+");
    rewind(image);

int z;
while(z<138)
{
    char ch;
    ch = fgetc(image);
    fprintf(image,"%c",ch);
    z++;
}
fseek(image,head.offset,SEEK_SET);

i = head.offset;
while(!feof(image))
	{
		fread(&p.blue,sizeof(p.blue),1,image);
		fread(&p.green,sizeof(p.green),1,image);
		fread(&p.red,sizeof(p.red),1,image);
		fread(&p.mask,sizeof(p.mask),1,image);
		pic[i]=p;
		i++;
	}
int temp1,j1;
char flag;
FILE *O;
O=fopen("pic1.txt","w+");
int i1, j, temp = 0;
	int width = bih.width, height = bih.height;
	int image_array[bih.height][bih.width];
	FILE* pgmimg;
	pgmimg = fopen("pgmimg2.pgm", "wb");
	fprintf(pgmimg, "P2\n");
	fprintf(pgmimg, "%d %d\n", width, height);
	fprintf(pgmimg, "255\n");

i=head.offset;
for(temp1=0;temp1<bih.height;temp1++)
{
    for(int j1=0;j1<bih.width;j1++)
    {
       flag=(intensity(pic[i].red,pic[i].green,pic[i].blue)*0.003921)*72;
       image_array[temp1][j1]=flag;
       fprintf(test,"%c",flag);
       i++;
    }
}


	int count = 0;
	for (i1 = 0; i1 < height; i1++) {
		for (j = 0; j < width; j++) {
			temp = image_array[i1][j];

			// Writing the gray values in the 2D array to the file
			fprintf(pgmimg, "%d ", temp);
		}
		fprintf(pgmimg, "\n");
	}
	fclose(pgmimg);
	fclose(image);
	fclose(test);

	printf("\n");

	return 0;
}

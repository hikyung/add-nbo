#include <stddef.h> 
#include <stdint.h> 
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) 
{
	if (argc != 3) {
		printf("syntax : %s <file1> <file2>\n", argv[0]);
		printf("sample : add-nbo a.bin c.bin");
	}

	FILE * p;
	uint32_t a, b;

	p = fopen(argv[1], "r");
	if (p == NULL) perror("error bin 1\n");

	fread(&a, sizeof(uint32_t), 1, p);

	p = fopen(argv[2], "r");
	if (p == NULL) perror("error bin 2\n");

	fread(&b, sizeof(uint32_t), 1, p);

    a = ntohl(a);
    b = ntohl(b);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);

	fclose(p);
	return 0;
}

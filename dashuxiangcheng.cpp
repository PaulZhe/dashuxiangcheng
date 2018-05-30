#include <stdio.h>
#include <string.h>
#define N 100
void getdate(char *s, int *a)
{
	int i;  
    char date;  
    int len = strlen(s);  
    memset(a, 0, N * sizeof(int));
    for(i = 0; i < len; i++){  
        date = s[i];  
        a[len - 1 - i] = date - '0';//第一个字符存在int数组的最后一个位置  
    }  
}
void multiply(int *a, int *b, int *c)
{
	int i, j;
	memset( c, 0, 2*N*sizeof(int) );
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			c[i + j] += a[i] * b[j];
	//以下是移位与进位
	for(i = 0; i < 2 * N - 1; i++){
		c[i + 1] += c[i] / 10;
		c[i] = c[i] % 10;
	} 
}
int main()
{
	int a[N], b[N], c[2 * N];	
	char s1[N], s2[N];
	int j = 2 * N - 1, i;
	printf("请输入第一个数：");
	scanf("%s", s1);
	printf("请输入第二个数：");
	scanf("%s", s2);
	getdate(s1, a);	
	getdate(s2, b);
	multiply(a, b, c);
	while( c[j] == 0 )
		j--;
	for(i = j; i >= 0; i--)
		printf("%d", c[i]);
	printf("\n");
	return 0;
} 

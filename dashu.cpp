#include<stdio.h>
 #define N 101
//定义一个存放结果的字符数组
char sum[2*N + 1];

//将字符转换成数字
int char_to_int(char ch)
{
	switch(ch){
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}

//将数字转换成字符
char int_to_char(int ch)
{
	switch(ch){
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	}
}

//计算两个数之和
void add(int k,int k2, char one[], char two[])
{
	int i = k2;
	int max = k;
	int j = 0;
	int add_1[N + 1] = {0};  //用来判断是否有进位
	int c;

	//先计算两个有相同位数的部分
   	for(;i >= 0; max--,i--,j++) {
		c = char_to_int(one[max]) + char_to_int(two[i]) + add_1[j];
		if(c > 9) {
			sum[j] = int_to_char(c % 10);
			add_1[j + 1] = 1;

		}else {
			sum[j] = int_to_char(c);
		}
	}

	//再计算其中一个位数大于另外一个数的位数的部分
	i = k - k2 -1;
	for(;i >= 0; j++,i--,max--) {
		c = char_to_int(one[max]) + add_1[j];
		if(c > 9) {
			sum[j] = int_to_char(c % 10);
			add_1[j + 1] = 1;
		}else {
			sum[j] = int_to_char(c);
		}
	}

	//判断最后是否有进位
	if(add_1[j] == 1) {
		sum[j++] = '1';
	}
    sum[j] = '\0';
}

//将字符数组反转,因为加法是从低位开始相加的
void transvert(char str[],int n)
{
	char ch;
	int i;
	for(i = 0; i <= n / 2; i++)
	{
		ch = str[i];
		str[i] = str[n - i];
		str[n - i] = ch;
	}
}

//分别计算其中一个数的每一位与另外一个数的每一位相乘
void add_to_twoarray(int k, int k2,char one[],char two[])
{
	int i,j,c,m = 0;
	int line,over;
	char a[N + 1], b[2*N + 1]; //a[]放的是一位数和另外一个数每一位相乘的结果,
	                           //b[]放的是sum[]的结果
	int count_num;

	sum[0] = '0';
	sum[1] = '\0';
	for(i = k2; i >= 0; i--,m++) {
		int add_[N  + 1] = {0};

		for(line = 0; line < m; line++) {
				a[line] = '0';    //目的就是进行移位,因为每计算一次就会移位一次
		}

		for(j = k,over = 0; j >= 0; j--,line++,over++) {
			c = char_to_int(two[i]) * char_to_int(one[j]) + add_[over];
			add_[over + 1] = c / 10;
			a[line] = int_to_char(c % 10);
		}
		if(add_[over] > 0) {
			a[line++] = int_to_char(add_[over]);
		}
		a[line] = '\0';
		for(j = 0; sum[j] != '\0'; j++){
			b[j] = sum[j];
		}
		b[j] = '\0';
		count_num = j - 1;

		transvert(a,line-1);
		transvert(b,count_num);

		if(count_num > line -1) {
			add(count_num,line-1,b,a);
		}else {
			add(line-1,count_num,a,b);
		}
	}

	//最后求出结果的位数,然后进行反转输出
	for(j = 0; sum[j] != '\0'; j++){}
	transvert(sum,j -1);
	printf("%50s",sum);
    printf("\n\n");
}

//输入两个大数,判断哪个数比较大
void two_bignumber_add()
{
	char one[N],two[N];
	int i = 0,k,k2;

	printf("input a big number:\n");
	gets(one);
	printf("input another number:\n");
	gets(two);

	for(i = 0; one[i] != '\0'; i++){}
	k = i - 1;
	for(i = 0; two[i] != '\0'; i++){}
	k2 = i - 1;

	printf("\t\t--------------the result is:----------------");
	printf("\n%50s\n",one);
	printf("%50s\n",two);
	printf("\t\t--------------------------------------------\n");
	if(k >= k2) {
		add_to_twoarray(k,k2,one,two);
	}else if(k < k2) {
		add_to_twoarray(k2,k,two,one);
	}
}

int main()
{
	two_bignumber_add();

	return 0;
}

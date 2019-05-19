#include<stdio.h>
 #define N 101
//����һ����Ž�����ַ�����
char sum[2*N + 1];

//���ַ�ת��������
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

//������ת�����ַ�
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

//����������֮��
void add(int k,int k2, char one[], char two[])
{
	int i = k2;
	int max = k;
	int j = 0;
	int add_1[N + 1] = {0};  //�����ж��Ƿ��н�λ
	int c;

	//�ȼ�����������ͬλ���Ĳ���
   	for(;i >= 0; max--,i--,j++) {
		c = char_to_int(one[max]) + char_to_int(two[i]) + add_1[j];
		if(c > 9) {
			sum[j] = int_to_char(c % 10);
			add_1[j + 1] = 1;

		}else {
			sum[j] = int_to_char(c);
		}
	}

	//�ټ�������һ��λ����������һ������λ���Ĳ���
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

	//�ж�����Ƿ��н�λ
	if(add_1[j] == 1) {
		sum[j++] = '1';
	}
    sum[j] = '\0';
}

//���ַ����鷴ת,��Ϊ�ӷ��Ǵӵ�λ��ʼ��ӵ�
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

//�ֱ��������һ������ÿһλ������һ������ÿһλ���
void add_to_twoarray(int k, int k2,char one[],char two[])
{
	int i,j,c,m = 0;
	int line,over;
	char a[N + 1], b[2*N + 1]; //a[]�ŵ���һλ��������һ����ÿһλ��˵Ľ��,
	                           //b[]�ŵ���sum[]�Ľ��
	int count_num;

	sum[0] = '0';
	sum[1] = '\0';
	for(i = k2; i >= 0; i--,m++) {
		int add_[N  + 1] = {0};

		for(line = 0; line < m; line++) {
				a[line] = '0';    //Ŀ�ľ��ǽ�����λ,��Ϊÿ����һ�ξͻ���λһ��
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

	//�����������λ��,Ȼ����з�ת���
	for(j = 0; sum[j] != '\0'; j++){}
	transvert(sum,j -1);
	printf("%50s",sum);
    printf("\n\n");
}

//������������,�ж��ĸ����Ƚϴ�
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

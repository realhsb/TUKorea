#include <stdio.h>
typedef struct studentTag {
	char	name[20]; 	// ���ڹ迭�� �� �̸�
	int		age;	 	// ���̸� ��Ÿ���� ������
	double	gpa;		// ��� ������ ��Ÿ���� �Ǽ���
} student;
double AvgOfGPA(student data[], int num);
int main(void)
{
	double avg;
	student data[10] = {	{ "kim", 20, 4.0 },
							{ "choi", 20, 3.7 },
							{ "park", 20, 4.1 },
							{ "lee", 20, 3.5 },
							{ "jeong", 20, 3.3 },
							{ "song", 20, 3.2 },
							{ "hwang", 20, 3.6 },
							{ "koo", 20, 3.5 },
							{ "na", 20, 3.8 },
							{ "oh", 20, 3.9 }
	};

	avg = AvgOfGPA(data, 10);
	printf("> avg = %lf\n", avg);
	return 0;
}

double AvgOfGPA(student data[], int num)
{
	double result = 0.0;
	// �ش� code�� �ۼ��Ͻÿ�.


	return result;
}
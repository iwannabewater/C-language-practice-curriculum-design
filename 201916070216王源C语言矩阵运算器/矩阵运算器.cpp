#include<stdio.h>
#include<windows.h>
#include<math.h>

void caidan(void);//�˵�
int shuru(void);//����
void panding(void);//�˳�/ѭ���ж�

void jiajian(void);//�Ӽ�
void chengfa(void);//�˷�
void zhuanzhi(void);//ת��
void qiuni(void);//����
void qiuhanglieshi(void);//������ʽ
int hanglieshi(int **a,int n);//����ʽ�ݹ�

//������
int main(void)
{
	//�˵�
	caidan();
	//�������
	switch(shuru())
	{
		case 1: jiajian();      break;//�Ӽ�
		case 2: chengfa();      break;//�˷�
		case 3: zhuanzhi();     break;//ת��
		case 4: qiuni();        break;//����
		case 5: qiuhanglieshi();break;//������ʽ
		default: printf("���� �Զ��˳�"); 
		return 0; 
		break;
	}
	//�˳�/ѭ���ж�
	panding();

	return 0;
}

//�˵�
void caidan(void)
{
	printf("\n\t��ӭʹ�ñ������������\n");
	printf("\n\t���� 1 ���о���Ӽ�");
	printf("\n\t���� 2 ���о���˷�");
	printf("\n\t���� 3 ���о���ת��");
	printf("\n\t���� 4 ���о�������");
	printf("\n\t���� 5 ����������ʽ\n");
	printf("\n\t����������еĲ������\n\t");
}

//����
int shuru(void)
{
	int input = NULL ;
	scanf("%d",&input);//����input
	switch(input)
	{//��ջ����� 
		case 1: fflush(stdin); return 1 ; break;//��ջ�����������
		case 2: fflush(stdin); return 2 ; break;
		case 3: fflush(stdin); return 3 ; break;
		case 4: fflush(stdin); return 4 ; break;
		case 5: fflush(stdin); return 5 ; break;
		default : fflush(stdin); printf("\n\t��������ȷ�ı��\n\t"); shuru() ; break;//����1��5 �������� ������������
	}
}

//�˳�/ѭ���ж�
void panding(void)
{
	int input = NULL ;
	printf("\n\t����1�ص���ʼ�˵� ���������˳�����\n\t");
	scanf("%d",&input);
	if(input==1)
	{
		system("cls");//����
		main();
	}
	else
	{
		exit(0);//�˳�
	}
}

//�Ӽ�///////////////////////////////////////////////////////////////////////////
void jiajian(void)
{
	int hang = 0 , lie = 0 , fuhao = -1 , input = NULL;//�к��� �ͷ���
	//��������
	printf("\n\t������������\n\t");
	scanf("%d",&hang);
	getchar();//��ջ�����
	
	printf("\t������������\n\t");
	scanf("%d",&lie);
	getchar();
	
	
	
	//���� hang*lie ��С��������ά���� 
	int **jvzhen1 = (int**)malloc(hang*sizeof(int*));//jvzhen1[hang][lie];���붯̬�����ڴ� 
	int **jvzhen2 = (int**)malloc(hang*sizeof(int*));//jvzhen2[hang][lie];
	for(int a=0;a<hang;a++)
	{
		jvzhen1[a] = (int*)malloc(lie*sizeof(int));
		jvzhen2[a] = (int*)malloc(lie*sizeof(int));
	}
	//����1
	printf("\n\t�������һ������(�밴�й淶����)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//����2
	printf("������ڶ�������(�밴�й淶����)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen2[a][b]);
		}
		printf("\t");
	}
	//�жϼӼ�
	printf("����1���о���ӷ� �����������м���\n\t");
	scanf("%d",&input);
	if(input==1)
	{
		fuhao = 1;//���ű���
	}
	else 
	{
		fuhao = -1;
	}
	//����
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			jvzhen1[a][b] += (fuhao*jvzhen2[a][b]);
		}
	}
	//������
	printf("\t���Ϊ\n\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			printf("%-5d ",jvzhen1[a][b]);
		}
		printf("\n\n\t");
	}
	//free���� jvzhen[hang][lie]                         
	for(int a=0;a<hang;a++)//�ͷŶ�̬�ռ�                            
	{                                                                
		free(jvzhen1[a]);//�ͷ�lie 
		free(jvzhen2[a]);//hang�� 
	}
	free(jvzhen1);//�ͷ�hang 
	free(jvzhen2);
}

//�˷�///////////////////////////////////////////////////////////////////////////
void chengfa(void)
{
	int hang = 0 , lie = 0 , lie2 = 0 , temp =0;//�к���
	//��������
	printf("\n\t��������߾������\n\t");
	scanf("%d",&hang);
	getchar();//��ջ�����
	printf("\t��������߾������\n\t");
	scanf("%d",&lie);
	getchar();
	printf("\t�������ұ߾������\n\t");
	scanf("%d",&lie2);
	getchar();
	//����������ά����   
	int **jvzhen1 = (int**)malloc(hang*sizeof(int*));     
	int **jvzhen2 = (int**)malloc(lie*sizeof(int*));
	int **jvzhen3 = (int**)malloc(hang*sizeof(int*));
	for(int a=0;a<hang;a++)
	{
		jvzhen1[a] = (int*)malloc(lie*sizeof(int)); //hang * lie
		jvzhen3[a] = (int*)malloc(lie2*sizeof(int));//hang * lie2
	}
	for(int a=0;a<lie;a++)
	{
		jvzhen2[a] = (int*)malloc(lie2*sizeof(int));//lie * lie2
	}
	//����1
	printf("\n\t�������һ������(�밴�й淶����)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//����2
	printf("������ڶ�������(�밴�й淶����)\n\t");
	for(int a=0;a<lie;a++)
	{
		for(int b=0;b<lie2;b++)
		{
			scanf("%d",&jvzhen2[a][b]);
		}
		printf("\t");
	}
	//����
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie2;b++)
		{
			temp = 0;
			for(int c=0;c<lie;c++)
			{
				temp += ( jvzhen1[a][c]*jvzhen2[c][b] );
			}
			jvzhen3[a][b]=temp;
		}
	}
	//������
	printf("���Ϊ\n\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie2;b++)
		{
			printf("%-5d ",jvzhen3[a][b]);
		}
		printf("\n\n\t");
	}
	//free����
	for(int a=0;a<hang;a++)
	{
		free(jvzhen1[a]);
		free(jvzhen3[a]);
	}
	for(int a=0;a<lie;a++)
	{
		free(jvzhen2[a]);
	}
	free(jvzhen1);
	free(jvzhen2);
	free(jvzhen3);
}

//ת��///////////////////////////////////////////////////////////////////////////
void zhuanzhi(void)
{
	int hang = 0 , lie = 0 ;//�к���
	//��������
	printf("\n\t������������\n\t");
	scanf("%d",&hang);
	getchar();//��ջ�����
	printf("\t������������\n\t");
	scanf("%d",&lie);
	getchar();
	//����������ά����
	int **jvzhen1 = (int**)malloc(hang*sizeof(int*));//hang*lie
	int **jvzhen2 = (int**)malloc(lie*sizeof(int*));//lie*hang
	for(int a=0;a<hang;a++)
	{
		jvzhen1[a] = (int*)malloc(lie*sizeof(int));
	}
	for(int a=0;a<lie;a++)
	{
		jvzhen2[a] = (int*)malloc(hang*sizeof(int));
	}
	//����1
	printf("\n\t���������(�밴�й淶����)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//����
	for(int a=0;a<lie;a++)
	{
		for(int b=0;b<hang;b++)
		{
			jvzhen2[a][b]=jvzhen1[b][a];
		}
	}
	//������
	printf("���Ϊ\n\n\t");
	for(int a=0;a<lie;a++)
	{
		for(int b=0;b<hang;b++)
		{
			printf("%-5d ",jvzhen2[a][b]);
		}
		printf("\n\n\t");
	}
	//free����
	for(int a=0;a<hang;a++)
	{
		free(jvzhen1[a]);
	}
	for(int a=0;a<lie;a++)
	{
		free(jvzhen2[a]);
	}
	free(jvzhen1);
	free(jvzhen2);
}

//����///////////////////////////////////////////////////////////////////////////
/*�㷨�ο�  https://www.cnblogs.com/rollenholt/articles/2050662.html*/
void qiuni(void)
{
	//����
	int jie,jie2,i,j,k;
    printf("\n\t���������Ľ���\n\t");
    scanf("%d",&jie);
    jie2 = jie*2;
    //�½�3������  2�� jie*jie   1�� jie*(2*jie)
    double **jvzhen1 = (double**)malloc(jie*sizeof(double*));//����  jie*jie
	double **jvzhen2 = (double**)malloc(jie*sizeof(double*));//���  jie*jie
	double **jvzhen3 = (double**)malloc(jie*sizeof(double*));//��չ
	for(int a=0;a<jie;a++)
	{
		jvzhen1[a] = (double*)malloc(jie*sizeof(double));//
		jvzhen2[a] = (double*)malloc(jie*sizeof(double));
		jvzhen3[a] = (double*)malloc(2*jie*sizeof(double));
	}
   	//�������
    printf("\n\t���������(�밴�й淶����)\n\t");
    for(i=0;i<jie;i++)
    {
        for(j=0;j<jie;j++)
        {
            scanf("%lf",&jvzhen1[i][j]);
            jvzhen3[i][j]=jvzhen1[i][j];//�̳�
        }
        printf("\t");
    }
    /*****************��չ����***********************/
    for(i=0;i<jie;i++)
    {
        for(j=jie;j<jie2;j++)
        {
            if(i==(j-jie))
            {
                jvzhen3[i][j]=1;
            }
            else
            {
                jvzhen3[i][j]=0;
            }
        }
    }
    /*****************��չ����***********************/

    /*****************����ģ��***********************/
    for(i=0;i<jie;i++)
    {
        if(jvzhen3[i][i]==0)
        {
            for(k=i;k<jie;k++)
            {
                if(jvzhen3[k][i]!=0)
                {
                    for(int j=0;j<jie2;j++)
                    {
                        double temp;
                        temp=jvzhen3[i][j];
                        jvzhen3[i][j]=jvzhen3[k][j];
                        jvzhen3[k][j]=temp;
                    }
                    break;
                }
            }
            if(k==jie)
            {
                printf("�þ��󲻿���");
				panding();//�ж�
				break;
            }
        }
        for(j=jie2-1;j>=i;j--)
        {
            jvzhen3[i][j]/=jvzhen3[i][i];
        }
        for(k=0;k<jie;k++)
        {
            if(k!=i)
            {
                double temp=jvzhen3[k][i];
                for(j=0;j<jie2;j++)
                {
                    jvzhen3[k][j]-=temp*jvzhen3[i][j];
                }
            }
        }
    }
    /*****************����ģ��***********************/

    /*****************�������***********************/
    for(i=0;i<jie;i++)
    {
        for(j=jie;j<jie2;j++)
        {
            jvzhen2[i][j-jie]=jvzhen3[i][j];
        }
    }
    /*****************�������***********************/
    printf("���Ϊ\n\n\t");
    for(i=0;i<jie;i++)
    {
        for(j=0;j<jie;j++)
        {
            printf("%-6.2lf ",jvzhen2[i][j]);
        }
        printf("\n\t");
    }
    //free����
	for(int a=0;a<jie;a++)
	{
		free(jvzhen1[a]);
		free(jvzhen2[a]);   //�ͷŶ�̬�ڴ� 
		free(jvzhen3[a]);
	}
	free(jvzhen1);
	free(jvzhen2);
	free(jvzhen3);
}

//������ʽ //////////////////////////////////////////////////////////////////////
void qiuhanglieshi(void)
{
	int jie = 0 ;//����
	//��������
	printf("\n\t���������Ľ���\n\t");
	scanf("%d",&jie);
	getchar();//��ջ�����
	//����һ����ά����
	int **jvzhen1 = (int**)malloc(jie*sizeof(int*));//����
	for(int a=0;a<jie;a++)
	{
		jvzhen1[a] = (int*)malloc(jie*sizeof(int));
	}
	//����1
	printf("\n\t���������(�밴�й淶����)\n\t");
	for(int a=0;a<jie;a++)
	{
		for(int b=0;b<jie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//������
	printf("���Ϊ\n\n\t");
	printf("%d\n", hanglieshi(jvzhen1,jie));
	printf("\n\n\t");

	//free����
	for(int a=0;a<jie;a++)
	{
		free(jvzhen1[a]);
	}
	free(jvzhen1);
}

//����ʽ�ݹ�
int hanglieshi(int **a,int n)
{
	int i,j,k;
	int len;//������ʽ�Ľ�
	int s=0;
	len = n-1;
	//���ն��壬��ʼ��һ��������ʽ����Ŀռ�
	int **p = (int **)malloc(sizeof(int *)*len);
	for(i=0;i<len;i++)
	{
		p[i] = (int *)malloc(sizeof(int)*len);
	}
	//��Ϊ1�����ն������
	if(n==1)
	{
		return a[0][0];
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<len;i++)
		{
			for(j=0;j<len;j++)
			{
				if(i<k)
				{
					p[i][j] = a[i][j+1];//��ʼ��������ʽ��ֵ
				}
				if(i>=k)
				{
					p[i][j] = a[i+1][j+1];
				}
			}
		}
		s += (int)pow(-1,k) * a[k][0]* hanglieshi(p,len);//�ݹ����
	}
	for(i=0;i<len;i++)
	{
		free(p[i]);
	}
	free(p);
	return s;
}

















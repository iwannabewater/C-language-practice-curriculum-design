#include<stdio.h>
#include<windows.h>
#include<math.h>

void caidan(void);//菜单
int shuru(void);//输入
void panding(void);//退出/循环判定

void jiajian(void);//加减
void chengfa(void);//乘法
void zhuanzhi(void);//转置
void qiuni(void);//求逆
void qiuhanglieshi(void);//求行列式
int hanglieshi(int **a,int n);//行列式递归

//主函数
int main(void)
{
	//菜单
	caidan();
	//检测输入
	switch(shuru())
	{
		case 1: jiajian();      break;//加减
		case 2: chengfa();      break;//乘法
		case 3: zhuanzhi();     break;//转置
		case 4: qiuni();        break;//求逆
		case 5: qiuhanglieshi();break;//求行列式
		default: printf("错误 自动退出"); 
		return 0; 
		break;
	}
	//退出/循环判定
	panding();

	return 0;
}

//菜单
void caidan(void)
{
	printf("\n\t欢迎使用本矩阵运算程序\n");
	printf("\n\t输入 1 进行矩阵加减");
	printf("\n\t输入 2 进行矩阵乘法");
	printf("\n\t输入 3 进行矩阵转置");
	printf("\n\t输入 4 进行矩阵求逆");
	printf("\n\t输入 5 求矩阵的行列式\n");
	printf("\n\t请输入想进行的操作编号\n\t");
}

//输入
int shuru(void)
{
	int input = NULL ;
	scanf("%d",&input);//接收input
	switch(input)
	{//清空缓存区 
		case 1: fflush(stdin); return 1 ; break;//清空缓冲区并返回
		case 2: fflush(stdin); return 2 ; break;
		case 3: fflush(stdin); return 3 ; break;
		case 4: fflush(stdin); return 4 ; break;
		case 5: fflush(stdin); return 5 ; break;
		default : fflush(stdin); printf("\n\t请输入正确的编号\n\t"); shuru() ; break;//输入1到5 正常进行 否则重新输入
	}
}

//退出/循环判定
void panding(void)
{
	int input = NULL ;
	printf("\n\t输入1回到初始菜单 输入其他退出程序\n\t");
	scanf("%d",&input);
	if(input==1)
	{
		system("cls");//清屏
		main();
	}
	else
	{
		exit(0);//退出
	}
}

//加减///////////////////////////////////////////////////////////////////////////
void jiajian(void)
{
	int hang = 0 , lie = 0 , fuhao = -1 , input = NULL;//行和列 和符号
	//输入行列
	printf("\n\t请输入矩阵的行\n\t");
	scanf("%d",&hang);
	getchar();//清空缓存区
	
	printf("\t请输入矩阵的列\n\t");
	scanf("%d",&lie);
	getchar();
	
	
	
	//建立 hang*lie 大小的两个二维数组 
	int **jvzhen1 = (int**)malloc(hang*sizeof(int*));//jvzhen1[hang][lie];申请动态分配内存 
	int **jvzhen2 = (int**)malloc(hang*sizeof(int*));//jvzhen2[hang][lie];
	for(int a=0;a<hang;a++)
	{
		jvzhen1[a] = (int*)malloc(lie*sizeof(int));
		jvzhen2[a] = (int*)malloc(lie*sizeof(int));
	}
	//输入1
	printf("\n\t请输入第一个矩阵(请按行规范输入)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//输入2
	printf("请输入第二个矩阵(请按行规范输入)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen2[a][b]);
		}
		printf("\t");
	}
	//判断加减
	printf("输入1进行矩阵加法 输入其他进行减法\n\t");
	scanf("%d",&input);
	if(input==1)
	{
		fuhao = 1;//符号变正
	}
	else 
	{
		fuhao = -1;
	}
	//运算
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			jvzhen1[a][b] += (fuhao*jvzhen2[a][b]);
		}
	}
	//输出结果
	printf("\t结果为\n\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			printf("%-5d ",jvzhen1[a][b]);
		}
		printf("\n\n\t");
	}
	//free数组 jvzhen[hang][lie]                         
	for(int a=0;a<hang;a++)//释放动态空间                            
	{                                                                
		free(jvzhen1[a]);//释放lie 
		free(jvzhen2[a]);//hang次 
	}
	free(jvzhen1);//释放hang 
	free(jvzhen2);
}

//乘法///////////////////////////////////////////////////////////////////////////
void chengfa(void)
{
	int hang = 0 , lie = 0 , lie2 = 0 , temp =0;//行和列
	//输入行列
	printf("\n\t请输入左边矩阵的行\n\t");
	scanf("%d",&hang);
	getchar();//清空缓存区
	printf("\t请输入左边矩阵的列\n\t");
	scanf("%d",&lie);
	getchar();
	printf("\t请输入右边矩阵的列\n\t");
	scanf("%d",&lie2);
	getchar();
	//建立三个二维数组   
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
	//输入1
	printf("\n\t请输入第一个矩阵(请按行规范输入)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//输入2
	printf("请输入第二个矩阵(请按行规范输入)\n\t");
	for(int a=0;a<lie;a++)
	{
		for(int b=0;b<lie2;b++)
		{
			scanf("%d",&jvzhen2[a][b]);
		}
		printf("\t");
	}
	//运算
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
	//输出结果
	printf("结果为\n\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie2;b++)
		{
			printf("%-5d ",jvzhen3[a][b]);
		}
		printf("\n\n\t");
	}
	//free数组
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

//转置///////////////////////////////////////////////////////////////////////////
void zhuanzhi(void)
{
	int hang = 0 , lie = 0 ;//行和列
	//输入行列
	printf("\n\t请输入矩阵的行\n\t");
	scanf("%d",&hang);
	getchar();//清空缓存区
	printf("\t请输入矩阵的列\n\t");
	scanf("%d",&lie);
	getchar();
	//建立两个二维数组
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
	//输入1
	printf("\n\t请输入矩阵(请按行规范输入)\n\t");
	for(int a=0;a<hang;a++)
	{
		for(int b=0;b<lie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//运算
	for(int a=0;a<lie;a++)
	{
		for(int b=0;b<hang;b++)
		{
			jvzhen2[a][b]=jvzhen1[b][a];
		}
	}
	//输出结果
	printf("结果为\n\n\t");
	for(int a=0;a<lie;a++)
	{
		for(int b=0;b<hang;b++)
		{
			printf("%-5d ",jvzhen2[a][b]);
		}
		printf("\n\n\t");
	}
	//free数组
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

//求逆///////////////////////////////////////////////////////////////////////////
/*算法参考  https://www.cnblogs.com/rollenholt/articles/2050662.html*/
void qiuni(void)
{
	//输入
	int jie,jie2,i,j,k;
    printf("\n\t请输入矩阵的阶数\n\t");
    scanf("%d",&jie);
    jie2 = jie*2;
    //新建3个矩阵  2个 jie*jie   1个 jie*(2*jie)
    double **jvzhen1 = (double**)malloc(jie*sizeof(double*));//输入  jie*jie
	double **jvzhen2 = (double**)malloc(jie*sizeof(double*));//结果  jie*jie
	double **jvzhen3 = (double**)malloc(jie*sizeof(double*));//扩展
	for(int a=0;a<jie;a++)
	{
		jvzhen1[a] = (double*)malloc(jie*sizeof(double));//
		jvzhen2[a] = (double*)malloc(jie*sizeof(double));
		jvzhen3[a] = (double*)malloc(2*jie*sizeof(double));
	}
   	//输入矩阵
    printf("\n\t请输入矩阵(请按行规范输入)\n\t");
    for(i=0;i<jie;i++)
    {
        for(j=0;j<jie;j++)
        {
            scanf("%lf",&jvzhen1[i][j]);
            jvzhen3[i][j]=jvzhen1[i][j];//继承
        }
        printf("\t");
    }
    /*****************扩展矩阵***********************/
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
    /*****************扩展矩阵***********************/

    /*****************求逆模块***********************/
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
                printf("该矩阵不可逆");
				panding();//判定
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
    /*****************求逆模块***********************/

    /*****************导出结果***********************/
    for(i=0;i<jie;i++)
    {
        for(j=jie;j<jie2;j++)
        {
            jvzhen2[i][j-jie]=jvzhen3[i][j];
        }
    }
    /*****************导出结果***********************/
    printf("结果为\n\n\t");
    for(i=0;i<jie;i++)
    {
        for(j=0;j<jie;j++)
        {
            printf("%-6.2lf ",jvzhen2[i][j]);
        }
        printf("\n\t");
    }
    //free数组
	for(int a=0;a<jie;a++)
	{
		free(jvzhen1[a]);
		free(jvzhen2[a]);   //释放动态内存 
		free(jvzhen3[a]);
	}
	free(jvzhen1);
	free(jvzhen2);
	free(jvzhen3);
}

//求行列式 //////////////////////////////////////////////////////////////////////
void qiuhanglieshi(void)
{
	int jie = 0 ;//阶数
	//输入行列
	printf("\n\t请输入矩阵的阶数\n\t");
	scanf("%d",&jie);
	getchar();//清空缓存区
	//建立一个二维数组
	int **jvzhen1 = (int**)malloc(jie*sizeof(int*));//输入
	for(int a=0;a<jie;a++)
	{
		jvzhen1[a] = (int*)malloc(jie*sizeof(int));
	}
	//输入1
	printf("\n\t请输入矩阵(请按行规范输入)\n\t");
	for(int a=0;a<jie;a++)
	{
		for(int b=0;b<jie;b++)
		{
			scanf("%d",&jvzhen1[a][b]);
		}
		printf("\t");
	}
	//输出结果
	printf("结果为\n\n\t");
	printf("%d\n", hanglieshi(jvzhen1,jie));
	printf("\n\n\t");

	//free数组
	for(int a=0;a<jie;a++)
	{
		free(jvzhen1[a]);
	}
	free(jvzhen1);
}

//行列式递归
int hanglieshi(int **a,int n)
{
	int i,j,k;
	int len;//子行列式的阶
	int s=0;
	len = n-1;
	//按照定义，初始化一个子行列式数组的空间
	int **p = (int **)malloc(sizeof(int *)*len);
	for(i=0;i<len;i++)
	{
		p[i] = (int *)malloc(sizeof(int)*len);
	}
	//阶为1，按照定义计算
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
					p[i][j] = a[i][j+1];//初始化子行列式的值
				}
				if(i>=k)
				{
					p[i][j] = a[i+1][j+1];
				}
			}
		}
		s += (int)pow(-1,k) * a[k][0]* hanglieshi(p,len);//递归计算
	}
	for(i=0;i<len;i++)
	{
		free(p[i]);
	}
	free(p);
	return s;
}

















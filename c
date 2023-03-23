#include<stdio.h>

int sift(int a )
	{
	//printf("输入一个数:\n"); 
	//scanf("%d",&a);
	if(a%2!=0)
	{
		//printf("是奇数\n");
		if(a>=1&&a<=100)
		   {
		    //printf("%d\n",a);
		    return a;
		}
	}
	else 
	    return 0; 
    }
int main()
{
	int i,b;
	for(i=0;i<100;i++)
	  {
	   b=i;
	   b=sift(b);  
	   printf("%d\n",b);
       }    
}
//#include<stdio.h>      用来判断是否为奇数 
//int main()
//{
//
//
//    int a;
//   printf("输入一个数:\n"); 
//	  scanf("%d",&a);
//	  if(a%2!=0)
//	  {
//		  printf("是奇数\n");
//		  if(a>=1&&a<=100)
//		     {
//		       printf("%d\n",a);
//		       return a;
//		    }
//	    }
//	   else 
//	      printf("不是奇数\n");
//}	


//#include<stdio.h>    当a=1的时候,循环一直进行 
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	while(a)
//	  printf("hhaha\n");
//}

//#include<stdio.h>     检测continue的用法 
//int main()
//{
//	int i=0;
//	while(i<=10)
//	{
//		i++;
//		if(i==5)
//		  continue;
//		printf("%d",i);
//	}
//}

//#include<stdio.h>       EOF-end of file-> -1  
//int main()              输入ctrl+z
//{
//	int ch=0;
//	while((ch=getchar())!=EOF)
//		putchar(ch);
//	
//}

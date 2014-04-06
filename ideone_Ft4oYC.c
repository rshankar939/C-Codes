#include <stdio.h>
#define mod 1000000007

int inline multiply(int result,int base)
{
	int x = 0,y = result%mod;
	while(base > 0)
	{
		if(base%2 == 1) x = (x + y)%mod;
		y = (y*2)%mod;
		base /= 2;
	}
	return x%mod;
}

int inline getans(int base, int exponent)
{
	int result = 1;
	while(exponent > 0)
	{
		if(exponent % 2 == 1) result = multiply(result,base);
		exponent = exponent >> 1;
		base = multiply(base,base);
	}
	return result;
}

int main(void) {
	// your code goes here
	int test,n,i,max,count,temp;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		
		scanf("%d",&temp);
		max = temp;
		count = 1;
		if(n == 1){
			printf("1\n");
			continue;
		}
		
		for(i=1;i<n;i++){
			scanf("%d",&temp);
			if(temp>max){
				max = temp;
				count = 1;
			}else if(max == temp){
				count++;
			}
		}
		
		if(count == n){
			printf("%d\n",(getans(2,count)-1)%mod);
		}else{
			printf("%d\n",(getans(2,count)-1)%mod);
		}
	}
	return 0;
}

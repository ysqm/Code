# include <cstdio>
const int A=999998,B=999989,C=999899;
int a[50010],b[50010],n,k,sum=0,x,y,z;
inline int cut(int i){
	return a[i]==i?a[i]:a[i]=cut(a[i]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(register int i=1;i<=n;i++) a[i]=i;
	while(k--){
		scanf("%d%d%d",&x,&y,&z);
		if(y > n || z > n) {sum++;continue;}
		if(x==1){
			int dy=cut(y),dz=cut(dz); 
			if((b[dy]&&b[dz])&&b[dy]!=b[dz]//�ж��ǲ����Ѻϲ�
			){sum++;continue;}//�жϴ�ǰ�ǲ����Ѿ����� 
			else{
				a[dy] = a[dz];
			}
		}
		else {
			int dy=cut(y),dz=cut(dz);
			if(b[dy] == b[dz]){sum++;continue;}
			if(b[dy] && b[dz]){
				if(b[dy] == A){
					if(b[dz] == B){continue;}
					else {sum++;continue;}
				}
				else if(b[dy] == B){
					if(b[dz] == C){continue;}
					else {sum++;continue;}
				}
				else if(b[dy] == C){
					if(b[dz] == A){continue;}
					else {sum++;continue;}
				}
			}
			else if(b[dy]){
				if(b[dy] == A){
					b[dz] = B;
					continue;
				}
				else if(b[dy] == B){
					b[dz] = C;
					continue;
				}
				else if(b[dy] == C){
					b[dz] = A;
					continue;
				}
			}
			else if(b[dz]){
				if(b[dz] == B){
					b[dy] = A;
					continue;
				}
				else if(b[dz] == C){
					b[dy] = B;
					continue;
				}
				else if(b[dz] == A){
					b[dy] = C;
					continue;
				}
			}
		}
	}
	printf("%d",sum);
	return 0;
} 

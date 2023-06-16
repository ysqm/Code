extern "C" int Seniorious(int);
extern "C" int Chtholly(int n, int c)
{
	register int l = 0,r = n,mid,d;
	while(l < r)
	{
		mid = (l+r)>>1;d = Seniorious(mid);
		if(d == 0) return mid;
		else if(d == -1) l = mid+1;
		else r = mid-1;
	}
	return l; 
}
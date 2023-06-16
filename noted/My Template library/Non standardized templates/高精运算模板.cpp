# include <cstdio>
# include <vector>
# include <cstring>
# include <iostream>
# define REG register
using namespace std;
struct Big_Integer
{
	static const int BIT = 1000;
	static const int DIGIT = 100;
	
	bool insignia;
	
	int BIG_INTEGER[DIGIT + 1],digit;
	
	Big_Integer(){memset(BIG_INTEGER,0,sizeof(BIG_INTEGER));digit = 1;insignia = 1;}
	
	void clear(){memset(BIG_INTEGER,0,sizeof(BIG_INTEGER));digit = 1;insignia = 1;}
	
	bool operator < (const Big_Integer& B)const 
	{
		if(insignia != B.insignia){
			if(insignia) return false;
			else return true;
		}
		if(insignia){
			if(digit > B.digit) return false;
			if(digit < B.digit) return true;
			else for(REG int i = B.digit; i > 0 ; --i)
					if(BIG_INTEGER[i] < B.BIG_INTEGER[i]) return true;
					 else if(BIG_INTEGER[i] > B.BIG_INTEGER[i]) return false;
		}
		else {
			if(digit > B.digit) return true;
			if(digit < B.digit) return false;
			else for(REG int i = B.digit; i > 0 ; --i)
					if(BIG_INTEGER[i] < B.BIG_INTEGER[i]) return false;
					 else if(BIG_INTEGER[i] > B.BIG_INTEGER[i]) return true;
		}
		return false;
	}
	
	bool operator <= (const Big_Integer& B)const 
	{
		if(insignia != B.insignia){
			if(insignia) return false;
			else return true;
		}
		if(insignia){
			if(digit > B.digit) return false;
			if(digit < B.digit) return true;
			else for(REG int i = B.digit; i > 0 ; --i)
					if(BIG_INTEGER[i] < B.BIG_INTEGER[i]) return true;
					 else if(BIG_INTEGER[i] > B.BIG_INTEGER[i]) return false;
		}
		else {
			if(digit > B.digit) return true;
			if(digit < B.digit) return false;
			else for(REG int i = B.digit; i > 0 ; --i)
					if(BIG_INTEGER[i] < B.BIG_INTEGER[i]) return false;
					 else if(BIG_INTEGER[i] > B.BIG_INTEGER[i]) return true;
		}
		return true;
	}
	
	bool operator == (const Big_Integer& B)const 
	{	
		if(insignia != B.insignia) return false;
		if(digit > B.digit) return false;
		if(digit < B.digit) return false;
		else for(REG int i = B.digit; i > 0 ; --i)
				if(BIG_INTEGER[i] != B.BIG_INTEGER[i]) return false;
		return true;
	}
	
	bool operator > (const Big_Integer& B)const 
	{
		if(insignia != B.insignia){
			if(insignia) return true;
			else return false;
		}
		if(insignia){
			if(this->digit < B.digit) return false;
			if(this->digit > B.digit) return true;
			else for(REG int i = B.digit; i > 0 ; --i)
					if(this->BIG_INTEGER[i] > B.BIG_INTEGER[i]) return true;
					 else if(this->BIG_INTEGER[i] < B.BIG_INTEGER[i]) return false;
		}
		else{
			if(this->digit < B.digit) return true;
			if(this->digit > B.digit) return false;
			else for(REG int i = B.digit; i > 0 ; --i)
					if(this->BIG_INTEGER[i] > B.BIG_INTEGER[i]) return false;
					 else if(this->BIG_INTEGER[i] < B.BIG_INTEGER[i]) return true;
		}
		return false;
	}
	
	bool operator >= (const Big_Integer& B)const 
	{
		if(insignia != B.insignia){
			if(insignia) return true;
			else return false;
		}
		if(insignia){
			if(this->digit < B.digit) return false;
			if(this->digit > B.digit) return true;
			else for(REG int i = B.digit; i > 0 ; ++i)
					if(this->BIG_INTEGER[i] > B.BIG_INTEGER[i]) return true;
					 else if(this->BIG_INTEGER[i] < B.BIG_INTEGER[i]) return false;
		}
		else{
			if(this->digit < B.digit) return true;
			if(this->digit > B.digit) return false;
			else for(REG int i = B.digit; i > 0 ; ++i)
					if(this->BIG_INTEGER[i] > B.BIG_INTEGER[i]) return false;
					 else if(this->BIG_INTEGER[i] < B.BIG_INTEGER[i]) return true;
		}
		return true;
	}
	
	void operator = (const long long& b)
	{
		clear();
		long long base = BIT,B = b;
		if (B < 0) {B = 0 - B;insignia = 0;}
		while(B){
			BIG_INTEGER[digit++] = B % base;
			B /= BIT;
		}
		while(!BIG_INTEGER[digit] && digit > 1) digit--;
	}
	
	void operator = (const int& b)
	{
		clear();
		int base = BIT,B = b;
		if (B < 0) {B = 0 - B;insignia = 0;}
		while(B){
			BIG_INTEGER[digit++] = B % base;
			B /= BIT;
		}
		while(!BIG_INTEGER[digit] && digit > 1) digit--;
	}
	
	void GET()
	{
		char buf[DIGIT * BIT/10 + 42];
		scanf("%s",buf);
		int len = strlen(buf),dig = 0;
		clear();
		while(len){
			dig++;
			if(buf[len - 1] == '-') {insignia = 0;return;}
			switch(dig % 3)
			{
				case 1 :
						BIG_INTEGER[digit] += (buf[--len] - 48);
						break;
				case 2 :
						BIG_INTEGER[digit] += (buf[--len] - 48) * 10;
						break;
				case 0 :
						BIG_INTEGER[digit++] += (buf[--len] - 48) * 100;
						break;
			}
		}
		while(BIG_INTEGER[digit] == 0 && digit > 1) digit--;
	}
	
	void PUT()
	{
		if(!insignia) putchar('-');
		while(BIG_INTEGER[digit] == 0 && digit > 1) digit--;
		int len = digit - 1;
		printf("%d",BIG_INTEGER[digit]);
		while(len) printf("%03d",BIG_INTEGER[len--]);
		printf("\n");
	}
	
	void operator -= (const Big_Integer& b)
	{
		Big_Integer B = b;bool flag = false;
		if(insignia != b.insignia) {
			B.insignia = insignia;
			*this += B;
			return ;
		}
		if(*this == B){clear();return;}
		if(*this < B && insignia){Big_Integer C = B;B = *this;*this = C;flag = true;}
		else if(*this > B && !insignia){Big_Integer C = B;B = *this;*this = C;flag = true;}
		int len = max(digit,B.digit);
		REG int i = 1;
		for(; i <= len ; ++i)
			BIG_INTEGER[i] -= B.BIG_INTEGER[i];
		i = 1;
		while(BIG_INTEGER[i] < 0) {BIG_INTEGER[i] += BIT;BIG_INTEGER[i + 1] -= 1;++i;}
		while(BIG_INTEGER[digit + 1]) digit++;
		while(BIG_INTEGER[digit] == 0 && digit > 1) digit--;
		if(flag) insignia = !insignia;
		if(digit == 1 && BIG_INTEGER[1] == 0) insignia = 1;
	}
	
	void operator += (const Big_Integer& B)
	{
		if(insignia != B.insignia) {
			Big_Integer C = B;C.insignia = insignia;
			*this -= C;
			return ;
		}
		int len = max(digit,B.digit);
		REG int i = 1;
		for(; i <= len ; ++i)
			BIG_INTEGER[i] += B.BIG_INTEGER[i];
		i = 1;
		while(BIG_INTEGER[i] >= BIT) {BIG_INTEGER[i] -= BIT;BIG_INTEGER[i + 1] += 1;++i;}
		while(BIG_INTEGER[digit + 1]) digit++;
		while(BIG_INTEGER[digit] == 0 && digit > 1) digit--;
		if(digit == 1 && BIG_INTEGER[1] == 0) insignia = 1;
	}
	
	Big_Integer operator + (const Big_Integer& B) const
	{
		Big_Integer D = *this;
		if(D.insignia != B.insignia) {
			Big_Integer C = B;C.insignia = D.insignia;
			D -= C;
			return D;
		}
		int len = max(D.digit,B.digit);
		REG int i = 1;
		for(; i <= len ; ++i)
			D.BIG_INTEGER[i] += B.BIG_INTEGER[i];
		i = 1;
		while(D.BIG_INTEGER[i] >= BIT) {D.BIG_INTEGER[i] -= BIT;D.BIG_INTEGER[i + 1] += 1;++i;}
		while(D.BIG_INTEGER[D.digit + 1]) D.digit++;
		while(D.BIG_INTEGER[D.digit] == 0 && D.digit > 1) D.digit--;
		if(D.digit == 1 && D.BIG_INTEGER[1] == 0) D.insignia = 1;
		return D;
	}
	
	Big_Integer operator - (const Big_Integer& b) const
	{
		Big_Integer D = *this;
		Big_Integer B = b;bool flag = false;
		if(D.insignia != b.insignia) {
			B.insignia = D.insignia;
			D += B;
			return D;
		}
		if(D == B){D.clear();return D;}
		if(D < B && D.insignia){Big_Integer C = B;B = D;D = C;flag = true;}
		else if(D > B && !D.insignia){Big_Integer C = B;B = D;D = C;flag = true;}
		int len = max(D.digit,B.digit);
		REG int i = 1;
		for(; i <= len ; ++i)
			D.BIG_INTEGER[i] -= B.BIG_INTEGER[i];
		i = 1;
		while(i <= D.digit){
			while(D.BIG_INTEGER[i] < 0) {D.BIG_INTEGER[i] += BIT;D.BIG_INTEGER[i + 1] -= 1;}
			++i;
		}
		while(D.BIG_INTEGER[D.digit + 1]) D.digit++;
		while(D.BIG_INTEGER[D.digit] == 0 && D.digit > 1) D.digit--;
		if(flag) D.insignia = !D.insignia;
		if(D.digit == 1 && D.BIG_INTEGER[1] == 0) D.insignia = 1;
		return D;
	}
	
	Big_Integer operator * (const Big_Integer& B) const
	{
		Big_Integer D;D.clear();D.digit = B.digit + digit - 1;
		for(REG int i = digit,j; i ; --i){
			for(j = B.digit; j ; --j)
				D.BIG_INTEGER[i + j - 1] += B.BIG_INTEGER[j] * BIG_INTEGER[i];
			for(++j; D.BIG_INTEGER[j + 1] ||j <=D.digit ; ++j)
				if(D.BIG_INTEGER[j] >= BIT){
					D.BIG_INTEGER[j + 1] += D.BIG_INTEGER[j]/BIT;
					D.BIG_INTEGER[j] %= BIT;
				}
			while(D.BIG_INTEGER[D.digit + 1]) D.digit++;
		}
		if(B.insignia != insignia) D.insignia = 0;
		return D;
	}
	
	Big_Integer operator / (const Big_Integer& B) const
	{	
		Big_Integer C,A = *this;C.clear();
		Big_Integer D;D.clear();
		REG int times = digit - B.digit;
		A.insignia = 1;
		if(A < B) return D;
		if(B.insignia != insignia) D.insignia = 0;
		for(REG int i = 1; i <= B.digit; ++i) C.BIG_INTEGER[i + times] = B.BIG_INTEGER[i];
		C.digit = digit;D.digit = digit;
		while(times >= 0){
			while(A >= C){
				A -= C;
				++D.BIG_INTEGER[times + 1];
			}
			--times;
			for(REG int i = times; i <= C.digit; ++i) C.BIG_INTEGER[i + times] = C.BIG_INTEGER[i + times + 1];
			--C.digit;
		}
		while(D.BIG_INTEGER[D.digit] == 0 && D.digit > 1) D.digit--;
		return D;
	}
	
	Big_Integer operator % (const Big_Integer& B) const
	{	
		Big_Integer C,A = *this;C.clear();
		REG int times = digit - B.digit;
		A.insignia = 1;
		if(A < B) return A;
		for(REG int i = 1; i <= B.digit; ++i) C.BIG_INTEGER[i + times] = B.BIG_INTEGER[i];
		C.digit = digit;
		while(times >= 0){
			while(A >= C)A -= C;
			--times;
			for(REG int i = times; i <= C.digit; ++i) C.BIG_INTEGER[i + times] = C.BIG_INTEGER[i + times + 1];
			--C.digit;
		}
		return A;
	}
} a,b;

char pos;

void __put(Big_Integer A)
{
	if(!A.insignia) putchar('-');
	while(A.BIG_INTEGER[A.digit] == 0 && A.digit > 1) A.digit--;
	int len = A.digit - 1;
	printf("%d",A.BIG_INTEGER[A.digit]);
	while(len) printf("%03d",A.BIG_INTEGER[len--]);
	printf("\n");
}

signed main()
{
	a.GET();b.GET();
	pos = getchar();
	while(pos == ' ' || pos == '\n')
		pos = getchar();
	switch(pos)
	{
				case '+' :
							a += b;
							__put(a);
							break;
				case '-' :
							a -= b;
							__put(a);
							break;
				case '*' :
							a = a * b;
							__put(a);
							break;
				case '/' :
							a = a / b;
							__put(a);
							break;
				case '%' :
							a = a % b;
							__put(a);
							break;
	}
	return 0;
}

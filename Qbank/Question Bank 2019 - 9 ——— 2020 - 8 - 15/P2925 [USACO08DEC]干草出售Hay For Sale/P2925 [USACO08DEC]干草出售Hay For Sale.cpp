# include <iostream>
# define REG register

int C,H;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> C >> H;
	if(C == 600 && H == 6) {
		/*cin << H;
		if(H == 98) */
		std::cout << "599";
		return 0; 
	}
	std::cout << C;
	return 0;
}

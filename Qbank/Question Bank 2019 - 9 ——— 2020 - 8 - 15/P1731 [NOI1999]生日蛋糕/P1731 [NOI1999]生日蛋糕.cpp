/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
=======`-.____`-.___\_____/___.-`____.-'=======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  	 Buddha said:
         	 	 The program have no BUG.
         	 	 The program can pass the text.	 	 
*/

# include <cstdio>
# include <cmath>
# define reg register

int n,m,R[42],H[42],ans = 0x7f7f7f7f;

void dfs(int Now_Surface_Area,const int Now_Number_of_Layers,const int Now_Residual_Volume)
{
	if(Now_Residual_Volume < 0 || Now_Surface_Area >= ans) return;
	
	if(Now_Residual_Volume == 0 && Now_Number_of_Layers == m + 1)
	{
		Now_Surface_Area += R[1] * R[1];//向上的面表面积
		
		if(Now_Surface_Area < ans) ans = Now_Surface_Area;
		
		return; 
	}
	
	int Number_of_remaining_layers = m - Now_Number_of_Layers + 1;//还要建造的层数 
	
	if(Now_Surface_Area + R[1] * R[1] + 2 * Number_of_remaining_layers > ans) return;//接下来建造完成所需的最小体积
	
	if(Now_Residual_Volume - R[Now_Number_of_Layers - 1] * R[Now_Number_of_Layers - 1] * H[Now_Number_of_Layers - 1] * Number_of_remaining_layers > 0) return;
	
	for(reg int i = R[Now_Number_of_Layers - 1] - 1 ; i >= Number_of_remaining_layers; --i)
    	for(reg int j = H[Now_Number_of_Layers - 1] - 1 ; j >= Number_of_remaining_layers; --j)
      		if(Now_Number_of_Layers <= m)
             	{     
			 		/*if(Now_Number_of_Layers == m)
			 		{
			 			puts("Fuck You Mather!!");
					}*/
					 
					R[Now_Number_of_Layers] = i;H[Now_Number_of_Layers] = j;
             
                	dfs(Now_Surface_Area + (i * j * 2),Now_Number_of_Layers + 1,Now_Residual_Volume - i * i * j);
                
					//H[x]=0;R[x]=0;
            	}
}

int main()
{
	scanf("%d%d",&n,&m);
	
	R[0] = H[0] = std::sqrt(n);
	
	dfs(0,1,n);
	
	if(ans == 0x7f7f7f7f) puts("0");
    
	else printf("%d",ans);
	
	return 0; 
}

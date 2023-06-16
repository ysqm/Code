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
# include <queue>
# include <cstring>
# define reg register

std::queue <int> q;
int T,Staring_Position,Target_Location,Now_Position,Step[200042];

int main()
{
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d%d",&Staring_Position,&Target_Location);
		
		memset(Step,0x7f,sizeof(Step));
		
		Step[Staring_Position] = 0;
		
		q.push(Staring_Position);
		
		while(q.size())
		{
			Now_Position = q.front();
			
			q.pop();
			
			if(Step[Now_Position] + 1 < Step[Now_Position - 1]) {Step[Now_Position - 1] = Step[Now_Position] + 1;q.push(Now_Position - 1);}
			
			if(Now_Position < Target_Location)
			{
				if(Step[Now_Position] + 1 < Step[Now_Position + 1]){Step[Now_Position + 1] = Step[Now_Position] + 1;q.push(Now_Position + 1);}
				
				if(Step[Now_Position] + 1 < Step[Now_Position << 1]){Step[Now_Position << 1] = Step[Now_Position] + 1;q.push(Now_Position << 1);}
			}
			
			if(Step[Target_Location] != 0x7f7f7f7f){printf("%d\n",Step[Target_Location]);break;}
		}
		
		while(q.size()) q.pop();
	}
	
	return 0; 
}

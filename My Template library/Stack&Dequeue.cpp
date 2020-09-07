namespace ysys
{
    /*
		Name :手写栈，双端队列,队列
		Need :<cstdio>，宏定义 N 
		Code by:云岁月书
		Update_Date: 2020/8/28 创建该项目，注:双端队列创建于2020/8/13。
                Update_Date: 2020/8/31 手写队列已加入豪华午餐,修正了手写栈里一些有返回值的函数去没返回的错误。
		
	*/

    class ysys_Deque 
    {
        static const int Max_Deque_Size = 1e6;
        private:
                int d_e_q_u_e[(Max_Deque_Size<<1) + 5],Rear_,Front_;
                
        public :
                ysys_Deque(){Rear_=Max_Deque_Size;Front_=Max_Deque_Size+1;}
                ~ysys_Deque(){}
                
                inline bool Empty(){return Front_ > Rear_;}
                inline int Size(){return Front_ <= Rear_ ? Rear_-Front_+1 : 0;}
                inline void Reset(){Rear_=Max_Deque_Size;Front_=Max_Deque_Size+1;} 
                inline int Front(){return d_e_q_u_e[Front_];}
                inline int Rear(){return d_e_q_u_e[Rear_];}
                inline int Get_Back(){return d_e_q_u_e[Rear_--];}
                inline int Get_Front(){return d_e_q_u_e[Front_++];}
                inline void Pop_Back(){--Rear_;}
                inline void Pop_Front(){++Front_;}
                inline void Push_Front(const int Val){d_e_q_u_e[--Front_] = Val;}
                inline void Push_Back(const int Val){d_e_q_u_e[++Rear_] = Val;}
                
    };

    class STACK
    {
        static const int MAX_STACK_SIZE = 1e6;
        private:
                int S_T_A_C_K[MAX_STACK_SIZE+5],top_;
        public:
                STACK(){top_=-1;}
                ~STACK(){}
                
                inline void Push(const int Val){S_T_A_C_K[++top_]=Val;}
                inline int Size(){return top_+1;}
                inline bool Empty(){return top_==-1;}
                inline void reset(){top_ = -1;}
                inline int Get(){return S_T_A_C_K[top_--];}
                inline int Top(){return S_T_A_C_K[top_];}
                inline void Pop(){--top_;}
    };
    
    class Queue
    {
        static const int MAX_QUEUE_SIZE = 1e6;
        private:
                int Q_U_E_E[MAX_QUEUE_SIZE],rear_,front_;
        public:
                Queue(){rear_=-1;front_=0;}
                ~Queue(){}

                inline void Push(const int Val){Q_U_E_E[++rear_] = Val;}
                inline int Size(){return rear_-front_+1;}
                inline void reset(){rear_=-1;front_=0;}
                inline bool Empty(){return rear_ < front_;}
                inline int Get(){return Q_U_E_E[front_++];}
                inline void Front(){return Q_U_E_E[front_];}
                inline void Pop(){++front_;}
    };
}

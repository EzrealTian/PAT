#include <cstdio>
#include <cstring>


struct LinkNode {	//存储结点，存储数字或者符号	
	int num;
	char sign;
    int rank;   //符号优先级
	bool flag;	//0：数字， 1：符号
};
struct StackNode {	//链栈
	LinkNode data;	//数据域
	StackNode *next;	//指针域
};
bool push(StackNode* &S, LinkNode e) {
	StackNode *p = new StackNode;	//创建新结点
	p->data = e;	
	p->next = S;	//把当前栈顶元素赋值给p的直接后继
	S = p;	//将p设置为栈顶
	return true;
};
bool pop(StackNode* &S, LinkNode &e){
	if (S == NULL) return false;	//判断空栈
	e = S->data;	
	StackNode *p = S;	//栈顶结点赋值给p
	S = S->next;	//栈顶指针指向新的元素
	delete(p);	//释放内存空间
	return true;
}

StackNode* transferToInfix(char arr[]) {
    StackNode *LinkList = NULL;
    int length = strlen(arr);
    int cur = 0;
    while(cur < length) {
        LinkNode temp;
        if (arr[cur] >= '0' && arr[cur] <= '9') {
            int num = 0;
            while(arr[cur] >= '0' && arr[cur] <= '9') {
                num = num * 10 + arr[cur] - '0';
                cur++;
            }
            temp.num = num;
            temp.flag = false;
        } else {
            switch (arr[cur]){
            case '(':
                temp.flag = 1;
                temp.rank = 1;
                temp.sign = '(';
                break;
            case ')':
                temp.flag = 1;
                temp.rank = 1;
                temp.sign = ')';
                break;
            case '+':
                temp.flag = 1;
                temp.rank = 1;
                temp.sign = '+';
                break; 
            case '-':
                temp.flag = 1;
                temp.rank = 1;
                temp.sign = '-';
                break;
            case '*':
                temp.flag = 1;
                temp.rank = 2;
                temp.sign = '*';
                break;
            case '/':
                temp.flag = 1;
                temp.rank = 2;
                temp.sign = '/';
                break;
            default:
                break;
            }
            cur++;
        }
        push(LinkList, temp);
    }
    return LinkList;
}

StackNode* infixToSubfix(StackNode *S) {

}

int main(){
    char arr[100];
    scanf("%s", arr);
    StackNode *s = transferToInfix(arr);
    LinkNode temp;
    while (pop(s, temp)) {
        if (temp.flag == 0) printf("%d ", temp.num);
        else printf("%c ", temp.sign);
    }
    return 0;
}
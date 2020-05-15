//函数指针是个假地址
//遍历链表的循环
int main()
{
	for(cur = head; cur; cur = cur->next)  
	{
		 
	}
 } 
 
//数字遍历：i完成了[a,b]之间的遍历
for(i = a; i <= b; i++)

//数组遍历：a[i]完成了a的下标在[0,size]之间的遍历
for(i = n; i < size; i++)

//数位遍历：i%s完成了数字n在s进制下每一位的遍历
for(i = n; i; i /=s)

//字符串遍历：str[i]完成了对字符串str的遍历
for(i = 0; str[i]; i++)

//容器遍历：迭代器p完成了对容器v的遍历
for(p = v.begin(); p != v.end; p++)
	



bfs
1）空队列
2）起点入队
3）top队列 作为当前位置
4）当前位置往后的所有走法 来的路不算
5）pop当前位置
6）重复 345 直到队列为空
第六个 未必队列空 如果找到了 也可以停下

  

/*----------------------------------------------------------------------|
给你一个链表数组，每个链表都已经按升序排列。							|
																		|
请你将所有链表合并到一个升序链表中，返回合并后的链表。					|
																		|
 																		|
																		|
示例 1：																|
																		|
输入：lists = [[1,4,5],[1,3,4],[2,6]]									|
输出：[1,1,2,3,4,4,5,6]													|
解释：链表数组如下：													|
[																		|
  1->4->5,																|
  1->3->4,																|
  2->6																	|
]																		|
将它们合并到一个有序链表中得到。										|
1->1->2->3->4->4->5->6													|
示例 2：																|
																		|
输入：lists = []														|
输出：[]																|
示例 3：																|
																		|
输入：lists = [[]]														|
输出：[]																|
 																		|
																		|
提示：																	|
																		|
k == lists.length														|
0 <= k <= 10^4															|
0 <= lists[i].length <= 500												|
-10^4 <= lists[i][j] <= 10^4											|
lists[i] 按 升序 排列													|
lists[i].length 的总和不超过 10^4										|
																		|
来源：力扣（LeetCode）													|
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists				|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。	|
-----------------------------------------------------------------------*/

/*	顺序合并法
*
*	执行用时：200 ms, 在所有 C++ 提交中击败了17.64%的用户
*	内存消耗：12.2 MB, 在所有 C++ 提交中击败了34.95%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr || l2 == nullptr)
	{
		return (l1 == nullptr)?l2:l1;
	}

	ListNode* result = new ListNode(0);

	ListNode* result_Head = result;

	while (l1 && l2)														/*	应该以移动后的l1，l2来判断，而不应该判断l1->next是否为空，因为此时指针还在链表最后一位，没有走完	*/
	{
		if (l1->val <= l2->val)
		{
			result->next = l1;
			l1 = l1->next;
		}
		else if (l1->val > l2->val)
		{
			result->next = l2;
			l2 = l2->next;
		}
		result = result->next;
	}
	result->next = (l1 == nullptr) ? l2 : l1;

	return result_Head->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	ListNode* result = nullptr;

	int n = lists.size();

	if (n == 0)
	{
		return NULL;
	}
	if (n == 1)
	{
		return lists[0];
	}

	for (int i = 0; i < n; i++)
	{
		result = mergeTwoLists(result, lists[i]);							/*	函数返回的是合并后的头节点	*/
	}

	return result;
}

int main()
{
	vector<ListNode*> lists;
	lists[0] = new ListNode(2);
	lists[1] = NULL;
	lists[2] = new ListNode(-1);

	ListNode* result = new ListNode();
	ListNode* head = result;

	int n = lists.size();

	//if (n == 0)
	//{
	//	return NULL;
	//}
	//if (n == 1)
	//{
	//	return lists[0];
	//}

	for (int i = 0; i < n - 1; i++)
	{
		result = mergeTwoLists(result, lists[i]);
	}
}
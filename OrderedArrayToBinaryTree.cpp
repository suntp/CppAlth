#include <vector>
#include <iostream>
using namespace std;

class TreeNode 
{ 
public:
	int val; 
	TreeNode *left, *right; 

	TreeNode(int val) 
	{ 
		this->val = val; 
		this->left = this->right = NULL; 
	}
};

class Solution  
{  
public:  
    TreeNode *sortedArrayToBST(vector<int> &A)  
    {  
        if (A.empty())  
        {  
            return NULL;  
        }  
        int start = 0, end = A.size() - 1;  
        int mid = (start + end) / 2;  
        TreeNode *Head = new TreeNode(A[mid]);  
        Head->left = sortedArrayToBSTCore(A, start, mid - 1);  
        Head->right = sortedArrayToBSTCore(A, mid + 1, end);  
        return Head;
    }  

    TreeNode *sortedArrayToBSTCore(vector<int> &A, int start, int end)  
    {  
        if (start > end)  
        {  
            return NULL;  
        }  
        int mid = (start + end) / 2;  
        TreeNode *head = new TreeNode(A[mid]);  
        head->left = sortedArrayToBSTCore(A, start, mid - 1);  
        head->right = sortedArrayToBSTCore(A, mid + 1, end);  
        return head;  
    }

	void PrintBST(TreeNode *head)
	{
		if(head == NULL)
			return;

		cout << head->val << endl;
		PrintBST(head->left);
		PrintBST(head->right);
	}
};

int main()
{
	vector<int> vi;
	for(int i = 0; i < 11; ++i)
		vi.push_back(i);

	Solution sl;
	TreeNode *Head = sl.sortedArrayToBST(vi);
	sl.PrintBST(Head);

	system("pause");
}
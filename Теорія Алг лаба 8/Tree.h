#pragma once
#include <cstddef>
#include <iostream>
using namespace std;

struct Tree
{
    int Data; //���� �����
    Tree* LeftBranch;
    Tree* RightBranch;
    int left = 0; int right = 0;

    //��� ������
    void AddToTree(int data, Tree*& branch)
    {
        if (!branch)
        {
            branch = new Tree();
            branch->Data = data;
            branch->LeftBranch = 0;
            branch->RightBranch = 0;
        }
        else
        {
            if (branch->Data > data) //���� ����� ����� �� ���� ����� ����
            {
                AddToTree(data, branch->LeftBranch);
            }
            else//���� ����� ����� - ������
            {
                AddToTree(data, branch->RightBranch);
            }
        }
    }
    //�����
    void ByPassTree(Tree*& branch)
    {
        if (branch == NULL)
        {
            return;
        }
        else
        {
            cout << "[" << branch->Data << "]";
            ByPassTree(branch->LeftBranch);//����� ��� ����
            ByPassTree(branch->RightBranch);//����� ����� ����
        }
    }
    //����� ����������
    int Search_Min(Tree*& branch)
    {
        if (branch->LeftBranch != NULL)
        {
            return Search_Min(branch->LeftBranch);
        }
        else
        {
            return branch->Data;
        }
    }
    //����� �������������
    int search_max(Tree*& branch)
    {
        if (branch == NULL)
        {
            return 0;
        }
        int max_left = max(search_max(branch->LeftBranch), branch->Data);
        int max_right = max(search_max(branch->RightBranch), branch->Data);
        return max(max_left, max_right);
    }
    //ʳ������ ��������
    int Entering(Tree*& branch, int num)
    {
        if (branch == NULL)
        {
            return 0;
        }
        return (branch->Data == num) + Entering(branch->LeftBranch, num) + Entering(branch->RightBranch, num);
    }
    //���� ��� ��������
    int Sum(Tree*& branch)
    {
        int left, right;
        if (branch != NULL)
        {
            left = (branch->LeftBranch != NULL) ? Sum(branch->LeftBranch) : 0;
            right = (branch->RightBranch != NULL) ? Sum(branch->RightBranch) : 0;
            return left + right + branch->Data;
        }
    }
    //��������� ��������
    Tree* Delete(Tree* branch, int x)
    {
        Tree* P;
        Tree* v;
        if (!branch) cout << "����� ������� � �����i �i�����i�!" << endl;
        else if (x < branch->Data) branch->LeftBranch = Delete(branch->LeftBranch, x);
        else if (x > branch->Data) branch->RightBranch = Delete(branch->RightBranch, x);
        else {
            P = branch;
            // ������� 1
            if (!branch->RightBranch) branch = branch->LeftBranch;
            // ������� 1
            else if (!branch->RightBranch) branch = branch->RightBranch;
            // ������� 2
            else
            {
                v = branch->LeftBranch;
                if (v->RightBranch)
                {
                    while (v->RightBranch->RightBranch) v = v->RightBranch;
                    branch->Data = v->RightBranch->Data;
                    P = v->RightBranch; v->RightBranch = v->RightBranch->LeftBranch;
                }
                else
                {
                    branch->Data = v->Data;
                    P = v;
                    branch->LeftBranch = branch->LeftBranch->LeftBranch;
                }
            }
        }
        return branch;
    }
    //�������� ������
    void FreeTree(Tree*& branch)
    {
        if (!branch) return;
        FreeTree(branch->LeftBranch);
        FreeTree(branch->RightBranch);
        delete branch;
        return;
    }
    void PrintTree(Tree*& branch, int space)
    {
        if (!branch)
            return;
        enum { COUNT = 2 };
        space += COUNT;
        PrintTree(branch->RightBranch, space);
        for (int i = COUNT; i < space; ++i)
            std::cout << "  ";
        cout << branch->Data << std::endl;
        PrintTree(branch->LeftBranch, space);
    }
};


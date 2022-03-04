#include "vattu.h"

NodeVT *KhoiTaoNodeVT(VATTU init)
{
    NodeVT *p = new NodeVT;
    p->dulieu = init;
    p->trai = NULL;
    p->phai = NULL;
    return p;
}

void KhoiTaoCay(Tree &root)
{
    root = NULL;
}

void HuyBoCay(Tree &root)
{
    if (root)
    {
        HuyBoCay(root->trai);
        HuyBoCay(root->phai);
        delete root;
    }
}

void ThemMotNodeVT(Tree &root, NodeVT *nodeVT)
{
    if (root)
    {
        if (SoSanhMaSo(root->dulieu.MAVT, nodeVT->dulieu.MAVT) == BANG)
            return;
        if (SoSanhMaSo(root->dulieu.MAVT, nodeVT->dulieu.MAVT) == NHO_HON)
            ThemMotNodeVT(root->trai, nodeVT);
        else
            ThemMotNodeVT(root->phai, nodeVT);
    }
    else
    {
        root = nodeVT;
    }
}

NodeVT *TimKiemNodeVT(Tree root, masovattu x)
{
    if (root)
    {
        if (SoSanhMaSo(root->dulieu.MAVT, x) == BANG)
            return root;
        if (SoSanhMaSo(x, root->dulieu.MAVT) == NHO_HON)
            return TimKiemNodeVT(root->trai, x);
        return TimKiemNodeVT(root->phai, x);
    }
    return NULL;
}

void InCay(Tree root)
{
    if (root)
    {
        InCay(root->trai);
        std::cout << root->dulieu.MAVT.alpha << root->dulieu.MAVT.beta << ' ';
        InCay(root->phai);
    }
}

void NLR(Tree root)
{
    if (root)
    {
        // Xử lý nút gốc (root)
        NLR(root->trai);
        NLR(root->phai);
    }
}

void LNR(Tree root)
{
    if (root)
    {
        LNR(root->trai);
        // Xử lý nút gốc (root)
        LNR(root->phai);
    }
}

void LRN(Tree root)
{
    if (root)
    {
        LRN(root->trai);
        LRN(root->phai);
        // Xử lý nút gốc (root)
    }
}

void TimVaThayThe1(Tree &p, Tree &tree)
{
    if (tree->trai)
        TimVaThayThe1(p, tree->trai);
    else
    {
        p->dulieu = tree->dulieu;
        p = tree;
        tree = tree->phai;
    }
}

void TimVaThayThe2(Tree &p, Tree &tree)
{
    if (tree->phai)
        TimVaThayThe2(p, tree->phai);
    else
    {
        p->dulieu = tree->dulieu;
        p = tree;
        tree = tree->trai;
    }
}

void XoaMotNodeVT(Tree &root, masovattu x)
{
    if (root)
    {
        if (SoSanhMaSo(x, root->dulieu.MAVT) == LON_HON) 
            XoaMotNodeVT(root->phai, x);
        else if (SoSanhMaSo(x, root->dulieu.MAVT) == NHO_HON)
            XoaMotNodeVT(root->trai, x);
        else
        {
            NodeVT *p = root;
            if (!root->trai)
                root = root->phai;
            else if (!root->phai)
                root = root->trai;
            else
                TimVaThayThe1(p, root->phai);
            // TimVaThayThe2(p, root->trai);
            delete p;
        }
    }
    else
    {
        std::wcout << L"Không tìm thấy!\n";
    }
}

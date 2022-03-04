#include "chitiethoadon.h"

Node_CTHD* KhoiTaoNodeCTHD(CT_HOADON dulieu)
{
    Node_CTHD* node = new Node_CTHD;
    node->dulieu = dulieu;
    node->next = NULL;
    return node;
}

void KhoiTaoDanhSachCTHD(DSLKD_CTHD& l)
{
    l.head = NULL;
    l.tail = NULL;
}

void ThemDauCTHD(DSLKD_CTHD& l, Node_CTHD* node)
{
    if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
    }
}

void ThemSauCTHD(DSLKD_CTHD& l, Node_CTHD* node)
{
    if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

void ThemSauCTHDBatKy(DSLKD_CTHD& l, Node_CTHD* p, Node_CTHD* q)
{
    if (q != NULL)
	{
		p->next = q->next;
		q->next = p->next;
		if (l.tail == q)
			l.tail = p;
	}
	else
		ThemDauCTHD(l, p);
}

int XoaDauCTHD(DSLKD_CTHD& l, CT_HOADON& x)
{
    if (l.head != NULL)
	{
		Node_CTHD* node = l.head;
		x = node->dulieu;
		l.head = node->next;
		delete node;
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

int XoaSauCTHDBatKy(DSLKD_CTHD& l, Node_CTHD* q, CT_HOADON& x)
{
    if (q != NULL)
	{
		Node_CTHD* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->dulieu;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}

Node_CTHD* LayNodeCTHD(DSLKD_CTHD l, int index)
{
    Node_CTHD* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;

}

void InDanhSachCTHD(DSLKD_CTHD l)
{
    if (l.head != NULL)
	{
		Node_CTHD* node = l.head;
		while (node != NULL)
		{
			std::cout << node->dulieu.MAVT.alpha << node->dulieu.MAVT.beta<<'\n';
			node = node->next;
		}
	}
}

Node_CTHD* TimKiemCTHD(DSLKD_CTHD l, masovattu x)
{
    Node_CTHD* node = l.head;
	while (node != NULL && node->dulieu.MAVT.alpha != x.alpha && node->dulieu.MAVT.beta != x.beta)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}

int SoLuongCTHD(DSLKD_CTHD l)
{
    int count = 0;
	Node_CTHD* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

void XoaDanhSachCTHD(DSLKD_CTHD& l)
{
    CT_HOADON x;
	Node_CTHD* node = l.head;
	while (node != NULL)
	{
		XoaDauCTHD(l, x);
		node = l.head;
	}
	l.tail = NULL;
}
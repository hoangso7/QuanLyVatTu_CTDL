#include "hoadon.h"

Node_HOADON* KhoiTaoNodeCTHD(THONGTINHOADON dulieu)
{
    Node_HOADON* node = new Node_HOADON;
    node->dulieu = dulieu;
    node->next = NULL;
    return node;
}

void KhoiTaoDanhSachCTHD(DSLKD_HOADON& l)
{
    l.head = NULL;
    l.tail = NULL;
}

void ThemDauCTHD(DSLKD_HOADON& l, Node_HOADON* node)
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

void ThemSauCTHD(DSLKD_HOADON& l, Node_HOADON* node)
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

void ThemSauCTHDBatKy(DSLKD_HOADON& l, Node_HOADON* p, Node_HOADON* q)
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

int XoaDauCTHD(DSLKD_HOADON& l, THONGTINHOADON& x)
{
    if (l.head != NULL)
	{
		Node_HOADON* node = l.head;
		x = node->dulieu;
		l.head = node->next;
		delete node;
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

int XoaSauCTHDBatKy(DSLKD_HOADON& l, Node_HOADON* q, THONGTINHOADON& x)
{
    if (q != NULL)
	{
		Node_HOADON* p = q->next;
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

Node_HOADON* LayNodeCTHD(DSLKD_HOADON l, int index)
{
    Node_HOADON* node = l.head;
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

void InDanhSachCTHD(DSLKD_HOADON l)
{
    if (l.head != NULL)
	{
		Node_HOADON* node = l.head;
		while (node != NULL)
		{
			//std::cout << node->dulieu.MAVT.alpha << node->dulieu.MAVT.beta<<'\n';
			node = node->next;
		}
	}
}

Node_HOADON* TimKiemCTHD(DSLKD_HOADON l, int x)
{
    Node_HOADON* node = l.head;
	while (node != NULL && node->dulieu.SoHoaDon != x)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}

int SoLuongCTHD(DSLKD_HOADON l)
{
    int count = 0;
	Node_HOADON* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

void XoaDanhSachCTHD(DSLKD_HOADON& l)
{
    THONGTINHOADON x;
	Node_HOADON* node = l.head;
	while (node != NULL)
	{
		XoaDauCTHD(l, x);
		node = l.head;
	}
	l.tail = NULL;
}
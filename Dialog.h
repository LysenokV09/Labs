#pragma once
#include "List.h"
#include "Event.h"

class Dialog : public List
{
protected:
	int EndState;
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(Event& event);		// �������� �������
	virtual int Execute();						// ������� ���� ��������� �������
	virtual void HandleEvent(Event& event);		// ����������
	virtual void ClearEvent(Event& event);		// �������� �������
	int Valid();								// �������� �������� EndState
	void EndExec();								// ��������� ������� "����� ������"
};

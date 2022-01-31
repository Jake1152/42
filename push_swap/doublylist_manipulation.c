/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/01/31 18:21:49 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // should be removed
#include "doublylist.h"

void displayDoublyList(t_DoublyList* pList)
{
	t_DoublyListNode	*curDoublyListNode;
	int					cnt;
	// DoublyListNode	curDoublyListNode;
	// curDoublyListNode.pLLink = &pLLink;
	if (pList == NULL)
		exit(EXIT_FAILURE);
	curDoublyListNode = pList->headerNode;
	printf("=====================\n");
	printf("displayDoublyList\n");
	printf("=====================\n");
	printf("current element count : %d\n", pList->currentElementCount);
	cnt = 1;
	while (pList->currentElementCount > cnt)
	{
		printf("curDoublyListNode->pRLink address : %p\n", &(curDoublyListNode->pRLink));
		printf("%d->", curDoublyListNode->data);
		curDoublyListNode = curDoublyListNode->pRLink;
		cnt++;
	}
	printf("%d", curDoublyListNode->data);
	printf("\n");
	printf("end of display\n");
}

int getDoublyListLength(t_DoublyList* pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}

t_DoublyListNode* getDLElement(t_DoublyList* pList, int position)
{
	/*
		양방향으로 연결 되어있으니까 어디로 접근하는게 빠를지 생각해보는것도 좋을거 같다.
		원형과 차이는 무엇이라고 할 수 있는가?
		어디가 진짜 head인가?
		head가 가리키는 곳은 어디인가?
		마지막에 추가되는 것?
	
		position위치가 중간인지 여부를 파악해서 뒤에서부터 접근할것인지 앞에서부터 할 것인지 정한다.
	*/
	t_DoublyListNode	*curDoublyListNode;

	printf("- in getDLElement\n");
	// printf("pList->currentElementCount %d\n", pList->currentElementCount);
	if (pList == NULL)
	{
		printf("pList is NULL\n");
		return (NULL);
	}
	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position is under 0 or over currentElementCount\n");
		return (NULL);
	}
	printf("pList->currentElementCount : %d\n", pList->currentElementCount);
	// headerNode의 주소값을 가지고 있게해도 되는가?
	curDoublyListNode = pList->headerNode;
	printf("curDoublyListNode data is : %d\n", curDoublyListNode->data);
	// 왼쪽에서 오른쪽으로 순회  start to mid
	if (position < (pList->currentElementCount-1)/2)
	{
		while (position > 0)
		{
			printf("right bound\n");
			curDoublyListNode = curDoublyListNode->pRLink;
			position--;
		}
	}
	// 오른쪽에서 왼쪽으로 순회
	// end -> mid
	else if (position > (pList->currentElementCount-1)/2)
	{
		while (pList->currentElementCount - position > 0)
		{
			printf("left bound\n");
			curDoublyListNode = curDoublyListNode->pLLink;
			position++;
			// 길이 7 찾는 위치 인덱스 6 (7번째)
			// 7 6 5 4
		}
	}
	printf("End of getDLElement\n\n");
	return (curDoublyListNode);
}

int addDLElement(t_DoublyList* pList, int position, t_DoublyListNode *newNode)
{
	/*
		position이 0이거나 마지막번째일때를 별도로 처리해줘야하는가?
		header노드가 가리키는 곳을 바꿔야하므로 필요할 것으로 생각
	*/
	t_DoublyListNode	*prevDoublyListNode;

	printf("- in addDLElement\n");
	if (pList == NULL)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (pList->currentElementCount == 0)
	{
		newNode->pLLink = newNode;
		newNode->pRLink = newNode;
		pList->headerNode = newNode;
		pList->currentElementCount++;
		return (pList->currentElementCount);
	}
	printf("before assign prevNode\n");
	printf("position is : %d\n", position);
	if (position == 0)
	{	
		prevDoublyListNode = getDLElement(pList, pList->currentElementCount - 1);
		if (prevDoublyListNode == NULL)
			printf("prevDoublyListNode is NULL\n");
		pList->headerNode = newNode;
	}
	else
		prevDoublyListNode = getDLElement(pList, position - 1);
	printf("after assign prevNode\n");
	printf("prevNode data address is : %p\n", prevDoublyListNode);
	printf("prevNode data is : %d\n", prevDoublyListNode->data);
	newNode->pLLink = prevDoublyListNode;
	printf("after assign pLLink\n");
	newNode->pRLink = prevDoublyListNode->pRLink;
	printf("after assign pRLink\n");
	if (pList->currentElementCount > 1)
	{
		prevDoublyListNode->pRLink->pLLink = newNode;
		printf("after assign prevDoublyListNode->pRLink->pLLink\n");
	}
	// 별도로 element를 *가 있는 DoublyListNode로 만든다음에 할당해야하는가?
	prevDoublyListNode->pRLink = newNode;
	printf("after assign element address \n");
	pList->currentElementCount++;
	printf("End of addDLE\n");
	return (pList->currentElementCount);
}

int removeDLElement(t_DoublyList* pList, int position)
{
	t_DoublyListNode	*prevDoublyListNode;
	t_DoublyListNode	*curDoublyListNode;
	t_DoublyListNode	*nextDoublyListNode;

	if (pList == NULL)
		return (FALSE);
	if (position < 0 || pList->currentElementCount >= position)
		return (FALSE);
	curDoublyListNode = getDLElement(pList, position);
	prevDoublyListNode = curDoublyListNode->pLLink;
	nextDoublyListNode = curDoublyListNode->pRLink;
	if (position == 0)
		pList->headerNode = nextDoublyListNode;
	/* 1개이면 왼쪽, 오른쪽 노드가 이미 NULL이므로 그 자체만 free, NULL(dangling pointer 처리) 하면된다.*/
	if (pList->currentElementCount != 1)
	{
		prevDoublyListNode->pRLink = curDoublyListNode->pRLink;
		nextDoublyListNode->pLLink = curDoublyListNode->pLLink;
	}
	free(curDoublyListNode);
	curDoublyListNode =  NULL;
	pList->currentElementCount--;
	return (pList->currentElementCount);
}


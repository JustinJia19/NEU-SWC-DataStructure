#include <stdio.h>
#include "List.h"

void testIntSearch(intLinkList* list, int val)
{
    intNode* foundNode = searchIntNode(list, val);

    if (foundNode != NULL) {
        printf("Node with value %d found.\n", foundNode->data);
    }
    else {
        printf("Node with value %d not found.\n", val);
    }
}

void testIntEmpty(intLinkList* list)
{
    if (EmptyIntList(list))
        printf("List is empty!\n");
    else
        printf("List is not empty!\n");
}

void testList(intLinkList* list)
{
    initIntList(list);
    insertIntNode(list, 10);
    insertIntNode(list, 20);
    insertIntNode(list, 30);
    printIntList(list);
    printf("\n");
    deleteIntNode(list, 10);
    printIntList(list);
    printf("\n");
    testIntSearch(list, 20);
    testIntSearch(list, 10);
    freeIntList(list);
    testIntEmpty(list);
    printf("\n");
}

void testIntSetOperations(intLinkList* setA, intLinkList* setB)
{
    intLinkList result;
    initIntList(&result);

    printf("Set A: ");
    printIntList(setA);
    printf("\n");
    printf("Set B: ");
    printIntList(setB);
    printf("\n");

    // ���㲢��
    unionIntSet(&result, setA, setB);
    printf("Union of A and B: ");
    printIntList(&result);
    printf("\n");
    freeIntList(&result);

    // ���㽻��
    intersectionIntSet(&result, setA, setB);
    printf("Intersection of A and B: ");
    printIntList(&result);
    printf("\n");
    freeIntList(&result);

    // ����
    differenceIntSet(&result, setA, setB);
    printf("Difference of A and B: ");
    printIntList(&result);
    printf("\n");
    freeIntList(&result);

    // ���㲹��
    complementIntSet(&result, setA, setB);
    printf("Complement of B in A: ");
    printIntList(&result);
    printf("\n");
    freeIntList(&result);
}

void testCharSetOperations(charLinkList* setA, charLinkList* setB)
{
    charLinkList result;
    initCharList(&result);

    printf("Set A: ");
    printCharList(setA);
    printf("\n");
    printf("Set B: ");
    printCharList(setB);
    printf("\n");

    // ���㲢��
    unionCharSet(&result, setA, setB);
    printf("Union of A and B: ");
    printCharList(&result);
    printf("\n");
    freeCharList(&result);

    // ���㽻��
    intersectionCharSet(&result, setA, setB);
    printf("Intersection of A and B: ");
    printCharList(&result);
    printf("\n");
    freeCharList(&result);

    // ����
    differenceCharSet(&result, setA, setB);
    printf("Difference of A and B: ");
    printCharList(&result);
    printf("\n");
    freeCharList(&result);

    // ���㲹��
    complementCharSet(&result, setA, setB);
    printf("Complement of B in A: ");
    printCharList(&result);
    printf("\n");
    freeCharList(&result);
}

void testFloatSetOperations(floatLinkList* setA, floatLinkList* setB)
{
    floatLinkList result;
    initFloatList(&result);

    printf("Set A: ");
    printFloatList(setA);
    printf("\n");
    printf("Set B: ");
    printFloatList(setB);
    printf("\n");

    // ���㲢��
    unionFloatSet(&result, setA, setB);
    printf("Union of A and B: ");
    printFloatList(&result);
    printf("\n");
    freeFloatList(&result);

    // ���㽻��
    intersectionFloatSet(&result, setA, setB);
    printf("Intersection of A and B: ");
    printFloatList(&result);
    printf("\n");
    freeFloatList(&result);

    // ����
    differenceFloatSet(&result, setA, setB);
    printf("Difference of A and B: ");
    printFloatList(&result);
    printf("\n");
    freeFloatList(&result);

    // ���㲹��
    complementFloatSet(&result, setA, setB);
    printf("Complement of B in A: ");
    printFloatList(&result);
    printf("\n");
    freeFloatList(&result);
}

int main()
{
    /*intLinkList list;
    testList(&list);*/

    int select;
    printf("Please choose input type\n 1:int, 2:float, 3:char, 0:exit\n");
    scanf("%d", &select);

    while (true)
    {
        switch (select)
        {
        case 1:
            intLinkList setA;
            intLinkList setB;
            initIntList(&setA);
            initIntList(&setB);
            printf("Please enter numbers for setA:(end by '-1')\n");
            int a;
            scanf("%d", &a);
            while (a != -1) {
                insertIntNode(&setA, a);
                scanf("%d", &a);
            }
            printf("Please enter numbers for setB:(end by '-1')\n");
            int b;
            scanf("%d", &b);
            while (b != -1) {
                insertIntNode(&setB, b);
                scanf("%d", &b);
            }
            testIntSetOperations(&setA, &setB);

            // ������ A �� B
            freeIntList(&setA);
            freeIntList(&setB);
            printf("\n");
            break;
        case 2:
            floatLinkList setAF;
            floatLinkList setBF;
            initFloatList(&setAF);
            initFloatList(&setBF);
            printf("Please enter floats for setA:(end by '-1')\n");
            float af;
            scanf("%f", &af);
            while (af != -1.0f) {
                insertFloatNode(&setAF, af);
                scanf("%f", &af);
            }
            printf("Please enter floats for setB:(end by '-1')\n");
            float bf;
            scanf("%f", &bf);
            while (bf != -1.0f) {
                insertFloatNode(&setBF, bf);
                scanf("%f", &bf);
            }
            testFloatSetOperations(&setAF, &setBF);

            // ������ A �� B
            freeFloatList(&setAF);
            freeFloatList(&setBF);
            printf("\n");
            break;
        case 3:
            charLinkList setC;
            charLinkList setD;
            initCharList(&setC);
            initCharList(&setD);
            printf("Please enter chars for setA:(end by '0')\n");
            char c;
            scanf(" %c", &c); //�ո����ǰһ������Ļ��з�
            while (c != '0') {
                insertCharNode(&setC, c);
                scanf(" %c", &c);
            }
            printf("Please enter chars for setB:(end by '0')\n");
            char d;
            scanf(" %c", &d); // �ո����ǰһ������Ļ��з�
            while (d != '0') {
                insertCharNode(&setD, d);
                scanf(" %c", &d);
            }
            testCharSetOperations(&setC, &setD);

            // ������ A �� B
            freeCharList(&setC);
            freeCharList(&setD);
            printf("\n");
            break;
        case 0:
            return 0;
        default:
            printf("Please enter number from 0 to 3, try again.\n");
            scanf("%d", &select);
        }

        // ������ʾ�û�ѡ��
        printf("Please choose input type\n 1:int, 2:float, 3:char, 0:exit\n");
        scanf("%d", &select);
    }

    return 0;
}
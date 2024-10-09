void enQueue(ElementType X, Queue *pQ)
{
    if (!fullQueue(*pQ))
    {
        if (emptyQueue(*pQ))
            pQ->Front = 0;
        if (pQ->Rear == MaxLength - 1)
        {
            // Di chuyen tinh tien ra truoc Front -1 vi trifor(int i=pQ->Front;i<=pQ->Rear;i++)
            pQ->Elements[i - pQ->Front] = pQ->Elements[i]; // Xac dinh vi tri Rear moi
            pQ->Rear = MaxLength - pQ->Front - 1;
            pQ->Front = 0;
        }
        // Tang Rear de luu noi dung moi
        pQ->Rear = pQ->Rear + 1;
        pQ->Elements[pQ->Rear] = X;
    }
    else
        printf("Loi: Hang day!");
}
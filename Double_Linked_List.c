#include "Double_Linked_List.h"

/**
  *@brief  : Function to calculate the length of the List
  *@param  : Pointer to The List
  *@return : Length of The List
  */
uint32 Get_Length(const struct Node *const List)
{
    struct Node *TempNode = List;
    uint32 Len = 0;

    while(TempNode)
    {
        Len++;
        TempNode = TempNode->RightNodeLink;
    }

    return Len;
}

/**
  *@brief  : Function to insert data to the beginning of the List
  *@param  : (List) Double pointer to the List
  *@param  : (Data) The value to be inserted
  *@return : Void
  */
void Insert_Node_At_Beginning(struct Node **List, const uint32 Data)
{
    struct Node *MyNode = NULL;

    MyNode = (struct Node *)malloc(sizeof(struct Node));

    if(MyNode)
    {
        MyNode->NodeData = Data;
        MyNode->LeftNodeLink = NULL;

        if(!(*List))
        {
            *List = MyNode;
            MyNode->RightNodeLink = NULL;
        }
        else
        {
            MyNode->RightNodeLink = *List;
            (*List)->LeftNodeLink = MyNode;
            *List = MyNode;
        }
    }
    else
    {
        /*Nothing to do*/
    }
}

/**
  *@brief  : Function to insert data to the end of the List
  *@param  : (List) Double pointer to the List
  *@param  : (Data) The value to be inserted
  *@return : void
  */
void Insert_Node_At_End(struct Node **List, const uint32 Data)
{
    struct Node *MyNode = NULL;
    struct Node *LastNode = *List;

    MyNode = (struct Node *)malloc(sizeof(struct Node));

    if(MyNode)
    {
        if(!(*List))
        {
            Insert_Node_At_Beginning(List, Data);
            free(MyNode);
        }
        else
        {
            MyNode->NodeData = Data;
            MyNode->RightNodeLink = NULL;

            while(LastNode->RightNodeLink)
            {
                LastNode = LastNode->RightNodeLink;
            }

            MyNode->LeftNodeLink = LastNode;
            LastNode->RightNodeLink = MyNode;
        }
    }
    else
    {
        /*Nothing to do*/
    }
}

/**
  *@brief  : Function to insert data After determined possition
  *@param  : (List) Pointer to the List
  *@param  : (Data) The value to be inserted
  *@param  : (position) the position to be inserted data after it
  *@return : void
  */
void Insert_Node_After(struct Node **List, const uint32 Data, uint32 position)
{
    struct Node *MyNode = NULL;
    struct Node *NeededNode = *List;

    MyNode = (struct Node *)malloc(sizeof(struct Node));

    if(MyNode)
    {
        if(!(*List))
        {
            Insert_Node_At_Beginning(List, Data);
            free(MyNode);
        }
        else
        {
            if(position == Get_Length(*List))
            {
                Insert_Node_At_End(List, Data);
                free(MyNode);
            }
            else
            {
                MyNode->NodeData = Data;

                while(position > 1)
                {
                    NeededNode = NeededNode->RightNodeLink;
                    position--;
                }

                MyNode->RightNodeLink = NeededNode->RightNodeLink;
                NeededNode->RightNodeLink = MyNode;
                MyNode->LeftNodeLink = NeededNode;
                MyNode->RightNodeLink->LeftNodeLink = MyNode;
            }
        }
    }
    else
    {
        /*Nothing to do*/
    }
}

/**
  *@brief  : Function to insert data Before determined possition
  *@param  : (List) Pointer to the List
  *@param  : (Data) The value to be inserted
  *@param  : (position) the position to be inserted data Before it
  *@return : void
  */
void Insert_Node_Before(struct Node **List, const uint32 Data, const uint32 position)
{
    struct Node *MyNode = NULL;
    struct Node *NeededNode = *List;
    uint32 Nodeposition = position;

    MyNode = (struct Node *)malloc(sizeof(struct Node));

    if(MyNode)
    {
        if((!(*List)) || (1 == position))
        {
            Insert_Node_At_Beginning(List, Data);
            free(MyNode);
        }
        else
        {
            if(position == Get_Length(*List))
            {
                Insert_Node_At_End(List, Data);
                free(MyNode);
            }
            else
            {
                MyNode->NodeData = Data;

                while(Nodeposition > (position - 1))
                {
                    NeededNode = NeededNode->RightNodeLink;
                    Nodeposition--;
                }

                MyNode->RightNodeLink = NeededNode->RightNodeLink;
                NeededNode->RightNodeLink = MyNode;
                MyNode->LeftNodeLink = NeededNode;
                MyNode->RightNodeLink->LeftNodeLink = MyNode;
            }
        }
    }
    else
    {
        /* Nothing to do */
    }
}

/**
  *@brief  : Function to delete the first element from the list
  *@param  : (List) Double pointer to the List
  *@return : void
  */
void Delete_Node_At_Beginning(struct Node **List)
{
    if(*List)
    {
        *List = (*List)->RightNodeLink;
        free((*List)->LeftNodeLink);
        (*List)->LeftNodeLink = NULL;
    }
    else
    {
        printf("List is Empty:(\n");
    }
}

/**
  *@brief  : Function to delete the last element from the list
  *@param  : (List) Pointer to the List
  *@return : void
  */
void Delete_Node_At_End(struct Node **List)
{
    struct Node *TempNode = *List;
    struct Node *LastNode = NULL;

    if(*List)
    {
        if(1 == Get_Length(*List))
        {
            Delete_Node_At_Beginning(List);
        }
        else
        {
            while(TempNode->RightNodeLink)
            {
                TempNode = TempNode->RightNodeLink;
            }

            LastNode = TempNode->LeftNodeLink;
            LastNode->RightNodeLink = NULL;
            TempNode->LeftNodeLink = NULL;
            free(TempNode);
            TempNode = NULL;
        }
    }
    else
    {
        printf("List is Empty:(\n");
    }
}

/**
  *@brief  : Function to delete the determined element from the list
  *@param  : (List) Pointer to the List
  *@param  : (position) the position to be deleted from list
  *@return : void
  */
void Delete_Node_At_Intermediate(struct Node **List, const uint32 position)
{
    struct Node *NeededNode = NULL;
    struct Node *DeletedNode = *List;
    uint32 NodePos = position;

    if(*List)
    {
        if(1 == Get_Length(*List))
        {
            Delete_Node_At_Beginning(List);
        }
        else if(position == Get_Length(*List))
        {
            Delete_Node_At_End(List);
        }
        else
        {
            while(NodePos > 1)
            {
                DeletedNode = DeletedNode->RightNodeLink;
                NodePos--;
            }

            NeededNode = DeletedNode->LeftNodeLink;
            NeededNode->RightNodeLink = DeletedNode->RightNodeLink;
            DeletedNode->RightNodeLink->LeftNodeLink = NeededNode;
            DeletedNode->LeftNodeLink = NULL;
            DeletedNode->RightNodeLink = NULL;
            free(DeletedNode);
            DeletedNode = NULL;
        }
    }
    else
    {
        printf("List is Empty:(\n");
    }
}

/**
  *@brief  : Function to Print Data from list from beginning
  *@param  : (List) Pointer to the List
  *@return : void
  */
void Display_All_Nodes_Forward(const struct Node *const List)
{
    struct Node *TempNode = List;
    if(!List)
    {
        printf("List is Empty :(\n");
    }
    else
    {
        printf("Nodes Data:\t");
        while(TempNode)
        {
            printf("%i\t", TempNode->NodeData);
            TempNode = TempNode->RightNodeLink;
        }
        printf("NULL\n");
    }
}

/**
  *@brief  : Function to Print Data from list from end
  *@param  : (List) Pointer to the List
  *@return : void
  */
void Display_All_Nodes_Reverse(const struct Node *const List)
{
    struct Node *TempNode = List;

    if(!List)
    {
        printf("List is Empty :(\n");
    }
    else
    {
        while(TempNode->RightNodeLink)
        {
            TempNode = TempNode->RightNodeLink;
        }

        printf("Nodes Data:\t");

        while(TempNode)
        {
            printf("%i\t", TempNode->NodeData);
            TempNode = TempNode->LeftNodeLink;
        }
        printf("NULL\n");
    }
}

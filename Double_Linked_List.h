#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

#include "STD_Types.h"

struct Node{
    uint32 NodeData;
    struct Node *LeftNodeLink;
    struct Node *RightNodeLink;
};

/**
  *@brief  : Function to calculate the length of the List
  *@param  : Pointer to The List
  *@return : Length of The List
  */
uint32 Get_Length(const struct Node *const List);

/**
  *@brief  : Function to insert data to the beginning of the List
  *@param  : (List) Double pointer to the List
  *@param  : (Data) The value to be inserted
  *@return : Void
  */
void Insert_Node_At_Beginning(struct Node **List, const uint32 Data);

/**
  *@brief  : Function to insert data to the end of the List
  *@param  : (List) Double pointer to the List
  *@param  : (Data) The value to be inserted
  *@return : void
  */
void Insert_Node_At_End(struct Node **List, const uint32 Data);

/**
  *@brief  : Function to insert data After determined possition
  *@param  : (List) Pointer to the List
  *@param  : (Data) The value to be inserted
  *@param  : (position) the position to be inserted data after it
  *@return : void
  */
void Insert_Node_After(struct Node **List, const uint32 Data, uint32 position);

/**
  *@brief  : Function to insert data Before determined possition
  *@param  : (List) Pointer to the List
  *@param  : (Data) The value to be inserted
  *@param  : (position) the position to be inserted data Before it
  *@return : void
  */
void Insert_Node_Before(struct Node **List, const uint32 Data, const uint32 position);

/**
  *@brief  : Function to delete the first element from the list
  *@param  : (List) Double pointer to the List
  *@return : void
  */
void Delete_Node_At_Beginning(struct Node **List);

/**
  *@brief  : Function to delete the last element from the list
  *@param  : (List) Pointer to the List
  *@return : void
  */
void Delete_Node_At_End(struct Node **List);

/**
  *@brief  : Function to delete the determined element from the list
  *@param  : (List) Pointer to the List
  *@param  : (position) the position to be deleted from list
  *@return : void
  */
void Delete_Node_At_Intermediate(struct Node **List, const uint32 position);

/**
  *@brief  : Function to Print Data from list from beginning
  *@param  : (List) Pointer to the List
  *@return : void
  */
void Display_All_Nodes_Forward(const struct Node *const List);

/**
  *@brief  : Function to Print Data from list from end
  *@param  : (List) Pointer to the List
  *@return : void
  */
void Display_All_Nodes_Reverse(const struct Node *const List);

#endif // _DOUBLE_LINKED_LIST_H
